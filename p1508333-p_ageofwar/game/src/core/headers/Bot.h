/**
 * @brief Le module bot permet de gérer l'IA du jeu
 * @file Bot.h
 * @date 2017/03/18
 */

#ifndef GAME_BOT_H
#define GAME_BOT_H

#include "Player.h"

/**
 * @brief La classe Bot prend seulement un joueur Player en paramètre
 * En réalité elle hérite de la classe Player
 */
class Bot {
    private:
        Player player;
    public:
        Bot();
        Player & getPlayer();

        /**
         * @brief Permet d'automatiser l'achat d'unité
         */
        void autoBuyUnit();

        /**
         * @brief Permet d'automatiser l'achat d'une tourelle
         */
        void autoBuyTurret();

        /**
         * @brief Permet d'automatiser le passage au niveau suivant
         */
        void autoLevelUp();

        /**
         * @brief Permet d'automatiser l'envoie de l'attaque spéciale
         */
        void autoUseSpecialWeapon();

        int rand_a_b (int a, int b);
        void regressionTest();
};


#endif //GAME_BOT_H
