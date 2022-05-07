#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"

namespace coup{
    Duke::Duke(Game &g, string n):Player(g,move(n)){
        this->player_role = "Duke";
    }
    void Duke::tax(){
        check_turn();
        check_start();
        this->money+=3;
        this->set_last_play("tax", this->name);
        game->next_turn();
    }
    void Duke::block(Player player){
        if(player.get_last_play().at(0)!= "foreign_aid"){
            throw("can't block this action");
        }
        player.remove_coins(2);
        this->set_last_play("block", player.get_name());
    }
};