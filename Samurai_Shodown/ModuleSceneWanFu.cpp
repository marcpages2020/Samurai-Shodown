#include "ModuleSceneWanFu.h"
#include "Application.h"
#include "ModulePlayer2.h"
#include "ModuleHaohmaru.h"
#include "ModuleWanFu.h"
#include "ModuleUI.h"

ModuleSceneWanFu::ModuleSceneWanFu(){
	//background animation
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

ModuleSceneWanFu::~ModuleSceneWanFu()
{}

// Load assets
bool ModuleSceneWanFu::Start()
{
	LOG("Loading Wan-Fu Scene");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprites/Scenes/ChinaSeianWan-Fu.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/Wan-Fu.ogg");
	App->audio->PlayMusic(music, NULL);
	App->player->Enable();
	App->player2->Enable();
	//App->haohmaru->Enable();
	//App->wanfu->Enable();
	left_wall = App->collision->AddCollider({ -90,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_LEFT);
	right_wall = App->collision->AddCollider({ 420,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_RIGHT);
	App->render->SetCamera();
	return ret;
}

// Load assets
bool ModuleSceneWanFu::CleanUp()
{
	LOG("Unloading Wan-Fu stage");
	App->player->Disable();
	App->player2->Disable();
	App->ui->Disable();
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	left_wall = nullptr;
	right_wall = nullptr;
	App->render->left = nullptr;
	App->render->right = nullptr;
	//App->audio->Cle
	return true;
}

update_status ModuleSceneWanFu::Update()
{
	SDL_Rect b;
	b = background.GetCurrentFrame();
	App->render->MoveCamera();

	App->render->Blit(graphics, -60, -100, &b,SDL_FLIP_NONE, 0.75f);
	if (((App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN) || (App->ui->victory == true && !App->ui->die_scene)) || (App->ui->draw >= 3 && !App->ui->die_scene))
	{
		App->fade->FadeToBlack((Module*)App->scene_wanfu, (Module*)App->scene_congrats, 1.5f);
	}
	if ((App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN))
	{
		App->fade->FadeToBlack((Module*)App->scene_wanfu, (Module*)App->scene_haohmaru, 1.5f);
	}

	return UPDATE_CONTINUE;
}