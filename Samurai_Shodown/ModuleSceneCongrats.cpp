#include "ModuleSceneCongrats.h"
#include "ModuleFonts.h"
#include "ModuleWindow.h"
#include "ModulePlayer2.h"
#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleUI.h"
#include <time.h>
#include <random>

ModuleSceneCongrats::ModuleSceneCongrats()
{
	//background
	{
		//haohmaru scene
		/*
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
		*/
		
		//wanfu scene
		{
			background.PushBack({ 0,0,504,325 }, 0.18f); //beginning
			background.PushBack({ 512,0,504,325 }, 0.18f);
			background.PushBack({ 1024,0,504,325 }, 0.18f);
			background.PushBack({ 1536,0,504,325 }, 0.18f);
			background.PushBack({ 0,325,504,325 }, 0.18f);
			background.PushBack({ 512,325,504,325 }, 0.18f);
			background.PushBack({ 1024,325,504,325 }, 0.18f);
			background.PushBack({ 1536,325,504,325 }, 0.18f);
			background.PushBack({ 0,650,504,325 }, 0.18f);
			background.PushBack({ 512,650,504,325 }, 0.18f);
			background.PushBack({ 1024,650,504,325 }, 0.18f);
			background.PushBack({ 1536,650,504,325 }, 0.18f);
			background.PushBack({ 0,975,504,325 }, 0.18f);
			background.PushBack({ 512,975,504,325 }, 0.18f);
			background.PushBack({ 1024,975,504,325 }, 0.18f);
			background.PushBack({ 1536,975,504,325 }, 0.18f);
			background.PushBack({ 0,1300,504,325 }, 0.18f);
			background.PushBack({ 512,1300,504,325 }, 0.18f);
			background.PushBack({ 1024,1300,504,325 }, 0.18f);
			background.PushBack({ 1536,1300,504,325 }, 0.18f);
			background.PushBack({ 0,1625,504,325 }, 0.18f);
			background.PushBack({ 0,0,504,325 }, 0.18f); //beginning
			background.PushBack({ 512,0,504,325 }, 0.18f);
			background.PushBack({ 1024,0,504,325 }, 0.18f);
			background.PushBack({ 1536,0,504,325 }, 0.18f);
			background.PushBack({ 0,325,504,325 }, 0.18f);
			background.PushBack({ 512,325,504,325 }, 0.18f);
			background.PushBack({ 1024,325,504,325 }, 0.18f);
			background.PushBack({ 1536,325,504,325 }, 0.18f);
			background.PushBack({ 0,650,504,325 }, 0.18f);
			background.PushBack({ 512,650,504,325 }, 0.18f);
			background.PushBack({ 1024,650,504,325 }, 0.18f);
			background.PushBack({ 1536,650,504,325 }, 0.18f);
			background.PushBack({ 0,975,504,325 }, 0.18f);
			background.PushBack({ 512,975,504,325 }, 0.18f);
			background.PushBack({ 1024,975,504,325 }, 0.18f);
			background.PushBack({ 1536,975,504,325 }, 0.18f);
			background.PushBack({ 0,1300,504,325 }, 0.18f);
			background.PushBack({ 512,1300,504,325 }, 0.18f);
			background.PushBack({ 1024,1300,504,325 }, 0.18f);
			background.PushBack({ 1536,1300,504,325 }, 0.18f);
			background.PushBack({ 0,1625,504,325 }, 0.18f);
			background.PushBack({ 512,1625,504,325 }, 0.18f); //lightning
			background.PushBack({ 1024,1625,504,325 }, 0.18f);
			background.PushBack({ 1536,1625,504,325 }, 0.18f); //lightning
		}
	}

	//judges
	{
		judges.PushBack({23,21,196,85}, 0.4f);
		judges.PushBack({256,21,194,85 }, 0.4f);
		judges.PushBack({23,122,198,85 }, 0.4f);
		judges.PushBack({ 256,122,194,85 }, 0.4f);
	}	
}

ModuleSceneCongrats::~ModuleSceneCongrats()
{
}

bool ModuleSceneCongrats::Start()
{
	LOG("Loading congrats stage assets");
	bool ret = true;
	//background_t = App->textures->Load("Assets/Sprites/Scenes/HaohmaruScene.png"); 
	background_t = App->textures->Load("Assets/Sprites/Scenes/ChinaSeianWan-Fu.png");
	haohmaru = App->textures->Load("Assets/Sprites/Scenes/Haohmaru2.png");
	wanfu = App->textures->Load("Assets/Sprites/Scenes/wan-fu.png");
	judges_t = App->textures->Load("Assets/Sprites/Scenes/judges.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/winning_demo.ogg"); 
	font = App->fonts->Load("Assets/Sprites/UI/white_text.png", "ABCDEFGHIKLMNOPQRSTUVWYZ?/-!:'(), ", 1);
	App->audio->PlayMusic(music,1);
	srand(time(NULL));
	sentence = rand() % 4;
	App->render->camera.x = App->render->camera.y = 0;
	winner_position_x =SCREEN_WIDTH + 100;
	judges_position = -150;
	background_position = -250;
	return ret;
}

