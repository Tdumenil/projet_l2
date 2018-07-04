//
// Created by skugga on 08/03/17.
//

#include <iostream>
#include "../headers/Unit.h"
#include "../headers/Turret.h"
#include "../headers/Level.h"

using namespace std;

int main() {
    Bullet Fleche(50, 1);
    Unit Archer(1,100,0,1,Fleche);
    Unit Epeiste(2,200,75,1,Fleche);
    cout << "Archer id : " << Archer.getId() << endl;
    cout << "Points de vie : " << Archer.getLife() << endl;
    cout << "Damage : " << Archer.getWeapon().getDamage() << endl;
    cout << "Taille : " << Archer.getSizeUnit() << endl;
    cout << "Combat Arché vs Epée :" << endl;
    Epeiste.attackUnit(Archer);
    cout << "Epéiste attaque avec 50 damage en premier, pdv archer : " << Archer.getLife() << endl;

    cout << endl;
    Bullet t1(100, 2);
    Turret tourelle(t1);
    cout << "Création d'une tourelle." << endl;
    cout << "Dégats de la tourelle : " << tourelle.getBullet().getDamage() << endl;

    Level l;
    cout << "taille tab : " << l.sizeTabUnits() << endl;
    l.addUnit(Archer,0);
    l.addUnit(Epeiste,1);
    cout << "Archer id : " << l.getUnitById(1).getLife() << endl;
    cout << l.getUnit(0).getLife() << endl;
    cout << "Appuyer sur entree pour quitter ";
    cin.get();
    return 0;
}