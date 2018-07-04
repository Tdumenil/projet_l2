//
// Created by skugga on 17/03/17.
//

#include "../headers/Game.h"
#include <iostream>
#include <cassert>
#include <unistd.h>

Game::Game() {
    player.getLevel().levelOne();
    player.setMoney(500);
    bot.getPlayer().getLevel().levelOne();
    bot.getPlayer().setMoney(500);
    player.setLife(2000);
    bot.getPlayer().setLife(2000);
    map = Map();
}

Player& Game::getPlayer() {
    return player;
}

Bot& Game::getBot() {
    return bot;
}

Map& Game::getMap() {
    return map;
}

void Game::keyboardAction(const char k) {
    switch(k) {
        case 'a':
            player.buyUnit(player.getLevel().getUnitById(1),0);
            break;
        case 'z':
            player.buyUnit(player.getLevel().getUnitById(2),0);
            break;
        case 'e':
            player.buyUnit(player.getLevel().getUnitById(3),0);
            break;
        case 'l':
            player.levelUp();
            break;
        case 't':
            player.buyTurret();
            break;
        case 'b':
            player.useSpecialWeapon();
            break;
    }
}

void Game::autoMoveUnits() {
    // Auto move des units du player
    if(player.getSizeTabUnitsActive() > 0) {
        if (player.getSizeTabUnitsActive() > 1) {
            for (unsigned int i = 0; i < player.getSizeTabUnitsActive(); ++i) {
                if ((player.getTabUnitActive(i + 1).getX() + 1) != player.getTabUnitActive(i).getX()) {
                    player.getTabUnitActive(i + 1).moveForward(map);
                }
            }
        }
        Unit & unitPlayer = player.getTabUnitActive(0);
        if (bot.getPlayer().getSizeTabUnitsActive() > 0) {
            Unit & unitBot = bot.getPlayer().getTabUnitActive(0);
            if (unitBot.getX() != unitPlayer.getX() + 1) {
                unitPlayer.moveForward(map);
            }
        } else {
            unitPlayer.moveForward(map);
        }
    }

    // Auto move des units du bot
    if(bot.getPlayer().getSizeTabUnitsActive() > 0) {
        if (bot.getPlayer().getSizeTabUnitsActive() > 1) {
            for (unsigned int i = 0; i < bot.getPlayer().getSizeTabUnitsActive(); ++i) {
                if ((bot.getPlayer().getTabUnitActive(i + 1).getX() - 1) !=
                    bot.getPlayer().getTabUnitActive(i).getX()) {
                    bot.getPlayer().getTabUnitActive(i + 1).moveBackward(map);
                }
            }
        }

        Unit & unitBot = bot.getPlayer().getTabUnitActive(0);
        if (player.getSizeTabUnitsActive() > 0) {
            Unit & unitPlayer = player.getTabUnitActive(0);
            if (unitBot.getX() - 1 != unitPlayer.getX()) {
                unitBot.moveBackward(map);
            }
        } else {
            unitBot.moveBackward(map);
        }
    }
}

void Game::autoCombat() {
    if(player.getSizeTabUnitsActive() > 0 && bot.getPlayer().getSizeTabUnitsActive() > 0) {
        Unit &uP = player.getTabUnitActive(0);
        Unit &uB = bot.getPlayer().getTabUnitActive(0);
        if (uP.getX() + 1 == uB.getX() && uB.getX() - 1 == uP.getX()) {
            if (uP.getLife() > 0 && uB.getLife() > 0) {
                uP.attackUnit(uB);
                uB.attackUnit(uP);
            }
            if (uP.getLife() <= 0) {
                bot.getPlayer().winMoneyAndXp(uP);
                player.unitIsDead();
            }
            if (uB.getLife() <= 0) {
                player.winMoneyAndXp(uB);
                bot.getPlayer().unitIsDead();
            }
        }
    }
}

void Game::autoCombatBase() {
    if(player.getSizeTabUnitsActive() > 0) {
        Unit &uP = player.getTabUnitActive(0);
        if (uP.getX() + 1 == map.getSizeTab() - 2) {
            if (bot.getPlayer().getLife() > 0) {
                bot.getPlayer().setLife(bot.getPlayer().getLife() - uP.getDamageUnit());
            }
        }
    }

    if(bot.getPlayer().getSizeTabUnitsActive() > 0){
        Unit & uB = bot.getPlayer().getTabUnitActive(0);
        if(uB.getX() - 1 == 1){
            if(player.getLife() > 0){
                player.setLife(player.getLife() - uB.getDamageUnit());
            }
        }
    }
}

