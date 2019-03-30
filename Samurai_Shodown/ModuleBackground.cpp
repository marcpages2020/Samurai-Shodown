#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	App->player->Enable();
	background = App->textures->Load("Assets/Textures/background.png");

	soundtrack = App->audio->LoadMusic("Assets/Audio/Music/Wan-Fu.ogg");
	ippon = App->audio->LoadFX("Assets/Audio/Fx/Ippon.wav");

	App->audio->PlayMusic(soundtrack);
	App->audio->PlayFX(ippon);

	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything	
	App->render->Blit(background, -92, -100, NULL);

	return UPDATE_CONTINUE;
}