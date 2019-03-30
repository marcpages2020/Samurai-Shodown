#ifndef __MODULESCENEWELCOME_H__
#define __MODULESCENEWELCOME_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

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

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect roof;
	SDL_Rect foreground;
	SDL_Rect background;
	Animation water;
};

#endif // __MODULESCENEWELCOME_H__
