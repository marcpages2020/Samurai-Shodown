#ifndef _MODULECHARACTERSELECTION_H
#define _MODULECHARACTERSELECTION_H
#include "Module.h"
#include "ModuleTextures.h"
class ModuleCharacterSelection :public Module {
public:
	ModuleCharacterSelection();
	~ModuleCharacterSelection();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* background;
};
#endif // !_MODULECHARACTERSELECTION_H

