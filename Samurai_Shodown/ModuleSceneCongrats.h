#ifndef __MODULESCENECONGRATS_H__
#define __MODULESCENECONGRATS_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;

class ModuleSceneCongrats : public Module
{
public:
	ModuleSceneCongrats();
	~ModuleSceneCongrats();

	bool Start();
	update_status Update();
	bool CleanUp();
	Animation background;
public:
	Mix_Music* music;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* haohmaru = nullptr;
	SDL_Rect left_black_square{ 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT };
	SDL_Rect right_black_square{ SCREEN_WIDTH / 2,0, SCREEN_WIDTH / 2,SCREEN_HEIGHT};
	SDL_Rect up_black_square{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT/5 };
	SDL_Rect down_black_square{ 0,(SCREEN_HEIGHT/5)*4+5, SCREEN_WIDTH,SCREEN_HEIGHT/5};
	iPoint position;
};

#endif // __MODULESCENECONGRATS_H__
