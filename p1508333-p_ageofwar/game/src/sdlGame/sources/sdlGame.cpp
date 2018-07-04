#include "../headers/sdlGame.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
using namespace std;
const int sizeSprite = 35;
const int sizePlan = 151;


sdlGame::sdlGame() {
    playerWin = false;
    gameOver = false;
    gamePause = false;
    leaveGame = false;
    OnSoundBot = 0;
    OnSoundPlayer = 0;
    OnSoundPlayer2 = 0;

    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( TTF_Init() == -1 ){
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        exit(1);
    }

    dimy = 689;
    dimx = game.getMap().getSizeTab();
    dimx = dimx * sizeSprite;

    // Creation de la fenetre
    window = SDL_CreateWindow("Clone Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (renderer == NULL){
        cout << "Erreur";
    }
    Menu_font.loadFont("data/fonts/Starjedi.ttf", renderer,35);
    Menu_background.loadImage("data/backgrounds/menu.jpg", renderer);
    Menu_sabre.loadImage("data/backgrounds/sabre2.png", renderer);
    credits.loadImage("data/backgrounds/credits.jpg", renderer);


    if(SDL_Init(SDL_INIT_AUDIO)==-1) {
        printf("SDL_Init: %s\n", SDL_GetError());
        exit(1);
    }
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(2);
    }
    Mix_AllocateChannels(32); //Allouer 32 canaux

    soundMenu.loadSound("data/sounds/mainMenu.ogg");
    soundOnMenu.loadSound("data/sounds/OnMenu.ogg");
}

sdlGame::~sdlGame() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    Mix_CloseAudio();
    SDL_Quit();
}

void sdlGame::sdlInitGame() {
    Unit1_L1_Sprite.loadImage("data/units/player/sprite_unit1_l1.png", renderer);
    Unit1_L1_Sprite_Attack.loadImage("data/units/player/sprite_unit1_l1_attack.png", renderer);
    Unit1_L1_Image.loadImage("data/units/player/unite1lvl1.png", renderer);
    Unit2_L1_Sprite.loadImage("data/units/player/unite2lvl1.png", renderer);
    Unit2_L1_Image.loadImage("data/units/player/unite2lvl1.png", renderer);
    Unit3_L1_Sprite.loadImage("data/units/player/unite3lvl1.png", renderer);
    Unit3_L1_Image.loadImage("data/units/player/unite3lvl1.png", renderer);

    Unit1_L1_Bot_Sprite.loadImage("data/units/bot/sprite_unit1_l1_bot.png", renderer);
    Unit1_L1_Bot_Sprite_Attack.loadImage("data/units/bot/sprite_unit1_l1_bot_attack.png", renderer);
    Unit2_L1_Bot_Sprite.loadImage("data/units/bot/unite2lvl1bot.png", renderer);
    Unit3_L1_Bot_Sprite.loadImage("data/units/bot/unite3lvl1bot.png", renderer);
    background.loadImage("data/backgrounds/bgmain.png", renderer);
    basePlayer.loadImage("data/units/player/base.png", renderer);
    turretPlayer.loadImage("data/units/player/test.png", renderer);
    turretBullet.loadImage("data/units/player/bullet.png", renderer);

    baseBot.loadImage("data/units/bot/baseennemie.png", renderer);
    vaisseau.loadImage("data/units/bot/Vaisseau1.png", renderer);
    vaisseau2.loadImage("data/units/bot/Vaisseau2.png", renderer);
    vaisseau3.loadImage("data/units/bot//Vaisseau3.png", renderer);
    vaisseau4.loadImage("data/units/bot/transporteursansterrain.png", renderer);
    gameFont.loadFont("data/fonts/Starjedi.ttf", renderer,20);
    soundGame.loadSound("data/sounds/inGame.ogg");
    soundBuyUnit.loadSound("data/sounds/buyUnit.ogg");
    soundUnit1.loadSound("data/sounds/fightu1.ogg");
    soundUnit2.loadSound("data/sounds/fightu2.ogg");
    soundUnit3.loadSound("data/sounds/fightu3.ogg");
    coeur.loadImage("data/backgrounds/coeur.png", renderer);
    flame.loadImage("data/backgrounds/flamme.png", renderer);
}

