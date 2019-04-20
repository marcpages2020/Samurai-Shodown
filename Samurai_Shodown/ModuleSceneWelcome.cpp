#include "ModuleSceneWelcome.h"

ModuleSceneWelcome::ModuleSceneWelcome()
{
	{
		letters.PushBack({ 0,0,253,114 }, 0.03f);
		letters.PushBack({ 253,0,253,114 }, 0.1f);
		letters.PushBack({ 506,0,253,114 }, 0.1f);
		letters.PushBack({ 0,114,253,114 }, 0.1f);
		letters.PushBack({ 253,114,253,114 }, 0.1f);
		letters.PushBack({ 506,114,253,114 }, 0.1f);
		letters.PushBack({ 0,228,253,114 }, 0.1f);
		letters.PushBack({ 253,228,253,114 }, 0.1f);
		letters.PushBack({ 506,228,253,114 }, 0.1f);
		letters.PushBack({ 0,342,253,114 }, 0.1f);
		letters.PushBack({ 253,342,253,114 }, 0.1f);
		letters.PushBack({ 506,342,253,114 }, 0.1f);
		letters.PushBack({ 0,456,253,114 }, 0.1f);
		letters.PushBack({ 253,456,253,114 }, 0.1f);
		letters.PushBack({ 506,456,253,114 }, 0.1f);
		letters.PushBack({ 0,570,253,114 }, 0.1f);
	}
}

ModuleSceneWelcome::~ModuleSceneWelcome()
{}

// Load assets
bool ModuleSceneWelcome::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/Textures/menu1.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/menu.ogg"); 
	Letters = App->textures->Load("Assets/Textures/3SamuraiShodownLetters.png");
	App->audio->PlayMusic(music,NULL);
	curr = &letters;
	return ret;
}

// Load assets
bool ModuleSceneWelcome::CleanUp()
{
	LOG("Unloading Welcome stage");
	App->player->Disable();
	App->textures->Unload(graphics);
	App->audio->UnLoadMusic(music);
	App->textures->Unload(Letters);
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
	App->render->Blit(Letters, 60, 50, &curr->GetCurrentFrame());
	// Make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_haohmaru, 2.5f);
	}
	return UPDATE_CONTINUE;
}