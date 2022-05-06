#include <iostream>
#include <vector>
#include "Game.hpp"

using namespace std;

namespace coup{
    Game::Game(){
        curr_turn = 0;
        started = false;
        game_winner = "";
        last_out = "";
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
        if(this->game_winner.compare("") == 0){
            throw("the game don't have a winner yet");
        }
        return this->game_winner;
    }
    void Game::remove_player(string name){
        for(unsigned int i=0; i<this->player_list.size(); i++){
            if(name.compare(this->player_list.at(i)) == 0){
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
    }
    void Game::assassination(string name){
        for(unsigned int i=0; i<this->player_list.size(); i++){
            if(name.compare(this->player_list.at(i)) == 0){
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
    }
    void Game::add_player(Player &player){
        if(this->player_list.size()>=6){
            throw("a game has max of 6 players");
        }
        this->player_list.push_back(player.get_name());
        this->Player_obj_list.push_back(&player);
    }
    void Game::put_back(){
        this->player_list.insert(this->player_list.begin()+this->last_i_out, this->last_out);
    }
    vector <Player*> Game::get_players(){
        return this->Player_obj_list;
    }
    bool Game::began(){
        return started;
    }
};