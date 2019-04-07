#ifndef _ModulePlayer2_H
#define _ModulePlayer2_H

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"

struct SDL_Texture;

/*struct PlayerInput {

};*/

/*enum States {
	IDLE,
	PUNCH,
	JUMP,
	KICK,
	FORWARD,
	BACKWARD,
	CROUCH,
	TWISTER
};*/

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
	bool god_mode = true;
	//Collider *collider_player_particles = nullptr;
	int mult = 1;
	int initial_y = 215;
	Animation* current_animation = nullptr;
	//PlayerInput player_input;
	//States state;
	float speed = 2;
};

#endif // !_ModulePlayer2_H