void sdlGame::sdlUnit() {
    Player & player = game.getPlayer();
    Uint32 ticks = SDL_GetTicks();
    Uint32 sprite = (ticks / 120) % 5;
    for (unsigned int i = 1; i < player.getSizeTabUnitsActive(); ++i) {
        if (player.getTabUnitActive(i).getId() == 1) {
            Unit1_L1_Sprite.drawSprite(renderer, player.getTabUnitActive(i).getX()*sizeSprite, dimy-sizeSprite-sizePlan, sizeSprite, sizeSprite,45*sprite, 45, 61);
        }
        if (player.getTabUnitActive(i).getId() == 2) {
            Unit2_L1_Sprite.draw(renderer, player.getTabUnitActive(i).getX()*sizeSprite, dimy-sizeSprite-sizePlan, sizeSprite, sizeSprite);
        }
        if (player.getTabUnitActive(i).getId() == 3) {
            Unit3_L1_Sprite.draw(renderer, player.getTabUnitActive(i).getX()*sizeSprite, dimy-sizeSprite-sizePlan, sizeSprite, sizeSprite);
        }
    }
    if((game.getBot().getPlayer().getSizeTabUnitsActive() > 0 && player.getTabUnitActive(0).getX()+1 != game.getBot().getPlayer().getTabUnitActive(0).getX()) || game.getBot().getPlayer().getSizeTabUnitsActive() == 0) {
        if (player.getTabUnitActive(0).getId() == 1) {
            Unit1_L1_Sprite.drawSprite(renderer, player.getTabUnitActive(0).getX() * sizeSprite,
                                       dimy - sizeSprite - sizePlan, sizeSprite, sizeSprite, 45 * sprite, 45, 61);
        }
        if (player.getTabUnitActive(0).getId() == 2) {
            Unit2_L1_Sprite.draw(renderer, player.getTabUnitActive(0).getX() * sizeSprite, dimy - sizeSprite - sizePlan,
                                 sizeSprite, sizeSprite);
        }
        if (player.getTabUnitActive(0).getId() == 3) {
            Unit3_L1_Sprite.draw(renderer, player.getTabUnitActive(0).getX() * sizeSprite, dimy - sizeSprite - sizePlan,
                                 sizeSprite, sizeSprite);
        }
    }

    if(player.getTabUnitActive(0).getId() == 3) {
        if(game.getBot().getPlayer().getSizeTabUnitsActive() > 0) {
            turretBullet.draw(renderer, (player.getTabUnitActive(0).getWeapon().getX() + 1) * sizeSprite,
                              dimy - sizeSprite * 1 - sizePlan, sizeSprite, sizeSprite);
            if(!OnSoundPlayer) {
                soundUnit3.playSound(0, 2);
                OnSoundPlayer = 1;
            }
        }
    }
    if(player.getSizeTabUnitsActive() > 1){
        if(player.getTabUnitActive(1).getId() == 3) {
            if(game.getBot().getPlayer().getSizeTabUnitsActive() > 0) {
                turretBullet.draw(renderer, (player.getTabUnitActive(1).getWeapon().getX()+1) * sizeSprite, dimy - sizeSprite * 1 - sizePlan, sizeSprite, sizeSprite);
                if(!OnSoundPlayer2) {
                    soundUnit3.playSound(0, 2);
                    OnSoundPlayer2 = 1;
                }
            }
        }
    }
}

