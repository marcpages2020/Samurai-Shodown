#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

ModuleSceneHaohmaru::ModuleSceneHaohmaru()
{}

ModuleSceneHaohmaru::~ModuleSceneHaohmaru()
{}

// Load assets
bool ModuleSceneHaohmaru::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("JapanJokamachiTogether.png");
	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	return ret;
}

// Load assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 160, &ground);

	// TODO 2: make so pressing SPACE the KEN stage is loaded

	return UPDATE_CONTINUE;
}