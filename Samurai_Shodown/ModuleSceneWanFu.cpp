#include "ModuleSceneWanFu.h"
#include "Application.h"
#include "ModulePlayer2.h"

ModuleSceneWanFu::ModuleSceneWanFu(){
	//background animation
	{/*
		background.PushBack({ 0,0,504,325 }, 0.08f);
		background.PushBack({ 504,103,504,325 }, 0.08f);		
		background.PushBack({ 1008,206,504,325 }, 0.08f);
		background.PushBack({ 1512,309,504,325 }, 0.08f);
		background.PushBack({ 325,325,504,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,325 }, 0.08f);
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);		
		background.PushBack({ ,,,103 }, 0.08f);	*/	

		/*
		x	y	w	h
0	0	504	325
504	0	504	325
1008	0	504	325
1512	0	504	325
325	325	504	325
829	325	504	325
1333	325	504	325
1837	325	504	325
650	650	504	325
1154	650	504	325
1658	650	504	325
2162	650	504	325
975	975	504	325
1479	975	504	325
1983	975	504	325
2487	975	504	325
1300	1300	504	325
1804	1300	504	325
2308	1300	504	325
2812	1300	504	325
1625	1625	504	325
2129	1625	504	325
2633	1625	504	325
3137	1625	504	325

		*/
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
	music = App->audio->LoadMusic("Assets/Audio/Music/Kyoshiro.ogg");
	App->audio->PlayMusic(music, NULL);
	App->player->Enable();
	App->player2->Enable();
	left_wall = App->collision->AddCollider({ -121,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_LEFT);
	right_wall = App->collision->AddCollider({ 390,0,50,SCREEN_HEIGHT }, COLLIDER_WALL_RIGHT);
	return ret;
}

// Load assets
bool ModuleSceneWanFu::CleanUp()
{
	LOG("Unloading Wan-Fu stage");
	App->player->Disable();
	App->player2->Disable();
	App->textures->Unload(graphics);
	Mix_FadeOutMusic(1250);
	App->audio->UnLoadMusic(music);
	App->collision->CleanUp();
	//App->audio->CleanUp();
	return true;
}

update_status ModuleSceneWanFu::Update()
{
	SDL_Rect b;
	// Draw everything --------------------------------------	
	b = background.GetCurrentFrame();
	App->render->Blit(graphics, -60, -100, &b,SDL_FLIP_NONE, 0.75f);
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_wanfu, (Module*)App->scene_congrats, 2.5);
	}
	if ((App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN))
	{
		App->fade->FadeToBlack((Module*)App->scene_wanfu, (Module*)App->scene_haohmaru, 1.5f);
	}

	return UPDATE_CONTINUE;
}