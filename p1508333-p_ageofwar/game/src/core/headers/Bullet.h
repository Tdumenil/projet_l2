/**
 * @brief Module qui gère les balles de la tourelle et des unités qui tire à distance
 * Dans unité il est utilisé comme une arme en elle-même mais pour la tourelle, on gère une balle à la fois
 * @file Bullet.h
 * @date 2017/03/18
 */

#ifndef GAME_BULLET_H
#define GAME_BULLET_H

/**
 * @brief La classe Bullet contient un x, les damages, un timer et une activité
 * Le x permet de suivre la balle dans le terrain, damage permet d'affliger des dégâts à des unités, l'activité permet de savoir si le joueur à acheté la tourelle de son niveau courant et enfin le timer la cadence de tir.
 */
class Bullet {
    private:
        unsigned int x;
        unsigned int damage;

    public:
        Bullet();
        Bullet(const unsigned int damageP);
        ~Bullet();
        void operator = (const Bullet b);
        unsigned int getX() const;
        void setX(const unsigned int xx);
        unsigned int getDamage() const;
        void setDamage(const unsigned int damageP);
        /**
         * @brief Permet de faire avancer la balle dans le sens +x normal (pour le player)
         */
        void moveForward();
        /**
         * @brief Permet de faire avancer la balle dans le sens -x inverse (pour le bot)
         */
        void moveBackward();
};


#endif //GAME_BULLET_H
