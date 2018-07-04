//
// Created by skugga on 01/05/17.
//

#include "../headers/Sound.h"

Sound::Sound(){
    chunk = NULL;
}

void Sound::loadSound(const char *filename) {
    chunk=Mix_LoadWAV(filename);
    if(!chunk) {
        printf("%s\n", Mix_GetError());
    }
}

void Sound::playSound(int mode, int intensite) {
    Mix_VolumeChunk(chunk, MIX_MAX_VOLUME/intensite);
    if(Mix_PlayChannel(-1, chunk, mode)==-1) {
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
        // well, there's no music, but most games don't break without music...
    }
}

void Sound::stopSound() {
    //Mix_FreeMusic(music);
    Mix_HaltChannel(-1);
}
