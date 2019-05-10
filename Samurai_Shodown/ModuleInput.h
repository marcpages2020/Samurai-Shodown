#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL_events.h"
#include "SDL\include\SDL_scancode.h"

#define MAX_KEYS 300
#define MAX_BUTTONS 15

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	SDL_Event Events;
	Uint8 game_pad[MAX_BUTTONS][2];

	SDL_GameController* controller_player_1 = nullptr;

private :

	int controller_1_index;
};

#endif // __ModuleInput_H__