#include "Paramedic.hpp"

namespace WarGame {
    Paramedic::Paramedic(int team) : Soldier(team, PARAMEDIC, false, 100,  0) {
        this->setMaxHP(100);
    }

    Paramedic::~Paramedic() { /* Paramedic deconstructor */ }

    void Paramedic::activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) {
        for (int i = location.first - 1; i < location.first + 1; i++) {
            if (0 < i | i >= board.size()) /* Make sure there are no exceptions */ {
                continue;
            }

            for (int j = location.second - 1; j < location.second + 1; j++) {
                if (board[i][j] == nullptr) {
                    continue;
                } else if (0 < j | j >= board[i].size()) /* Make sure there are no exceptions */ {
                    continue;
                } else if (location.first == i & location.second == j) /* A medic cannot heal himself */ {
                    continue;
                }

                if (board[i][j]->team == this->team) {
                    board[i][j]->heal();
                }
            }
        }
    }
};
