/**
 * @brief Module qui gère l'attaque spécial
 * Un joueur peut utilisé l'attaque spécial
 * @file SpecialWeapon.h
 * @date 2017/03/18
 */

#ifndef GAME_SPECIALWEAPON_H
#define GAME_SPECIALWEAPON_H

#include "Unit.h"

/**
 * @brief La classe SpecialWeapon contient les dégâts de l'attaque, un timer, et un booléan selon l'activité
 */

class SpecialWeapon {
    private:
        unsigned int damage;
        int price;
        bool active;
    public:
        SpecialWeapon();
        SpecialWeapon(const unsigned int damageP, const int priceP);
        ~SpecialWeapon();
        void operator = (const SpecialWeapon sw);
        unsigned int getDamage() const;
        void setDamage(const unsigned int damageP);
        int getPrice() const;
        void setPrice(const int priceP);
        bool getActive() const;
        void setActive(const bool activeP);
        /**
         * @brief Permet d'attaquer une unité sur le terrain
         * @param u
         */
        void attack(Unit & u);
};


#endif //GAME_SPECIALWEAPON_H
