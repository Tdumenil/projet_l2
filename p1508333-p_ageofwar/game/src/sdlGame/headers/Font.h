/**
 * @brief Le module Font gère les polices du jeu
 * Ce module va permettre d'afficher du texte à l'écran
 * @file Font.h
 * @date 2017/04/18
 */

#ifndef GAME_FONT_H
#define GAME_FONT_H

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
* @brief La classe Font contient un pointeur TTF_Font et un pointeur sur texture
*/

class Font {
    private:
        TTF_Font * font;
        SDL_Texture * texture;

    public:
        ~Font();
        /**
         * @brief Permet de charger une police
         * @param filename Chemin+Nom de la police
         * @param renderer
         * @param size La taille de la police
         */
        void loadFont(const char *filename, SDL_Renderer *renderer, const unsigned int size);

        /**
         * @brief Permet de récupérer la taille de la texture créer par loadFont
         * @param renderer
         * @param textColor La couleur de la police
         * @param text Le texte à afficher
         * @param w Largeur
         * @param h Hauteur
         */
        void loadGetSize(SDL_Renderer *renderer, SDL_Color textColor, const char *text, int &w, int &h);

        /**
         * @brief Permet d'afficher la police à l'écran selon un x et y
         * @param renderer
         * @param x
         * @param y
         * @param w largeur
         * @param h hauteur
         */
        void draw(SDL_Renderer * renderer, unsigned int x, unsigned int y, unsigned int w, unsigned int h);
};


#endif //GAME_FONT_H
