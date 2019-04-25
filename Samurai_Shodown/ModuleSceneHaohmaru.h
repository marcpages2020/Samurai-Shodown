#ifndef __MODULESCENEHAOHMARU_H__
#define __MODULESCENEHAOHMARU_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "Globals.h"
#include "Application.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "ModuleCollision.h"

struct SDL_Texture;

class ModuleSceneHaohmaru : public Module
{
public:
	ModuleSceneHaohmaru();
	~ModuleSceneHaohmaru();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Music *music;
	Mix_Chunk *ippon;
	Mix_Chunk *victory_fx;
	SDL_Texture* graphics = nullptr;
	Animation background;
	Collider* left_wall;
	Collider* right_wall;
	int font = 0;
	float start_time = 0.0f;
	int player1_wins;
	int player2_wins;
	int draw;
	bool victory=false;
	bool round_end = false;
	bool vtransition = false;
	bool htransition = false;
	SDL_Rect up_black_rect {0,0,SCREEN_WIDTH,SCREEN_HEIGHT/2};
	SDL_Rect down_black_rect{ 0,SCREEN_HEIGHT / 2,SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
};

#endif // __MODULESCENEHAOHMARU_H__
