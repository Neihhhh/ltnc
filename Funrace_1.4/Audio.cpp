#include "Audio.h"
#include <iostream>
using namespace std;

Mix_Chunk* buttonSound= nullptr;
Mix_Chunk* diceRollSound=nullptr;
Mix_Chunk* buffdebuffSound=nullptr;
Mix_Chunk* winSound=nullptr;
Mix_Chunk* loseSound=nullptr;
Mix_Chunk* moveSound=nullptr;

Mix_Music* backgroundMusic=nullptr;

void InitAudio(){
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cout << "SDL_mixer Initialization failed: " << Mix_GetError() << endl;
        return;
    }
    Mix_AllocateChannels(16);

    buttonSound=Mix_LoadWAV("playbutton.wav");
    diceRollSound=Mix_LoadWAV("soundroll.mp3");
    buffdebuffSound=Mix_LoadWAV("event.mp3");
    moveSound=Mix_LoadWAV("move.mp3");
    winSound=Mix_LoadWAV("win.ogg");
    loseSound=Mix_LoadWAV("lose.ogg");

    backgroundMusic=Mix_LoadMUS("backgroundmusic.mp3");
    if(!buttonSound || !diceRollSound || !buffdebuffSound || !winSound || !loseSound || !backgroundMusic){
        cout << "Failed to load sound/music: " << Mix_GetError() << endl;
        return;
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME / 8);
    Mix_Volume(-1, MIX_MAX_VOLUME);
}

void playButtonSound(){
    Mix_PlayChannel(-1,buttonSound,0);
}

void playDiceRollSound(){
    Mix_PlayChannel(-1,diceRollSound,0);
}

void playMoveSound(){
    Mix_PlayChannel(-1,moveSound,0);
}

void playBuffdebuffSound(){
    Mix_PlayChannel(-1,buffdebuffSound,0);
}

void playWinSound(){
    Mix_PlayChannel(-1,winSound,0);
}

void playLoseSound(){
    Mix_PlayChannel(-1,loseSound,0);
}

void playBackgroundMusic(){
    Mix_FadeInMusic(backgroundMusic,-1,2000);
}

void pauseMusic(){
    Mix_PauseMusic();
}

void resumeMusic(){
    Mix_ResumeMusic();
}

void fadeOutMusic(){
    Mix_FadeOutMusic(2000);
}

void cleanupAudio(){
    Mix_FreeChunk(buttonSound);
    Mix_FreeChunk(diceRollSound);
    Mix_FreeChunk(buffdebuffSound);
    Mix_FreeChunk(winSound);
    Mix_FreeChunk(loseSound);
    Mix_FreeMusic(backgroundMusic);

    Mix_CloseAudio();
}
