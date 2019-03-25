#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "Application.h"
#include "SDL_mixer/include/SDL_mixer.h"


struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();

public:
	
	SDL_Texture* background = nullptr;

	SDL_Texture* haohmaruSpreadsheet = nullptr;
	Animation Haohmaru;

	int x = -92;
	int y = -100;

	Mix_Music *soundtrack;
	Mix_Chunk *ippon;


};

#endif