/**
 * @brief Le module de niveau permet d'associer des unités, une tourelle et une attaque spéciale au sein d'un même module
 * @file Level.h
 * @date 2017/03/18
 */

#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "Unit.h"
#include "Turret.h"
#include "SpecialWeapon.h"

/**
 * @brief La classe Level contient un identifiant, un tableau d'unités, une attaque spéciale, une tourelle et de l'expérience
 */

class Level {
    private:
        unsigned int id;
        Unit tabUnits[3];
        SpecialWeapon weaponS;
        Turret turret;
        unsigned int xp;

    public:
        Level();
        Level(const unsigned int idP, const Unit units[], const SpecialWeapon w, const Turret t);
        ~Level();
        void operator = (Level l);
        unsigned int getId() const;
        void setId(const unsigned int idP);
        Turret & getTurret();
        SpecialWeapon & getWeaponS();

        /**
         * @brief Récupérer une unité selon sa place dans le tableau d'unités
         * @param i
         * @return une unité
         */
        const Unit & getUnit(const unsigned int i);

        /**
         * @brief Récupérer une unité selon son identifiant
         * @param id
         * @return une unité
         */
        Unit & getUnitById(const unsigned int id);

        /**
         * @brief Ajouter une unité au tableau d'unités
         * @param u
         * @param i
         */
        void addUnit(const Unit u, const unsigned int i);
        unsigned int sizeTabUnits();
        unsigned int getXp() const;
        void setXp(const unsigned int xpP);

        /**
         * @brief Initialise le niveau 1
         */
        void levelOne();
        /**
        * @brief Initialise le niveau 2
        */
        void levelTwo();
        /**
        * @brief Initialise le niveau 3
        */
        void levelThree();
        void regressionTest();
};


#endif //GAME_LEVEL_H
