#include "ModuleJudge.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include <cmath>

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

	Move();

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

bool ModuleJudge::Move() {
	int* player_1_position;
	int* player_2_position;
	int middle;
	player_1_position = &App->player->position.x;
	player_2_position = &App->player2->position.x;
	if (player_1_position < player_2_position)
	{
		middle = *player_1_position + (player_2_position - player_1_position) / 2;
	}
	else
	{
		middle = *player_2_position + (player_1_position - player_2_position) / 2;
	}
	if ((position_x < middle - 20) || (position_x > middle +20))
	{
		moving = true;
		state_j = MOVE_J;
	}
	if (moving == true)
	{
		if (position_x < middle)
		{
			position_x++;
		}
		else if (position_x > middle)
		{
			position_x--;
		}
		else if (position_x == middle)
		{
			moving = false;
		}
	}

	
}