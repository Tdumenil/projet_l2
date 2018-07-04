//
// Created by skugga on 17/03/17.
//

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "../headers/winTxt.h"
#include "../../core/headers/Game.h"
using namespace std;
void txtAff(WinTXT & win, Game & game) {
    const Map & map = game.getMap();
    Player & player = game.getPlayer();
    Bot & bot = game.getBot();
    system("clear");
    win.clear();

    // Affichage des murs et des pastilles

    win.print(0,10,'x');
    win.print(map.getSizeTab()-1,10,'y');
    for(unsigned int i = 0 ; i < player.getSizeTabUnitsActive() ; ++i){
        switch(player.getTabUnitActive(i).getId()){
            case 1:
                win.print(player.getTabUnitActive(i).getX(), 10, 'a');
                break;
            case 2:
                win.print(player.getTabUnitActive(i).getX(), 10, 'z');
                break;
            case 3:
                win.print(player.getTabUnitActive(i).getX(), 10, 'e');
                break;
            case 4:
                win.print(player.getTabUnitActive(i).getX(), 10, 'r');
                break;
        }
        if(player.getTabUnitActive(i).getWeapon().getDamage() != 0){
            win.print(player.getTabUnitActive(i).getWeapon().getX(), 8, '.');
        }
    }
    for(unsigned int i = 0 ; i < bot.getPlayer().getSizeTabUnitsActive() ; ++i){
        win.print(bot.getPlayer().getTabUnitActive(i).getX(),10,'^');
    }
    if(player.getTurretA() == 1){
        win.print(0,9,'o');
        win.print(player.getLevel().getTurret().getBullet().getX(),9,'-');
    }
    if(game.getBot().getPlayer().getSizeTabUnitsActive() > 0 && game.getPlayer().getSizeTabUnitsActive() > 0){
        if(game.getBot().getPlayer().getTabUnitActive(0).getX() - 1 == game.getPlayer().getTabUnitActive(0).getX()) {
            win.print(game.getPlayer().getTabUnitActive(0).getX(), 7, '\'');
            win.print(game.getBot().getPlayer().getTabUnitActive(0).getX(), 7, '\'');
        }
    }

    win.draw();
    cout << endl << endl << endl << endl << endl;
    cout << "Vous êtes niveau : " << player.getLevel().getId() << endl;
    cout << "Gold : " << player.getMoney() << endl;
    Level ln;
    ln.levelTwo();
    cout << "Xp : " << player.getXp() << "/" << ln.getXp() << endl;
    cout << endl;
    cout << "a : " << player.getLevel().getUnitById(1).getPrice() << "$  Unité 1, z : " << player.getLevel().getUnitById(2).getPrice()  << "$ Unité 2, e : " << player.getLevel().getUnitById(3).getPrice() << "$ Unité 3" << endl;
    cout << "t : " << player.getLevel().getTurret().getPrice() << "$ Tourelle, b : Super-attaque, l : niveau suivant" << endl;
}

void txtBoucle (Game & game) {
    // Creation d'une nouvelle fenetre en mode texte
    // => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win(game.getMap().getSizeTab(),11);

    bool stay = true;
    bool winG = false;
    int c;

    do {
        usleep(200000);
        txtAff(win, game);
        if(game.getPlayer().getLife() <= 0){
            stay = false;
            winG = false;
        }
        if(game.getBot().getPlayer().getLife() <= 0){
            stay = false;
            winG = true;
        }
        if(game.getBot().getPlayer().getSizeTabUnitsActive() == 0){
            game.getPlayer().getLevel().getTurret().getBullet().setX(1);
        }

        game.autoMoveUnits();
        game.autoCombat();
        game.autoCombatRange();
        game.autoCombatBase();
        game.autoAttackTurret();
        game.launchSpecialWeapon();
        game.getBot().autoBuyUnit();

        c = win.getCh();
        switch (c) {
            case 'a':
                game.keyboardAction('a');
                break;
            case 'z':
                game.keyboardAction('z');
                break;
            case 'e':
                game.keyboardAction('e');
                break;
            case 'l':
                game.keyboardAction('l');
                break;
            case 't':
                game.keyboardAction('t');
                break;
            case 'b':
                game.keyboardAction('b');
                break;
            case 'q':
                stay = false;
                break;
        }

    } while (stay);
    if(winG){
        system("clear");
        cout << "Tu as gagnééééééééé" << endl;
    } else{
        system("clear");
        cout << "Tu as perduuuuuuuuuu" << endl;
    }
    cout << "Appuyer sur entree pour quitter ";
    cin.get();
}