void Game::autoCombatRange() {
    if(player.getSizeTabUnitsActive() > 0 && bot.getPlayer().getSizeTabUnitsActive() > 0) {
        Unit &unitPlayer1 = player.getTabUnitActive(1);
        Unit &unitPlayer2 = player.getTabUnitActive(0);
        Bullet &weaponUnit1 = unitPlayer1.getWeapon();
        Bullet &weaponUnit2 = unitPlayer2.getWeapon();
        Unit &unitBot = bot.getPlayer().getTabUnitActive(0);


        if (player.getSizeTabUnitsActive() > 1) {
            if (weaponUnit1.getDamage() != 0) {
                weaponUnit1.moveForward();
                if (weaponUnit1.getX() >= unitBot.getX()) {
                    unitPlayer1.attackUnit(unitBot);
                    weaponUnit1.setX(unitPlayer1.getX());
                }
            }
            if (weaponUnit2.getDamage() != 0 &&
                unitPlayer2.getX() + 1 != unitBot.getX()) {
                weaponUnit2.moveForward();
                if (weaponUnit2.getX() >= unitBot.getX()) {
                    unitPlayer2.attackUnit(unitBot);
                    weaponUnit2.setX(unitPlayer2.getX());
                }
            }
        } else if (player.getSizeTabUnitsActive() > 0) {
            if (weaponUnit2.getDamage() != 0 &&
                unitPlayer2.getX() + 1 != unitBot.getX()) {
                weaponUnit2.moveForward();
                if (weaponUnit2.getX() >= unitBot.getX()) {
                    unitPlayer2.attackUnit(unitBot);
                    weaponUnit2.setX(unitPlayer2.getX());
                }
            }

            if (unitBot.getLife() <= 0) {
                player.winMoneyAndXp(unitBot);
                bot.getPlayer().unitIsDead();
            }
        }
    } else if(player.getSizeTabUnitsActive() > 0 && bot.getPlayer().getSizeTabUnitsActive() == 0){
        Unit &unitPlayer1 = player.getTabUnitActive(1);
        Unit &unitPlayer2 = player.getTabUnitActive(0);
        Bullet &weaponUnit1 = unitPlayer1.getWeapon();
        Bullet &weaponUnit2 = unitPlayer2.getWeapon();
        weaponUnit1.setX(unitPlayer1.getX());
        weaponUnit2.setX(unitPlayer2.getX());
    }
}

void Game::autoAttackTurret() {
    if(player.getTurretA()) {
        Turret &turretPlayer = player.getLevel().getTurret();
        if (bot.getPlayer().getSizeTabUnitsActive() > 0) {
            Unit &unitBot = bot.getPlayer().getTabUnitActive(0);
            if (unitBot.getLife() > 0 && unitBot.getX() <= 20) {
                turretPlayer.getBullet().moveForward();
                if (turretPlayer.getBullet().getX() >= unitBot.getX()) {
                    turretPlayer.attack(unitBot);
                    turretPlayer.getBullet().setX(1);
                }
                if (unitBot.getLife() <= 0) {
                    player.winMoneyAndXp(unitBot);
                    bot.getPlayer().unitIsDead();
                }
            } else{
                turretPlayer.getBullet().setX(1);
            }
        } else {
            turretPlayer.getBullet().setX(1);
        }
    }
}

void Game::launchSpecialWeapon() {
    if(player.getLevel().getWeaponS().getActive()) {
        while (bot.getPlayer().getSizeTabUnitsActive() > 0) {
            for (unsigned int i = 0; i < bot.getPlayer().getSizeTabUnitsActive(); ++i) {
                player.getLevel().getWeaponS().attack(bot.getPlayer().getTabUnitActive(i));
            }
            if (bot.getPlayer().getTabUnitActive(0).getLife() <= 0) {
                player.winMoneyAndXp(bot.getPlayer().getTabUnitActive(0));
                bot.getPlayer().unitIsDead();
            }
        }
        player.getLevel().getWeaponS().setActive(false);
    }
}

void Game::reset() {
    player.getLevel().levelOne();
    player.setMoney(500);
    player.setTurretA(0);
    bot.getPlayer().getLevel().levelOne();
    bot.getPlayer().setMoney(500);
    player.setLife(150);
    bot.getPlayer().setLife(150);
    player.setSizeTab(0);
    player.setTab(NULL);
    bot.getPlayer().setSizeTab(0);
    bot.getPlayer().setTab(NULL);
    player.setXp(0);
    bot.getPlayer().setXp(0);
    player.setLife(2000);
    bot.getPlayer().setLife(2000);
}

void Game::regressionTest() {
    Game g1;
    g1.getPlayer().setMoney(1000);
    g1.keyboardAction('a');
    assert(g1.getPlayer().getTabUnitActive(0).getId() == 1);
    g1.keyboardAction('z');
    g1.keyboardAction('b');
    std::cout << "Test game réussi " << std::endl;
}
