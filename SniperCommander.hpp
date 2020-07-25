#pragma once

/**
 * SniperCommander class is derived from Sniper base class.
 */

#include "Sniper.hpp"

namespace WarGame {
    class SniperCommander : public Sniper {
    public:
        /**
         * SniperCommander constructor.
         */
        SniperCommander(int team);

        /**
         * SniperCommander deconstructor.
         */
        ~SniperCommander();

        /**
         * This method activates the skill of the current sniper commander.
         */
        void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) override;
    };
};
