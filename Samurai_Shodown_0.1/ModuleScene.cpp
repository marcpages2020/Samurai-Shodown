#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

ModuleScene::ModuleScene()
{
}

ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init() {

	background = App->textures->Load("background.png");
	//App->audio->PlaySong("Level1.ogg");
	//App->audio->PlayFX("Ippon.wav");
	return true;
}

update_status ModuleScene::PreUpdate() {
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::Update()
{
	
	App->render->Blit(background, x,y, NULL);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp(){
	return true;
}