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
	ippon = App->audio->LoadFX("Assets/Audio/Fx/Judge/Ippon.wav");
	victory_fx = App->audio->LoadFX("Assets/Audio/Fx/Judge/Victory.wav");
	App->audio->PlayMusic(music,NULL);
	App->player->Enable();
	App->player2->Enable();
	//Colliders for the screen borders
	left_wall = App->collision->AddCollider({ -119,0,50,SCREEN_HEIGHT }, COLLIDER_WALL);
	right_wall= App->collision->AddCollider({ 422,0,50,SCREEN_HEIGHT }, COLLIDER_WALL);
	font = App->fonts->Load("Assets/Textures/UI.png", "9876543210", 1);
	start_time = SDL_GetTicks();
	player1_wins = 0;
	player2_wins = 0;
	time_fight = 96;
	App->render->SetCamera();
	return ret;
}

// Load assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru Scene");
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadFx(ippon);
	App->player->Disable();
	App->player2->Disable();
	App->fonts->UnLoad(font);
	App->audio->UnLoadMusic(music);
	App->collision->CleanUp();
	left_wall = nullptr;
	right_wall = nullptr;
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

	App->render->Blit(graphics, -92, -100, &b, SDL_FLIP_NONE);
	App->fonts->BlitText(177, 40, font, time_text);

	// run out of time
	if (time_fight == 0) {
		if (App->player->life > App->player2->life)
		{
			player1_wins++;
			round_end = true;
		}
		else if (App->player->life == App->player2->life)
		{
			draw++;
			round_end = true;
		}
		else {
			player2_wins++;
			round_end = true;
		}
	}
	// player 1 dies
	if (App->player->life <= 0)
	{
		player2_wins++;
		round_end = true;
	}
	// player 2 dies
	if (App->player2->life <= 0)
	{
		player1_wins++;
		round_end = true;
	}
	// round end
	if ((round_end == true)&&(victory==false))
	{
		App->audio->PlayFX(ippon);
		//victory
		if ((player1_wins == 2)||(player2_wins==2))
		{
			victory = true;
			App->audio->PlayFX(victory_fx);
		}
		//the battle continues
		else
		{
			
			vtransition = true;
			App->player->life = 100;
			App->player->position = App->player->initial_position;
			App->player->state = IDLE;
			App->player2->life = 100;
			App->player2->position = App->player2->initial_position;
			App->player2->state2 = IDLE2;
			time_fight = 96;
			App->ui->animKO_active = false;
			App->render->camera.x = App->render->camera.y= 0;
			App->render->SetCamera();
		}
		round_end = false;
	}
	if (App->input->keyboard[SDL_SCANCODE_F7])
	{
		round_end = true;
		//victory = true;
		App->audio->PlayFX(victory_fx);
	}
	if (vtransition==true)
	{
		if (App->ui->VericalTransition() == false)
		{
			vtransition = false;
			htransition = true;
		}
		else
		{
			App->ui->VericalTransition();
		}

	}
	if (htransition == true)
	{
		if (App->ui->HorizontalTransition()==false)
		{
			htransition = false;
		}
		else
		{
			App->ui->HorizontalTransition();
		}
	}
	App->render->MoveCamera();

	if((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)||(victory==true))
	{
		App->fade->FadeToBlack((Module*)App->scene_haohmaru,(Module*)App->scene_congrats,1.5f);
	}
	return UPDATE_CONTINUE;
}

