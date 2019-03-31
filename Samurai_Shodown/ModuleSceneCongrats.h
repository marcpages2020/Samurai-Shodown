#ifndef __MODULESCENECONGRATS_H__
#define __MODULESCENECONGRATS_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;

class ModuleSceneCongrats : public Module
{
public:
	ModuleSceneCongrats();
	~ModuleSceneCongrats();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Music* music;
	SDL_Texture* graphics = nullptr;
	SDL_Rect congrats;
};

#endif // __MODULESCENECONGRATS_H__
