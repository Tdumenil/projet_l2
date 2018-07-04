//
// Created by skugga on 08/03/17.
//

#include "../headers/Unit.h"
#include <iostream>
#include <cassert>
#include <unistd.h>
Unit::Unit() {
    x = 0;
    sizeUnit = 0;
    weapon = Bullet();
    damageUnit = 0;
    life = 0;
    price = 0;
    xp = 0;
    id = 0;
}

Unit::Unit(const unsigned int idP, const unsigned int lifeP, const unsigned int damageUnitP,
           const unsigned int sizeUnitP, const unsigned int priceP, const unsigned int xpP, const Bullet weaponP) {
    id = idP;
    life = lifeP;
    damageUnit = damageUnitP;
    sizeUnit = sizeUnitP;
    x = 0;
    xp = xpP;
    price = priceP;
    weapon = weaponP;
}

Unit::~Unit() {

}

void Unit::operator=(Unit u) {
    x = u.getX();
    sizeUnit = u.getSizeUnit();
    weapon = u.getWeapon();
    damageUnit = u.damageUnit;
    life = u.getLife();
    id = u.getId();
    xp = u.getXp();
    price = u.getPrice();
}

unsigned int Unit::getX() const {
    return x;
}

void Unit::setX(const unsigned int xx) {
    x = xx;
}

unsigned int Unit::getSizeUnit() const {
    return sizeUnit;
}

void Unit::setSizeUnit(const unsigned int sizeP) {
    sizeUnit = sizeP;
}

Bullet & Unit::getWeapon() {
    return weapon;
}

void Unit::setWeapon(const Bullet w) {
    weapon = w;
    damageUnit = 0;
}

unsigned int Unit::getId() const {
    return id;
}

void Unit::setId(const unsigned int idP) {
    id = idP;
}

unsigned int Unit::getDamageUnit() const {
    return damageUnit;
}

void Unit::setDamageUnit(const unsigned int damageUnitP) {
    damageUnit = damageUnitP;
}

int Unit::getLife() const {
    return life;
}

void Unit::setLife(const int lifeP) {
    life = lifeP;
}

int Unit::getPrice() const {
    return price;
}

void Unit::setPrice(const int priceP) {
    price = priceP;
}

unsigned int Unit::getXp() const {
    return xp;
}

void Unit::setXp(const unsigned int xpP) {
    xp = xpP;
}

void Unit::moveForward(Map & m) {
    if(m.isUnitFine(x + 1)){
        ++x;
    }
}

void Unit::moveBackward(Map & m) {
    if(m.isUnitFine(x - 1)) {
        --x;
    }
}

void Unit::attackUnit(Unit & unit) {
    if(weapon.getDamage() == 0) {
        unit.setLife(unit.getLife() - damageUnit);
    } else{
        unit.setLife(unit.getLife() - weapon.getDamage());
    }
}

void Unit::regressionTest() {
    /* Création d'une unité sans arme
    Avec id = 1, life = 100, damage = 50 et size = 1 */
    Unit u(1,100,50,1,0,0);
    assert(u.getId() == 1);
    assert(u.getLife() == 100);
    assert(u.getDamageUnit() == 50);
    assert(u.getSizeUnit() == 1);
    u.setPrice(20);
    assert(u.getPrice() == 20);
    u.setXp(50);
    assert(u.getXp() == 50);
    /* Création d'une arme
     Avec damage = 50 et timer = 1 */
    Bullet b(50);
    assert(b.getDamage() == 50);

    /* On lie l'arme avec l'unité
     On vérifie que les caractéristiques de l'arme sont ok */
    u.setWeapon(b);
    assert(u.getWeapon().getDamage() == 50);

    u.setId(2);
    assert(u.getId() == 2);
    u.setX(5);
    assert(u.getX() == 5);
    u.setLife(50);
    assert(u.getLife() == 50);
    u.setDamageUnit(50);
    assert(u.getDamageUnit() == 50);
    u.setSizeUnit(2);
    assert(u.getSizeUnit() == 2);


    Bullet w(100);
    Unit u1(1,125,0,1,0,0,w);
    u.attackUnit(u1);
    assert(u1.getLife() == 75);

    std::cout << "Test pour Unit et Bullet réussi" << std::endl;
}
