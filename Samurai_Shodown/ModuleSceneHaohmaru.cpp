#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleSceneHaohmaru::ModuleSceneHaohmaru()
{
	background.PushBack({ 0,0,512,333 }, 0.08f); //0
	background.PushBack({ 512,0,512,333 }, 0.08);
	background.PushBack({ 1024,0,512,333 }, 0.08f);
	background.PushBack({ 1536,0,512,333 }, 0.08f);
	background.PushBack({ 0,333,512,333 }, 0.08f); //512
	background.PushBack({ 512,333,512,333 }, 0.08f);
	background.PushBack({ 1024,333,512,333 }, 0.08f);
	background.PushBack({ 1536,333,512,333 }, 0.08f);
	background.PushBack({ 0,666,512,333 }, 0.08f); //1024
	background.PushBack({ 512,666,512,333 }, 0.08f);
	background.PushBack({ 1024,666,512,333 }, 0.08f);
	background.PushBack({ 1536,666,512,333 }, 0.08f);
	background.PushBack({ 0,999,512,333 }, 0.08f); //1536
	background.PushBack({ 512,999,512,333 }, 0.08f);
	background.PushBack({ 1024,999,512,333 }, 0.08f);
	background.PushBack({ 1536,999,512,333 }, 0.08f);
	background.PushBack({ 0,1332,512,333 }, 0.08f); //2048
	background.PushBack({ 512,1332,512,333 }, 0.08f);
	background.PushBack({ 1024,1332,512,333 }, 0.08f);
	background.PushBack({ 1536,1332,512,333 }, 0.08f);
	background.PushBack({ 0,1665,512,333 }, 0.08f); //2560
	background.PushBack({ 512,1665,512,333 }, 0.08f);
	background.PushBack({ 1024,1665,512,333 }, 0.08f);
	background.PushBack({ 1536,1665,512,333 }, 0.08f);
}

ModuleSceneHaohmaru::~ModuleSceneHaohmaru()
{}

// Load assets
bool ModuleSceneHaohmaru::Start()
{
	LOG("Loading Haohmaru Scene");
	bool ret = true;

	graphics = App->textures->Load("Assets/Textures/HaohmaruScene.png");
	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	return ret;
}

// Load assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru stage");
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{
	SDL_Rect b;
	// Draw everything --------------------------------------	
	b = background.GetCurrentFrame();
	App->render->Blit(graphics,-92,-100,&b,0.75f);
	// TODO 2: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		//App->fade->FadeToBlack((Module*)App->scene_haohmaru,(Module*)App->);
	}

	return UPDATE_CONTINUE;
}