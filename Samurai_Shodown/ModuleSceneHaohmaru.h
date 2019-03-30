#ifndef __MODULESCENEHAOHMARU_H__
#define __MODULESCENEHAOHMARU_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneHaohmaru : public Module
{
public:
	ModuleSceneHaohmaru();
	~ModuleSceneHaohmaru();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation background;
};

#endif // __MODULESCENEHAOHMARU_H__
