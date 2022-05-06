#include <iostream>
#include "Player.hpp"

namespace coup{
    class Contessa:public Player{
        public:
        Contessa(Game &g, string n);
        void block(Player player);
    };
};