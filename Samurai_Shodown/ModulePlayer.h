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

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
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
	

};

#endif