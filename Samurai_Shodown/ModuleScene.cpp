#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

ModuleScene::ModuleScene()
{
	//Haohmaru kick
	Haohmaru.PushBack({1506,167,62,97});
	Haohmaru.PushBack({1578,168,79,98}); 
	Haohmaru.PushBack({1657,170,99,100}); 
	Haohmaru.PushBack({1756,167,110,97}); 
	Haohmaru.PushBack({1866,168,79,98}); 
	Haohmaru.PushBack({1945,167,62,97}); 
	Haohmaru.speed = 0.2f;

}

ModuleScene::~ModuleScene()
{

}

bool ModuleScene::Init() {

	LOG("Loading background assets");
	background = App->textures->Load("Assets/Textures/background.png");
	haohmaruSpreadsheet = App->textures->Load("Assets/Sprites/Characters/Haohmaru/spritesHaohmaru.png");

	soundtrack = App->audio->LoadMusic("Assets/Audio/Music/Wan-Fu.ogg");
	ippon = App->audio->LoadFX("Assets/Audio/Fx/Ippon.wav");

	App->audio->PlayMusic(soundtrack);
	App->audio->PlayFX(ippon);

	return true;
}

update_status ModuleScene::PreUpdate() {
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::Update()
{

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 1210;
	rect.h = SCREEN_HEIGHT;

	// Draw everything	
	App->render->Blit(background, x,y, &rect);
	App->render->Blit(haohmaruSpreadsheet, 300, 600, &(Haohmaru.GetCurrentFrame()));

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp(){
	return true;
}