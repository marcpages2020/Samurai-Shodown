#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"

struct SDL_Texture;

enum States {
	IDLE,
	PUNCH,
	JUMP,
	KICK,
	FORWARD,
	BACKWARD,
	CROUCH,	
	TWISTER,
};

struct PlayerInput {

	bool pressing_A;
	bool pressing_D;
	bool pressing_U;
	bool pressing_J;
	bool pressing_W;
	bool pressing_S;
	bool pressing_K;
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* haohmaruSpreadsheet = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation jump;
	Animation crouch;
	Animation twister;
	Animation twisterAlone;
	iPoint position;


	bool animationAvailable = true;
	int mult = 1;
	int initial_y = 215;
	Animation* current_animation = nullptr;
	PlayerInput player_input;
	States state;
	Particle tornado;
	float speed = 2;

};

#endif