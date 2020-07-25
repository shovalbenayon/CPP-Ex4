#pragma once

/**
 * Sniper class is derived from Soldier base class.
 */

#include "Soldier.hpp"

namespace WarGame {
    class Sniper : public Soldier {
    public:
        /**
         * Sniper constructor.
         */
        Sniper(int team);

        /**
         * Sniper deconstructor.
         */
        ~Sniper();

        /**
         * This method activates the skill of the current sniper.
         */
        void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) override;
    };
};
