#include "ModuleUI.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"
#include <iostream>
ModuleUI::ModuleUI() {

	animKO.PushBack({ 151,0,26,23 }, 0.1F);
	animKO.PushBack({ 151,23,26,23 }, 0.1F);
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

	max_capacity = App->player->life;
	currentW_player2 = life_2.w;
	current_life2 = max_capacity;
	current_life1 = max_capacity;
	player1_point = 0;
	player2_point = 0;
	animKO_active = false;
	font_point_numbers = App->fonts->Load("Assets/Textures/PointNumbers.png", "0123456789", 1);
	return true;
}

bool ModuleUI::CleanUp() {
	LOG("UI Unloaded\n");
	App->textures->Unload(ui_png);
	App->fonts->UnLoad(font_point_numbers);
	return true;
}

update_status ModuleUI::Update() {



	UpdateBars();



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

bool ModuleUI::VericalTransition() {
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