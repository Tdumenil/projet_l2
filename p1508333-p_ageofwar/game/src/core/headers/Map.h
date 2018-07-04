/**
 * @brief Le module map permet de gérer la position des unités sur le terrain
 * @file Map.h
 * @date 2017/03/18
 */

#ifndef GAME_MAP_H
#define GAME_MAP_H

/**
 * @brief La classe Map à un tableau de caractère, et la taille de ce tableau
 */

class Map {
    private:
        char tab[35];
        unsigned int sizeTab;
    public:
        Map();
        char getX(const unsigned x) const;
        void setX(const char c, const unsigned int x);
        unsigned int getSizeTab() const;
        void setSizeTab(const unsigned int stab);

        /**
         * @brief Permet de vérifier sur une unité dépasse de la map ou non
         * @param x
         * @return true si l'unité est bien placé, false sinon
         */
        bool isUnitFine(const unsigned int x);
};


#endif //GAME_MAP_H
