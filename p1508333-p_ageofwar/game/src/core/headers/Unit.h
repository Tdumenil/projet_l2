/**
 * @brief Le module Unit gère les unités du jeu
 * Ce module va permettre d'avoir des collections d'unités aux corps à corps et à distance
 * @file Unit.h
 * @date 2017/03/18
 */

#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#include "Map.h"
#include "Bullet.h"

/**
 * @brief La classe Unit contient un x pour suivre la position de l'unité, une taille, une arme (optionnel), des dégâts, un identifiant, des points de vie, un prix et enfin de l'expérience
 */

class Unit {
    private:
        unsigned int x;
        unsigned int sizeUnit;
        Bullet weapon;
        unsigned int damageUnit;
        unsigned int id;
        int life;
        int price;
        unsigned int xp;

    public:
        Unit();
        Unit(const unsigned int idP, const unsigned int lifeP, const unsigned int damageUnitP,
             const unsigned int sizeUnitP, const unsigned int priceP, const unsigned int xpP, const Bullet weaponP = Bullet());
        ~Unit();
        void operator = (Unit u);
        unsigned int getX() const;
        void setX(const unsigned int xx);
        unsigned int getSizeUnit() const;
        void setSizeUnit(const unsigned int sizeP);
        Bullet & getWeapon();
        void setWeapon(const Bullet w);
        unsigned int getId() const;
        void setId(const unsigned int idP);
        unsigned int getDamageUnit() const;
        void setDamageUnit(const unsigned int damageUnitP);
        int getLife() const;
        void setLife(const int lifeP);
        int getPrice() const;
        void setPrice(const int priceP);
        unsigned int getXp() const;
        void setXp(const unsigned int xpP);

        /**
         * @brief Permet à l'unité d'avancé dans l'axe x normal (pour le player)
         * @param m
         */
        void moveForward(Map & m);

        /**
         * @brief Permet à l'unité d'avancé dans l'axe -x inverse (pour le bot)
         * @param m
         */
        void moveBackward(Map & m);

        /**
         * @brief Permet d'attaquer une unité
         * @param unit
         */
        void attackUnit(Unit & unit);
        void regressionTest();
};


#endif //GAME_UNIT_H
