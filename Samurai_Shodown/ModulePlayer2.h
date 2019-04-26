#ifndef _ModulePlayer2_H
#define _ModulePlayer2_H

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"

struct SDL_Texture;

enum States2 {
	BACKWARD2,
	CROUCH_UP2,
	CROUCH_DOWN2,
	CROUCH_KICK2,
	CROUCH_PUNCH2,
	JUMP_NEUTRAL2,
	JUMP_FORWARD2,
	JUMP_BACKWARD2,
	FORWARD2,
	IDLE2,
	KICK2,
	PUNCH2,
	TWISTER2,
	HIT2,
	DEATH2
};


struct PlayerInput2 {
	bool pressing_left;
	bool pressing_right;
	bool pressing_down;
	bool pressing_up;
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
	Animation idle2;
	Animation forward2;
	Animation backward2;
	Animation punch2;
	Animation kick2;
	Animation hit2;
	Animation die2;
	Animation jump_neutral2;
	Animation jump_forward2;
	Animation jump_backward2;
	Animation crouch_down2;
	Animation crouch_up2;
	Animation crouch_punch2;
	Animation crouch_kick2;
	Animation twister2;
	Animation twisterAlone2;
	iPoint position;
	iPoint lposition;
	iPoint initial_position;
	Collider *collider_player_2_up = nullptr;
	Collider *collider_player_2_mid = nullptr;
	Collider *collider_player_2_down = nullptr;
	Collider *collider_player_2_attack = nullptr;
	Collider *test_collider = nullptr;
	int life = 100;
	int mult = 1;
	Animation* current_animation = nullptr;
	PlayerInput2 player_input2;
	States2 state2;
	float speed = 2;
	bool is_tornado_created2 = false;
	Mix_Chunk* light_attack_fx;
	Mix_Chunk* light_kick_fx;
	Mix_Chunk* twister_fx;
	Mix_Chunk* hit_fx;
	int attack_frames = 0;
};

#endif // !_ModulePlayer2_H
