#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL_events.h"
#include "SDL\include\SDL_scancode.h"

#define MAX_KEYS 300
#define MAX_BUTTONS 15
#define MAX_HISTORY 180
#define MAX_COMMAND_FRAMES 180

#define GAME_PAD_1 0
#define GAME_PAD_2 1
#define MAX_GAME_PAD 2

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum class InputCommandTypes {
	special_attack,
	punch,
	max
};

struct InputCommand {
	InputCommandTypes type = InputCommandTypes::max;

	InputCommand(InputCommandTypes type):type(type){}
	virtual bool Check(uint past_frames) const = 0;
};

struct CommandPunch :public InputCommand {
	CommandPunch():InputCommand(InputCommandTypes::punch){}
	bool Check(uint frames_past) const override;
};

struct CommandSpecialAttack : public InputCommand {
	CommandSpecialAttack():InputCommand(InputCommandTypes::special_attack){}
	bool Check(uint frames_past) const override;
};

struct History {
	uint frame = 0u;
	KEY_STATE keyboard[MAX_KEYS];
	//GamePad pads[MAX_PADS];
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
	Uint8 game_pad[MAX_BUTTONS][MAX_GAME_PAD];

	SDL_GameController* controller_player_1 = nullptr;
	SDL_GameController* controller_player_2 = nullptr;

private :

	int controller_1_index;
};

#endif // __ModuleInput_H__