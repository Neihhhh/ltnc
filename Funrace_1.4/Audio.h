#ifndef AUDIO_H
#define AUDIO_H

#include<SDL_mixer.h>

void InitAudio();
void playButtonSound();
void playDiceRollSound();
void playBuffdebuffSound();
void playMoveSound();
void playWinSound();
void playLoseSound();
void playBackgroundMusic();
void pauseMusic();
void resumeMusic();
void fadeOutMusic();
void cleanupAudio();

#endif
