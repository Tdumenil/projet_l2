#include "../headers/sdlGame.h"
#include <iostream>
#include <unistd.h>

using namespace std;
const unsigned int sizeSprite = 43;

sdlGame::sdlGame() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


    int dimx;
    dimy = 500;
    dimx = game.getMap().getSizeTab();
    dimx = dimx * sizeSprite;

    // Creation de la fenetre
    window = SDL_CreateWindow("Clone Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    Unit1_L1.loadImage("data/unite1lvl1.png", renderer);
    Unit2_L1.loadImage("data/unite2lvl1.png", renderer);
    Unit3_L1.loadImage("data/unite3lvl1.png", renderer);
    background.loadImage("data/bg.jpg", renderer);
    basePlayer.loadImage("data/bg.png", renderer);
}

sdlGame::~sdlGame() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlGame::sdlShow() {
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);
    background.draw(renderer,0,0,game.getMap().getSizeTab()*sizeSprite-1,dimy-1);

    for(unsigned int i = 0 ; i < game.getMap().getSizeTab()  ; ++i){
        if(game.getMap().getX(i) == 'x'){
            basePlayer.draw(renderer,i*sizeSprite,dimy - sizeSprite-43,sizeSprite,sizeSprite);

        }
    }
    if(game.getPlayer().getSizeTabUnitsActive() > 0) {
        for (unsigned int i = 0; i < game.getPlayer().getSizeTabUnitsActive(); ++i) {
            if (game.getPlayer().getTabUnitActive(i).getId() == 1) {
                Unit1_L1.draw(renderer, game.getPlayer().getTabUnitActive(i).getX()*sizeSprite, dimy-sizeSprite-43, sizeSprite, sizeSprite);
            }
            if (game.getPlayer().getTabUnitActive(i).getId() == 2) {
                Unit2_L1.draw(renderer, game.getPlayer().getTabUnitActive(i).getX()*sizeSprite, dimy-sizeSprite-43, sizeSprite, sizeSprite);
            }
            if (game.getPlayer().getTabUnitActive(i).getId() == 3) {
                Unit3_L1.draw(renderer, game.getPlayer().getTabUnitActive(i).getX()*sizeSprite, dimy-sizeSprite-43, sizeSprite, sizeSprite);
            }
        }
    }
}

void sdlGame::sdlLoop() {
    bool ingame = true;
    SDL_Event events;
    Uint32 t = SDL_GetTicks(), nt;
    

    while(ingame){
        nt = SDL_GetTicks();
        if (nt-t>100) {
            t = nt;
            game.autoMoveUnits();
        }

         while (SDL_PollEvent(&events)) {
             if (events.type == SDL_QUIT) ingame = true;
             else if (events.type == SDL_KEYDOWN) {
                 switch (events.key.keysym.sym) {
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
                     case SDLK_SPACE:
                         ingame = false;
                         break;
                     default: break;
                 }
             }
         }
        sdlShow();
        SDL_RenderPresent(renderer);
    }
}