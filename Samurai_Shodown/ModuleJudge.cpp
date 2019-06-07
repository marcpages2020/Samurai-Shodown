#include "ModuleJudge.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"

ModuleJudge::ModuleJudge() {
	//animations
	{
		//idle
		{
			idle.PushBack({ 455, 267, 58, 70 }, 0.5f);
			idle.loop = true;
		}


		//move right
		{
			move_right.PushBack({ 44, 268, 58, 69 }, 0.3f);
			move_right.PushBack({ 122, 267, 58, 70 }, 0.3f);
			move_right.PushBack({ 201, 267, 58, 70 }, 0.3f);
			move_right.PushBack({ 286, 271, 66, 66 }, 0.3f);
			move_right.PushBack({ 369, 270, 60, 67 }, 0.3f);
			move_right.PushBack({ 455, 267, 58, 70 }, 0.3f);
			move_right.loop = true;
		}


		//move left
		{
			move_left.PushBack({ 44, 268, 58, 69 }, 0.3f);
			move_left.PushBack({ 723, 267, 58, 70 }, 0.3f);
			move_left.PushBack({ 798, 267, 58, 70 }, 0.3f);
			move_left.PushBack({ 455, 267, 58, 70 }, 0.3f);
			move_left.loop = true;
		}


		//begin
		{
			begin_j.PushBack({ 45, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 106, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 161, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 221, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 286, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 221, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 161, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 106, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 45, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 579, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 455, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 710, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 782, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 710, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 455, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 924, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 991, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 924, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 455, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1059, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1154, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1213, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1270, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1213, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1154, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1441, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 1532, 78, 73, 123 }, 0.2f);
			begin_j.PushBack({ 455, 78, 73, 123 }, 0.2f);
			begin_j.loop = false;
			
		}


		//player1 hit
		{
			hit1.PushBack({ 1013, 267, 51, 70 }, 0.5f);
			hit1.PushBack({ 1083, 267, 51, 70 }, 0.5f);
			hit1.PushBack({ 1146, 246, 81, 92 }, 0.5f);
			hit1.PushBack({ 1232, 246, 78, 91 }, 0.5f);
			hit1.PushBack({ 1316, 246, 73, 91 }, 0.5f);
			hit1.PushBack({ 1394, 257, 70, 80 }, 0.5f);
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
			finish.PushBack({ 125, 378, 42, 75 }, 0.5f);
			finish.PushBack({ 188, 368, 32, 85 }, 0.5f);
			finish.PushBack({ 248, 368, 38, 85 }, 0.5f);
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

}

ModuleJudge::~ModuleJudge(){}

bool ModuleJudge::Start() {
	bool ret = true;
	LOG("Loading Judge\n");
	position_x = SCREEN_WIDTH/2-35;
	position_y = 110;
	judge_tex = App->textures->Load("Assets/Sprites/Characters/Judge/Judge.png");
	state_j = IDLE_J;
	current_animation = &idle;
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
		if (state_j == BEGIN_J)
		{
			if (current_animation->Finished())
			{
				state_j = IDLE_J;
				begin_j.Reset();
			}
		}
		if (state_j == HIT1_J)
		{
			if (current_animation->Finished())
			{
				state_j = IDLE_J;
				hit1.Reset();
			}
		}
		if (state_j == HIT2_J)
		{
			if (current_animation->Finished())
			{
				state_j = IDLE_J;
				hit2.Reset();
			}
		}
		if ((state_j != BEGIN_J)&&(state_j != HIT1_J) && (state_j != HIT2_J))
		{
			Move();
		}
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
		case MOVE_LEFT_J:
			current_animation = &move_left;
			break;
		case MOVE_RIGHT_J:
			current_animation = &move_right;
			break;
		case BEGIN_J:
			current_animation = &begin_j;
			break;
		case HIT1_J:
			current_animation = &hit1;
			break;
		case HIT2_J:
			current_animation = &hit2;
			break;
		default:
			break;
		}
	}
	App->render->Blit(judge_tex, position_x, position_y, &current_animation->GetCurrentFrame());
	return UPDATE_CONTINUE;
}

void ModuleJudge::Move() {

	int player_1_position;
	int player_2_position;
	int middle;

	player_1_position = App->player->position.x;
	player_2_position = App->player2->position.x;

	if (player_1_position < player_2_position)
	{
		middle = player_1_position + (player_2_position - player_1_position) / 2;
	}
	else
	{
		middle = player_2_position + (player_1_position - player_2_position) / 2;
	}
	if (position_x < middle - 30)
	{
		moving = true;
		state_j = MOVE_RIGHT_J;
	}
	else if (position_x > middle + 30)
	{
		moving = true;
		state_j = MOVE_LEFT_J;
	}
	if (moving == true)
	{
		if ((position_x == middle) || (position_x == middle + 1))
		{
			moving = false;
			state_j = IDLE_J;
		}
		else if (position_x < middle)
		{
			position_x += speed;
		}
		else if (position_x > middle)
		{
			position_x -= speed;
		}
	}

	
}