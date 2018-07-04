/**
 * @brief Le module Player permet de gérer le joueur
 * C'est le joueur que l'utilisateur va jouer
 * @file Player.h
 * @date 2017/03/18
 */

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Level.h"

/**
 * @brief La classe Player a des points de vie, un niveau défini, de l'argent, de l'expérience, un pointeur sur tableau d'unité actif
 */

class Player {
    private:
        int life;
        Level level;
        int money;
        unsigned int xp;
        bool positionBase;
        Unit * tabUnitsActive;
        unsigned int sizeTabUnitsActive;
        bool turretA;
    public:
        Player();
        Player(const int lifeP, const Level l, const unsigned int moneyP, const unsigned int xpP, const bool posB, const bool t);
        ~Player();
        int getLife() const;
        void setLife(const int lifeP);
        Level & getLevel();
        void setLevel(const Level l);
        int getMoney() const;
        void setMoney(const int moneyP);
        unsigned int getXp() const;
        void setXp(const unsigned int xpP);
        bool getPositionBase() const;
        void setPositionBase(const bool posB);

        /**
         * @brief Permet de récupérer une unité grâce à son positionnement dans le tableau
         * @param i
         * @return une unité actif
         */
        Unit & getTabUnitActive(const unsigned int i);

        /**
         * @brief Permet de récupérer une unité grâce à son Id
         * @param id
         * @return une unité actif
         */
        Unit & getTabUnitActiveById(const unsigned int id);

        /**
         * @brief Permet de récupérer une unité grâce à son positionnement sur la map
         * @param x
         * @return une unité actif
         */
        Unit & getTabUnitActiveByX(const unsigned int x);
        unsigned int getSizeTabUnitsActive() const;
        bool getTurretA() const;
        void setTurretA(const bool t);

        void setTab(Unit * tab);
        void setSizeTab(unsigned int size);

        /**
         * @brief Ajouter une unité dans le tableau des unités actifs
         * @param u
         */
        void addUnitToTab(const Unit & u);

        /**
         * @brief Permet de passer au niveau suivant si la valeur de l'expérience est bonne
         */
        void levelUp();

        /**
         * @brief Permet d'acheter et de faire apparâitre une unité sur la map
         * @param u
         * @param p
         */
        void buyUnit(Unit & u, const bool p);

        /**
         * @brief Enlève du tableau des unités atifs le premier élément
         */
        void unitIsDead();

        /**
         * @brief Enlève du tableau des unités actifs le dernier élément
         */
        void unitIsDeadLast();

        /**
         * @brief Enlève une unité du tableau des unités actifs selon son positionnement dans celui-ci
         * @param in
         */
        void unitIsDeadByI(const unsigned int in);

        /**
         * @brief Ajoute l'argent et l'expérience selon une unité
         * @param u
         */
        void winMoneyAndXp(const Unit & u);

        /**
         * @brief Permet d'acheter une tourelle
         */
        void buyTurret();

        /**
         * @brief Permet d'utilisé l'attaque spéciale
         */
        void useSpecialWeapon();
        void regressionTest();
};


#endif //GAME_PLAYER_H
