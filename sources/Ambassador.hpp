#include <iostream>
#include "Player.hpp"

namespace coup{
    class Ambassador:public Player{
        public:
        Ambassador(Game &g, string n);
        void transfer(Player &p1, Player &p2);
        void block(Player &player);
    };
};