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
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.PushBack({ 0,y += 32,92,32 }, 0.6F);
	ipon.loop = false;

	y = -33;
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.PushBack({ 102,y += 33,127,33 }, 0.6F);
	haohmaru.loop = false;

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
	current_life1 = max_capacity;
	player1_point = 0;
	player2_point = 0;
	animKO_active = false;
	finish_round = App->textures->Load("Assets/Textures/finish_round.png");
	font_point_numbers = App->fonts->Load("Assets/Textures/PointNumbers.png", "0123456789", 1);
	timer_font = App->fonts->Load("Assets/Textures/UI.png", "9876543210", 1);
	ippon = App->audio->LoadFX("Assets/Audio/Fx/Judge/Ippon.wav");
	victory_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Victory.wav");
	return true;
}

bool ModuleUI::CleanUp() {
	LOG("UI Unloaded\n");
	App->textures->Unload(ui_png);
	App->textures->Unload(finish_round);
	App->fonts->UnLoad(font_point_numbers);
	App->fonts->UnLoad(timer_font);
	App->audio->UnLoadFx(ippon);
	return true;
}

update_status ModuleUI::Update() {

	UpdateBars();
	timer();
	DieScene();
	// player 1 points
	sprintf_s(point_text1, 10, "%7d", player1_point);
	App->fonts->BlitText(77, 8, font_point_numbers, point_text1);
	// player 1 points
	sprintf_s(point_text2, 10, "%7d", player2_point);
	App->fonts->BlitText(313, 8, font_point_numbers, point_text2);

	SDL_Rect player1_p{ 182,0,23,8 }; // P1 =
	App->render->Blit(ui_png, 27, 8, &player1_p, SDL_FLIP_NONE,1.0F,false);
	SDL_Rect player2_p{ 182,8,23,16 }; // P2 =
	App->render->Blit(ui_png, 263, 8, &player2_p, SDL_FLIP_NONE, 1.0F, false);

	// KO image
	if (!animKO_active) { 
		App->render->Blit(ui_png, SCREEN_WIDTH/2 - 13, 10, &animKO.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
	}
	else {
		App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 13 / 2, 10, &animKO.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
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
	
	if (App->player->life <= 0)
	{
		player2_wins++;
		round_end = true;
	}
	// player 2 dies
	if (App->player2->life <= 0)
	{
		player1_wins++;
		App->player2->state2 = States2::DEATH2;
		round_end = true;
	}
	if (round_end == true)
	{
		App->player->life = 1;
		App->player2->life = 1;
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
		App->audio->PlayFX(ippon);
		round_end = false;
		die_scene = true;
		ipon_time = SDL_GetTicks();
	}

	if (App->input->keyboard[SDL_SCANCODE_F7])
	{
		round_end = true;
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
	
	return UPDATE_CONTINUE;
}

void ModuleUI::UpdateBars()
{

	if (App->player->life < 30 || App->player2->life < 30)
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
		if (start_time <= SDL_GetTicks() - 1000 && time_fight > 0) {
			--time_fight;
			start_time = SDL_GetTicks();
		}
	}
	sprintf_s(time_text, 10, "%7d", time_fight);
	App->fonts->BlitText(177, 40, timer_font, time_text);
	if (time_fight == 0) {
		if (App->player->life > App->player2->life)
		{
		player1_wins++;
		round_end = true;
		}
		else if (App->player->life == App->player2->life)
		{
			draw++;
			round_end = true;
		}
		else {
			player2_wins++;
			round_end = true;
		}
	}
}

void ModuleUI::ResetScene() {
	App->player->life = 100;
	App->player->position = App->player->initial_position;
	App->player->state = IDLE;
	App->player2->life = 100;
	App->player2->position = App->player2->initial_position;
	App->player2->state2 = IDLE2;
	time_fight = 96;
	animKO_active = false;
	App->render->camera.x = App->render->camera.y = 0;
	App->render->SetCamera();
	ipon.Reset();
	ipon_finished = false;
	haomaru_finished = false;
}

void ModuleUI::DieScene()
{

	if (die_scene) {
		if (!ipon_finished) {
			if (ipon_time >= SDL_GetTicks() - 1000) {
				App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 46, SCREEN_HEIGHT / 2 - 16, &ipon.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
			}
			else if (ipon.SeeCurrentFrame() < 13) {
				App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 46, SCREEN_HEIGHT / 2 - 16, &ipon.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
			}
			else {
				ipon_finished = true;
				haohmaru_time = SDL_GetTicks();
			}
		}
		if (!haomaru_finished && ipon_finished) {
			if (haohmaru_time >= SDL_GetTicks() - 2000) {
				App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 63, SCREEN_HEIGHT / 2 - 16, &haohmaru.frames[0].rect, SDL_FLIP_NONE, 1.0F, false);
			}
			else if (haohmaru.SeeCurrentFrame() < 14) {
				App->render->Blit(finish_round, SCREEN_WIDTH / 2 - 63, SCREEN_HEIGHT / 2 - 16, &haohmaru.GetCurrentFrame(), SDL_FLIP_NONE, 1.0F, false);
			}
			else {
				die_scene = false;
			}
		}
		
	}

}
