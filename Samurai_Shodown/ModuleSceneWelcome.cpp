#include "ModuleSceneWelcome.h"


ModuleSceneWelcome::ModuleSceneWelcome()
{}

ModuleSceneWelcome::~ModuleSceneWelcome()
{}

// Load assets
bool ModuleSceneWelcome::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/Textures/menu.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/menu.ogg"); 
	App->audio->PlayMusic(music);
	// TODO 1: Enable (and properly disable) the player module
	return ret;
}

// Load assets
bool ModuleSceneWelcome::CleanUp()
{
	LOG("Unloading Welcome stage");
	App->player->Disable();
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	//App->audio->CleanUp();
	return true;
}

// Update: draw background
update_status ModuleSceneWelcome::Update()
{
	welcome.x = 0;
	welcome.y = 0;
	welcome.w = SCREEN_WIDTH;
	welcome.h = SCREEN_HEIGHT;
	// Draw everything --------------------------------------	
	App->render->Blit(graphics,NULL, NULL, &welcome);
	// TODO 2: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_haohmaru, 2.5f);
	}
	return UPDATE_CONTINUE;
}