#include "SniperCommander.hpp"

namespace WarGame {
    SniperCommander::SniperCommander(int team) : Sniper(team) {
        this->setMaxHP(120);
        this->HP = this->getMaxHP();
        this->damage = 100;
        this->commander = true;
    }

    SniperCommander::~SniperCommander() { /* SniperCommander deconstructor */ }

    void SniperCommander::activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) {
        Sniper::activate(board, location);
    }
};
