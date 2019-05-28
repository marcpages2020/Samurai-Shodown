#include "ModuleJudge.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

ModuleJudge::ModuleJudge() {
	
	//idle

}

ModuleJudge::~ModuleJudge(){}

bool ModuleJudge::Start() {
	bool ret = true;
	LOG("Loading Judge\n");
	position_x = 60;
	position_y = 200;
	judge_tex = App->textures->Load("");
	player_1_position = &App->player->position.x;
	player_2_position = &App->player2->position.x;
	state_j = IDLE_J;
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
		/*
		if (state == IDLE)
		{
			if () {
				state = MOVE;
			}
		}
		*/
	}
	return UPDATE_CONTINUE;
}

update_status ModuleJudge::Update() {
	if (!App->is_paused)
	{
		switch (state_j)
		{
		case IDLE_J:
			current_animation = &idle;
			break;
		case MOVE_J:
			current_animation = &move;
			break;
		default:
			break;
		}
	}
	return UPDATE_CONTINUE;
}