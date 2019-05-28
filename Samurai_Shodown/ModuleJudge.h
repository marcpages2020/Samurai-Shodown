#ifndef __ModuleJudge_H__
#define __ModuleJudge_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_render.h"

struct SDL_Texture;

enum States_J
{
	IDLE_J,
	MOVE_LEFT_J,
	MOVE_RIGHT_J,
	BEGIN_J,
	HIT1_J,
	HIT2_J,
	FINISH_J,
};

class ModuleJudge : public Module
{
public:
	ModuleJudge();
	~ModuleJudge();

	virtual bool Start();
	update_status PreUpdate();
	update_status Update();
	virtual bool CleanUp();
	void Move();

public:
	SDL_Texture* player_textures = nullptr;
	SDL_Texture* spritesheet1 = nullptr;
	SDL_Texture* spritesheet2 = nullptr;

	Animation idle;
	Animation move_right;
	Animation move_left;
	Animation begin_j;
	Animation hit1;
	Animation hit2;
	Animation finish;
	Animation* current_animation = nullptr;
	States_J state_j;

	float speed = 2;

	int position_x;
	int position_y;

	bool moving = false;

	SDL_Texture* judge_tex;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};

#endif // __ModuleJudge_H__
