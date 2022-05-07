#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

constexpr int MAX_COINS = 10;
constexpr int TO_COUP = 7;

namespace coup{
    Player::Player(Game &g, string n):game(&g), money(0){
        if(g.began()){
            throw("game already began");
        }
        this->name = move(n);
        this->player_role = "";
        game->add_player(*this);
        this->action.push_back("");
        this->action.push_back("");
    }
    void Player::check_turn(){
        if(game->turn() != this->name){
            throw("It's not your turn");
        }
        if(this->money >= MAX_COINS){
            throw("have to make a coup");
        }
    }
    void Player::check_start(){
        if(this->game->players().size()<2){
            throw("not enough players joined the game");
        }
    }
    void Player::check_coup(){
        if(game->turn() != this->name){
            throw("It's not your turn");
        }
    }
    void Player::income(){
        check_turn();
        check_start();
        this->money++;
        this->set_last_play("income", this->name);
        game->next_turn();
    }
    void Player::foreign_aid(){
        check_turn();
        check_start();
        this->money+=2;
        this->set_last_play("foreign_aid", this->name);
        game->next_turn();
    }
    void Player::coup(Player &player){
        check_coup();
        check_start();
        if(this->money<TO_COUP){
            throw("You don't have enough coins for this action");
        }
        game->remove_player(player.name);
        this->set_last_play("coup", player.name);
        this->money-=TO_COUP;
        game->next_turn();
    }
    string Player::role(){
        return this->player_role;
    }
    int Player::coins() const{return this->money;}
    void Player::block(Player &player){}
    void Player::add_coins(int num){this->money+=num;}
    void Player::remove_coins(int num){this->money-=num;}
    string Player::get_name(){
        return this->name;
    }
    vector<string> Player::get_last_play(){
        return this->action;
    }
    void Player::set_last_play(string act, string done_to){
        this->action.at(0) = move(act);
        this->action.at(1) = move(done_to);
    }
};