#ifndef _MODULESCENEWANFU_H
#define _MODULESCENEWANFU_H

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

class ModuleSceneWanFu : public Module
{
public:
	ModuleSceneWanFu();
	~ModuleSceneWanFu();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Music *music=nullptr;
	SDL_Texture* graphics = nullptr;
	Animation background;
};
#endif // !_MODULESCENEWANFU_H

