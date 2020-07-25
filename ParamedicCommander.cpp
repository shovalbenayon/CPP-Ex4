#include "ParamedicCommander.hpp"

namespace WarGame {
    ParamedicCommander::ParamedicCommander(int team) : Paramedic(team) {
        this->setMaxHP(200);
        this->HP = this->getMaxHP();
        this->commander = true;
    }

    ParamedicCommander::~ParamedicCommander() { /* ParamedicCommander deconstructor */ }

    void ParamedicCommander::activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) {
        Paramedic::activate(board, location);
    }
};
