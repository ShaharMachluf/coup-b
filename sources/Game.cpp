#include <iostream>
#include <vector>
#include "Game.hpp"

using namespace std;

constexpr int MAX_PLAYERS = 6;

namespace coup{
    Game::Game(){
        curr_turn = 0;
        started = false;
        game_winner = "";
        last_out = "";
        last_i_out = 0;
    }
    vector <string> Game::players(){
        return this->player_list;
    }
    string Game::turn(){return this->player_list.at(curr_turn);}
    void Game::next_turn(){
        curr_turn = (curr_turn+1)%this->player_list.size();
        started = true;
    }
    string Game::winner(){
        if(this->game_winner.empty()){
            throw("the game don't have a winner yet");
        }
        return this->game_winner;
    }
    void Game::remove_player(string const &name){
        for(unsigned int i=0; i<this->player_list.size(); i++){
            if(name == this->player_list.at(i)){
                if(i<this->curr_turn){
                    curr_turn--;
                }
                this->player_list.erase(this->player_list.begin()+i);
                if(this->player_list.size() == 1){
                    this->game_winner = this->player_list.at(0);
                }
                return;
            }
        }
        throw("this player is already dead");
    }
    void Game::assassination(string const &name){
        for(unsigned int i=0; i<this->player_list.size(); i++){
            if(name == this->player_list.at(i)){
                if(i<this->curr_turn){
                    curr_turn--;
                }
                this->last_out = name;
                this->last_i_out = i;
                this->player_list.erase(this->player_list.begin()+i);
                if(this->player_list.size() == 1){
                    this->game_winner = this->player_list.at(0);
                }
                return;
            }
        }
        throw("this player is already dead");
    }
    void Game::add_player(Player &player){
        if(this->player_list.size()>=MAX_PLAYERS){
            throw("a game has max of 6 players");
        }
        this->player_list.push_back(player.get_name());
        this->Player_obj_list.push_back(&player);
    }
    void Game::put_back(){
        this->player_list.insert(this->player_list.begin()+this->last_i_out, this->last_out);
        if(last_i_out<this->curr_turn){
            this->next_turn();
        }
    }
    vector <Player*> Game::get_players(){
        return this->Player_obj_list;
    }
    bool Game::began() const{
        return started;
    }
};