void sdlGame::sdlUnitBot() {
    Player & bot = game.getBot().getPlayer();
    Uint32 ticks = SDL_GetTicks();
    Uint32 sprite = (ticks / 120) % 5;
    for(unsigned int i = 1 ; i < bot.getSizeTabUnitsActive() ; ++i){
        if(bot.getTabUnitActive(i).getId() == 1){
            Unit1_L1_Bot_Sprite.drawSprite(renderer, bot.getTabUnitActive(i).getX()*sizeSprite,dimy-sizeSprite-sizePlan, sizeSprite,sizeSprite,45*sprite,45,61);
        }
        if(bot.getTabUnitActive(i).getId() == 2){
            Unit2_L1_Bot_Sprite.draw(renderer, bot.getTabUnitActive(i).getX()*sizeSprite,dimy-sizeSprite-sizePlan, sizeSprite,sizeSprite);
        }
    }
    if((game.getPlayer().getSizeTabUnitsActive() > 0 && game.getPlayer().getTabUnitActive(0).getX()+1 != bot.getTabUnitActive(0).getX()) || game.getPlayer().getSizeTabUnitsActive() == 0) {
        if (bot.getTabUnitActive(0).getId() == 1) {
            Unit1_L1_Bot_Sprite.drawSprite(renderer, bot.getTabUnitActive(0).getX() * sizeSprite,
                                           dimy - sizeSprite - sizePlan, sizeSprite, sizeSprite, 45 * sprite, 45, 61);
        }
        if (bot.getTabUnitActive(0).getId() == 2) {
            Unit2_L1_Bot_Sprite.draw(renderer, bot.getTabUnitActive(0).getX() * sizeSprite,
                                     dimy - sizeSprite - sizePlan, sizeSprite, sizeSprite);
        }
    }
}

void sdlGame::sdlHud() {
    Unit1_L1_Image.draw(renderer, dimx/4+20,20,sizeSprite*1.2,sizeSprite*1.2);
    Unit2_L1_Image.draw(renderer, dimx/4+95,20,sizeSprite*1.2,sizeSprite*1.2);
    Unit3_L1_Image.draw(renderer, dimx/4+180,20,sizeSprite*1.2,sizeSprite*1.2);
    turretBullet.draw(renderer, 730,22,sizeSprite*1.4,sizeSprite*1.4);
    int ij = 92;
    SDL_Color textColor = { 255, 255, 255 };
    int w, h;
    string textS = to_string(game.getPlayer().getMoney());
    const char * text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,90,27, w, h);

    textS = to_string(game.getPlayer().getLevel().getUnitById(1).getPrice());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,dimx/4+30,ij, w, h);

    textS = to_string(game.getPlayer().getLevel().getUnitById(2).getPrice());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,dimx/4+110,ij, w, h);

    textS = to_string(game.getPlayer().getLevel().getUnitById(3).getPrice());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,dimx/4+190,ij, w, h);

    textS = to_string(game.getPlayer().getLevel().getTurret().getPrice());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,749,ij, w, h);

    textS = to_string(game.getPlayer().getLevel().getWeaponS().getPrice());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,965,ij, w, h);

    unsigned int xp;
    unsigned int xpPlayer;
    if(game.getPlayer().getLevel().getId() == 1){
        Level l2;
        l2.levelTwo();
        xp = l2.getXp();
        xpPlayer = game.getPlayer().getXp();
    } else if(game.getPlayer().getLevel().getId() == 2){
        Level l3;
        l3.levelThree();
        xp = l3.getXp();
        xpPlayer = game.getPlayer().getXp();
    } else if(game.getPlayer().getLevel().getId() == 3){
        Level l3;
        l3.levelThree();
        xpPlayer = l3.getXp();
        xp = l3.getXp();
    }
    textS = to_string(xpPlayer) + "/" + to_string(xp);
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,dimx-w-15,ij, w, h);

    textS = string("t") + to_string(game.getPlayer().getLevel().getId());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,dimx-65,30, w, h);

    coeur.draw(renderer, dimx-sizeSprite, dimy-sizeSprite*3, sizeSprite,sizeSprite);
    coeur.draw(renderer, 0, dimy-sizeSprite*3, sizeSprite,sizeSprite);

    textS = to_string(game.getBot().getPlayer().getLife());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,dimx-w*2+10,dimy-sizeSprite*3, w, h);

    textS = to_string(game.getPlayer().getLife());
    text = textS.c_str();
    gameFont.loadGetSize(renderer, textColor, text, w, h);
    gameFont.draw(renderer,sizeSprite+10,dimy-sizeSprite*3, w, h);

    flame.draw(renderer, dimx/2+335, 15, 40,60);

}

