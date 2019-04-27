#include "ModuleSceneHaohmaru.h"
#include "ModuleCollision.h"
#include "Application.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleUI.h"
#include <iostream>

ModuleSceneHaohmaru::ModuleSceneHaohmaru()
{
	//background animation
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
}

ModuleSceneHaohmaru::~ModuleSceneHaohmaru()
{}

// Load assets
bool ModuleSceneHaohmaru::Start()
{
	LOG("Loading Haohmaru Scene");
	bool ret = true;
	graphics = App->textures->Load("Assets/Textures/HaohmaruScene.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/Haohmaru.ogg");
	App->audio->PlayMusic(music,NULL);
	App->player->Enable();
	App->player2->Enable();
	App->ui->Enable();
	left_wall = App->collision->AddCollider({ -121,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_LEFT);
	right_wall= App->collision->AddCollider({ 390,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_RIGHT);
	App->ui->start_time = SDL_GetTicks();
	App->render->SetCamera();
	return ret;
}

// Load assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru Scene");
	App->textures->Unload(graphics);
	App->audio->UnLoadMusic(music);
	Mix_FadeOutMusic(1250);
	App->player->Disable();
	App->player2->Disable();
	App->ui->Disable();
	left_wall = nullptr;
	right_wall = nullptr;
	App->render->left = nullptr;
	App->render->right = nullptr;
	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{
	SDL_Rect b;
	// Draw everything --------------------------------------	
	b = background.GetCurrentFrame();

	App->render->Blit(graphics, -92, -100, &b, SDL_FLIP_NONE);
	App->render->MoveCamera();

	if(((App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)||(App->ui->victory==true && !App->ui->die_scene))||(App->ui->draw==3 && !App->ui->die_scene))
	{
		App->fade->FadeToBlack((Module*)App->scene_haohmaru,(Module*)App->scene_congrats,1.5f);
	}
	if ((App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN))
	{
		App->fade->FadeToBlack((Module*)App->scene_haohmaru, (Module*)App->scene_kyoshiro, 1.5f);
	}
	return UPDATE_CONTINUE;
}
