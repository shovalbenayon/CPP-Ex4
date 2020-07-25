#pragma once

#include <cmath>
#include <vector>
#include <iostream>

#define FOOT 0
#define SNIPER 1
#define PARAMEDIC 2

namespace WarGame {
    class Soldier {
    private:
        int maxHP;

    public:
        uint team;
        uint type;
        bool commander;
        int HP;
        int damage;

        /**
         * Soldier constructor.
         */
        Soldier(uint team, uint type, bool commander, int HP, int damage);

        /**
         * Soldier deconstructor.
         */
        virtual ~Soldier();

        /**
         * This method returns the maximum HP of the current soldier.
         */
        int getMaxHP() const;

        /**
         * This method sets the maximum HP of the current soldier.
         */
        void setMaxHP(int maxHP);

        /**
         * This method heals the current soldier.
         * Should be used by medics only.
         */
        void heal();

        /**
         * This method activates the skill of the current soldier.
         */
        virtual void activate(std::vector<std::vector<Soldier*>>& board, std::pair<int,int> location) = 0;

        /**
         * Used by commanders only.
         */
        void activateTogether(std::vector<std::vector<Soldier*>>& board);
    };
};
