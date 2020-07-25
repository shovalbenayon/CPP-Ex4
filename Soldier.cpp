#include "Soldier.hpp"
#include "FootSoldier.hpp"

namespace WarGame {
    Soldier::Soldier(uint team, uint type, bool commander, int HP, int damage) {
        this->team = team;
        this->type = type;
        this->commander = commander;
        this->HP = HP;
        this->damage = damage;
    }

    Soldier::~Soldier() { /* Soldier deconstructor */ }

    int Soldier::getMaxHP() const {
        return this->maxHP;
    }

    void Soldier::setMaxHP(int maxHP) {
        this->maxHP = maxHP;
    }

    void Soldier::heal() {
        this->HP = this->getMaxHP();
    }

    void Soldier::activateTogether(std::vector<std::vector<Soldier*>>& board) {
        if (!this->commander) /* Only a commander can run this method */ {
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == nullptr) {
                    continue;
                } else if (board[i][j]->commander) {
                    continue;
                } else if (board[i][j]->team != this->team) {
                    continue;
                } else if (board[i][j]->type != this->type) {
                    continue;
                }

                this->activate(board, std::pair<int,int> {i,j});
            }
        }
    }
};