void sdlGame::sdlShow() {
    Player & player = game.getPlayer();
    Player & bot = game.getBot().getPlayer();
    Map & map = game.getMap();

    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);
    background.draw(renderer,0,0,map.getSizeTab()*sizeSprite,dimy);

    if(player.getLevel().getId() == 2){
        Unit1_L1_Sprite.loadImage("data/units/player/sprite_unit1_l2.png", renderer);
        Unit1_L1_Sprite_Attack.loadImage("data/units/player/sprite_unit1_l2_attack.png", renderer);
        Unit1_L1_Image.loadImage("data/units/player/unite1lvl1.png", renderer);
    } else if(player.getLevel().getId() == 3){
        Unit1_L1_Sprite.loadImage("data/units/player/sprite_unit1_l3.png", renderer);
        Unit1_L1_Sprite_Attack.loadImage("data/units/player/sprite_unit1_l3_attack.png", renderer);
        Unit1_L1_Image.loadImage("data/units/player/unite1lvl1.png", renderer);
    }

    vaisseau.draw(renderer, 0, 0, dimx, dimy);
    vaisseau2.draw(renderer, 0, 0, dimx, dimy);
    vaisseau3.draw(renderer, 0, 0, dimx, dimy);
    vaisseau4.draw(renderer, 0, 0, dimx, dimy);
    for(unsigned int i = 0 ; i < map.getSizeTab()  ; ++i){
        if(map.getX(i) == 'x'){
            basePlayer.draw(renderer,0, 0,dimx,dimy);

        }
        if(map.getX(i) == 'y'){
            baseBot.draw(renderer,0, 0,dimx,dimy);
        }
    }

    if(game.getPlayer().getSizeTabUnitsActive() > 0) {
        sdlUnit();

        if(bot.getSizeTabUnitsActive() > 0) {
            if (player.getTabUnitActive(0).getX() + 1 == bot.getTabUnitActive(0).getX()) {
                Uint32 ticks = SDL_GetTicks();
                Uint32 sprite = (ticks / 120) % 5;
                if(player.getTabUnitActive(0).getId() == 1){
                    Unit1_L1_Sprite_Attack.drawSprite(renderer, player.getTabUnitActive(0).getX() * sizeSprite,dimy - sizeSprite - sizePlan, sizeSprite, sizeSprite, 45 * sprite, 45,61);
                    if(!OnSoundPlayer) {
                        soundUnit1.playSound(0, 2);
                        OnSoundPlayer = 1;
                    }
                }
                if(player.getTabUnitActive(0).getId() == 2){
                    Unit2_L1_Sprite.draw(renderer, player.getTabUnitActive(0).getX()*sizeSprite,dimy-sizeSprite-sizePlan, sizeSprite,sizeSprite);

                    if(!OnSoundPlayer) {
                        soundUnit2.playSound(0, 2);
                        OnSoundPlayer = 1;
                    }
                }
                if(player.getTabUnitActive(0).getId() == 3){
                    Unit3_L1_Sprite.draw(renderer, player.getTabUnitActive(0).getX()*sizeSprite,dimy-sizeSprite-sizePlan, sizeSprite,sizeSprite);

                }
            } else {
                sdlUnit();
                if(player.getTabUnitActive(0).getId() != 3){
                    OnSoundPlayer = 0;
                } else{

                }
            }
        } else{
            sdlUnit();
            OnSoundPlayer = 0;
        }
    }

    if(bot.getSizeTabUnitsActive() > 0){
        sdlUnitBot();
        if(player.getSizeTabUnitsActive() > 0) {
            if (player.getTabUnitActive(0).getX() + 1 == bot.getTabUnitActive(0).getX()) {
                Uint32 ticks = SDL_GetTicks();
                Uint32 sprite = (ticks / 120) % 5;
                if(bot.getTabUnitActive(0).getId() == 1) {
                    Unit1_L1_Bot_Sprite_Attack.drawSprite(renderer, bot.getTabUnitActive(0).getX() * sizeSprite, dimy - sizeSprite - sizePlan, sizeSprite, sizeSprite, 45 * sprite, 45, 61);
                    if(!OnSoundBot) {
                        soundUnit1.playSound(0, 2);
                        OnSoundBot = 1;
                    }
                } else if(bot.getTabUnitActive(0).getId() == 2){
                    Unit2_L1_Bot_Sprite.draw(renderer, bot.getTabUnitActive(0).getX()*sizeSprite,dimy-sizeSprite-sizePlan, sizeSprite,sizeSprite);

                    if(!OnSoundBot){
                        soundUnit2.playSound(0, 2);
                        OnSoundBot = 1;
                    }

                }
            } else {
                sdlUnitBot();
                OnSoundBot = 0;
            }
        } else{
            sdlUnitBot();
            OnSoundBot = 0;
        }
    }

    if(player.getTurretA()){
        turretPlayer.draw(renderer,0,dimy-sizeSprite*1-sizePlan,sizeSprite,sizeSprite);
        turretBullet.draw(renderer,player.getLevel().getTurret().getBullet().getX()*sizeSprite,dimy-sizeSprite*1-sizePlan,sizeSprite,sizeSprite);
        if(bot.getSizeTabUnitsActive() > 0 && bot.getTabUnitActive(0).getX() <= 20) {
            if (!OnSoundPlayer3) {
                soundUnit3.playSound(0, 2);
                OnSoundPlayer3 = 1;
            }
        }
    }

    sdlHud();


}

