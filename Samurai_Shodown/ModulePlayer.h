#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#define FPS 60

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

enum States {
	IDLE,
	PUNCH,
	JUMP,
	KICK,
	FORWARD,
	BACKWARD,
};

struct PlayerInput {

	bool pressing_A;
	bool pressing_D;
	bool pressing_U;
	bool pressing_J;
	bool pressing_W;
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* haohmaruSpreadsheet = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation jump;
	iPoint position;

	bool animationAvailable = true;
	int mult = 1;

	Animation* current_animation = nullptr;
	PlayerInput player_input;
	States state;
	int speed = 1;

};

#endif