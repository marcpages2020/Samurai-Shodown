#ifndef _MODULESCENE_H
#define _MODULESCENE_H

#include "Module.h"
#include "SDL/include/SDL.h"
#include "Application.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "Animation.h"

class ModuleScene: public Module 
{
public:

	ModuleScene();
	~ModuleScene();
	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

public:

	SDL_Texture* background;
	SDL_Texture* haohmaru;
	Animation Haohmaru;

	int x = -92;
	int y = 0;

	Mix_Music *soundtrack;
	Mix_Chunk *ippon;
};

#endif // !_MODULESCENE_H

