#pragma once

/**
 * Paramedic class is derived from Soldier base class.
 */

#include "Soldier.hpp"

namespace WarGame {
    class Paramedic : public Soldier {
    public:
        /**
         * Paramedic constructor.
         */
        Paramedic(int team);

        /**
         * Paramedic deconstructor.
         */
        ~Paramedic();

        /**
         * This method activates the skill of the current paramedic.
         */
        void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) override;
    };
};