update_status ModuleSceneCongrats::Update()
{
	SDL_Rect background_r,judges_r;
	background_r = background.GetCurrentFrame();
	judges_r = judges.GetCurrentFrame();
	App->render->Blit(background_t, background_position, -140, &background_r);
	App->render->Blit(judges_t, judges_position, 80, &judges_r);
	if (winner_position_x > 50)
	{
		winner_position_x -= 5;
	}
	if (judges_position < SCREEN_WIDTH+20)
	{
		judges_position +=3;
	}
	if (background_position < -10)
	{
		background_position += 4;
	}
	//black lines and Haohmaru
	{

		App->render->DrawQuad(up_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		//App->render->Blit(haohmaru, winner_position_x, 23, NULL);
		App->render->Blit(wanfu, winner_position_x, 40, NULL);
		App->render->DrawQuad(left_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		App->render->DrawQuad(right_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		App->render->DrawQuad(down_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		/*
		if ( sentence == 1)
		{
			App->fonts->BlitText(SCREEN_WIDTH / 4-20, (SCREEN_HEIGHT / 5) * 4 , font, "FOR WIMPS LIKE YOU USING");
			App->fonts->BlitText(SCREEN_WIDTH / 4-20, (SCREEN_HEIGHT / 5) * 4+20, font, "MY FULL POWER IS A NO-NO");
		}
		else if (sentence == 0)
		{
			App->fonts->BlitText(SCREEN_WIDTH/4+5, (SCREEN_HEIGHT / 5) * 4, font, "TO CALL ME 'AWESOME'");
			App->fonts->BlitText(SCREEN_WIDTH / 4, (SCREEN_HEIGHT / 5) * 4+20, font, "IS AN UNDERSTATEMENT");
		}
		*/
		if (sentence == 0)
		{
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 20, (SCREEN_HEIGHT / 5) * 4, font, "FOR EVERYONE TO REMEMBER:");
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 20, (SCREEN_HEIGHT / 5) * 4 + 20, font, "I AM WAN-FU, HEAR ME ROAR");
		}
		if (sentence == 1)
		{
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 30, (SCREEN_HEIGHT / 5) * 4, font, "GOODBYE, BROTHERS. FORGET");
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 30, (SCREEN_HEIGHT / 5) * 4 + 20, font, "ME NOT IN THAT ETERNAL SLEEP");
		}
		if (sentence == 2)
		{
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 20, (SCREEN_HEIGHT / 5) * 4, font, "I THOUGHT I WAS DEAD. BUT");
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 20, (SCREEN_HEIGHT / 5) * 4 + 20, font, "I THINK I'M CLEOPATRA, TOO");
		}
		if (sentence == 3)
		{
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 40, (SCREEN_HEIGHT / 5) * 4, font, "THINK OF THE GLORY, CUT ME");
			App->fonts->BlitText(SCREEN_WIDTH / 4 - 40, (SCREEN_HEIGHT / 5) * 4 + 20, font, "DOWN AND LIVE FOREVER IN LEGEND");
		}

		if (right_black_square.w > 0)
		{
			left_black_square.w -= 5;
			right_black_square.x += 5;
		}
	}
	if (App->ui->player1_wins == 2) {
		App->fonts->BlitText(120, 20, font, "PLAYER ONE WINS");
	}
	else if (App->ui->player2_wins == 2)
	{
		App->fonts->BlitText(120, 20, font, "PLAYER TWO WINS");
	}
	else
	{
		App->fonts->BlitText(100, 20, font, "IT LOOKS LIKE A DRAW");
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][GAME_PAD_1] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][GAME_PAD_2] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_congrats, (Module*)App->neo_geo,2.5f);
	}
	return UPDATE_CONTINUE;
}

bool ModuleSceneCongrats::CleanUp()
{
	LOG("Unloading Congrats stage");
	App->player->Disable();
	App->textures->Unload(background_t);
	App->textures->Unload(haohmaru);
	App->textures->Unload(judges_t);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	App->fonts->UnLoad(font);
	background.Reset();
	judges.Reset();
	App->player->life = 100;
	App->player2->life = 100;
	App->ui->victory = false;
	App->scene_haohmaru->start_time = 0.0F;
	return true;
}