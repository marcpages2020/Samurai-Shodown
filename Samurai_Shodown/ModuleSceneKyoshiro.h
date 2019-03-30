#ifndef _MODULESCENEKYOSHIRO_H
#define _MODULESCENEKYOSHIRO_H

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "Globals.h"
#include "Application.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;

class ModuleSceneKyoshiro : public Module
{
public:
	ModuleSceneKyoshiro();
	~ModuleSceneKyoshiro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Music *music;
	SDL_Texture* graphics = nullptr;
	Animation background;
};
#endif // !_MODULESCENEKYOSHIRO_H

