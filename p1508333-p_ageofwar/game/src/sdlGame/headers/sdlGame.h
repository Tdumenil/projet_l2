/**
 * @brief Le module sdlGame gère le jeu SDL
 * Ce module va permettre de jouer au jeu avec tous les composants nécessaires
 * @file sdlGame.h
 * @date 2017/04/18
 */

#ifndef GAME_SDLGAME_H
#define GAME_SDLGAME_H

#include "../../core/headers/Game.h"
#include "Image.h"
#include "Font.h"
#include <string>
#include "Sound.h"

/**
* @brief La classe sdlGame contient toutes les images/sons/sprites/polices
*/
class sdlGame {
    private:
        Game game;
        SDL_Window * window;
        SDL_Renderer * renderer;
        int dimx;
        int dimy;
        bool playerWin;
        bool gameOver;
        bool gamePause;
        bool leaveGame;
        Image background;
        Image coeur;
        Image flame;
        Image credits;
        // Base player
        Image basePlayer;
        Image baseBot;
        Image turretPlayer;
        Image turretBullet;

        // Player
        // Level 1
        Image Unit1_L1_Sprite;
        Image Unit1_L1_Image;
        Image Unit1_L1_Sprite_Attack;
        Image Unit2_L1_Sprite;
        Image Unit2_L1_Image;
        Image Unit3_L1_Sprite;
        Image Unit3_L1_Image;

        // Bot
        // Level 1
        Image Unit1_L1_Bot_Sprite;
        Image Unit1_L1_Bot_Sprite_Attack;
        Image Unit2_L1_Bot_Sprite;
        Image Unit2_L1_Bot_Sprite_Attack;
        Image Unit3_L1_Bot_Sprite;
        Image Unit3_L1_Bot_Attack;

        Font gameFont;

        // Base ennemi
        Image vaisseau;
        Image vaisseau2;
        Image vaisseau3;
        Image vaisseau4;

        // Le menu
        Image Menu_sabre;
        Font Menu_font;
        Image Menu_background;

        // Son
        Sound soundGame;
        Sound soundMenu;
        Sound soundBuyUnit;
        Sound soundOnMenu;
        Sound soundUnit1;
        Sound soundUnit2;
        Sound soundUnit3;
        int OnSoundBot;
        int OnSoundPlayer;
        int OnSoundPlayer2;
        int OnSoundPlayer3;

    public:
        sdlGame();
        ~sdlGame();

        /**
         * @brief Initialise les polices/images/sons dans une partie
         */
        void sdlInitGame();

        /**
         * @brief Affichage pour la boucle principale du jeu
         */
        void sdlShow();

        /**
         * @brief Boucle principale dans une partie
         */
        void sdlLoop();

        /**
         * @brief Centralise tous les menus (principale/pause/victoiredéfaire)
         */
        void sdlMenu();

        /**
         * @brief Initialise les fps
         * @param fps Image par secondes
         */
        void sdlFps(unsigned int fps);

        /**
         * @brief Gère l'affichage des sprites des unités du joueur
         */
        void sdlUnit();

        /**
         * @brief Gère l'affichage des sprites des unités du bot
         */
        void sdlUnitBot();

        /**
         * @brief Gère l'affiche de l'interface en partie (money/xp etc)
         */
        void sdlHud();
};


#endif //GAME_SDLGAME_H
