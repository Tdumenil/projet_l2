//
// Created by skugga on 17/03/17.
//

#include "../headers/Player.h"
#include <iostream>
#include <cassert>
Player::Player() {
    life = 0;
    level = Level();
    money = 0;
    xp = 0;
    positionBase = 0;
    tabUnitsActive = NULL;
    sizeTabUnitsActive = 0;
    turretA = 0;
}

Player::Player(const int lifeP, const Level l, const unsigned int moneyP, const unsigned int xpP,
               const bool posB, const bool t) {
    life = lifeP;
    level = l;
    money = moneyP;
    xp = xpP;
    positionBase = posB;
    turretA = t;
}

Player::~Player() {
}

int Player::getLife() const {
    return life;
}

void Player::setLife(const int lifeP) {
    life = lifeP;
}

Level& Player::getLevel() {
    return level;
}

void Player::setLevel(const Level l) {
    level = l;
}

int Player::getMoney() const {
    return money;
}

void Player::setMoney(const int moneyP) {
    money = moneyP;
}

unsigned int Player::getXp() const {
    return xp;
}

void Player::setXp(const unsigned int xpP) {
    xp = xpP;
}

bool Player::getPositionBase() const {
    return positionBase;
}

void Player::setPositionBase(const bool posB) {
    positionBase = posB;
}

Unit& Player::getTabUnitActive(const unsigned int i) {
    assert(tabUnitsActive);
    return tabUnitsActive[i];
}

Unit& Player::getTabUnitActiveById(const unsigned int id) {
    assert(tabUnitsActive);
    for(unsigned int i ; i < sizeTabUnitsActive ; ++i){
        if(tabUnitsActive[i].getId() == id){
            return tabUnitsActive[i];
        }
    }
    return tabUnitsActive[0];
}

Unit& Player::getTabUnitActiveByX(const unsigned int x) {
    assert(tabUnitsActive);
    for (unsigned int i; i < sizeTabUnitsActive; ++i) {
        if (tabUnitsActive[i].getX() == x) {
            return tabUnitsActive[i];
        }
    }
    return tabUnitsActive[0];
}

unsigned int Player::getSizeTabUnitsActive() const {
    return sizeTabUnitsActive;
}

bool Player::getTurretA() const {
    return turretA;
}

void Player::setTurretA(const bool t) {
    turretA = t;
}

void Player::setTab(Unit *tab) {
    tabUnitsActive = tab;
}

void Player::setSizeTab(unsigned int size) {
    sizeTabUnitsActive = size;
}

void Player::addUnitToTab(const Unit & u) {
        Unit temp[sizeTabUnitsActive];
        for (unsigned int i = 0; i < sizeTabUnitsActive; ++i) {
            temp[i] = tabUnitsActive[i];
        }
        ++sizeTabUnitsActive;
        tabUnitsActive = new Unit[sizeTabUnitsActive];
        for (unsigned int i = 0; i < sizeTabUnitsActive - 1; ++i) {
            tabUnitsActive[i] = temp[i];
        }
        tabUnitsActive[sizeTabUnitsActive - 1] = u;
}

void Player::levelUp() {
    unsigned int currentLevel = level.getId();
    Level l2;
    l2.levelTwo();
    if(currentLevel == 1 && xp >= l2.getXp()){
        level.levelTwo();
    }
    Level l3;
    l3.levelThree();
    if(currentLevel == 2 && xp >= l3.getXp()){
        level.levelThree();
    }
}

void Player::buyUnit(Unit & u, const bool p) {
    unsigned int x = 33;
    if(sizeTabUnitsActive < 15) {
        if (money - u.getPrice() >= 0) {
            if(tabUnitsActive != NULL) {
                if (tabUnitsActive[sizeTabUnitsActive - 1].getX() > 1 &&
                    tabUnitsActive[sizeTabUnitsActive - 1].getX() < x) {
                    if (p == 0) {
                        u.setX(1);
                    } else {
                        u.setX(x);
                    }
                    money -= u.getPrice();
                    addUnitToTab(u);
                }
            } else{
                if (p == 0) {
                    u.setX(1);
                } else {
                    u.setX(x);
                }
                money -= u.getPrice();
                addUnitToTab(u);
            }
        }
    }
}

