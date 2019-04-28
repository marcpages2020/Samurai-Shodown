#include "ModuleUI.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"
#include "ModuleSceneHaohmaru.h"
#include <iostream>

ModuleUI::ModuleUI() {
	animKO.PushBack({ 151,0,26,23 }, 0.1F);
	animKO.PushBack({ 151,23,26,23 }, 0.1F);

	int y = -32;
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ippon.loop = false;

	y = -32;
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.PushBack({ 102,y += 32,127,32 }, 0.6F);
	haohmaru.loop = false;

	float speed = 0.5F;

	y = -32;
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.PushBack({ 243,y += 32,111,32 }, speed);
	victory_anim.loop = false;

	y = -32;
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.PushBack({ 367,y += 32,286,32 }, 0.6F);
	well_done.loop = false;


	y = -32;
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.PushBack({ 269,y += 32,111,32 }, 0.6F);
	time_up_anim.loop = false;

	y = -32;
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.PushBack({ 406,y += 32,63,32 }, 0.6F);
	draw_anim.loop = false;

	//en garde
	{
		en_garde.PushBack({ 805,0,194,32 }, 0.4f);
		en_garde.PushBack({ 806,33,194,32 }, 0.4f);
		en_garde.PushBack({ 806,66,194,32 }, 0.4f);
		en_garde.PushBack({ 805,99,194,32 }, 0.4f);
		en_garde.PushBack({ 805,132,194,32 }, 0.4f);
		en_garde.PushBack({ 805,165,194,32 }, 0.4f);
		en_garde.PushBack({ 805,198,194,32 }, 0.4f);
		en_garde.PushBack({ 805,231,194,32 }, 0.4f);
		en_garde.PushBack({ 805,264,194,32 }, 0.4f);
		en_garde.PushBack({ 805,297,194,32 }, 0.4f);
		en_garde.PushBack({ 805,330,194,32 }, 0.4f);
		en_garde.PushBack({ 805,363,194,32 }, 0.4f);
		en_garde.PushBack({ 805,395,194,32 }, 0.4f);
		en_garde.PushBack({ 805,429,194,32 }, 0.4f);
		en_garde.PushBack({ 805,461,194,32 }, 0.4f);
		en_garde.PushBack({ 805,493,194,32 }, 0.4f);
		en_garde.PushBack({ 804,524,194,32 }, 0.4f);
		en_garde.PushBack({ 805,558,194,32 }, 0.4f);
		en_garde.PushBack({ 805,590,194,32 }, 0.4f);
		en_garde.PushBack({ 805,622,194,32 }, 0.4f);
		en_garde.PushBack({ 805,654,194,32 }, 0.4f);
		en_garde.PushBack({ 805,686,194,32 }, 0.4f);
		en_garde.PushBack({ 805,718,194,32 }, 0.4f);
		en_garde.PushBack({ 805,749,194,32 }, 0.4f);
		en_garde.PushBack({ 806,781,194,32 }, 0.4f);
		en_garde.PushBack({ 805,813,194,32 }, 0.4f);
		en_garde.loop = false;

	}
	y = -48;
	begin.PushBack({ 490,y += 48,102,48 }, 0.01F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.PushBack({ 490,y += 48,102,48 }, 0.5F);
	begin.loop = false;


}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {
	LOG("Loading UI\n");
	ui_png = App->textures->Load("Assets/Textures/in_gameUI.png");
	life_1 = { 8,32,128,9 };
	life_2 = { 8,32,128,9 };
	App->player->life = 100;
	App->player2->life = 100;
	currentW_player1 = life_1.w;
	time_fight = 96;
	max_capacity = App->player->life;
	currentW_player2 = life_2.w;
	current_life2 = max_capacity;
	begin.Reset();
	show_ui = false;
	current_life1 = max_capacity;
	player1_point = 0;
	player1_wins = 0;
	player2_wins = 0;
	player2_point = 0;
	animKO_active = false;
	points_fx = App->audio->LoadFX("Assets/Audio/Fx/count_points.wav");
	finish_round = App->textures->Load("Assets/Textures/finish_round.png");
	font_point_numbers = App->fonts->Load("Assets/Textures/PointNumbers.png", "0123456789", 1);
	timer_font = App->fonts->Load("Assets/Textures/UI.png", "9876543210", 1);
	ippon_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Ippon.wav");
	victory_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Victory.wav");
	begin_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Begin.wav");
	iza_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Iza.wav");
	ipponme_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Ippon-me.wav");
	jinjoni_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Begin_02.wav");
	round_03_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Round_03.wav");
	App->player->life = 100;
	player1_win = false;
	player2_win = false;
	App->player->position = App->player->initial_position;
	App->player->state = IDLE;
	App->player2->life = 100;
	App->player2->position = App->player2->initial_position;
	App->player2->state2 = IDLE2;
	time_fight = 96;
	animKO_active = false;
	App->render->camera.x = App->render->camera.y = 0;
	draw_anim.Reset();
	App->render->SetCamera();
	ippon.Reset();
	ippon_finished = false;
	haohmaru.Reset();
	is_draw = false;
	App->player->hit_done = 0;
	App->player->hit_percent = 0;
	App->player2->hit_done = 0;
	App->player2->hit_percent = 0;
	time_up = false;
	haomaru_finished = false;
	die_scene = false;
	total_points = 0;
	points_done = false;
	well_done.Reset();
	time_count = false;
	victory_anim.Reset();
	ippon_time = 0;
	points_first_wait = 0;
	en_garde_bool = true;
	points_second_wait = 0;
	life_done = false;
	time_done = false;
	time_up_anim.Reset();
	hit_percent_done = false;
	begin_finish = false;
	App->player->state = EN_GARDE;
	App->player2->state2 = EN_GARDE2;
	draw = 0;
	show_ui = false;
	return true;
}

bool ModuleUI::CleanUp() {

	LOG("UI Unloaded\n");
	App->textures->Unload(ui_png);
	App->textures->Unload(finish_round);
	App->fonts->UnLoad(font_point_numbers);
	App->fonts->UnLoad(timer_font);
	App->audio->UnLoadFx(ippon_fx);
	App->audio->UnLoadFx(victory_fx);
	App->audio->UnLoadFx(points_fx);
	return true;
}

update_status ModuleUI::Update() {

	if (play_ipponme == true)
	{
		App->audio->PlayFX(ipponme_fx);
		play_ipponme = false;
	}
	
	if (show_ui==true)
	{
		if (play_begin == true)
		{
			App->audio->PlayFX(begin_fx);
			play_begin = false;
		}

	UpdateBars();
	timer();
	DieScene();
	VictorySprite();
	// player 1 points
	sprintf_s(point_text1, 10, "%7d", player1_point);
	App->fonts->BlitText(77, 8, font_point_numbers, point_text1);
	// player 1 points
	sprintf_s(point_text2, 10, "%7d", player2_point);
	App->fonts->BlitText(313, 8, font_point_numbers, point_text2);

	SDL_Rect player1_p{ 182,0,23,8 }; // P1 =
	App->render->Blit(ui_png, 27, 8, &player1_p, SDL_FLIP_NONE, 1.0F, false);
	SDL_Rect player2_p{ 182,8,23,16 }; // P2 =
	App->render->Blit(ui_png, 263, 8, &player2_p, SDL_FLIP_NONE, 1.0F, false);

	// KO image
	if (!animKO_active) {
		App->render->Blit(ui_png, SCREEN_WIDTH / 2 - animKO.GetCurrentRect().w/2, 10, &animKO.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
	}
	else {
		App->render->Blit(ui_png, SCREEN_WIDTH / 2 - animKO.GetCurrentRect().w / 2, 10, &animKO.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
	}

	SDL_Rect name{ 0,0,64,8 }; // haomaru name
	App->render->Blit(ui_png, 27, 32, &name, SDL_FLIP_NONE, 1.0F, false); //
	App->render->Blit(ui_png, 288, 32, &name, SDL_FLIP_NONE, 1.0F, false);
	SDL_Rect rect{ 6,17,132,13 }; // bar
	//player 1 bar
	App->render->Blit(ui_png, 18, 17, &rect, SDL_FLIP_NONE, 1.0F, false); //
	App->render->Blit(ui_png, 20, 19, &life_1, SDL_FLIP_NONE, 1.0F, false); //

	//player 2 bar
	App->render->Blit(ui_png, 233, 17, &rect, SDL_FLIP_NONE, 1.0F, false); //
	App->render->Blit(ui_png, 235, 19, &life_2, SDL_FLIP_NONE, 1.0F, false); //

	// player 1 dies
	if (App->player->life <= 0)
	{
		player2_win = true;
		player2_wins++;
		round_end = true;
		points_life_gain = (6400 * App->player2->life) / 100;
		sprintf_s(point_gain_life, 10, "%7d", points_life_gain);
		float percent = ((float)(App->player2->hit_percent * 100) / (float)(App->player2->hit_done * 100));
		points_hit = ((percent * 100) * 20000) / 100;
		sprintf_s(char_hit_percentatge, 10, "%7d", points_hit);
		App->player->state = States::DEATH;
		App->player2->state2 = WIN2;
	}
	// player 2 dies
	if (App->player2->life <= 0)
	{
		player1_win = true;
		player1_wins++;
		App->player2->state2 = States2::DEATH2;
		App->player->state = WIN;
		points_life_gain = (6400 * App->player->life) / 100;
		sprintf_s(point_gain_life, 10, "%7d", points_life_gain);
		float percent = ((float)(App->player->hit_percent * 100) / (float)(App->player->hit_done * 100));
		points_hit = ((percent * 100) * 20000) / 100;
		sprintf_s(char_hit_percentatge, 10, "%7d", points_hit);
		round_end = true;

	}
	if (round_end == true)
	{
		if (App->player->life <= 0)
		{
			App->player->life = 1;
		}
		if (App->player2->life <= 0)
		{
			App->player2->life = 1;
		}
		//victory
		if ((player1_wins == 2) || (player2_wins == 2))
		{
			victory = true;
			App->audio->PlayFX(victory_fx);
		}
		//the battle continues
		else
		{
			vtransition = true;
		}
		App->audio->PlayFX(ippon_fx);
		round_end = false;
		die_scene = true;
		ippon_time = SDL_GetTicks();
	}
	if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_DOWN)
	{
		round_end = true;
		draw++;
		//victory = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_F8] == KEY_DOWN)
	{
		time_fight = 0;
		//victory = true;
	}
	if (vtransition == true && !die_scene)
	{
		if (App->ui->VerticalTransition() == false)
		{
			vtransition = false;
			htransition = true;
			App->ui->ResetScene();
		}
		else
		{
			App->ui->VerticalTransition();
		}

	}
	if (htransition == true)
	{
		if (App->ui->HorizontalTransition() == false)
		{
			htransition = false;	
		}
		else
		{
			App->ui->HorizontalTransition();
		}
	}
	}
	if (en_garde_bool == true)
	{
		App->player->BlockControls(true);
		App->player2->BlockControls(true);
		App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 90, SCREEN_HEIGHT / 2 - 65, &en_garde.GetCurrentFrame());
		if (en_garde.Finished())
		{
			en_garde.Reset();
			en_garde_bool = false;
			show_ui = true;
		}
	}
	if (show_ui && !en_garde_bool && !begin_finish) {
		if (!begin.Finished()) {
			App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 51, SCREEN_HEIGHT / 2 - 24, &begin.GetCurrentFrame());
			App->player->BlockControls(true);
			App->player2->BlockControls(true);
		}
		else {
			App->player->BlockControls(false);
			App->player2->BlockControls(false);
			begin_finish = true;
			play_begin = true;
		}
	}
	return UPDATE_CONTINUE;
}

void ModuleUI::UpdateBars()
{

	if (App->player->life < 45 || App->player2->life < 45)
		animKO_active = true;

	if (current_life1 != App->player->life) {
		int new_width = currentW_player1;
		int quantity = App->player->life - current_life1;
		int new_quantity = (current_life1 + quantity);
		current_life1 += quantity;

		if (max_capacity != 0)
			new_width = (new_quantity * max_width) / max_capacity;

		if (current_life1 <= 0) {
			current_life1 = 0;
			target_life1 = 0;
		}
		else if (current_life1 >= max_capacity) {
			current_life1 = max_capacity;
			target_life1 = max_width;
		}
		else
			target_life1 = new_width;

		decrease_player1 = true;
	}
	if (decrease_player1) {
		if (currentW_player1 > target_life1) {
			currentW_player1 -= 1;
		}
		else if (currentW_player1 < target_life1) {
			currentW_player1 += 1;
		}
		else {
			decrease_player1 = false;
		}
		life_1.w = currentW_player1;
	}

	if (current_life2 != App->player2->life) {
		int new_width = currentW_player2;
		int quantity = App->player2->life - current_life2;
		int new_quantity = (current_life2 + quantity);
		current_life2 += quantity;

		if (max_capacity != 0)
			new_width = (new_quantity * max_width) / max_capacity;

		if (current_life2 <= 0) {
			current_life2 = 0;
			target_life2 = 0;
		}
		else if (current_life2 >= max_capacity) {
			current_life2 = max_capacity;
			target_life2 = max_width;
		}
		else
			target_life2 = new_width;

		decrease_player2 = true;
	}
	if (decrease_player2) {
		if (currentW_player2 > target_life2) {
			currentW_player2 -= 1;
		}
		else if (currentW_player2 < target_life2) {
			currentW_player2 += 1;
		}
		else {
			decrease_player2 = false;
		}
		life_2.w = currentW_player2;
	}
}

void ModuleUI::VictorySprite()
{
	SDL_Rect win{ 214,0,24,15 };
	if (player1_wins == 1) {
		App->render->Blit(ui_png, 5, 43, &win, SDL_FLIP_NONE, 1.0F, false);
	}
	else if (player1_wins == 2) {
		App->render->Blit(ui_png, 5, 43, &win, SDL_FLIP_NONE, 1.0F, false);
		App->render->Blit(ui_png, 33, 43, &win, SDL_FLIP_NONE, 1.0F, false);
	}

	if (player2_wins == 1) {
		App->render->Blit(ui_png, 355, 43, &win, SDL_FLIP_NONE, 1.0F, false);
	}
	else if (player2_wins == 2) {
		App->render->Blit(ui_png, 325, 43, &win, SDL_FLIP_NONE, 1.0F, false);
		App->render->Blit(ui_png, 353, 43, &win, SDL_FLIP_NONE, 1.0F, false);
	}

}

bool ModuleUI::VerticalTransition() {
	App->render->DrawQuad(up_black_rect, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
	App->render->DrawQuad(down_black_rect, 0, 0, 0, SDL_ALPHA_OPAQUE, false);

	if (down_black_rect.y <= SCREEN_HEIGHT / 2)
	{
		up_black_rect.h = 0;
		down_black_rect.y = SCREEN_HEIGHT;
		return false;
	}
	else
	{
		up_black_rect.h += 2;
		down_black_rect.y -= 2;
		return true;
	}
}

bool ModuleUI::HorizontalTransition() {
	App->render->DrawQuad(right_black_rect, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
	App->render->DrawQuad(left_black_rect, 0, 0, 0, SDL_ALPHA_OPAQUE, false);

	if (left_black_rect.w <= 0)
	{
		left_black_rect.w = SCREEN_WIDTH / 2;
		right_black_rect.x = SCREEN_WIDTH / 2;
		play_ipponme= true;
		return false;
	}
	else
	{
		left_black_rect.w -= 2;
		right_black_rect.x += 2;
		return true;
	}
}

void ModuleUI::timer() {
	if (!App->is_paused) {
		if (!die_scene) {
			if (start_time <= SDL_GetTicks() - 1000 && time_fight > 0) {
				--time_fight;
				start_time = SDL_GetTicks();
			}
		}
		
	}
	if (!die_scene) {
		sprintf_s(time_text, 10, "%7d", time_fight);
		time_points = time_fight * 100;
		sprintf_s(char_time, 10, "%7d", time_points);
	}
		
	App->fonts->BlitText(177, 40, timer_font, time_text);
	if (time_fight == 0 && !time_count) {
		if (App->player->life > App->player2->life)
		{
		player1_wins++;
		player1_win = true;
		points_life_gain = (6400 * App->player->life) / 100;
		sprintf_s(point_gain_life, 10, "%7d", points_life_gain);
		float percent = ((float)(App->player->hit_percent * 100) / (float)(App->player->hit_done * 100));
		points_hit = ((percent * 100) * 20000) / 100;
		sprintf_s(char_hit_percentatge, 10, "%7d", points_hit);
		round_end = true;
		}
		else if (App->player->life == App->player2->life)
		{
			is_draw = true;
			draw++;
			round_end = true;
		}
		else {
			player2_wins++;
			points_life_gain = (6400 * App->player2->life) / 100;
			sprintf_s(point_gain_life, 10, "%7d", points_life_gain);
			float percent = ((float)(App->player2->hit_percent * 100) / (float)(App->player2->hit_done * 100));
			points_hit = ((percent * 100) * 20000) / 100;
			sprintf_s(char_hit_percentatge, 10, "%7d", points_hit);
			player2_win = true;
			round_end = true;
		}
		time_count = true;
		time_up = true;
		time_up_wait = SDL_GetTicks();
	}
}

void ModuleUI::ResetScene() {
	App->player->life = 100;
	time_up = false;
	App->player->position = App->player->initial_position;
	App->player->state = IDLE;
	App->player2->life = 100;
	App->player2->position = App->player2->initial_position;
	App->player2->state2 = IDLE2;
	time_fight = 96;
	animKO_active = false;
	App->render->camera.x = App->render->camera.y = 0;
	App->render->SetCamera();
	ippon.Reset();
	ippon_finished = false;
	haohmaru.Reset();
	draw_anim.Reset();
	App->player->hit_done = 0;
	App->player->hit_percent = 0;
	begin_finish = false;
	App->player2->hit_done = 0;
	begin.Reset();
	App->player2->hit_percent = 0;
	time_count = false;
	haomaru_finished = false;
	die_scene = false;
	total_points = 0;
	points_done = false;
	well_done.Reset();
	player1_win = false;
	player2_win = false;
	victory_anim.Reset();
	time_up_anim.Reset();
	ippon_time = 0;
	points_first_wait = 0;
	points_second_wait = 0;
	life_done = false;
	is_draw = false;
	time_done = false;
	hit_percent_done = false;
}

void ModuleUI::DieScene()
{

	if (die_scene && (player1_win || player2_win) && !time_up) {
		if (play_victory == true)
		{
			App->audio->PlayFX(victory_fx);
			play_victory = false;
		}
		if (player1_wins != 2 && player2_wins != 2 && !points_done) {
			if (!ippon_finished) {
				if (ippon_time >= SDL_GetTicks() - 1000) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 46, SCREEN_HEIGHT / 2 - 16, &ippon.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
				}
				else if (ippon.SeeCurrentFrame() < 13) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 46, SCREEN_HEIGHT / 2 - 16, &ippon.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
				}
				else {
					ippon_finished = true;
					haohmaru_time = SDL_GetTicks();
					rest_time = SDL_GetTicks();
				}
			}
			if (!haomaru_finished && ippon_finished && rest_time <= SDL_GetTicks() - 500) {
				if (haohmaru_time >= SDL_GetTicks() - 2000) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 63, SCREEN_HEIGHT / 2 - 16, &haohmaru.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
				}
				else if (haohmaru.SeeCurrentFrame() < 14) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 63, SCREEN_HEIGHT / 2 - 16, &haohmaru.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
				}
				else {
					points_done = true;
					points_first_wait = SDL_GetTicks();
				}
			}
		}
		else if (player1_wins == 2 && !points_done) {
			if (!ippon_finished) {
				if (ippon_time >= SDL_GetTicks() - 1000) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 55, SCREEN_HEIGHT / 2 - 16, &victory_anim.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
				}
				else if (victory_anim.SeeCurrentFrame() < 13) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 55, SCREEN_HEIGHT / 2 - 16, &victory_anim.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
				}
				else {
					ippon_finished = true;
					haohmaru_time = SDL_GetTicks();
					rest_time = SDL_GetTicks();
				}
			}
			if (!haomaru_finished && ippon_finished && rest_time <= SDL_GetTicks() - 500) {
				if (haohmaru_time >= SDL_GetTicks() - 2000) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 143, SCREEN_HEIGHT / 2 - 16, &well_done.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
				}
				else if (well_done.SeeCurrentFrame() < 13) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 143, SCREEN_HEIGHT / 2 - 16, &well_done.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
				}
				else {
					points_done = true;
					points_first_wait = SDL_GetTicks();
				}
			}
		}
		else if (player2_wins == 2 && !points_done) {
			if (!ippon_finished) {
				if (ippon_time >= SDL_GetTicks() - 1000) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 55, SCREEN_HEIGHT / 2 - 16, &victory_anim.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
				}
				else if (victory_anim.SeeCurrentFrame() < 13) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 55, SCREEN_HEIGHT / 2 - 16, &victory_anim.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
				}
				else {
					ippon_finished = true;
					haohmaru_time = SDL_GetTicks();
					rest_time = SDL_GetTicks();
				}
			}
			if (!haomaru_finished && ippon_finished && rest_time <= SDL_GetTicks() - 500) {
				if (haohmaru_time >= SDL_GetTicks() - 2000) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 143, SCREEN_HEIGHT / 2 - 16, &well_done.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
				}
				else if (well_done.SeeCurrentFrame() < 13) {
					App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 143, SCREEN_HEIGHT / 2 - 16, &well_done.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
				}
				else {
					points_done = true;
					points_first_wait = SDL_GetTicks();
				}
			}
		}
		if (points_done) {
			SDL_Rect r{ 706,0,75,127 };
			App->render->Blit(finish_round, 103, 65, &r, SDL_FLIP_NONE, 1.0F, false);
			if (points_first_wait >= SDL_GetTicks() - 800) {
				App->fonts->BlitText(193, 68, timer_font, point_gain_life);
				App->fonts->BlitText(193, 105, timer_font, char_time);
				App->fonts->BlitText(193, 140, timer_font, char_hit_percentatge);
				App->fonts->BlitText(193, 174, timer_font, "0");
			} 
			else if (!life_done && !time_done && !hit_percent_done && points_first_wait < SDL_GetTicks() - 800) {
				if (points_life_gain > 0) {
					if (player1_win)
						player1_point += 100;
					else if (player2_win)
						player2_point += 100;
					points_life_gain-=100;
					total_points+=100;
					sprintf_s(point_gain_life, 10, "%7d", points_life_gain);
					App->fonts->BlitText(193, 68, timer_font, point_gain_life);
					sprintf_s(char_total, 10, "%7d", total_points);
					App->fonts->BlitText(193, 174, timer_font, char_total);
					App->audio->PlayFX(points_fx);
				}
				else {
					life_done = true;
					points_life_gain = 0;
					sprintf_s(point_gain_life, 10, "%7d", points_life_gain);
				}
				
				App->fonts->BlitText(193, 105, timer_font, char_time);
				App->fonts->BlitText(193, 140, timer_font, char_hit_percentatge);
			}
			else if (life_done && !time_done && !hit_percent_done && points_first_wait < SDL_GetTicks() - 800) {
				if (time_points > 0) {
					if (player1_win)
						player1_point += 100;
					else if (player2_win)
						player2_point += 100;
					time_points-=100;
					total_points+=100;
					sprintf_s(char_time, 10, "%7d", time_points);
					App->fonts->BlitText(193, 105, timer_font, char_time);
					sprintf_s(char_total, 10, "%7d", total_points);
					App->fonts->BlitText(193, 174, timer_font, char_total);
					App->audio->PlayFX(points_fx);
				}
				else {
					time_points = 0;
					sprintf_s(char_time, 10, "%7d", time_points);
					time_done = true;
				}

				App->fonts->BlitText(193, 68, timer_font, point_gain_life);
				App->fonts->BlitText(193, 140, timer_font, char_hit_percentatge);
			}
			else if (life_done && time_done && !hit_percent_done && points_first_wait < SDL_GetTicks() - 800) {
				if (points_hit > 0) {
					if (player1_win)
						player1_point += 100;
					else if (player2_win)
						player2_point += 100;
					points_hit -= 100;
					total_points += 100;
					sprintf_s(char_hit_percentatge, 10, "%7d", points_hit);
					App->fonts->BlitText(193, 140, timer_font, char_hit_percentatge);
					sprintf_s(char_total, 10, "%7d", total_points);
					App->fonts->BlitText(193, 174, timer_font, char_total);
					App->audio->PlayFX(points_fx);
				}
				else {
					points_hit = 0;
					sprintf_s(char_hit_percentatge, 10, "%7d", points_hit);
					hit_percent_done = true;
					points_second_wait = SDL_GetTicks();
				}

				App->fonts->BlitText(193, 105, timer_font, char_time);
				App->fonts->BlitText(193, 68, timer_font, point_gain_life);
			}
			else if (life_done && time_done && hit_percent_done && points_first_wait < SDL_GetTicks() - 800 && points_second_wait <= SDL_GetTicks() - 1500) {

				die_scene = false;
			}
			else {
				App->fonts->BlitText(193, 140, timer_font, char_hit_percentatge);
				App->fonts->BlitText(193, 174, timer_font, char_total);
				App->fonts->BlitText(193, 105, timer_font, char_time);
				App->fonts->BlitText(193, 68, timer_font, point_gain_life);
			}
		}
	}
	else if (time_up) {
		if (time_up_wait > SDL_GetTicks() - 1000) {
			App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 55, SCREEN_HEIGHT / 2 - 16, &time_up_anim.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
		}
		else if (time_up_anim.SeeCurrentFrame() < 13) {
			App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 55, SCREEN_HEIGHT / 2 - 16, &time_up_anim.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
		}
		else {
			time_up = false;
			ippon_time = SDL_GetTicks();
		}
	}
	else if (die_scene && !player1_win && !player2_win && !time_up) {
		if (ippon_time > SDL_GetTicks() - 1000) {
			App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 31, SCREEN_HEIGHT / 2 - 16, &draw_anim.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
		}
		else if (draw_anim.SeeCurrentFrame() < 13) {
			App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 31, SCREEN_HEIGHT / 2 - 16, &draw_anim.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
		}
		else {
			die_scene = false;
		}
	}
}