void sdlGame::sdlLoop() {
    bool ingame = true;
    Bot & bot = game.getBot();
    Player & player = game.getPlayer();
    SDL_Event e;
    Uint32 t = SDL_GetTicks(), nt;
    Uint32 t2 = SDL_GetTicks(), nt2;


    soundMenu.stopSound();
    soundGame.playSound(-1);

    while(ingame){
        sdlFps(150);
        if(player.getLife() > 0 && bot.getPlayer().getLife() > 0) {
            sdlShow();
        } else{
            if(player.getLife() <= 0){
                playerWin = false;
            }
            if(bot.getPlayer().getLife() <= 0){
                playerWin = true;
            }
            gameOver = true;
            ingame = false;
        }
        if(leaveGame){
            ingame = false;
        }
        nt = SDL_GetTicks();

        if (nt-t>400) {
            t = nt;
            game.autoMoveUnits();
            game.autoCombat();
            game.autoCombatBase();
            game.launchSpecialWeapon();
            game.getBot().autoBuyUnit();
        }




        nt2 = SDL_GetTicks();
        if(nt2-t2>100){
            t2 = nt2;
            game.autoAttackTurret();
            if(player.getSizeTabUnitsActive() > 0 && bot.getPlayer().getSizeTabUnitsActive() > 0) {
                if(player.getTabUnitActive(0).getId() == 3) {
                    if (player.getTabUnitActive(0).getWeapon().getX() - 1 == player.getTabUnitActive(0).getX()) {
                        OnSoundPlayer = 0;
                    }
                }
            }
            if(player.getSizeTabUnitsActive() > 1 && bot.getPlayer().getSizeTabUnitsActive() > 0) {
                if(player.getTabUnitActive(1).getId() == 3) {
                    if (player.getTabUnitActive(1).getWeapon().getX() - 1 == player.getTabUnitActive(1).getX()) {
                        OnSoundPlayer2 = 0;
                    }
                }
            }
            if(player.getTurretA()){
                if(player.getLevel().getTurret().getBullet().getX() == 1){
                    OnSoundPlayer3 = 0;
                }
            }
            game.autoCombatRange();
        }
        int mX;
        int mY;

         while (SDL_PollEvent(&e)) {
             SDL_GetMouseState(&mX, &mY);
             if (e.type == SDL_QUIT) ingame = true;
             else if (e.type == SDL_KEYDOWN) {
                 switch (e.key.keysym.sym) {
                     case SDLK_a:
                         game.keyboardAction('a');
                         break;
                     case SDLK_z:
                         game.keyboardAction('z');
                         break;
                     case SDLK_e:
                         game.keyboardAction('e');
                         break;
                     case SDLK_t:
                         game.keyboardAction('t');
                         break;
                     case SDLK_ESCAPE:
                         gamePause = true;
                         sdlMenu();
                         break;
                     case SDLK_SPACE:
                        ingame = false;
                         break;
                     default: break;
                 }
             }
             else if(e.type == SDL_MOUSEBUTTONDOWN) {
                 if (e.button.button == SDL_BUTTON_LEFT) {
                     if (mX >= 302 && mX <= 385 && mY >= 0 && mY <= 83) {
                         game.keyboardAction('a');
                         soundBuyUnit.playSound(0);
                     }

                     if(mX >= 385 && mX <= 468 && mY >= 0 && mY <= 83){
                         game.keyboardAction('z');
                         soundBuyUnit.playSound(0);
                     }

                     if(mX >= 468 && mX <= 551 && mY >= 0 && mY <= 83){
                         game.keyboardAction('e');
                         soundBuyUnit.playSound(0);
                     }

                     if(mX >= dimx-83 && mX <= dimx && mY >= 0 && mY <= 83){
                         game.keyboardAction('l');
                     }

                     if(mX >= 717 && mX <= 800 && mY >= 0 && mY <= 83){
                         if(!player.getTurretA()) {
                             game.keyboardAction('t');
                             soundBuyUnit.playSound(0);
                         }
                     }

                     if(mX >= 930 && mX <= 1013 && mY >= 0 && mY <= 83){
                         game.keyboardAction('b');
                         soundBuyUnit.playSound(0);
                     }
                 }
             }
         }
         SDL_RenderPresent(renderer);
    }
}

