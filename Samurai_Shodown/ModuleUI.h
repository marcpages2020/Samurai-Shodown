#ifndef _MODULE_UI
#define _MODULE_UI
#include "Module.h"
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
};

#endif // !_MODULE_UI

