#ifndef _ModulePlayer2_H
#define _ModulePlayer2_H

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"


struct SDL_Texture;

enum States2 {
	IDLE2,
	PUNCH2,
	JUMP2,
	KICK2,
	FORWARD2,
	BACKWARD2,
	CROUCH2,
	TWISTER2,
};


struct PlayerInput2 {
	bool pressing_1;
	bool pressing_3;
	bool pressing_2;
	bool pressing_5;
	bool pressing_B;
	bool pressing_N;
	bool pressing_M;
	bool pressing_F5;
};

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
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
	iPoint lposition;
	Collider *collider_player2 = nullptr;
	//Collider *collider_player_particles = nullptr;
	int mult = 1;
	int initial_y = 215;
	Animation* current_animation = nullptr;
	PlayerInput2 player_input2;
	States2 state2;
	float speed = 2;
};

#endif // !_ModulePlayer2_H
