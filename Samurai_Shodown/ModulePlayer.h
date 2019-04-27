#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_render.h"

struct SDL_Texture;

enum States
{
	BACKWARD,
	CROUCH_UP,
	CROUCH_DOWN,
	CROUCH_KICK,
	CROUCH_PUNCH,
	JUMP_NEUTRAL,
	JUMP_FORWARD,
	JUMP_BACKWARD,
	FORWARD,
	IDLE,
	KICK,
	PUNCH,
	TWISTER,
	HIT,
	EN_GARDE,
	WIN,
	DEATH,


};

struct PlayerInput {

	bool pressing_A;
	bool pressing_D;
	bool pressing_C;
	bool pressing_B;
	bool pressing_W;
	bool pressing_S;
	bool pressing_V;
	bool pressing_F4;
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
	void OnCollision(Collider* c1, Collider* c2);
public:

	SDL_Texture * graphics = nullptr;
	SDL_Texture* haohmaruSpreadsheet = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation punch;
	Animation kick;
	Animation hit;	
	Animation jump_neutral;
	Animation jump_forward;
	Animation jump_backward;
	Animation crouch_up;
	Animation crouch_down;
	Animation crouch_punch;
	Animation crouch_kick;
	Animation twister;
	Animation twisterAlone;
	Animation en_garde;
	int hit_percent = 0;
	int hit_done = 0;
	Animation die;
	iPoint position;
	iPoint lposition;
	bool god = false;
	iPoint initial_position;
	Collider *collider_player_up = nullptr;
	Collider *collider_player_mid = nullptr;
	Collider *collider_player_down = nullptr;
	Collider *collider_player_attack = nullptr;
	int life=100;
	int mult = 1;
	Animation* current_animation = nullptr;
	PlayerInput player_input;
	States state;
	float speed = 2;
	bool is_tornado_created = false;
	Mix_Chunk* light_attack_fx;
	Mix_Chunk* light_kick_fx;
	Mix_Chunk* twister_fx;
	Mix_Chunk* hit_fx;
	Animation win;
	int attack_frames=0;
	void PlayerCollidersCleanUp();
	int shadow_x;
	int shadow_w = 70;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};

#endif // __ModulePlayer_H__