#pragma once

/**
 * ParamedicCommander class is derived from Paramedic base class.
 */

#include "Paramedic.hpp"

namespace WarGame {
    class ParamedicCommander : public Paramedic {
    public:
        /**
         * ParamedicCommander constructor.
         */
        ParamedicCommander(int team);

        /**
         * ParamedicCommander deconstructor.
         */
        ~ParamedicCommander();

        /**
         * This method activates the skill of the current paramedic commander.
         */
        void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) override;
    };
};
