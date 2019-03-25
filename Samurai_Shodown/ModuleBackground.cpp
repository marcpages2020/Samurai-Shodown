#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	Haohmaru.PushBack({ 1506,167,62,97 });
	Haohmaru.PushBack({ 1578,168,79,98 });
	Haohmaru.PushBack({ 1657,170,99,100 });
	Haohmaru.PushBack({ 1756,167,110,97 });
	Haohmaru.PushBack({ 1866,168,79,98 });
	Haohmaru.PushBack({ 1945,167,62,97 });
	Haohmaru.speed = 0.2f;

}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	background = App->textures->Load("Assets/Textures/background.png");
	haohmaruSpreadsheet = App->textures->Load("Assets/Sprites/Characters/Haohmaru/spritesHaohmaru.png");

	soundtrack = App->audio->LoadMusic("Assets/Audio/Music/Wan-Fu.ogg");
	ippon = App->audio->LoadFX("Assets/Audio/Fx/Ippon.wav");

	App->audio->PlayMusic(soundtrack);
	App->audio->PlayFX(ippon);

	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------



	// Draw everything	
	App->render->Blit(background, -92, -100y, NULL);
	App->render->Blit(haohmaruSpreadsheet, 300, 600, &(Haohmaru.GetCurrentFrame()));


	return UPDATE_CONTINUE;
}