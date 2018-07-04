/**
 * @brief Le module Sound gère les sons dans le jeu
 * Ce module va permettre d'écouter du son
 * @file Sound.h
 * @date 2017/04/18
 */

#ifndef GAME_SOUND_H
#define GAME_SOUND_H

#include <SDL2/SDL_mixer.h>

/**
* @brief La classe Sound contient un pointeur sur un sample/chunk
*/
class Sound {
    private:
        Mix_Chunk *chunk;
    public:
        Sound();

        /**
         * @brief Permet de charger une musique/son
         * @param filename Nom du fichier son
         */
        void loadSound(const char * filename);

        /**
         * @brief Permet de jouer un son dans un canal
         * @param mode Nombre de loop
         * @param intensite volumemax/intensite, par défaut à 1
         */
        void playSound(int mode, int intensite = 1);

        /**
         * @brief Arrêter tous les canaux de son
         */
        void stopSound();
};


#endif //GAME_SOUND_H
