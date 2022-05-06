#include <iostream>
#include "Player.hpp"
#include "Captain.hpp"

namespace coup{
    Captain::Captain(Game &g, string n):Player(g,n){
        this->player_role = "Captain";
    }
    void Captain::steal(Player &player){
        check_turn();
        check_start();
        if(player.coins()==0){
            this->set_last_play("steal0", player.get_name());
            game->next_turn();
        }else if(player.coins()==1){
            this->money+=1;
            player.remove_coins(1);
            this->set_last_play("steal1", player.get_name());
            game->next_turn();
        }else{
            this->money+=2;
            player.remove_coins(2);
            this->set_last_play("steal2", player.get_name());
            game->next_turn();
        }
    }
    void Captain::block(Player &player){
        check_start();
        int num;
        vector<string>vec = player.get_last_play();
        if(vec.at(0).compare("steal0") == 0){
            num = 0;
        }
        else if(vec.at(0).compare("steal1") == 0){
            num = 1;
        }else if(vec.at(0).compare("steal2") == 0){
            num = 2;
        }
        else{
            throw("Last action wasn't 'steal'");
        }
        vector<Player*> players = game->get_players();
        for(unsigned int i=0; i<players.size(); i++){
            if((*players.at(i)).get_name() == vec.at(1)){
                (*players.at(i)).add_coins(num);
            }
        }
        player.remove_coins(num);
        this->set_last_play("block", player.get_name());
    }
};