#include "../headers/Image.h"
#include <iostream>

Image::~Image() {
    texture = NULL;
    SDL_DestroyTexture(texture);
}

void Image::loadImage(const char *filename, SDL_Renderer *renderer) {
    texture = IMG_LoadTexture(renderer, filename);
    if(texture == NULL){
        std::cout << "Erreur de chargement de : " << filename << std::endl;
        exit(1);
    }
}

void Image::draw(SDL_Renderer *renderer, unsigned int x, unsigned int y, unsigned int w, unsigned int h) {
    SDL_Rect v;
    v.x = x;
    v.y = y;
    v.w = w;
    v.h = h;
    SDL_RenderCopy(renderer,texture,NULL,&v);
}

void Image::drawSprite(SDL_Renderer *renderer, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int posX, unsigned int posW, unsigned int posH) {
    SDL_Rect v;
    SDL_Rect v2;
    v.x = x;
    v.y = y;
    v.w = w;
    v.h = h;
    v2.x = posX;
    v2.y = 0;
    v2.w = posW;
    v2.h = posH;
    SDL_RenderCopy(renderer, texture,&v2,&v);
}