//
// Created by skugga on 17/03/17.
//

#include "../headers/Map.h"

Map::Map() {
    sizeTab = 35;
    tab[0] = 'x';
    for(unsigned int i = 1 ; i < sizeTab - 1 ; ++i){
        tab[i] = '_';
    }
    tab[sizeTab-1] = 'y';
}

char Map::getX(const unsigned int x) const {
    return tab[x];
}

void Map::setX(const char c, const unsigned int x) {
    tab[x] = c;
}

unsigned int Map::getSizeTab() const {
    return sizeTab;
}

void Map::setSizeTab(const unsigned int stab) {
    sizeTab = stab;
}

bool Map::isUnitFine(const unsigned int x) {
    return (x < sizeTab-2) && (x > 1);
}