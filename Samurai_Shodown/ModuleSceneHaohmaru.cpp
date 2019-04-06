#include "ModuleSceneHaohmaru.h"
#include "ModuleCollision.h"
#include "Application.h"

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

	//Colliders for the screen borders
	App->collision->AddCollider({ -160,0,50,1000 }, COLLIDER_WALL);
	App->collision->AddCollider({ 430,0,50,1000 }, COLLIDER_WALL);

	return ret;
}

// Load assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru stage");
	App->player->Disable();
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	//App->audio->CleanUp();
	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{
	SDL_Rect b;
	// Draw everything --------------------------------------	
	b = background.GetCurrentFrame();

	App->render->Blit(graphics,-92,-100,&b,0.75f);
	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_haohmaru,(Module*)App->scene_kyoshiro,2.5);
	}

	return UPDATE_CONTINUE;
}