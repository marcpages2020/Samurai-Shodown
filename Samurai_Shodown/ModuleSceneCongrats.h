#ifndef __MODULESCENECONGRATS_H__
#define __MODULESCENECONGRATS_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

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

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect roof;
	SDL_Rect foreground;
	SDL_Rect background;
	Animation water;
};

#endif // __MODULESCENECONGRATS_H__
