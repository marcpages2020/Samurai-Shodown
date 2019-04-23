#include "ModuleSceneCongrats.h"
#include "ModuleFonts.h"
#include "ModuleWindow.h"
#include "ModulePlayer2.h"
#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleSceneHaohmaru.h"
#include <time.h>
#include <random>

ModuleSceneCongrats::ModuleSceneCongrats()
{
	//background
	{
		background.PushBack({ 0,0,512,333 }, 0.15f); //0
		background.PushBack({ 512,0,512,333 }, 0.15f);
		background.PushBack({ 1024,0,512,333 }, 0.15f);
		background.PushBack({ 1536,0,512,333 }, 0.15f);
		background.PushBack({ 0,333,512,333 }, 0.15f); //512
		background.PushBack({ 512,333,512,333 }, 0.15f);
		background.PushBack({ 1024,333,512,333 }, 0.15f);
		background.PushBack({ 1536,333,512,333 }, 0.15f);
		background.PushBack({ 0,666,512,333 }, 0.15f); //1024
		background.PushBack({ 512,666,512,333 }, 0.15f);
		background.PushBack({ 1024,666,512,333 }, 0.15f);
		background.PushBack({ 1536,666,512,333 }, 0.15f);
		background.PushBack({ 0,999,512,333 }, 0.15f); //1536
		background.PushBack({ 512,999,512,333 }, 0.15f);
		background.PushBack({ 1024,999,512,333 }, 0.15f);
		background.PushBack({ 1536,999,512,333 }, 0.15f);
		background.PushBack({ 0,1332,512,333 }, 0.15f); //2048
		background.PushBack({ 512,1332,512,333 }, 0.15f);
		background.PushBack({ 1024,1332,512,333 }, 0.15f);
		background.PushBack({ 1536,1332,512,333 }, 0.15f);
		background.PushBack({ 0,1665,512,333 }, 0.15f); //2560
		background.PushBack({ 512,1665,512,333 }, 0.15f);
		background.PushBack({ 1024,1665,512,333 }, 0.15f);
		background.PushBack({ 1536,1665,512,333 }, 0.15f);
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
	background_t = App->textures->Load("Assets/Textures/HaohmaruScene.png"); 
	haohmaru = App->textures->Load("Assets/Textures/Scenes/Congrats_Scene/Haohmaru2.png");
	judges_t = App->textures->Load("Assets/Textures/Scenes/Congrats_Scene/judges.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/winning_demo.ogg"); 
	font = App->fonts->Load("Assets/Sprites/UI/white_text.png", "ABCDEFGHIKLMNOPQRSTUVWYZ?/-! ", 1);
	App->audio->PlayMusic(music,1);
	srand(time(NULL));
	sentence = rand() % 2;
	App->render->camera.x = App->render->camera.y = 0;
	hao_position = SCREEN_WIDTH + 100;
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
	if (hao_position > 50)
	{
		hao_position -= 10;
	}

	if (judges_position < SCREEN_WIDTH+20)
	{
		judges_position +=4;
	}
	if (background_position < -10)
	{
		background_position += 8;
	}
	//black lines and Haohmaru
	{

		App->render->DrawQuad(up_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		App->render->Blit(haohmaru, hao_position, 23, NULL);
		App->render->DrawQuad(left_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		App->render->DrawQuad(right_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		App->render->DrawQuad(down_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
		if ( sentence == 1)
		{
			App->fonts->BlitText(SCREEN_WIDTH / 4-20, (SCREEN_HEIGHT / 5) * 4 , font, "FOR WIMPS LIKE YOU USING");
			App->fonts->BlitText(SCREEN_WIDTH / 4-20, (SCREEN_HEIGHT / 5) * 4+20, font, "MY FULL POWER IS A NO-NO");
		}
		else if (sentence == 0)
		{
			App->fonts->BlitText(SCREEN_WIDTH/4, (SCREEN_HEIGHT / 5) * 4 , font, "TO CALL ME 'AWESOME'");
			App->fonts->BlitText(SCREEN_WIDTH / 4, (SCREEN_HEIGHT / 5) * 4+20, font, "IS AN UNDERSTATEMENT");
		}

		SDL_RenderPresent(App->render->renderer);

		if (right_black_square.w > 0)
		{
			left_black_square.w -= 10;
			right_black_square.x += 10;
		}
	}
	

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_congrats, (Module*)App->neo_geo, 2.5);
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
	App->audio->CleanUp();
	App->fonts->UnLoad(font);
	background.Reset();
	judges.Reset();
	App->player->life = 100;
	App->player2->life = 100;
	App->scene_haohmaru->victory = false;
	App->scene_haohmaru->start_time = 0.0F;
	return true;
}