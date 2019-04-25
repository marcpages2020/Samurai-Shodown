#ifndef _MODULE_UI
#define _MODULE_UI
#include "Module.h"
#include "Animation.h"
#include "SDL/include/SDL_rect.h"
struct SDL_Texture;

class ModuleUI : public Module 
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

	void UpdateBars();

public:
	SDL_Texture * ui_png = nullptr;

	Animation animKO;
	bool animKO_active = false;
	
	//BARS
	int max_capacity = 0;
	int max_width = 128;
	//player1
	int target_life1 = 0;
	int current_life1 = 0;
	int currentW_player1 = 0;
	bool decrease_player1 = false;
	SDL_Rect life_1{ 8,32,128,9 };
	//player2
	int target_life2 = 0;
	int current_life2 = 0;
	int currentW_player2 = 0;
	bool decrease_player2 = false;
	SDL_Rect life_2{ 8,32,128,9 };
	SDL_Rect up_black_rect{ 0 ,0,SCREEN_WIDTH,0 };
	SDL_Rect down_black_rect{ 0,SCREEN_HEIGHT,SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
	SDL_Rect left_black_rect{ 0 ,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT };
	SDL_Rect right_black_rect{ SCREEN_WIDTH / 2 ,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT };
	bool VericalTransition();
	bool HorizontalTransition();
};

#endif // !_MODULE_UI

