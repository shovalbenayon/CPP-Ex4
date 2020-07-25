#include "Board.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"

namespace WarGame {
    Soldier*& Board::operator[] /* Overloading */ (std::pair<int,int> location) {
        Board::check(location);
        return Board::board[location.first][location.second];
    }

    Soldier* Board::operator[] /* Overloading */ (std::pair<int,int> location) const {
        Board::check(location);
        return Board::board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
        if (!has_soldiers(player_number)) /* The current team has no soldiers */ {
            return;
        }

        Board::check(source);

        if (board[source.first][source.second] == nullptr) {
            throw std::invalid_argument("ERROR! the given source location is null");
        }

        else if (board[source.first][source.second]->team != player_number) {
            throw std::invalid_argument("ERROR! this soldier belongs to the opposing team");
        }

        std::pair<int,int> destination /* Copy constructor */ (source);

        switch (direction) {
            case Down :
                if (destination.first - 1 < 0) {
                    throw std::invalid_argument("ERROR! An illegal attempt to move the current soldier up");
                }

                destination.first -= 1;
            
            break;
            case Up :
                if (destination.first + 1 == Board::board.size()) {
                    throw std::invalid_argument("ERROR! An illegal attempt to move the current soldier down");
                }

                destination.first += 1;

            break;
            case Left :
                if (destination.second - 1 < 0) {
                    throw std::invalid_argument("ERROR! An illegal attempt to move the current soldier left");
                }

                destination.second -= 1;

            break;
            case Right :
                if (destination.second + 1 == Board::board[0].size()) {
                    throw std::invalid_argument("ERROR! An illegal attempt to move the current soldier right");
                }

                destination.second += 1;

            break;
        }

        if (board[destination.first][destination.second] != nullptr) {
            throw std::invalid_argument("ERROR! there is already another soldier at the destination");
        }

        /* Perform swap */
        board[destination.first][destination.second] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;

        /* Activate skill */
        if (board[destination.first][destination.second]->commander) {
            board[destination.first][destination.second]->activate(board, destination);
            board[destination.first][destination.second]->activateTogether(board);
        } else {
            board[destination.first][destination.second]->activate(board, destination);
        }
    }

    bool Board::has_soldiers(uint player_number) const {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == nullptr) {
                    continue;
                }

                if (board[i][j]->team == player_number) /* The current team has at least one soldier */ {
                    return true;
                }
            }
        }

        return false;
    }

    void Board::check(std::pair<int,int> location) const {
        if (location.first < 0 | location.first >= board.size()) {
            throw std::runtime_error("ERROR! the given location is out of bounds");
        }

        else if (location.second < 0 | location.second >= board[0].size()) {
            throw std::runtime_error("ERROR! the given location is out of bounds");
        }
    }
};
