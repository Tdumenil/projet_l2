/**
 * @brief Le module jeu permet d'organiser les fonctions permettant le bon déroulement d'une partie
 * @file Game.h
 * @date 2017/03/18
 */

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Player.h"
#include "Map.h"
#include "Bot.h"

/**
 * @brief La classe Game a une joueur Player, une ia Bot et une map Map
 */

class Game {
    private:
        Player player;
        Bot bot;
        Map map;
    public:
        Game();
        Player & getPlayer();
        Bot & getBot();
        Map & getMap();
        /**
         * @brief Gestion des actions du joueur, achat, etc
         * @param k
         */
        void keyboardAction(const char k);

        /**
         * @brief Permet de faire avancer les unités du joueur et du bot automatiquement
         */
        void autoMoveUnits();

        /**
         * @brief Permet que les unités du joueur et de l'ia se battent aux corps à corps
         */
        void autoCombat();

        /**
         * @brief Permet d'affliger des dégâts à la base
         */
        void autoCombatBase();

        /**
         * @brief Permet de faire combattre les unités à distance, en faisant avancer les balles
         */
        void autoCombatRange();

        /**
         * @brief Les tourelles attaques une cible automatiquement
         */
        void autoAttackTurret();

        /**
         * @brief Permet d'affliger les dégâts lors de l'activaiton de l'attaque spéciale
         */
        void launchSpecialWeapon();

        /**
         * @brief Permet de réinitialiser une partie
         */
        void reset();

        void regressionTest();
};


#endif //GAME_GAME_H
