#pragma once

/**
 * FootSoldier class is derived from Soldier base class.
 */

#include "Soldier.hpp"

namespace WarGame {
    class FootSoldier : public Soldier {
    public:
        /**
         * FootSoldier constructor.
         */
        FootSoldier(int team);

        /**
         * FootSoldier deconstructor.
         */
        ~FootSoldier();

        /**
         * This method activates the skill of the current foot soldier.
         */
        void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) override;
    };
};
