#include <iostream>
#include "Player.hpp"
#include "Ambassador.hpp"

namespace coup{
    Ambassador::Ambassador(Game &g, string n):Player(g,move(n)){
        this->player_role = "Ambassador";
    }
    void Ambassador::transfer(Player &p1, Player &p2){
        check_turn();
        check_start();
        if(p1.coins() < 1){
            throw("can't take money from someone that doesn't have enough");
        }
        p1.remove_coins(1);
        p2.add_coins(1);
        this->set_last_play("transfer", this->name);
        game->next_turn();
    }
    void Ambassador::block(Player &player){
        check_start();
        int num=0;
        vector<string>vec = player.get_last_play();
        if(vec.at(0) == "steal0"){
            num = 0;
        }
        else if(vec.at(0) == "steal1"){
            num = 1;
        }else if(vec.at(0) == "steal2"){
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