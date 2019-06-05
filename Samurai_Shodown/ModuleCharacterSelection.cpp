#include "ModuleCharacterSelection.h"
#include "Application.h"
#include "ModuleRender.h"

ModuleCharacterSelection::ModuleCharacterSelection() {

}

ModuleCharacterSelection::~ModuleCharacterSelection() {

}

bool ModuleCharacterSelection::Init() {
	background = App->textures->Load("Assets/Sprites/Scenes/character_selection_background.png");
	return true;
}

update_status ModuleCharacterSelection::Update() {
	SDL_Rect back;
	back = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
	App->render->Blit(background, 0, 0, &back);
	return UPDATE_CONTINUE;
}

bool ModuleCharacterSelection::CleanUp() {
	return true;
}