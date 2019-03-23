#ifndef _MODULESCENE_H
#define _MODULESCENE_H
#include "Module.h"
#include "SDL/include/SDL.h"
#include "Application.h"
class ModuleScene:public Module 
{
public:
	ModuleScene();
	~ModuleScene();
	bool Init();
	update_status PreUpdate();
	bool CleanUp();
	SDL_Texture* background;
};

#endif // !_MODULESCENE_H

