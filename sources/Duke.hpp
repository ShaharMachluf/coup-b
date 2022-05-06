#include <iostream>
#include "Player.hpp"

namespace coup{
    class Duke:public Player{
        public:
        Duke(Game &g, string n);
        void tax();
        void block(Player player);
    };
};