#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

bool ModuleScene::Init() {
	return true;
}

update_status ModuleScene::PreUpdate() {
	App->textures->Load("background.png");
	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp(){
	return true;
}