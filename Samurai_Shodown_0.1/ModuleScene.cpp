#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleRender.h"

ModuleScene::ModuleScene()
{
}

ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init() {

	background = App->textures->Load("background.png");


	return true;
}

update_status ModuleScene::PreUpdate() {
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::Update()
{

	App->render->Blit(background, 300, 300, NULL);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp(){
	return true;
}