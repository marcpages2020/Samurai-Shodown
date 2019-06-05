#include "ModuleCharacterSelection.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleUI.h"

ModuleCharacterSelection::ModuleCharacterSelection() {
	//p1 shining square

	//p2 shining square

}

ModuleCharacterSelection::~ModuleCharacterSelection() {

}

bool ModuleCharacterSelection::Init() {
	background = App->textures->Load("Assets/Sprites/Scenes/character_selection_background.png");
	character = App->textures->Load("Assets/Sprites/UI/finish_round.png");
	//App->player->Enable();
	//App->player2->Enable();
	return true;
}

update_status ModuleCharacterSelection::Update() {
	SDL_Rect back, face;
	back = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
	face = { 0,0,50,50 };
	App->render->Blit(background, 0, 0, &back);
	//App->render->Blit();
	return UPDATE_CONTINUE;
}

bool ModuleCharacterSelection::CleanUp() {
	return true;
}