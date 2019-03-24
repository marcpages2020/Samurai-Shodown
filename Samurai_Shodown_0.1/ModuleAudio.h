#ifndef _ModuleAudio_H
#define _ModuleAudio_H

#include "Module.h"
#include "Application.h"
#include "SDL_mixer/include/SDL_mixer.h"

#define MAX_SONGS 5
#define MAX_FX 10

class ModuleAudio:public Module {
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();
public:
	void PlaySong(const char* path);
	void PlayFX(const char* path);
	Mix_Music *songs[MAX_SONGS];
	Mix_Chunk *fxs[MAX_FX];
};
#endif // !_ModuleAudio_H

