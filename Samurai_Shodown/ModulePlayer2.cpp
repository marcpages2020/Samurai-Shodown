#include "ModulePlayer2.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleUI.h"

ModulePlayer2::ModulePlayer2()
{
	//animations
	{
		//idle animation
		{
			idle2.PushBack({ 16,22,71,109 }, 0.3f);
			idle2.PushBack({ 92,22,72,109 }, 0.3f);
			idle2.PushBack({ 168,22,71,109 }, 0.3f);
			idle2.PushBack({ 245,20,72,111 }, 0.3f);
			idle2.PushBack({ 322,18,72,113 }, 0.3f);
			idle2.PushBack({ 399,19,72,112 }, 0.3f);
			idle2.PushBack({ 476,19,74,112 }, 0.3f);
			idle2.PushBack({ 554,19,74,112 }, 0.3f);
			idle2.PushBack({ 630,19,73,112 }, 0.3f);
			idle2.PushBack({ 245,20,72,111 }, 0.3f);
			idle2.PushBack({ 322,18,72,113 }, 0.3f);
			idle2.PushBack({ 399,19,72,112 }, 0.3f);
		}

		//forward animation
		{
			forward2.PushBack({ 15,496,70,112 }, 0.4f);
			forward2.PushBack({ 89,496,70,112 }, 0.4f);
			forward2.PushBack({ 163,499,76,109 }, 0.4f);
			forward2.PushBack({ 243,499,76,109 }, 0.4f);
			forward2.PushBack({ 322,499,76,109 }, 0.4f);
			forward2.PushBack({ 402,496,69,112 }, 0.4f);
			forward2.PushBack({ 475,496,69,112 }, 0.4f);
			forward2.PushBack({ 548,496,69,112 }, 0.4f);
			forward2.PushBack({ 621,492,59,116 }, 0.4f);
			forward2.PushBack({ 684,492,59,116 }, 0.4f);
			forward2.PushBack({ 747,492,59,116 }, 0.4f);
			forward2.PushBack({ 810,492,57,116 }, 0.4f);
			forward2.PushBack({ 871,490,57,118 }, 0.4f);
			forward2.PushBack({ 933,490,56,118 }, 0.4f);
			forward2.PushBack({ 994,490,61,118 }, 0.4f);
			forward2.PushBack({ 1060,492,61,116 }, 0.4f);
			forward2.PushBack({ 1126,492,61,116 }, 0.4f);
		}

		//backward animation
		{
			backward2.PushBack({ 624,608,82,121 }, 0.4f);//9
			backward2.PushBack({ 711,608,82,121 }, 0.4f);//10
			backward2.PushBack({ 798,608,82,121 }, 0.4f);//11
			backward2.PushBack({ 884,608,82,121 }, 0.4f);//12
			backward2.PushBack({ 15,614,74,114 }, 0.4f); //1
			backward2.PushBack({ 94,614,74,114 }, 0.4f); //2
			backward2.PushBack({ 173,614,74,114 }, 0.4f); //3 
			backward2.PushBack({ 264,610,68,118 }, 0.4f); //4
			backward2.PushBack({ 337,610,68,118 }, 0.4f); //5
			backward2.PushBack({ 410,612,68,117 }, 0.4f); //6
			backward2.PushBack({ 482,609,67,121 }, 0.4f);//7
			backward2.PushBack({ 553,608,67,121 }, 0.4f);//8
			backward2.PushBack({ 971,608,69,122 }, 0.4f);//13
			backward2.PushBack({ 1045,608,69,121 }, 0.4f);//14
			backward2.PushBack({ 1119,608,69,120 }, 0.4f);//15
			backward2.PushBack({ 1193,614,74,114 }, 0.4f);//16
			backward2.PushBack({ 1272,614,74,114 }, 0.4f);//17
			backward2.PushBack({ 1351,614,74,114 }, 0.4f);//18
		}

		//jump animation
		{
			jump_neutral2.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
			jump_neutral2.PushBack({ 80, 371, 60, 112 }, 0.2f); //2
			jump_neutral2.PushBack({ 145, 371, 60, 112 }, 0.2f); //3
			jump_neutral2.PushBack({ 209, 371, 75, 92 }, 0.2f);
			jump_neutral2.PushBack({ 288, 371, 75, 92 }, 0.2f);
			jump_neutral2.PushBack({ 367, 371, 75, 92 }, 0.2f);
			jump_neutral2.PushBack({ 446, 371, 78, 83 }, 0.2f);
			jump_neutral2.PushBack({ 209, 371, 75, 92 }, 0.2f);
			jump_neutral2.PushBack({ 288, 371, 75, 92 }, 0.2f);
			jump_neutral2.PushBack({ 367, 371, 75, 92 }, 0.2f);
			jump_neutral2.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
			jump_neutral2.PushBack({ 80, 371, 60, 112 }, 0.2f);
			jump_neutral2.PushBack({ 145, 371, 60, 112 }, 0.2f);
			jump_neutral2.PushBack({ 527, 371, 68, 112 }, 0.2f); //8
			jump_neutral2.PushBack({ 601, 371, 68, 112 }, 0.2f); //9
			jump_neutral2.PushBack({ 674, 371, 68, 112 }, 0.2f); //10
		}

		//jump forward animation
		{
			jump_forward2.PushBack({ 15, 1362, 63, 130 }, 0.3f);
			jump_forward2.PushBack({ 83, 1362, 63, 130 }, 0.3f);
			jump_forward2.PushBack({ 151, 1362, 63, 130 }, 0.3f);
			jump_forward2.PushBack({ 224, 1362, 74, 93 }, 0.3f);
			jump_forward2.PushBack({ 307, 1362, 74, 93 }, 0.3f);
			jump_forward2.PushBack({ 391, 1362, 74, 93 }, 0.3f);
			jump_forward2.PushBack({ 478, 1362, 62, 81 }, 0.3f);
			jump_forward2.PushBack({ 559, 1362, 62, 81 }, 0.3f);
			jump_forward2.PushBack({ 631, 1362, 62, 81 }, 0.3f);
			jump_forward2.PushBack({ 706, 1362, 80, 62 }, 0.3f);
			jump_forward2.PushBack({ 799, 1362, 80, 62 }, 0.3f);
			jump_forward2.PushBack({ 888, 1362, 80, 62 }, 0.3f);
			jump_forward2.PushBack({ 981, 1362, 62, 81 }, 0.3f);
			jump_forward2.PushBack({ 1066, 1362, 62, 81 }, 0.3f);
			jump_forward2.PushBack({ 1152, 1362, 62, 81 }, 0.3f);
			jump_forward2.PushBack({ 1226, 1362, 80, 62 }, 0.3f);
			jump_forward2.PushBack({ 1312, 1362, 80, 62 }, 0.3f);
			jump_forward2.PushBack({ 1407, 1362, 80, 62 }, 0.3f);
			jump_forward2.PushBack({ 1509, 1362, 77, 85 }, 0.3f);
			jump_forward2.PushBack({ 1595, 1362, 77, 85 }, 0.3f);
			jump_forward2.PushBack({ 1686, 1362, 77, 85 }, 0.3f);
			jump_forward2.loop = false;
		}

		//jump backward animation
		{
			jump_backward2.PushBack({ 15, 1492, 63, 112 }, 0.3f);
			jump_backward2.PushBack({ 83, 1492, 63, 112 }, 0.3f);
			jump_backward2.PushBack({ 151, 1492, 63, 112 }, 0.3f);
			jump_backward2.PushBack({ 224, 1492, 74, 93 }, 0.3f);
			jump_backward2.PushBack({ 307, 1492, 74, 93 }, 0.3f);
			jump_backward2.PushBack({ 391, 1492, 74, 93 }, 0.3f);
			jump_backward2.PushBack({ 478, 1492, 80, 61 }, 0.3f);
			jump_backward2.PushBack({ 566, 1492, 80, 61 }, 0.3f);
			jump_backward2.PushBack({ 661, 1492, 80, 61 }, 0.3f);
			jump_backward2.PushBack({ 757, 1492, 62, 80 }, 0.3f);
			jump_backward2.PushBack({ 842, 1492, 62, 80 }, 0.3f);
			jump_backward2.PushBack({ 927, 1492, 62, 80 }, 0.3f);
			jump_backward2.PushBack({ 1013, 1492, 80, 61 }, 0.3f);
			jump_backward2.PushBack({ 1105, 1492, 80, 61 }, 0.3f);
			jump_backward2.PushBack({ 1195, 1492, 80, 61 }, 0.3f);
			jump_backward2.PushBack({ 1286, 1492, 62, 80 }, 0.3f);
			jump_backward2.PushBack({ 1367, 1492, 62, 80 }, 0.3f);
			jump_backward2.PushBack({ 1436, 1492, 62, 80 }, 0.3f);
			jump_backward2.PushBack({ 1509, 1492, 77, 85 }, 0.3f);
			jump_backward2.PushBack({ 1595, 1492, 77, 85 }, 0.3f);
			jump_backward2.PushBack({ 1686, 1492, 77, 85 }, 0.3f);
			jump_backward2.loop = false;
		}

		//punch animation
		{
			punch2.PushBack({ 14, 236, 69, 130 }, 0.5f);
			punch2.PushBack({ 87, 236, 69, 130 }, 0.3f);
			punch2.PushBack({ 160, 236, 79, 127 }, 0.3f);
			punch2.PushBack({ 243, 236, 79, 127 }, 0.5f);
			punch2.PushBack({ 327, 236, 79, 127 }, 0.5f);
			punch2.PushBack({ 410, 236, 129, 127 }, 0.5f);
			punch2.PushBack({ 545, 236, 130, 127 }, 0.5f);
			punch2.PushBack({ 679, 236, 130, 127 }, 0.5f);
			punch2.PushBack({ 814, 236, 129, 127 }, 0.5f); //9
			punch2.PushBack({ 946, 236, 130, 127 }, 0.5f);
			punch2.PushBack({ 1081, 236, 130, 127 }, 0.5f);
			punch2.PushBack({ 1213, 236, 120, 127 }, 0.5f);
			punch2.PushBack({ 1337, 236, 120, 127 }, 0.5f);
			punch2.PushBack({ 1461, 236, 83, 127 }, 0.8f);
			punch2.PushBack({ 1548, 236, 83, 127 }, 0.8f);
			punch2.PushBack({ 1635, 236, 83, 127 }, 0.8f); //16
			punch2.PushBack({ 1721, 236,131, 127 }, 0.7f);
			punch2.PushBack({ 1856, 236, 131, 127 }, 0.7f);
			punch2.loop = false;
		}

		//kick animation
		{
			kick2.PushBack({ 16,137,66,95 }, 0.8f); //initial kick frames
			kick2.PushBack({ 87,137,66,95 }, 0.8f);
			kick2.PushBack({ 158,137,66,95 }, 0.8f);
			kick2.PushBack({ 229,134,86,98 }, 0.6f); //final kick frames
			kick2.PushBack({ 320,134,86,98 }, 0.6f);
			kick2.PushBack({ 411,134,86,98 }, 0.6f);
			kick2.PushBack({ 16,137,66,95 }, 0.7f); //initial kick frames
			kick2.PushBack({ 87,137,66,95 }, 0.7f);
			kick2.PushBack({ 158,137,66,95 }, 0.7f);
			kick2.loop = false;
		}

		//get hit animation 2
		{
			hit2.PushBack({ 14, 1616, 78, 100 }, 0.3f);
			hit2.PushBack({ 105, 1616, 78, 100 }, 0.3f);
			hit2.PushBack({ 195, 1616, 78, 100 }, 0.3f);
			hit2.PushBack({ 282, 1616, 77, 94 }, 0.3f);
			hit2.PushBack({ 367, 1616, 77, 94 }, 0.3f);
			hit2.PushBack({ 452, 1616, 77, 94 }, 0.3f);
			hit2.PushBack({ 14, 1616, 78, 100 }, 0.3f);
			hit2.PushBack({ 105, 1616, 78, 100 }, 0.3f);
			hit2.PushBack({ 195, 1616, 78, 100 }, 0.3f);
			hit2.loop = false;
		}

		//crouch animation
		{
			crouch_down2.PushBack({ 15, 1239, 68, 110 }, 0.5f);
			crouch_down2.PushBack({ 94, 1239, 68, 110 }, 0.5f);
			crouch_down2.PushBack({ 180, 1239, 68, 110 }, 0.5f);
			crouch_down2.PushBack({ 299, 1273, 88, 76 }, 0.5f);
			crouch_down2.PushBack({ 431, 1273, 88, 76 }, 0.5f);
			crouch_down2.PushBack({ 557, 1273, 88, 76 }, 0.5f);
			crouch_down2.loop = false;
			
			crouch_up2.PushBack({ 180, 12439, 68, 110 }, 0.5f);
			crouch_up2.PushBack({ 94, 12439, 68, 110 }, 0.5f);
			crouch_up2.PushBack({ 15, 1239, 68, 110 }, 0.5f);
			crouch_up2.loop = false;
		}

		//crouch punch
		{
			crouch_punch2.PushBack({ 15, 1718, 100, 93 }, 0.6f);
			crouch_punch2.PushBack({ 102, 1718, 104, 93 }, 0.6f);
			crouch_punch2.PushBack({ 210, 1718, 109, 93 }, 0.6f);
			crouch_punch2.PushBack({ 324, 1718, 155, 90 }, 0.6f);
			crouch_punch2.PushBack({ 476, 1718, 155, 90 }, 0.6f);
			crouch_punch2.PushBack({ 640, 1718, 155, 91 }, 0.6f);
			crouch_punch2.PushBack({ 792, 1718, 154, 92 }, 0.6f);
			crouch_punch2.PushBack({ 953, 1718, 150, 94 }, 0.6f);
			crouch_punch2.PushBack({ 1129, 1718, 150, 93 }, 0.6f);
			crouch_punch2.PushBack({ 1287, 1718, 111, 93 }, 0.6f);
			crouch_punch2.PushBack({ 1411, 1718, 111, 93 }, 0.6f);
			crouch_punch2.PushBack({ 1539, 1718, 111, 93 }, 0.6f);
			crouch_punch2.PushBack({ 1660, 1718, 111, 93 }, 0.6f);
			crouch_punch2.PushBack({ 1786, 1718, 111, 93 }, 0.6f);
			crouch_punch2.PushBack({ 1901, 1718, 109, 93 }, 0.6f);
			crouch_punch2.loop = false;
		}

		//crouch kick
		{
			crouch_kick2.PushBack({ 12, 1830, 74, 77 }, 0.3f);
			crouch_kick2.PushBack({ 106, 1828, 74, 77 }, 0.3f);
			crouch_kick2.PushBack({ 203, 1826, 79, 81 }, 0.3f);
			crouch_kick2.PushBack({ 300, 1826, 79, 81 }, 0.3f);
			crouch_kick2.PushBack({ 395, 1835, 99, 73 }, 0.3f);
			crouch_kick2.PushBack({ 513, 1835, 99, 73 }, 0.3f);
			crouch_kick2.PushBack({ 643, 1825, 79, 80 }, 0.6f);
			crouch_kick2.PushBack({ 751, 1825, 79, 80 }, 0.6f);
			crouch_kick2.loop = false;
		}

		//twister animation
		{
			twister2.PushBack({ 15, 798, 90, 90 }, 0.6f);
			twister2.PushBack({ 106, 798, 90, 90 }, 0.6f);
			twister2.PushBack({ 197, 798, 90, 90 }, 0.6f);
			twister2.PushBack({ 289, 798, 71, 90 }, 0.6f);
			twister2.PushBack({ 362, 798, 71, 90 }, 0.6f);
			twister2.PushBack({ 435, 803, 74, 86 }, 0.6f);
			twister2.PushBack({ 511, 803, 74, 86 }, 0.6f);
			twister2.PushBack({ 586, 795, 59, 94 }, 0.6f);
			twister2.PushBack({ 646, 795, 59, 94 }, 0.6f);
			twister2.PushBack({ 709, 788, 93, 101 }, 0.6f);
			twister2.PushBack({ 809, 788, 93, 101 }, 0.6f);
			twister2.PushBack({ 909, 788, 93, 101 }, 0.6f);
			twister2.PushBack({ 1006, 734, 62, 155 }, 0.6f);
			twister2.PushBack({ 1071, 734, 62, 155 }, 0.6f);
			twister2.PushBack({ 1138, 734, 62, 155 }, 0.6f);
			twister2.PushBack({ 1203, 787, 100, 102 }, 0.6f);
			twister2.PushBack({ 1313, 787, 100, 102 }, 0.6f);
			twister2.PushBack({ 1429, 787, 100, 102 }, 0.6f);
			twister2.PushBack({ 1543, 795, 98, 94 }, 0.6f);
			twister2.PushBack({ 1646, 795, 98, 94 }, 0.6f);
			twister2.PushBack({ 1749, 795, 98, 94 }, 0.6f);
			twister2.PushBack({ 15, 923, 104, 93 }, 0.6f);
			twister2.PushBack({ 121, 923, 104, 93 }, 0.6f);
			twister2.PushBack({ 228, 923, 104, 93 }, 0.6f);
			twister2.PushBack({ 337, 923, 84, 93 }, 0.6f);
			twister2.PushBack({ 425, 923, 84, 93 }, 0.6f);
			twister2.PushBack({ 512, 923, 84, 93 }, 0.6f);
			twister2.PushBack({ 599, 896, 72, 120 }, 0.6f);
			twister2.PushBack({ 673, 896, 72, 120 }, 0.6f);
			twister2.PushBack({ 748, 896, 72, 120 }, 0.6f);
			twister2.loop = false;

			//Twister animation (only the twister)
			twisterAlone2.loop = false;
		}
		{
			die2.PushBack({ 852,0,108,54 });
		}
	}
}

