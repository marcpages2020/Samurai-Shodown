#ifndef __MODULESCENEWELCOME_H__
#define __MODULESCENEWELCOME_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;

class ModuleSceneWelcome : public Module
{
public:
	ModuleSceneWelcome();
	~ModuleSceneWelcome();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	_Mix_Music* music;
	SDL_Texture* graphics = nullptr;
	SDL_Rect welcome;
};

#endif // __MODULESCENEWELCOME_H__
