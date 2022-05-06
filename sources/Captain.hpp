#include <iostream>
#include "Player.hpp"

namespace coup{
    class Captain:public Player{
        public:
        Captain(Game &g, string n);
        void steal(Player &player);
        void block(Player &player);
    };
};