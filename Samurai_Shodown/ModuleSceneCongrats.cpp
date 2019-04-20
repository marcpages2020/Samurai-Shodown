#include "ModuleSceneCongrats.h"
#include "ModuleWindow.h"

ModuleSceneCongrats::ModuleSceneCongrats()
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

	position.x = 500;
}

ModuleSceneCongrats::~ModuleSceneCongrats()
{
}

// Load assets
bool ModuleSceneCongrats::Start()
{
	LOG("Loading congrats stage assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/Textures/HaohmaruScene.png"); 
	haohmaru = App->textures->Load("Assets/Textures/Scenes/Congrats_Scene/Haohmaru2.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/winning_demo.ogg"); 
	App->audio->PlayMusic(music,NULL);
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
	SDL_Rect background_r;
	background_r = background.GetCurrentFrame();
	App->render->Blit(graphics, NULL, -100, &background_r);
	App->render->Blit(haohmaru, 40, 20, NULL);
	App->render->DrawQuad(left_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
	App->render->DrawQuad(right_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
	App->render->DrawQuad(up_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
	App->render->DrawQuad(down_black_square, 0, 0, 0, SDL_ALPHA_OPAQUE, false);
	SDL_RenderPresent(App->render->renderer);
	if (right_black_square.w > 0)
	{
		left_black_square.w -= 10;
		right_black_square.x += 10;
	}
	


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_congrats, (Module*)App->neo_geo, 2.5);
	}
	return UPDATE_CONTINUE;
}