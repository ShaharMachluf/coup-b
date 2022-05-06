#include <iostream>
#include "Player.hpp"

namespace coup{
    class Assassin:public Player{
        public:
        Assassin(Game &g, string n);
        void coup(Player player);
    };
};