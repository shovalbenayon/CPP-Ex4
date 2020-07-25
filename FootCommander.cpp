#include "FootCommander.hpp"

namespace WarGame {
    FootCommander::FootCommander(int team) : FootSoldier(team) {
        this->setMaxHP(150);
        this->HP = this->getMaxHP();
        this->damage = 20;
        this->commander = true;
    }

    FootCommander::~FootCommander() { /* FootCommander deconstructor */ }

    void FootCommander::activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) {
        FootSoldier::activate(board, location);
    }
};
