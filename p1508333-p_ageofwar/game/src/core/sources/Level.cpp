//
// Created by skugga on 09/03/17.
//

#include "../headers/Level.h"
#include <iostream>
#include <cassert>

Level::Level() {
    for(unsigned int i = 0 ; i < sizeTabUnits() ; ++i){
        tabUnits[i] = Unit();
    }
    id = 0;
    weaponS = SpecialWeapon();
    turret = Turret();
}

Level::Level(const unsigned int idP, const Unit units[], const SpecialWeapon w, const Turret t = Turret()) {
    for(unsigned int i = 0 ; i < sizeTabUnits() ; ++i){
        tabUnits[i] = units[i];
    }
    weaponS = w;
    turret = t;
    id = idP;
}

Level::~Level() {

}

void Level::operator=(Level l) {
    for(unsigned int i = 0 ; i < sizeTabUnits() ; ++i){
        tabUnits[i] = l.getUnit(i);
    }
    weaponS = l.getWeaponS();
    turret = l.getTurret();
    id = l.getId();
}

unsigned int Level::getId() const {
    return id;
}

void Level::setId(const unsigned int idP) {
    id = idP;
}

Turret & Level::getTurret() {
    return turret;
}

SpecialWeapon & Level::getWeaponS() {
    return weaponS;
}

const Unit & Level::getUnit(const unsigned int i) {
    return tabUnits[i];
}

Unit & Level::getUnitById(const unsigned int id) {
    for(unsigned int i = 0 ; i < sizeTabUnits() ; ++i){
        if(tabUnits[i].getId() == id){
            return tabUnits[i];
        }
    }
    return tabUnits[0];
}

void Level::addUnit(const Unit u, const unsigned int i) {
    assert(i < sizeTabUnits());
    tabUnits[i] = u;
}

unsigned int Level::sizeTabUnits() {
    return (sizeof(tabUnits)/sizeof(*tabUnits));
}

unsigned int Level::getXp() const {
    return xp;
}

void Level::setXp(const unsigned int xpP) {
    xp = xpP;
}

void Level::levelOne() {
    Unit u1(1,250,50,1,50,10);
    Unit u2(2,500,10,1,75,15);
    Bullet weapon(45);
    Unit u3(3,275,45,1,85,20,weapon);
    tabUnits[0] = u1;
    tabUnits[1] = u2;
    tabUnits[2] = u3;
    id = 1;
    Bullet b(75);
    Turret t(b,500);
    turret = t;
    SpecialWeapon sw(10000,1000);
    weaponS = sw;
    xp = 0;
}

void Level::levelTwo() {
    Unit u1(1,450,70,1,250,30);
    Unit u2(2,600,30,1,300,50);
    Bullet weapon(80);
    Unit u3(3,475,80,1,400,70,weapon);
    tabUnits[0] = u1;
    tabUnits[1] = u2;
    tabUnits[2] = u3;
    id = 2;
    Bullet b(75);
    Turret t(b,1000);
    turret = t;
    SpecialWeapon sw(10000,5000);
    weaponS = sw;
    xp = 200;
}

void Level::levelThree() {
    Unit u1(1,650,100,1,550,200);
    Unit u2(2,800,80,1,700,250);
    Bullet weapon(80);
    Unit u3(3,1000,200,1,999,300,weapon);
    tabUnits[0] = u1;
    tabUnits[1] = u2;
    tabUnits[2] = u3;
    id = 2;
    Bullet b(150);
    Turret t(b,2000);
    turret = t;
    SpecialWeapon sw(10000,5000);
    weaponS = sw;
    xp = 999;
}


void Level::regressionTest() {
    Unit u1(1,200,50,1,130,10);
    Unit u2(2,201,51,1,131,11);
    Unit u3(3,202,52,1,132,12);
    Unit tabU[4];
    tabU[0] = u1;
    tabU[1] = u2;
    tabU[2] = u3;
    SpecialWeapon sw(100,500);
    Level l1(1,tabU,sw);
    assert(l1.getWeaponS().getDamage() == 100);
    assert(l1.getUnitById(2).getLife() == 201);
    assert(l1.getUnitById(2).getDamageUnit() == 51);
    assert(l1.getUnitById(1).getDamageUnit() == 50);
    assert(l1.getUnit(0).getLife() == 200);
    assert(l1.getUnit(0).getDamageUnit() == 50);
    assert(l1.getUnitById(3).getPrice() == 132);
    assert(l1.getUnitById(1).getXp() == 10);

    Bullet w(50);
    Unit u4(4,203,53,1,133,13,w);
    assert(u4.getWeapon().getDamage() == 50);
    u4.getWeapon().moveForward();
    assert(u4.getWeapon().getX() == 1);
    std::cout << "Test de level réussi" << std::endl;
}