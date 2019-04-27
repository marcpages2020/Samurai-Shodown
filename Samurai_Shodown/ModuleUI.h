#ifndef _MODULE_UI
#define _MODULE_UI
#include "Module.h"
#include "Animation.h"
#include "SDL/include/SDL_rect.h"
#include "ModuleAudio.h"
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
	void VictorySprite();


public:
	SDL_Texture * ui_png = nullptr;

	Animation animKO;
	bool animKO_active = false;
	
	SDL_Rect* en_garde_rect = nullptr;

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
	//transitions
	SDL_Rect up_black_rect{ 0 ,0,SCREEN_WIDTH,0 };
	SDL_Rect down_black_rect{ 0,SCREEN_HEIGHT,SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
	SDL_Rect left_black_rect{ 0 ,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT };
	SDL_Rect right_black_rect{ SCREEN_WIDTH / 2 ,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT };
	bool VerticalTransition();
	bool HorizontalTransition();
	bool round_end = false;
	bool victory = false;
	bool vtransition = false;
	bool htransition = false;
	Mix_Chunk *ippon_fx;
	Mix_Chunk *victory_fx;
	float start_time = 0.0f;
	int font_point_numbers = 0;
	int timer_font = 0;
	int player1_point = 0;
	int player2_point = 0;
	int player1_wins=0;
	int player2_wins=0;
	int draw=0;
	char point_text1[10];
	char point_text2[10];
	uint time_fight = 96;
	char time_text[10];
	char point_gain_life[10];
	char char_points[10];
	char char_time[10];
	char char_total[10];
	char char_hit_percentatge[10];
	void timer();
	void ResetScene();
	bool die_scene = false;
	SDL_Texture* finish_round = nullptr;
	void DieScene();
	Animation ippon;
	float ippon_time = 0;
	Animation haohmaru;
	float haohmaru_time = 0;
	bool ippon_finished = false;
	float rest_time = 0;
	bool haomaru_finished = false;
	Animation victory_anim;
	Animation well_done;
	Animation en_garde;
	bool points_done = false;
	int points_life_gain = 0;
	int time_points = 0;
	int points_hit = 0;
	float points_first_wait = 0;
	float points_second_wait = 0;
	bool player1_win = false;
	bool player2_win = false;
	bool life_done = false;
	bool time_done = false;
	bool hit_percent_done = false;
	int total_points = 0;
};

#endif // !_MODULE_UI

