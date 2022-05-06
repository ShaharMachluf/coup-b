#pragma once
#include <iostream>
#include "Game.hpp"

using namespace std;

namespace coup{
    class Game;
    class Player{
        protected:
        string name;
        string player_role;
        Game *game;
        int money;
        vector <string> action;
        void check_turn();
        void check_start();
        void check_coup();
        public:
        Player(Game &g, string n);
        void income();
        void foreign_aid();
        virtual void coup(Player player);
        string role();
        int coins();
        virtual void block(Player player);
        void add_coins(int num);
        void remove_coins(int num);
        string get_name();
        vector<string> get_last_play();
        void set_last_play(string act, string done_to);
    };
};