ModulePlayer2::~ModulePlayer2() {}

// Load assets
bool ModulePlayer2::Start()
{
	bool ret = true;
	LOG("Loading player textures\n");
	position.x = initial_position.x = 230;
	position.y = initial_position.y =215;
	lposition = position;
	graphics = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");
	light_attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/light_attack.wav");
	light_kick_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/light_kick.wav");
	twister_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/twister.wav");
	hit_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/Hit_1.wav");
	state2 = IDLE2;
	life = 100;
	current_animation = &idle2;
	if (!collider_player_2_up)
		collider_player_2_up = App->collision->AddCollider({ position.x + 15, position.y - 85,30,40 }, COLLIDER_PLAYER_2, (Module*)App->player2);
	if (!collider_player_2_down)
		collider_player_2_down = App->collision->AddCollider({ position.x + 10, position.y - 45,40,45 }, COLLIDER_PLAYER_2, (Module*)App->player2);

	App->ui->Enable();
	//test_collider = App->collision->AddCollider({ 150,160,30,30 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
	return ret;
}

update_status ModulePlayer2::PreUpdate()
{
	if (!App->is_paused) {
		player_input2.pressing_left = App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT;
		player_input2.pressing_right = App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT;
		player_input2.pressing_down = App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT;
		player_input2.pressing_up = App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN;
		player_input2.pressing_N = App->input->keyboard[SDL_SCANCODE_N] == KEY_DOWN;
		player_input2.pressing_M = App->input->keyboard[SDL_SCANCODE_M] == KEY_DOWN;
		player_input2.pressing_B = App->input->keyboard[SDL_SCANCODE_B] == KEY_DOWN;
		player_input2.pressing_F5 = App->input->keyboard[SDL_SCANCODE_F5] == KEY_DOWN;


		if (state2 == IDLE2) {
			if (player_input2.pressing_left)
				state2 = FORWARD2;
			if (player_input2.pressing_right)
				state2 = BACKWARD2;
			if (player_input2.pressing_N){
				state2 = KICK2;
			App->audio->PlayFX(light_kick_fx);
		}
			if (player_input2.pressing_M) {
				state2 = PUNCH2;
				App->audio->PlayFX(light_attack_fx);
			}
			if (player_input2.pressing_up)
				state2 = JUMP_NEUTRAL2;
			if (player_input2.pressing_down)
				state2 = CROUCH_DOWN2;
			if (player_input2.pressing_B) {
				App->audio->PlayFX(twister_fx);
				state2 = TWISTER2;
			}
		}

		if (state2 == BACKWARD2) {
			if (!player_input2.pressing_right)
				state2 = IDLE2;
			if (player_input2.pressing_M)
				state2 = PUNCH2;
			if (player_input2.pressing_N)
				state2 = KICK2;
			if (player_input2.pressing_up)
				state2 = JUMP_BACKWARD2;
		}
		if (state2 == FORWARD2) {
			if (!player_input2.pressing_left)
				state2 = IDLE2;
			if (player_input2.pressing_M)
				state2 = PUNCH2;
			if (player_input2.pressing_N)
				state2 = KICK2;
			if (player_input2.pressing_up)
				state2 = JUMP_FORWARD2;
		}
		if (state2 == KICK2) {
			if (current_animation->Finished()) {
				state2 = IDLE2;
				kick2.Reset();
				if (collider_player_2_mid != nullptr)
				{
					collider_player_2_mid->to_delete = true;
				}
			}
		}
		if (state2 == PUNCH2) {
			if (current_animation->Finished()) {
				state2 = IDLE2;
				punch2.Reset();
			}
		}
		if (state2 == JUMP_NEUTRAL2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_neutral2.Reset();
			}
		}
		if (state2 == JUMP_FORWARD2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_forward2.Reset();
			}
		}
		if (state2 == JUMP_BACKWARD2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_backward2.Reset();
			}
		}
		if (state2 == CROUCH_DOWN2)
		{
			if (!player_input2.pressing_down)
			{
				state2 = CROUCH_UP2;
				crouch_down2.Reset();
			}
			if (player_input2.pressing_N) {
				state2 = CROUCH_KICK2;
				App->audio->PlayFX(light_kick_fx);				
			}
			if (player_input2.pressing_M) {
				state2 = CROUCH_PUNCH2;
				App->audio->PlayFX(light_attack_fx);
			}
		}
		if (state2 == CROUCH_UP2)
		{
			if (current_animation->Finished()) {
				state2 = IDLE2;
				crouch_up2.Reset();
			}
		}
		if (state2 == TWISTER2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				twister2.Reset();
				is_tornado_created2 = false;
			}
		}
		if (state2 == CROUCH_KICK2) 
		{			
			if (current_animation->Finished()) {
				state2 = IDLE2;
				crouch_kick2.Reset();
			}
		}
		if (state2 == CROUCH_PUNCH2) {
			if (current_animation->Finished()) {
				state2 = IDLE2;
				crouch_punch2.Reset();
			}
		}
		if (state2 == HIT2) {
			if (current_animation->Finished()) {
				state2 = IDLE2;
				hit2.Reset();

			}
		}
		if ((player_input2.pressing_F5) && (collider_player_2_up != nullptr)) {
			collider_player_2_up->to_delete = true;
			collider_player_2_up = nullptr;

			if (collider_player_2_mid != nullptr)
			{
				collider_player_2_mid->to_delete = true;
				collider_player_2_mid = nullptr;
			}

			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->to_delete = true;
				collider_player_2_down = nullptr;
			}
		}
		else if ((player_input2.pressing_F5) && (collider_player_2_up == nullptr))
		{
			collider_player_2_up = App->collision->AddCollider({ 0, 0,71,95 }, COLLIDER_PLAYER_2, (Module*)App->player2);
			if (collider_player_2_down == nullptr)
			{
				collider_player_2_down = App->collision->AddCollider({ 0, 0,71,95 }, COLLIDER_PLAYER_2, (Module*)App->player2);
			}
		}

		if ((state2 != PUNCH2) && (state2 != KICK2) && (state2 != CROUCH_KICK2) && (state2 != CROUCH_PUNCH2) && (collider_player_2_attack != nullptr))
		{
			collider_player_2_attack->to_delete = true;
			collider_player_2_attack = nullptr;
		}
	}
	
	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	lposition = position;
	if (!App->is_paused) {
		switch (state2)
		{
		case IDLE2:
			current_animation = &idle2;
			position.y = lposition.y;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x + 15, position.y - 85);
				collider_player_2_up->SetSize(30, 40);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x + 10, position.y - 45);
				collider_player_2_down->SetSize(40, 45);
			}
			break;
		case FORWARD2:
			current_animation = &forward2;
			position.x -= speed;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x + 15, position.y - 85);
				collider_player_2_up->SetSize(30, 40);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x + 10, position.y - 45);
				collider_player_2_down->SetSize(35, 45);
			}
			break;
		case BACKWARD2:
			current_animation = &backward2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x +10, position.y - 85);
				collider_player_2_up->SetSize(35, 40);
			}
			if (collider_player_2_down != nullptr) {
				collider_player_2_down->SetPos(position.x, position.y - 45);
				collider_player_2_down->SetSize(50, 45);
			}
			position.x += speed;
			break;

		case CROUCH_DOWN2:
			current_animation = &crouch_down2;
			
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x +10, position.y - 80);
				collider_player_2_up->SetSize(35, 50);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x, position.y - 30);
				collider_player_2_down->SetSize(50, 30);
			}
			if (current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) { 
				collider_player_2_up->SetPos(position.x, position.y - 65);
				collider_player_2_up->SetSize(35, 35);
			}
			
			break;
		case CROUCH_UP2:
			current_animation = &crouch_up2;
			break;
		case CROUCH_KICK2:
			current_animation = &crouch_kick2;
			
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x + 20, position.y - 65);
				collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x+20, position.y - 25);
				collider_player_2_down->SetSize(90, 25);
			}
			if (current_animation->SeeCurrentFrame() < 2) 
			{
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x, position.y - 65);
					collider_player_2_up->SetSize(35, 35);
				}
			}
			if (collider_player_2_attack == nullptr) {
				collider_player_2_attack = App->collision->AddCollider({ position.x, position.y-15,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
				collider_player_2_attack->SetSize(50, 15);
			}
			
			break;
		case CROUCH_PUNCH2:
			current_animation = &crouch_punch2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x + 45, position.y - 65);
				collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x, position.y - 30);
				collider_player_2_down->SetSize(100, 30);
			}
			if (current_animation->SeeCurrentFrame() < 3 || current_animation->SeeCurrentFrame() > 7) {
				collider_player_2_up->SetPos(position.x, position.y - 65);
				collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_attack == nullptr)
			{
				collider_player_2_attack = App->collision->AddCollider({ position.x, position.y - 15,80,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
			}
			break;
		case JUMP_NEUTRAL2:
			current_animation = &jump_neutral2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x+25, position.y - 90);
				collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x+20, position.y - 50);
				collider_player_2_down->SetSize(50, 30);
			}
			position.y -= speed * 2 * mult;

			if (position.y <= 120) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				
				mult = 1;
				jump_neutral2.Reset();
				state2 = IDLE2;
			}
			break;
		case JUMP_FORWARD2:
			current_animation = &jump_forward2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x + 30, position.y - 90);
				collider_player_2_up->SetSize(40, 50);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x + 10, position.y - 50);
				collider_player_2_down->SetSize(30, 50);
			}
			if (current_animation->SeeCurrentFrame() > 4)
			{
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 10, position.y - 45);
					collider_player_2_up->SetSize(45, 35);
				}
			}
			position.y -= speed * 1.75 * mult;
			position.x -= 1.25*speed;

			if (position.y <= 120) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_forward2.Reset();
				state2 = IDLE2;
			}
			break;
		case JUMP_BACKWARD2:
			current_animation = &jump_backward2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x +30, position.y - 90);
				collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x+30, position.y - 50);
				collider_player_2_down->SetSize(40, 30);
			}
			if (current_animation->SeeCurrentFrame() > 4)
			{
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 10, position.y - 90);
					collider_player_2_up->SetSize(35, 35);
				}
			}
			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed;

			if (position.y <= 120) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_backward2.Reset();
				state2 = IDLE2;
			}
			break;
		case PUNCH2:
			current_animation = &punch2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x, position.y - 60);
				collider_player_2_up->SetSize(50, 47);
			}
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_down->SetPos(position.x + 5, position.y - 10);
				collider_player_2_down->SetSize(70, 15);
			}
			if (collider_player_2_attack == nullptr)
			{
				collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);

			}
			collider_player_2_attack->SetPos(position.x + 60, position.y - 50);
			collider_player_2_attack->SetSize(67, 30);

			break;
		case KICK2:
			current_animation = &kick2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x + 10, position.y - 70);
				collider_player_2_up->SetSize(50, 30);

				if (collider_player_2_mid == nullptr)
				{
					collider_player_2_mid = App->collision->AddCollider({ position.x + 30,position.y - 50 ,25,30 }, COLLIDER_PLAYER_2, (Module*)App->player2);
					collider_player_2_mid->SetPos(position.x, position.y-37);
					collider_player_2_mid->SetSize(45, 30);
				}
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x + 20, position.y - 80);
				collider_player_2_down->SetSize(25, 85);
			}
			if (collider_player_2_attack == nullptr)
			{
				collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
				collider_player_2_attack->SetPos(position.x, position.y - 35);
				collider_player_2_attack->SetSize(56, 30);
			}
			break;
		case TWISTER2:
			current_animation = &twister2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x, position.y - 75);
				collider_player_2_up->SetSize(40, 45);
			}
			if (collider_player_2_down != nullptr)
			{
				collider_player_2_down->SetPos(position.x, position.y - 35);
				collider_player_2_down->SetSize(60, 40);
			}
			if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created2) {
				App->particles->AddParticle(App->particles->tornado, position.x, position.y - 205, COLLIDER_PLAYER_2_PARTICLES);
				is_tornado_created2 = true;
			}
			break;
		case HIT2:
			current_animation = &hit2;
			if (collider_player_2_up != nullptr)
			{
				collider_player_2_up->SetPos(position.x + 15, position.y - 85);
				collider_player_2_down->SetPos(position.x + 10, position.y - 45);
			}
			break;
		case DEATH2:
			current_animation = &die2;
			break;
		default:
			LOG("No state found :(");
			break;
		}
	}


	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r,SDL_FLIP_HORIZONTAL);

	return UPDATE_CONTINUE;
}