void Player::unitIsDead() {
    if(sizeTabUnitsActive > 1) {
        Unit temp[sizeTabUnitsActive-1];
        unsigned int j = 0;
        for (unsigned int i = 1; i < sizeTabUnitsActive; ++i) {
            temp[j] = tabUnitsActive[i];
            ++j;
        }

        --sizeTabUnitsActive;
        if (sizeTabUnitsActive > 0) {
            tabUnitsActive = new Unit[sizeTabUnitsActive];
            for (unsigned int i = 0; i < sizeTabUnitsActive; ++i) {
                tabUnitsActive[i] = temp[i];
            }
        }
    }
    else{
        tabUnitsActive = NULL;
        sizeTabUnitsActive = 0;
    }
}

void Player::unitIsDeadByI(const unsigned int in) {
    Unit temp[sizeTabUnitsActive-1];
    unsigned int j = 0;
    for(unsigned int i = 0 ; i < in ; ++i){
        temp[j] = tabUnitsActive[i];
        ++j;
    }
    for(unsigned int i = in+1 ; i < sizeTabUnitsActive ; ++i){
        temp[j] = tabUnitsActive[i];
        ++j;
    }

    --sizeTabUnitsActive;
    if(sizeTabUnitsActive > 0){
        tabUnitsActive = new Unit[sizeTabUnitsActive];
        for(unsigned int i = 0 ; i < sizeTabUnitsActive ; ++i){
            tabUnitsActive[i] = temp[i];
        }
    }
}

void Player::unitIsDeadLast() {
    if(sizeTabUnitsActive > 1) {
        Unit temp[sizeTabUnitsActive-1];
        unsigned int j = 0;
        for (unsigned int i = 0; i < sizeTabUnitsActive - 1; ++i) {
            temp[j] = tabUnitsActive[i];
            ++j;
        }

        --sizeTabUnitsActive;
        if (sizeTabUnitsActive > 0) {
            tabUnitsActive = new Unit[sizeTabUnitsActive];
            for (unsigned int i = 0; i < sizeTabUnitsActive; ++i) {
                tabUnitsActive[i] = temp[i];
            }
        }
    }
    else{
        tabUnitsActive = NULL;
        sizeTabUnitsActive = 0;
    }
}

void Player::winMoneyAndXp(const Unit &u) {
    money += u.getPrice() + 50;
    xp += u.getXp();
}

void Player::buyTurret() {
    if(money - level.getTurret().getPrice() >= 0) {
        turretA = 1;
        level.getTurret().getBullet().setX(1);
        money -= level.getTurret().getPrice();
    }
}

void Player::useSpecialWeapon() {
    if(money - level.getWeaponS().getPrice() >= 0){
        assert(money >= 0);
        money -= level.getWeaponS().getPrice();
        level.getWeaponS().setActive(true);
    }
}

void Player::regressionTest() {
    Player p1;
    p1.getLevel().levelOne();
    assert(p1.getLevel().getUnitById(1).getLife() == 250);
    assert(p1.getLevel().getUnitById(2).getLife() == 500);
    assert(p1.getLevel().getUnit(2).getLife() == 275);
    p1.winMoneyAndXp(p1.getLevel().getUnitById(3));
    assert(p1.getMoney() == 85 + 50);
    assert(p1.getMoney() == p1.getLevel().getUnitById(3).getPrice() + 50);
    p1.addUnitToTab(p1.getLevel().getUnitById(1));
    assert(p1.getTabUnitActive(0).getId() == 1);
    assert(p1.getTabUnitActive(0).getLife() == 250);
    p1.getTabUnitActive(0).setX(5);
    p1.buyUnit(p1.getLevel().getUnitById(2), 0);
    assert(p1.getMoney() == 135 - 75);
    assert(p1.getTabUnitActive(1).getId() == 2);
    assert(p1.getTabUnitActive(1).getDamageUnit() == 10);
    assert(p1.getTabUnitActive(0).getDamageUnit() == 50);
    p1.unitIsDead();
    assert(p1.getTabUnitActive(0).getId() == 2);
    p1.unitIsDeadByI(0);
    assert(p1.getSizeTabUnitsActive() == 0);
    p1.useSpecialWeapon();
    p1.setMoney(200);
    p1.buyTurret();
    p1.setXp(1000);
    assert(p1.getXp() == 1000);
    p1.levelUp();
    assert(p1.getLevel().getId() == 2);
    std::cout << "Test pour player réussi" << std::endl;
}