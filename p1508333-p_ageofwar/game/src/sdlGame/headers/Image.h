/**
 * @brief Le module Image gère les images du jeu
 * Ce module va permettre d'afficher des images à l'écran
 * @file Image.h
 * @date 2017/04/18
 */
#ifndef GAME_IMAGE_H
#define GAME_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
* @brief La classe Image contient un pointeur sur texture
*/
class Image {
    private:
        SDL_Texture * texture;

    public:
        ~Image();

        /**
         * @brief Permet de charger une image dans le renderer
         * @param filename Le nom du fichier
         * @param renderer
         */
        void loadImage(const char * filename, SDL_Renderer * renderer);

        /**
         * @brief Permet d'afficher l'image selon un x et y
         * @param renderer
         * @param x
         * @param y
         * @param w
         * @param h
         */
        void draw(SDL_Renderer * renderer, unsigned int x, unsigned int y, unsigned int w, unsigned int h);

        /**
         * @brief Permet d'afficher un sprite selon un x et y, et d'un posX
         * @param renderer
         * @param x
         * @param y
         * @param w largeur
         * @param h hauteur
         * @param posX position x dans le sprite en lui-même
         * @param posW largeur dans le sprite
         * @param posH hauteur dans le sprite
         */
        void drawSprite(SDL_Renderer * renderer, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int posX, unsigned int posW, unsigned int posH);
};


#endif //GAME_IMAGE_H