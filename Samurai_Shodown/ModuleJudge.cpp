#include "ModuleJudge.h"
#include "ModuleTextures.h"


ModuleJudge::ModuleJudge() {

}

ModuleJudge::~ModuleJudge(){}

bool ModuleJudge::Start() {
	bool ret = true;
	LOG("Loading Judge\n");
	position_x = 60;
	position_y = 200;
	judge_tex = App->textures->Load("");
	state = IDLE;
	return ret;
}

bool ModuleJudge::CleanUp() {
	LOG("Unloading Judge\n");
	App->textures->Unload(judge_tex);
	return true;
}

update_status ModuleJudge::PreUpdate() {
	if (!App->is_paused)
	{

	}
}

update_status ModuleJudge::Update() {
	if (!App->is_paused)
	{
		switch (state)
		{
		case IDLE:
			current_animation = &idle;
			break;
		case MOVE:
			current_animation = &move;
			break;
		default:
			break;
		}
	}
}