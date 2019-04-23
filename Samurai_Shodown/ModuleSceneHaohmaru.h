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
	SDL_Texture* graphics = nullptr;
	Animation background;
	uint time_fight = 96;
	int font = 0;
	float start_time = 0.0f;
	char time_text[10];
	int player1_wins;
	int player2_wins;
	int draw;
	bool victory=false;
	bool round_end = false;
};

#endif // __MODULESCENEHAOHMARU_H__