void sdlGame::sdlFps(unsigned int fps) {
    Uint32 start_time = SDL_GetTicks();
    if((1000/fps)>(SDL_GetTicks()-start_time))    {
        SDL_Delay((1000/fps)-(SDL_GetTicks()-start_time));
    }
}

void sdlGame::sdlMenu() {
    bool inmenu = true;
    int mX, mY;
    SDL_Event e;
    bool hoverNews = false, hoverCredit = false, hoverLeave = false;
    int wNew, hNew, wC, hC, wQ, hQ;
    int dimNewX, dimNewY, dimCX, dimCY, dimQX, dimQY;

    soundGame.stopSound();
    soundMenu.playSound(-1);
    bool m = 0, n = 0, p = 0, b = 1;
    while(inmenu){

        if(leaveGame){
            inmenu = false;
        }
        sdlFps(150);
        while (SDL_PollEvent(&e)) {
            if(b) {
                Menu_background.draw(renderer, 0, 0, dimx, dimy);

                // Draw le sabre du menu
                if(hoverNews){
                    Menu_sabre.draw(renderer, dimx / 2 - 280 / 2, dimy / 2 - 50, 280, 22);
                    if(!m) {
                        soundOnMenu.playSound(0);
                        m = 1;
                    }
                } else{
                    m = 0;
                }
                if(hoverCredit){
                    Menu_sabre.draw(renderer, dimx / 2 - 280 / 2, dimy / 2 + 50,280, 22);
                    if(!n) {
                        soundOnMenu.playSound(0);
                        n = 1;
                    }
                } else{
                    n = 0;
                }
                if(hoverLeave){
                    Menu_sabre.draw(renderer, dimx / 2 - 280 / 2, dimy / 2 + 150,280, 22);
                    if(!p) {
                        soundOnMenu.playSound(0);
                        p = 1;
                    }
                } else{
                    p = 0;
                }

                // Draw le texte du menu au bon endroit
                SDL_Color textColor = { 255, 232, 51 };
                if(!gamePause) {
                    if (!gameOver) {
                        Menu_font.loadGetSize(renderer, textColor, "Nouvelle partie", wNew, hNew);
                        dimNewX = dimx / 2 - wNew / 2;
                        dimNewY = dimy / 2 - 100;
                        Menu_font.draw(renderer, dimNewX, dimNewY, wNew, hNew);
                        Menu_font.loadGetSize(renderer, textColor, "Credits", wC, hC);
                        dimCX = dimx / 2 - wC / 2;
                        dimCY = dimy / 2;
                        Menu_font.draw(renderer, dimx / 2 - wC / 2, dimy / 2, wC, hC);
                        Menu_font.loadGetSize(renderer, textColor, "quitter", wQ, hQ);
                        dimQX = dimx / 2 - wQ / 2;
                        dimQY = dimy / 2 + 100;
                        Menu_font.draw(renderer, dimx / 2 - wQ / 2, dimy / 2 + 100, wQ, hQ);
                    } else {
                        if (playerWin) {
                            Menu_font.loadGetSize(renderer, textColor, "bravo vous avez gagne ! voulez-vous recommencer ?",
                                                  wNew, hNew);
                        } else {
                            Menu_font.loadGetSize(renderer, textColor,
                                                  "dommage vous avez perdu ! voulez-vous recommencer ?", wNew, hNew);
                        }
                        dimNewX = dimx / 2 - wNew / 2;
                        dimNewY = dimy / 2 - 100;
                        Menu_font.draw(renderer, dimNewX, dimNewY, wNew, hNew);
                        Menu_font.loadGetSize(renderer, textColor, "oui", wC, hC);
                        dimCX = dimx / 2 - wC / 2;
                        dimCY = dimy / 2;
                        Menu_font.draw(renderer, dimx / 2 - wC / 2, dimy / 2, wC, hC);
                        Menu_font.loadGetSize(renderer, textColor, "quitter le jeu", wQ, hQ);
                        dimQX = dimx / 2 - wQ / 2;
                        dimQY = dimy / 2 + 100;
                        Menu_font.draw(renderer, dimx / 2 - wQ / 2, dimy / 2 + 100, wQ, hQ);
                    }
                } else{
                    Menu_font.loadGetSize(renderer, textColor, "reprendre la partie", wNew, hNew);
                    dimNewX = dimx / 2 - wNew / 2;
                    dimNewY = dimy / 2 - 100;
                    Menu_font.draw(renderer, dimNewX, dimNewY, wNew, hNew);
                    Menu_font.loadGetSize(renderer, textColor, "recommencer une partie", wC, hC);
                    dimCX = dimx / 2 - wC / 2;
                    dimCY = dimy / 2;
                    Menu_font.draw(renderer, dimx / 2 - wC / 2, dimy / 2, wC, hC);
                    Menu_font.loadGetSize(renderer, textColor, "quitter le jeu", wQ, hQ);
                    dimQX = dimx / 2 - wQ / 2;
                    dimQY = dimy / 2 + 100;
                    Menu_font.draw(renderer, dimx / 2 - wQ / 2, dimy / 2 + 100, wQ, hQ);
                }
            } else{
                SDL_RenderClear(renderer);
                credits.draw(renderer,0,0,dimx,dimy);
            }
            SDL_GetMouseState(&mX, &mY);
            if (e.type == SDL_QUIT) inmenu = true;
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        if(!b){
                            b = 1;
                        } else {
                            inmenu = false;
                        }
                        break;
                    default: break;
                }
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN) {
                if(e.button.button == SDL_BUTTON_LEFT) {
                    if (e.button.x >= dimNewX && e.button.x <= dimNewX + wNew &&
                        e.button.y >= dimNewY && e.button.y <= dimNewY + hNew) {
                        if(!gameOver) {
                            gamePause = false;
                            sdlInitGame();
                            sdlLoop();
                        }
                    }

                    if (e.button.x >= dimCX && e.button.x <= dimCX + wC &&
                        e.button.y >= dimCY && e.button.y <= dimCY + hC) {
                        if(gameOver || gamePause){
                            gameOver = false;
                            gamePause = false;
                            playerWin = false;
                            game.reset();
                            sdlInitGame();
                            sdlLoop();
                        } else {
                            b = 0;
                        }
                    }

                    if (e.button.x >= dimQX && e.button.x <= dimQX + wQ &&
                        e.button.y >= dimQY && e.button.y <= dimQY + hQ) {
                        gamePause = false;
                        gameOver = false;
                        playerWin = false;
                        leaveGame = true;
                        inmenu = false;
                    }
                }
            }
            else if(e.type == SDL_MOUSEMOTION) {
                if (e.button.x >= dimNewX && e.button.x <= dimNewX + wNew &&
                    e.button.y >= dimNewY && e.button.y <= dimNewY + hNew) {
                    hoverNews = true;
                } else{
                    hoverNews = false;
                }
                if(e.button.x >= dimCX && e.button.x <= dimCX + wC &&
                   e.button.y >= dimCY && e.button.y <= dimCY + hC){
                    hoverCredit = true;
                } else{
                    hoverCredit = false;
                }
                if(e.button.x >= dimQX && e.button.x <= dimQX + wQ &&
                   e.button.y >= dimQY && e.button.y <= dimQY + hQ){
                    hoverLeave = true;
                } else{
                    hoverLeave = false;
                }
            }
        }
        SDL_RenderPresent(renderer);
    }
}