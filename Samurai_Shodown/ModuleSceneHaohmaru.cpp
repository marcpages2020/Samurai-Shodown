#include "ModuleSceneHaohmaru.h"
#include "ModuleCollision.h"
#include "Application.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
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
	ippon = App->audio->LoadFX("Assets/Audio/Fx/Ippon.wav");
	App->audio->PlayMusic(music,NULL);
	App->player->Enable();
	App->player2->Enable();
	//Colliders for the screen borders
	App->collision->AddCollider({ -165,0,50,SCREEN_HEIGHT }, COLLIDER_WALL);
	App->collision->AddCollider({ 427,0,50,SCREEN_HEIGHT }, COLLIDER_WALL);
	font = App->fonts->Load("Assets/Textures/UI.png", "9876543210", 1);
	start_time = SDL_GetTicks();
	player1_wins = 0;
	player2_wins = 0;
	return ret;
}

// Load assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru stage");
	App->player->Disable();
	App->player2->Disable();
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	App->collision->CleanUp();
	//App->audio->CleanUp();
	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{
	SDL_Rect b;
	// Draw everything --------------------------------------	
	b = background.GetCurrentFrame();
	
	if (!App->is_paused) {
		if (start_time <= SDL_GetTicks() - 1000 && time_fight > 0) {
			--time_fight;
			start_time = SDL_GetTicks();
		}
	}

	sprintf_s(time_text, 10, "%7d", time_fight);

	App->render->Blit(graphics, -92, -100, &b, SDL_FLIP_NONE, 0.75f);

	App->fonts->BlitText(160, 25, font, time_text);

	if (time_fight == 0) {
		if (App->player->life > App->player2->life)
		{
			player1_wins++;
		}
		else if (App->player->life == App->player2->life)
		{
			draw++;
		}
		else {
			player2_wins++;
		}
	}
	if (App->player->life <= 0)
	{
		player2_wins++;
		round_end = true;
	}
	if (App->player2->life <= 0)
	{
		player1_wins++;
		round_end = true;
	}
	
	if (round_end == true)
	{
		App->audio->PlayFX(ippon);
		if ((player1_wins == 2)||(player2_wins==2))
		{
			victory = true;
		}
		else
		{
			App->player->life = 100;
			App->player2->life = 100;
		}
		round_end = false;
	}

	if((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)||(victory==true))
	{
		App->fade->FadeToBlack((Module*)App->scene_haohmaru,(Module*)App->scene_kyoshiro,2.5);
	}
	return UPDATE_CONTINUE;
}