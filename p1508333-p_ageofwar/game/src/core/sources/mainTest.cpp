//
// Created by skugga on 08/03/17.
//

#include <iostream>
#include "../headers/Unit.h"
#include "../headers/Turret.h"
#include "../headers/Level.h"
#include "../headers/Player.h"
#include "../headers/Bot.h"
#include "../headers/Game.h"
using namespace std;

int main() {
    Level l;
    l.regressionTest();
    Unit u;
    u.regressionTest();
    Player p;
    p.regressionTest();
    Bot b;
    b.regressionTest();
    Game g;
    g.regressionTest();
    cout << "Appuyer sur entree pour quitter ";
    cin.get();
    return 0;
}