//
// Created by skugga on 09/03/17.
//

#include "../headers/Turret.h"
#include <unistd.h>

Turret::Turret() {
    bullet = Bullet();
}

Turret::Turret(const Bullet b, const int p) {
    bullet = b;
    price = p;
}

Turret::~Turret() {

}

void Turret::operator=(Turret t) {
    bullet = t.getBullet();
    price = t.price;
}

Bullet & Turret::getBullet() {
    return bullet;
}

void Turret::attack(Unit & u) {
    u.setLife(u.getLife() - getBullet().getDamage());
}

int Turret::getPrice() const {
    return price;
}

void Turret::setPrice(int p) {
    price = p;
}