bool ModulePlayer2::CleanUp() {
	LOG("Unloading player");
	App->textures->Unload(graphics);
	App->audio->UnLoadFx(light_attack_fx);
	App->audio->UnLoadFx(light_kick_fx);
	App->audio->UnLoadFx(twister_fx);
	App->audio->UnLoadFx(hit_fx);
	App->collision->CleanUp();
	collider_player_2_up = nullptr;
	collider_player_2_mid = nullptr;
	collider_player_2_down = nullptr;
	App->ui->Disable();
	return true;
}


void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {
	if (state2 != DEATH2) {
		switch (c2->type)
		{
		case COLLIDER_WALL_LEFT:
			if (!player_input2.pressing_right)
				position.x += speed;

			break;
		case COLLIDER_WALL_RIGHT:
			if (!player_input2.pressing_left)
				position.x -= speed;
			break;
		case COLLIDER_PLAYER:
			if (((state2 != KICK2) && (state2 != PUNCH2) && (state2 != CROUCH_KICK2) && (state2 != CROUCH_PUNCH2)) && (state2 != TWISTER2))
			{
				if (position.x < App->player->position.x)
				{
					position.x = lposition.x - speed;
				}

				else
				{
					position.x = lposition.x + speed;
				}
			}
			break;
		case COLLIDER_PLAYER_1_ATTACK:
			if (!App->player->collider_player_attack->to_delete) {
				switch (App->player->state)
				{
				case States::KICK:
					App->ui->player1_point += 50;
					break;
				case States::PUNCH:
					App->ui->player1_point += 50;
					break;
				case States::CROUCH_PUNCH:
					App->ui->player1_point += 200;
					break;
				case States::CROUCH_KICK:
					App->ui->player1_point += 200;
					break;
				case States::TWISTER:
					App->ui->player1_point += 400;
				default:
					break;
				}
				App->audio->PlayFX(hit_fx);
				life -= 10;
				state2 = HIT2;
				App->player->collider_player_attack->to_delete = true;
				if (position.x < App->player->position.x)
				{
					position.x += -10;
				}

				else
				{
					position.x += 10;
				}
			}



			break;
		case COLLIDER_PLAYER_PARTICLES:
			App->audio->PlayFX(hit_fx);
			life -= 20;
			state2 = HIT2;
			position.x += 5;
			break;
		default:
			break;
		}
	}
	
}