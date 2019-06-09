#ifndef _ModulePlayer2_H
#define _ModulePlayer2_H

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_render.h"
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
	JUMP_PUNCH2,
	JUMP_KICK2,
	JUMP_HEAVY_PUNCH2,
	JUMP_HEAVY_KICK2,
	FORWARD2,
	HEAVY_PUNCH2,
	HEAVY_KICK2,
	IDLE2,
	KICK2,
	PUNCH2,
	TWISTER2,
	HIT2,
	EN_GARDE2,
	DIE2,
	WIN2,
	GRAB2,
	GRABBED2,
	DASH_FORWARD2,
	DASH_BACKWARD2,
	SPECIAL_ATTACK_2
};

struct PlayerInput2 {
	bool pressing_left;
	bool pressing_right;
	bool pressing_down;
	bool pressing_up;
	bool pressing_J;
	bool pressing_K;
	bool pressing_L;
	bool pressing_P;
	bool pressing_H;
	bool holding_J;
	bool pressing_F5;
};

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	virtual bool Start();
	update_status PreUpdate();
	update_status Update();
	virtual bool CleanUp();
	virtual void OnCollision(Collider* c1, Collider* c2);
	virtual void BlockControls(bool block);

public:

	Animation idle2;
	Animation forward2;
	Animation backward2;
	Animation punch2;
	Animation kick2;
	Animation heavy_kick2;
	Animation heavy_punch2;
	Animation hit2;
	Animation die2;
	Animation jump_neutral2;
	Animation jump_forward2;
	Animation jump_backward2;
	Animation jump_punch2;
	Animation jump_kick2;
	Animation jump_heavy_punch2;
	Animation jump_heavy_kick2;
	Animation crouch_down2;
	Animation win2;
	Animation en_garde2;
	Animation crouch_up2;
	Animation crouch_punch2;
	Animation crouch_kick2;
	Animation twister2;
	Animation twisterAlone2;
	Animation specialattack2;
	Animation grab2;
	Animation grabbed2;
	Animation dash_forward2;
	Animation dash_backward2;
	Animation* current_animation = nullptr;

		
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
	int direction_x =0;
	int hit_percent = 0;
	int hit_done = 0;
	int attack_frames = 0;
	int shadow_x;
	int shadow_w = 70;
	int gposition;
	void PlayerCollidersCleanUp();

	void checkDash(); //type 1=dash forward. 2=dash backward

	//Special attack 
	bool checkSpecialAttack(); //return true if special attack input has been introduced
	void introduceInputs();
	void newInput(char newInput); //It adds a new input into the last inputs array
	char inputs[100];
	int firstInput = 0;
	int lastInput = 0;

	PlayerInput2 player_input2;

	States2 state2;

	float speed = 2;

	bool are_particles_created2 = false;
	bool shadow_blit = true;
	bool god = false;
	bool controls = true;
	bool show_fx = false;

	Mix_Chunk* attack_fx;
	Mix_Chunk* kick_fx;
	Mix_Chunk* twister_fx;
	Mix_Chunk* hit_fx;
	Mix_Chunk* special_attack_fx;

	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	SDL_RendererFlip gflip = SDL_FLIP_HORIZONTAL;

	SDL_Texture* player2_textures=nullptr;
	SDL_Texture* spritesheet1_2 = nullptr;
	SDL_Texture* spritesheet2_2 = nullptr;
};

#endif // !_ModulePlayer2_H
