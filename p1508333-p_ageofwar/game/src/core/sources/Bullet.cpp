//
// Created by skugga on 08/03/17.
//

#include "../headers/Bullet.h"

Bullet::Bullet() {
    x = 0;
    damage = 0;
}

Bullet::Bullet(const unsigned int damageP) {
    x = 0;
    damage = damageP;
}

Bullet::~Bullet() {

}

void Bullet::operator=(const Bullet b) {
    x = b.getX();
    damage = b.getDamage();
}

unsigned int Bullet::getX() const {
    return x;
}

void Bullet::setX(const unsigned int xx) {
    x = xx;
}

unsigned int Bullet::getDamage() const {
    return damage;
}

void Bullet::setDamage(const unsigned int damageP) {
    damage = damageP;
}

void Bullet::moveForward() {
    ++x;
}

void Bullet::moveBackward() {
    --x;
}