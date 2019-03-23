#ifndef _MODULEAUDIO_H
#define _MODULEAUDIO_H
#include "Module.h"
#include "Application.h"
#include "SDL_mixer/include/SDL_mixer.h"

#define MAX_SONGS 5
/*class ModuleAudio:public Module {
public:
	ModuleAudio();
	~ModuleAudio();
	bool Init();
	bool CleanUp();
public:
	Mix_Music* const Load(const char* path);
	Mix_Music *song[MAX_SONGS];
};*/
#endif // !_MODULEAUDIO_H

