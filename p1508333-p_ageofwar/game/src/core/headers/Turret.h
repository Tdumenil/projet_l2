/**
 * @brief Module qui gère les tourelles
 * Ce module utilise la classe Bullet. Une tourelle lance des bullets
 * @file Turret.h
 * @date 2017/03/18
 */

#ifndef GAME_TURRET_H
#define GAME_TURRET_H

#include "Bullet.h"
#include "Unit.h"

/**
 * @brief La classe Turret contient une balle Bullet et un prix
 */

class Turret {
    private:
        Bullet bullet;
        int price;
    public:
        Turret();
        Turret(const Bullet b, const int p);
        ~Turret();
        void operator = (Turret t);
        Bullet & getBullet();
        void attack(Unit & u);
        int getPrice() const;
        void setPrice(int p);
};


#endif //GAME_TURRET_H
