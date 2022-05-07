#include <iostream>
#include "Player.hpp"
#include "Assassin.hpp"

constexpr int TO_COUP = 7;

namespace coup{
    Assassin::Assassin(Game &g, string n):Player(g,move(n)){
        this->player_role = "Assassin";
    }
    void Assassin::coup(Player player){
        check_coup();
        check_start();
        if(this->money < 3){
            throw("You don't have enough money for this action");
        }
        if(this->money >= TO_COUP){
            Player::coup(player);
        }
        else{
            game->assassination(player.get_name());
            this->set_last_play("special_coup", player.get_name());
            this->money-=3;
            game->next_turn();
        }
    }
}