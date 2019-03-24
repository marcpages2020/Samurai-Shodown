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
	Mix_Music* LoadMusic(const char* path);
	bool PlayMusic(Mix_Music*);
	Mix_Chunk* LoadFX(const char* path);
	bool PlayFX(Mix_Chunk*);
public:
	Mix_Music *songs[MAX_SONGS];
	Mix_Chunk *fxs[MAX_FX];
};
#endif // !_ModuleAudio_H

