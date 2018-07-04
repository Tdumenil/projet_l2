//
// Created by skugga on 09/03/17.
//

#include "../headers/SpecialWeapon.h"

SpecialWeapon::SpecialWeapon() {
    damage = 0;
    active = false;
    price = 0;
}

SpecialWeapon::SpecialWeapon(const unsigned int damageP, const int priceP) {
    damage = damageP;
    price = priceP;
}

SpecialWeapon::~SpecialWeapon() {

}

void SpecialWeapon::operator=(const SpecialWeapon sw) {
    damage = sw.getDamage();
    price = sw.getPrice();
    active = sw.getActive();
}

unsigned int SpecialWeapon::getDamage() const {
    return damage;
}

void SpecialWeapon::setDamage(const unsigned int damageP) {
    damage = damageP;
}

int SpecialWeapon::getPrice() const {
    return price;
}

void SpecialWeapon::setPrice(const int priceP) {
    price = priceP;
}

bool SpecialWeapon::getActive() const {
    return active;
}

void SpecialWeapon::setActive(const bool activeP) {
    active = activeP;
}

void SpecialWeapon::attack(Unit &u) {
    u.setLife(u.getLife() - damage);
}