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
	graphics = App->textures->Load("Assets/Textures/congrats.png"); //change picture
	music = App->audio->LoadMusic("Assets/Audio/Music/winning_demo.ogg"); //add music
	App->audio->PlayMusic(music);
	return ret;
}

// Load assets
bool ModuleSceneCongrats::CleanUp()
{
	LOG("Unloading Congrats stage");
	App->player->Disable();
	App->textures->Unload(graphics);

	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	//App->audio->CleanUp();
	return true;
}

// Update: draw background
update_status ModuleSceneCongrats::Update()
{
	SDL_Rect congrats;
	congrats.x = 0;
	congrats.y = 0;
	congrats.w = SCREEN_WIDTH;
	congrats.h = SCREEN_HEIGHT;

	// Draw everything --------------------------------------

	App->render->Blit(graphics, NULL, NULL, &congrats);

	// TODO 2: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_congrats, (Module*)App->neo_geo, 2.5);
	}

	return UPDATE_CONTINUE;
}