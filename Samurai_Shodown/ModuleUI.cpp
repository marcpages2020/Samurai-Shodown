#include "ModuleUI.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"

ModuleUI::ModuleUI() {}

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
	return true;
}

bool ModuleUI::CleanUp() {
	LOG("UI Unloaded\n");
	App->textures->Unload(ui_png);
	return true;
}



update_status ModuleUI::Update() {



	UpdateBars();

	SDL_Rect name{ 0,0,64,8 }; // haomaru name
	App->render->Blit(ui_png, 17, 32, &name, SDL_FLIP_NONE, false); //
	App->render->Blit(ui_png, 298, 32, &name, SDL_FLIP_NONE, false);
	SDL_Rect rect{ 6,17,132,13 }; // bar
	//player 1 bar
	App->render->Blit(ui_png, 8, 17, &rect, SDL_FLIP_NONE, false); //
	App->render->Blit(ui_png, 10, 19, &life_1, SDL_FLIP_NONE, false); //

	//player 2 bar
	App->render->Blit(ui_png, 243, 17, &rect, SDL_FLIP_NONE, false); //
	App->render->Blit(ui_png, 245, 19, &life_2, SDL_FLIP_NONE, false); //


	return UPDATE_CONTINUE;
}



void ModuleUI::UpdateBars()
{
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
