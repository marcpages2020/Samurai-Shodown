#include "ModuleJudge.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include <cmath>

ModuleJudge::ModuleJudge() {

	//idle
	{
		idle.PushBack({ 455, 267, 58, 70 }, 0.5f);
		idle.loop = true;
	}
	   
	
	//move right
	{
		moveright.PushBack({ 44, 268, 58, 69 }, 0.5f);
		moveright.PushBack({ 122, 267, 58, 70 }, 0.5f);
		moveright.PushBack({ 201, 267, 58, 70 }, 0.5f);
		moveright.PushBack({ 286, 271, 66, 66 }, 0.5f);
		moveright.PushBack({ 369, 270, 60, 67 }, 0.5f);
		moveright.PushBack({ 455, 267, 58, 70 }, 0.5f);
		moveright.loop = true;
	}


	//move left
	{
		moveleft.PushBack({ 44, 268, 58, 69 }, 0.5f);
		moveleft.PushBack({ 723, 267, 58, 70}, 0.5f);
		moveleft.PushBack({ 798, 267, 58, 70}, 0.5f);
		moveleft.PushBack({ 455, 267, 58, 70 }, 0.5f);
		moveleft.loop = true;
	}


	//start
	{
		start.PushBack({ 45, 125, 40, 76}, 0.5f);
		start.PushBack({ 106, 128, 38, 73}, 0.5f);
		start.PushBack({ 161, 137, 38, 64}, 0.5f);
		start.PushBack({ 221, 143, 36, 58}, 0.5f);
		start.PushBack({ 286, 143, 34, 58}, 0.5f);
		start.PushBack({ 221, 143, 36, 58}, 0.5f);
		start.PushBack({ 161, 137, 38, 64}, 0.5f);
		start.PushBack({ 106, 128, 38, 73}, 0.5f);
		start.PushBack({ 45, 125, 40, 76}, 0.5f);
		start.PushBack({ 579, 125, 45, 75}, 0.5f);
		start.PushBack({ 455, 267, 58, 70}, 0.5f);
		start.PushBack({ 710, 130, 58, 70}, 0.5f);
		start.PushBack({ 782, 130, 58, 70}, 0.5f);
		start.PushBack({ 710, 130, 58, 70 }, 0.5f);
		start.PushBack({ 455, 267, 58, 70 }, 0.5f);
		start.PushBack({ 924, 130, 58, 70}, 0.5f);
		start.PushBack({ 991, 130, 58, 70}, 0.5f);
		start.PushBack({ 924, 130, 58, 70}, 0.5f);
		start.PushBack({ 455, 267, 58, 70}, 0.5f);
		start.PushBack({ 1059, 114, 72, 86}, 0.5f);
		start.PushBack({ 1154, 87, 36, 113}, 0.5f);
		start.PushBack({ 1213, 80, 36, 120}, 0.5f);
		start.PushBack({ 1270, 78, 36, 122}, 0.5f);
		start.PushBack({ 1213, 80, 36, 120 }, 0.5f);
		start.PushBack({ 1154, 87, 36, 113 }, 0.5f);
		start.PushBack({ 1441, 156, 78, 44}, 0.5f);
		start.PushBack({ 1532, 139, 64, 61}, 0.5f);
		start.PushBack({ 455, 267, 58, 70 }, 0.5f);
		start.loop = false;
	}


	//player1 hit
	{
		hit1.PushBack({ 1013, 267, 51, 70}, 0.5f);
		hit1.PushBack({ 1083, 267, 51, 70}, 0.5f);
		hit1.PushBack({ 1146, 246, 81, 92}, 0.5f);
		hit1.PushBack({ 1232, 246, 78, 91}, 0.5f);
		hit1.PushBack({ 1316, 246, 73, 91}, 0.5f);
		hit1.PushBack({ 1394, 257, 70, 80}, 0.5f);
		hit1.loop = false;
	}


	//player2 hit
	{
		hit2.PushBack({ 1530, 267, 51, 70 }, 0.5f);
		hit2.PushBack({ 1594, 267, 51, 70 }, 0.5f);
		hit2.PushBack({ 1661, 245, 81, 91 }, 0.5f);
		hit2.PushBack({ 1749, 246, 78, 91 }, 0.5f);
		hit2.PushBack({ 1833, 246, 73, 91 }, 0.5f);
		hit2.PushBack({ 1920, 257, 70, 80 }, 0.5f);
		hit2.loop = false;
	}


	//finish animation
	{
		finish.PushBack({ 1059, 114, 72, 86 }, 0.5f);
		finish.PushBack({ 125, 378, 42, 75}, 0.5f);
		finish.PushBack({ 188, 368, 32, 85}, 0.5f);
		finish.PushBack({ 248, 368, 38, 85}, 0.5f);
		finish.PushBack({ 188, 368, 32, 85 }, 0.5f);
		finish.PushBack({ 248, 368, 38, 85 }, 0.5f);
		finish.PushBack({ 188, 368, 32, 85 }, 0.5f);
		finish.PushBack({ 248, 368, 38, 85 }, 0.5f);
		finish.PushBack({ 45, 125, 40, 76 }, 0.5f);
		finish.PushBack({ 106, 128, 38, 73 }, 0.5f);
		finish.PushBack({ 161, 137, 38, 64 }, 0.5f);
		finish.PushBack({ 221, 143, 36, 58 }, 0.5f);
		finish.PushBack({ 286, 143, 34, 58 }, 0.5f);
		finish.PushBack({ 221, 143, 36, 58 }, 0.5f);
		finish.PushBack({ 161, 137, 38, 64 }, 0.5f);
		finish.PushBack({ 106, 128, 38, 73 }, 0.5f);
		finish.PushBack({ 45, 125, 40, 76 }, 0.5f);
		finish.loop = false;
	}



}

ModuleJudge::~ModuleJudge(){}

bool ModuleJudge::Start() {
	bool ret = true;
	LOG("Loading Judge\n");
	position_x = 60;
	position_y = 200;
	judge_tex = App->textures->Load("Assets/Sprites/Characters/Judge/Judge.png");
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