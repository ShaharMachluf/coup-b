#include <iostream>
#include "Player.hpp"
#include "Contessa.hpp"

namespace coup{
    Contessa::Contessa(Game &g, string n):Player(g,n){
        this->player_role = "Contessa";
    }
    void Contessa::block(Player player){
        check_start();
        if(player.role() != "Assassin"){
            throw("contessa can block only assasin");
        }
        if(player.get_last_play().at(0)!= "special_coup"){
            throw("contessa can only block assassination");
        }
        game->put_back();
        this->set_last_play("block", player.get_name());
    }
};