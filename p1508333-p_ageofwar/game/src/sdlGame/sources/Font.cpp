//
// Created by skugga on 04/04/17.
//

#include "../headers/Font.h"

Font::~Font() {
    texture = NULL;
    font = NULL;
}

void Font::loadFont(const char *filename, SDL_Renderer *renderer, const unsigned int size) {
    font = TTF_OpenFont(filename, size);
    if(font == NULL){
        printf( "SDL_ttf Error: %s\n", TTF_GetError() );
    }
}

void Font::loadGetSize(SDL_Renderer *renderer, SDL_Color textColor, const char *text, int &w, int &h) {
    SDL_Surface * textSurface = TTF_RenderText_Solid(font, text, textColor);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
}

void Font::draw(SDL_Renderer * renderer, unsigned int x, unsigned int y, unsigned int w, unsigned int h) {
    SDL_Rect v;
    v.x = x;
    v.y = y;
    v.w = w;
    v.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &v);
}