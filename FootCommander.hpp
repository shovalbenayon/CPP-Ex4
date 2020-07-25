#pragma once

/**
 * FootCommander class is derived from FootSoldier base class.
 */

#include "FootSoldier.hpp"

namespace WarGame {
    class FootCommander : public FootSoldier {
    public:
        /**
         * FootCommander constructor.
         */
        FootCommander(int team);

        /**
         * FootCommander deconstructor.
         */
        ~FootCommander();

        /**
         * This method activates the skill of the current foot commander.
         */
        void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) override;
    };
};
