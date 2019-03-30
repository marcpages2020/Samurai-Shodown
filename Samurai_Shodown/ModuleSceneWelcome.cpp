#include "Globals.h"
#include "Application.h"
#include "ModuleSceneWelcome.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

ModuleSceneWelcome::ModuleSceneWelcome()
{

}

ModuleSceneWelcome::~ModuleSceneWelcome()
{

}

// Load assets
bool ModuleSceneWelcome::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	return ret;
}

// Load assets
bool ModuleSceneWelcome::CleanUp()
{
	LOG("Unloading Welcome stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneWelcome::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 160, &ground);

	// TODO 2: make so pressing SPACE the KEN stage is loaded

	return UPDATE_CONTINUE;
}