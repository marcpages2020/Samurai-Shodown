#include "ModuleSceneCongrats.h"


ModuleSceneCongrats::ModuleSceneCongrats()
{
}

ModuleSceneCongrats::~ModuleSceneCongrats()
{
}

// Load assets
bool ModuleSceneCongrats::Start()
{
	LOG("Loading congrats stage assets");
	bool ret = true;
	graphics = App->textures->Load("");//add picture
	music = App->audio->LoadMusic(""); //add music
	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	return ret;
}

// Load assets
bool ModuleSceneCongrats::CleanUp()
{
	LOG("Unloading Congrats stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneCongrats::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 160, congrats);

	// TODO 2: make so pressing SPACE the KEN stage is loaded

	return UPDATE_CONTINUE;
}