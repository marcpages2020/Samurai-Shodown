#ifndef __MODULESNEOGEO_H__
#define __MODULESNEOGEO_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleNeoGeo : public Module
{
public:
	ModuleNeoGeo();
	~ModuleNeoGeo();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * intro = nullptr;

	Animation* anim = nullptr;
	Animation* anim2 = nullptr;
	Animation* anim3 = nullptr;
	Animation* anim4 = nullptr;
	Animation* anim5 = nullptr;

	Animation Neogeo;
	Animation SNK;
	Animation Letters;
	Animation Letters2;
	Animation Copy;
	uint fx = 0;
	int time = 0;
	int time2 = 0;
	bool change = false;
	bool next = false;
	Mix_Music * music = nullptr;
};

#endif // __MODULESCENEINTRO_H__