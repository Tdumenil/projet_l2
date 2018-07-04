//
// Created by skugga on 19/03/17.
//

#include "../headers/Bot.h"
#include <cassert>
#include <iostream>
Bot::Bot() {
    player = Player();
}

Player& Bot::getPlayer() {
    return player;
}

int Bot::rand_a_b (int a, int b) {
    return rand() % (b - a) + a;
}

void Bot::autoBuyUnit() {
    int totalMoney = player.getMoney();
    if(totalMoney < 400 && player.getSizeTabUnitsActive() < 2){
        player.buyUnit(player.getLevel().getUnitById(1),1);
    }
    if(totalMoney > 400 && player.getSizeTabUnitsActive() < 3){
        if(rand_a_b(0,10) == 0){
            player.buyUnit(player.getLevel().getUnitById(1),1);
        }
        if(rand_a_b(0,15) == 0){
            player.buyUnit(player.getLevel().getUnitById(2),1);
        }
    }
    if(totalMoney > 400 && player.getSizeTabUnitsActive() < 4){
        if(rand_a_b(0,15) == 0){
            player.buyUnit(player.getLevel().getUnitById(2),1);
            player.buyUnit(player.getLevel().getUnitById(1),1);
        }
    }
    if(totalMoney > 200 && player.getSizeTabUnitsActive() < 3){
        player.buyUnit(player.getLevel().getUnitById(1),1);
    }
}

void Bot::autoBuyTurret() {

}

void Bot::autoUseSpecialWeapon() {

}

void Bot::regressionTest() {
    Bot b;
    b.getPlayer().getLevel().levelOne();
    b.getPlayer().setMoney(100);
    b.autoBuyUnit();
    assert(b.getPlayer().getTabUnitActive(0).getSizeUnit() == 1);
    b.getPlayer().regressionTest();
}