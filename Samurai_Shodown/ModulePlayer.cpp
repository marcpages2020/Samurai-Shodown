#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"
#include "ModuleCollision.h"
#include "ModulePlayer2.h"

ModulePlayer::ModulePlayer()
{
	//animations
	{
		//idle animation
		{
			idle.PushBack({ 16,22,71,109 }, 0.3f);
			idle.PushBack({ 92,22,72,109 }, 0.3f);
			idle.PushBack({ 168,22,71,109 }, 0.3f);
			idle.PushBack({ 245,20,72,111 }, 0.3f);
			idle.PushBack({ 322,18,72,113 }, 0.3f);
			idle.PushBack({ 399,19,72,112 }, 0.3f);
			idle.PushBack({ 476,19,74,112 }, 0.3f);
			idle.PushBack({ 554,19,74,112 }, 0.3f);
			idle.PushBack({ 630,19,73,112 }, 0.3f);
			idle.PushBack({ 245,20,72,111 }, 0.3f);
			idle.PushBack({ 322,18,72,113 }, 0.3f);
			idle.PushBack({ 399,19,72,112 }, 0.3f);
		}

		//forward animation
		{
			forward.PushBack({ 15,496,70,112 }, 0.4f);
			forward.PushBack({ 89,496,70,112 }, 0.4f);
			forward.PushBack({ 163,499,76,109 }, 0.4f);
			forward.PushBack({ 243,499,76,109 }, 0.4f);
			forward.PushBack({ 322,499,76,109 }, 0.4f);
			forward.PushBack({ 402,496,69,112 }, 0.4f);
			forward.PushBack({ 475,496,69,112 }, 0.4f);
			forward.PushBack({ 548,496,69,112 }, 0.4f);
			forward.PushBack({ 621,492,59,116 }, 0.4f);
			forward.PushBack({ 684,492,59,116 }, 0.4f);
			forward.PushBack({ 747,492,59,116 }, 0.4f);
			forward.PushBack({ 810,492,57,116 }, 0.4f);
			forward.PushBack({ 871,490,57,118 }, 0.4f);
			forward.PushBack({ 933,490,56,118 }, 0.4f);
			forward.PushBack({ 994,490,61,118 }, 0.4f);
			forward.PushBack({ 1060,492,61,116 }, 0.4f);
			forward.PushBack({ 1126,492,61,116 }, 0.4f);
		}

		//backward animation
		{
			backward.PushBack({ 624,608,82,121 }, 0.4f);//9
			backward.PushBack({ 711,608,82,121 }, 0.4f);//10
			backward.PushBack({ 798,608,82,121 }, 0.4f);//11
			backward.PushBack({ 884,608,82,121 }, 0.4f);//12
			backward.PushBack({ 15,614,74,114 }, 0.4f); //1
			backward.PushBack({ 94,614,74,114 }, 0.4f); //2
			backward.PushBack({ 173,614,74,114 }, 0.4f); //3 
			backward.PushBack({ 264,610,68,118 }, 0.4f); //4
			backward.PushBack({ 337,610,68,118 }, 0.4f); //5
			backward.PushBack({ 410,612,68,117 }, 0.4f); //6
			backward.PushBack({ 482,609,67,121 }, 0.4f);//7
			backward.PushBack({ 553,608,67,121 }, 0.4f);//8
			backward.PushBack({ 971,608,69,122 }, 0.4f);//13
			backward.PushBack({ 1045,608,69,121 }, 0.4f);//14
			backward.PushBack({ 1119,608,69,120 }, 0.4f);//15
			backward.PushBack({ 1193,614,74,114 }, 0.4f);//16
			backward.PushBack({ 1272,614,74,114 }, 0.4f);//17
			backward.PushBack({ 1351,614,74,114 }, 0.4f);//18
		}

		//jump neutral animation
		{
			jump_neutral.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
			jump_neutral.PushBack({ 80, 371, 60, 112 }, 0.2f); //2
			jump_neutral.PushBack({ 145, 371, 60, 112 }, 0.2f); //3
			jump_neutral.PushBack({ 209, 371, 75, 92 }, 0.2f);
			jump_neutral.PushBack({ 288, 371, 75, 92 }, 0.2f);
			jump_neutral.PushBack({ 367, 371, 75, 92 }, 0.2f);
			jump_neutral.PushBack({ 446, 371, 78, 83 }, 0.2f);
			jump_neutral.PushBack({ 209, 371, 75, 92 }, 0.2f);
			jump_neutral.PushBack({ 288, 371, 75, 92 }, 0.2f);
			jump_neutral.PushBack({ 367, 371, 75, 92 }, 0.2f);
			jump_neutral.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
			jump_neutral.PushBack({ 80, 371, 60, 112 }, 0.2f);
			jump_neutral.PushBack({ 145, 371, 60, 112 }, 0.2f);
			jump_neutral.PushBack({ 527, 371, 68, 112 }, 0.2f); //8
			jump_neutral.PushBack({ 601, 371, 68, 112 }, 0.2f); //9
			jump_neutral.PushBack({ 674, 371, 68, 112 }, 0.2f); //10
		}

		//jump forward animation
		{
			jump_forward.PushBack({ 15, 1362, 63, 130 }, 0.3f);
			jump_forward.PushBack({ 83, 1362, 63, 130 }, 0.3f);
			jump_forward.PushBack({ 151, 1362, 63, 130 }, 0.3f);
			jump_forward.PushBack({ 224, 1362, 74, 93 }, 0.3f);
			jump_forward.PushBack({ 307, 1362, 74, 93 }, 0.3f);
			jump_forward.PushBack({ 391, 1362, 74, 93 }, 0.3f);
			jump_forward.PushBack({ 478, 1362, 62, 81 }, 0.3f);
			jump_forward.PushBack({ 559, 1362, 62, 81 }, 0.3f);
			jump_forward.PushBack({ 631, 1362, 62, 81 }, 0.3f);
			jump_forward.PushBack({ 706, 1362, 80, 62 }, 0.3f);
			jump_forward.PushBack({ 799, 1362, 80, 62 }, 0.3f);
			jump_forward.PushBack({ 981, 1362, 62, 81 }, 0.3f);
			jump_forward.PushBack({ 1066, 1362, 62, 81 }, 0.3f);
			jump_forward.PushBack({ 1152, 1362, 62, 81 }, 0.3f);
			jump_forward.PushBack({ 1226, 1362, 80, 62 }, 0.3f);
			jump_forward.PushBack({ 1312, 1362, 80, 62 }, 0.3f);
			jump_forward.PushBack({ 1407, 1362, 80, 62 }, 0.3f);
			jump_forward.PushBack({ 1509, 1362, 77, 85 }, 0.3f);
			jump_forward.PushBack({ 1595, 1362, 77, 85 }, 0.3f);
			jump_forward.PushBack({ 1686, 1362, 77, 85 }, 0.3f);
			jump_forward.loop = false;
		}

		//jump backward animation
		{
			jump_backward.PushBack({ 15, 1492, 63, 112 }, 0.3f);
			jump_backward.PushBack({ 83, 1492, 63, 112 }, 0.3f);
			jump_backward.PushBack({ 151, 1492, 63, 112 }, 0.3f);
			jump_backward.PushBack({ 224, 1492, 74, 93 }, 0.3f);
			jump_backward.PushBack({ 307, 1492, 74, 93 }, 0.3f);
			jump_backward.PushBack({ 391, 1492, 74, 93 }, 0.3f);
			jump_backward.PushBack({ 478, 1492, 80, 61 }, 0.3f);
			jump_backward.PushBack({ 566, 1492, 80, 61 }, 0.3f);
			jump_backward.PushBack({ 661, 1492, 80, 61 }, 0.3f);
			jump_backward.PushBack({ 757, 1492, 62, 80 }, 0.3f);
			jump_backward.PushBack({ 842, 1492, 62, 80 }, 0.3f);
			jump_backward.PushBack({ 927, 1492, 62, 80 }, 0.3f);
			jump_backward.PushBack({ 1013, 1492, 80, 61 }, 0.3f);
			jump_backward.PushBack({ 1105, 1492, 80, 61 }, 0.3f);
			jump_backward.PushBack({ 1195, 1492, 80, 61 }, 0.3f);
			jump_backward.PushBack({ 1286, 1492, 62, 80 }, 0.3f);
			jump_backward.PushBack({ 1367, 1492, 62, 80 }, 0.3f);
			jump_backward.PushBack({ 1436, 1492, 62, 80 }, 0.3f);
			jump_backward.PushBack({ 1509, 1492, 77, 85 }, 0.3f);
			jump_backward.PushBack({ 1595, 1492, 77, 85 }, 0.3f);
			jump_backward.PushBack({ 1686, 1492, 77, 85 }, 0.3f);
			jump_backward.loop = false;			
		}

		//punch animation
		{
			punch.PushBack({ 14, 236, 69, 130 }, 0.5f);
			punch.PushBack({ 87, 236, 69, 130 }, 0.3f);
			punch.PushBack({ 164, 235, 79, 127 }, 0.3f);
			punch.PushBack({ 243, 236, 79, 127 }, 0.5f);
			punch.PushBack({ 331, 236, 79, 127 }, 0.5f);
			punch.PushBack({ 410, 236, 129, 127 }, 0.5f);
			punch.PushBack({ 545, 236, 130, 127 }, 0.5f);
			punch.PushBack({ 679, 236, 130, 127 }, 0.5f);
			punch.PushBack({ 814, 236, 129, 127 }, 0.5f); //9
			punch.PushBack({ 946, 236, 130, 127 }, 0.5f);
			punch.PushBack({ 1081, 236, 130, 127 }, 0.5f);
			punch.PushBack({ 1213, 236, 120, 127 }, 0.5f);
			punch.PushBack({ 1337, 236, 120, 127 }, 0.5f);
			punch.PushBack({ 1461, 236, 83, 127 }, 0.8f);
			punch.PushBack({ 1548, 236, 83, 127 }, 0.8f);
			punch.PushBack({ 1635, 236, 83, 127 }, 0.8f); //16
			punch.PushBack({ 1721, 236,131, 127 }, 0.7f);
			punch.PushBack({ 1856, 236, 131, 127 }, 0.7f);
			punch.loop = false;
		}

		//kick animation
		{
			kick.PushBack({ 16,137,66,95 }, 0.8f); //initial kick frames
			kick.PushBack({ 87,137,66,95 }, 0.8f);
			kick.PushBack({ 158,137,66,95 }, 0.8f);
			kick.PushBack({ 229,134,86,98 }, 0.6f); //final kick frames
			kick.PushBack({ 320,134,86,98 }, 0.6f);
			kick.PushBack({ 411,134,86,98 }, 0.6f);
			kick.PushBack({ 16,137,66,95 }, 0.7f); //initial kick frames
			kick.PushBack({ 87,137,66,95 }, 0.7f);
			kick.PushBack({ 158,137,66,95 }, 0.7f);
			kick.loop = false;
		}

		//get hit animation 2
		{
			hit.PushBack({14, 1616, 78, 100}, 0.3f);
			hit.PushBack({105, 1616, 78, 100}, 0.3f);
			hit.PushBack({195, 1616, 78, 100}, 0.3f);
			hit.PushBack({282, 1616, 77, 94}, 0.3f);
			hit.PushBack({367, 1616, 77, 94}, 0.3f);
			hit.PushBack({452, 1616, 77, 94}, 0.3f);
			hit.PushBack({14, 1616, 78, 100}, 0.3f);
			hit.PushBack({105, 1616, 78, 100}, 0.3f);
			hit.PushBack({195, 1616, 78, 100}, 0.3f);
			hit.loop = false;
		}

		//crouch animation
		{
			//Crouch Down
			crouch_down.PushBack({ 15, 1239, 68, 110}, 0.5f);
			crouch_down.PushBack({ 94, 1239, 68, 110}, 0.5f);
			crouch_down.PushBack({ 180, 1239, 68, 110}, 0.5f);
			crouch_down.PushBack({ 299, 1273, 88, 76}, 0.5f);
			crouch_down.PushBack({ 431, 1273, 88, 76}, 0.5f);
			crouch_down.PushBack({ 557, 1273, 88, 76 }, 0.5f);
			crouch_down.loop = false;

			//Crouch Up
			crouch_up.PushBack({ 180, 12439, 68, 110 }, 0.5f);
			crouch_up.PushBack({ 94, 12439, 68, 110 }, 0.5f);
			crouch_up.PushBack({ 15, 1239, 68, 110 }, 0.5f);	
			crouch_up.loop = false;
		}

		//crouch punch
		{
			crouch_punch.PushBack({15, 1718, 100, 93}, 0.6f);
			crouch_punch.PushBack({102, 1718, 104, 93}, 0.6f);
			crouch_punch.PushBack({210, 1718, 109, 93}, 0.6f);
			crouch_punch.PushBack({324, 1718, 155, 90}, 0.6f);
			crouch_punch.PushBack({476, 1718, 155, 90 }, 0.6f);
			crouch_punch.PushBack({640, 1718, 155, 91 }, 0.6f);
			crouch_punch.PushBack({792, 1718, 154, 92 }, 0.6f);
			crouch_punch.PushBack({953, 1718, 150, 94 }, 0.6f);
			crouch_punch.PushBack({1129, 1718, 150, 93 }, 0.6f);
			crouch_punch.PushBack({1287, 1718, 111, 93 }, 0.6f);
			crouch_punch.PushBack({1411, 1718, 111, 93 }, 0.6f);
			crouch_punch.PushBack({1539, 1718, 111, 93 }, 0.6f);
			crouch_punch.PushBack({1660, 1718, 111, 93 }, 0.6f);
			crouch_punch.PushBack({1786, 1718, 111, 93 }, 0.6f);
			crouch_punch.PushBack({1901, 1718, 109, 93 }, 0.6f);
			crouch_punch.loop = false;
		}

		//crouch kick
		{
			crouch_kick.PushBack({12, 1830, 74, 77}, 0.3f);
			crouch_kick.PushBack({106, 1828, 74, 77}, 0.3f);
			crouch_kick.PushBack({203, 1826, 79, 81}, 0.3f);
			crouch_kick.PushBack({300, 1826, 79, 81}, 0.3f);
			crouch_kick.PushBack({395, 1835, 99, 73}, 0.3f);
			crouch_kick.PushBack({513, 1835, 99, 73}, 0.3f);
			crouch_kick.PushBack({643, 1825, 79, 80}, 0.6f);
			crouch_kick.PushBack({751, 1825, 79, 80}, 0.6f);
			crouch_kick.loop = false;
		}

		//twister animation
		{
			twister.PushBack({ 15, 798, 90, 90}, 0.6f);
			twister.PushBack({ 106, 798, 90, 90}, 0.6f);
			twister.PushBack({ 197, 798, 90, 90}, 0.6f);
			twister.PushBack({ 289, 798, 71, 90}, 0.6f);
			twister.PushBack({ 362, 798, 71, 90}, 0.6f);
			twister.PushBack({ 435, 803, 74, 86}, 0.6f);
			twister.PushBack({ 511, 803, 74, 86}, 0.6f);
			twister.PushBack({ 586, 795, 59, 94}, 0.6f);
			twister.PushBack({ 646, 795, 59, 94}, 0.6f);
			twister.PushBack({ 709, 788, 93, 101}, 0.6f);
			twister.PushBack({ 809, 788, 93, 101}, 0.6f);
			twister.PushBack({ 909, 788, 93, 101}, 0.6f);
			twister.PushBack({ 1006, 734, 62, 155}, 0.6f);
			twister.PushBack({ 1071, 734, 62, 155}, 0.6f);
			twister.PushBack({ 1138, 734, 62, 155}, 0.6f);
			twister.PushBack({ 1203, 787, 100, 102}, 0.6f);
			twister.PushBack({ 1313, 787, 100, 102}, 0.6f);
			twister.PushBack({ 1429, 787, 100, 102}, 0.6f);
			twister.PushBack({ 1543, 795, 98, 94}, 0.6f);
			twister.PushBack({ 1646, 795, 98, 94}, 0.6f);
			twister.PushBack({ 1749, 795, 98, 94}, 0.6f);
			twister.PushBack({ 15, 923, 104, 93}, 0.6f);
			twister.PushBack({ 121, 923, 104, 93}, 0.6f);
			twister.PushBack({ 228, 923, 104, 93}, 0.6f);
			twister.PushBack({ 337, 923, 84, 93}, 0.6f);
			twister.PushBack({ 425, 923, 84, 93}, 0.6f);
			twister.PushBack({ 512, 923, 84, 93}, 0.6f);
			twister.PushBack({ 599, 896, 72, 120}, 0.6f);
			twister.PushBack({ 673, 896, 72, 120}, 0.6f);
			twister.PushBack({ 748, 896, 72, 120}, 0.6f);
			twister.loop = false;

			//Twister animation (only the twister)
			twisterAlone.loop = false;
		}

		//die
		{
			die.PushBack({ 852,0,108,54 });
		}
	
		//en garde
		{
			en_garde.PushBack({ 14, 1921, 74,113 }, 0.15f);
			en_garde.PushBack({ 95, 1921, 78,113 }, 0.15f);
			en_garde.PushBack({ 182, 1921, 79,113 }, 0.15f);
			en_garde.PushBack({ 264, 1921, 79,113 }, 0.15f);
			en_garde.PushBack({ 346, 1921, 81,113 }, 0.15f);
			en_garde.PushBack({ 433, 1921, 78,113 }, 0.15f);
			en_garde.PushBack({ 517, 1921, 79,113 }, 0.15f);
			en_garde.PushBack({ 595, 1921, 74,113 }, 0.15f);
			en_garde.PushBack({ 677, 1921, 73,113 }, 0.15f);
			en_garde.PushBack({ 164, 235, 79, 127 }, 0.15f);
			en_garde.PushBack({ 243, 236, 79, 127 }, 0.15f);
			//punch
			en_garde.PushBack({ 1721, 236,131, 127 }, 0.4f);
			en_garde.PushBack({ 1856, 236, 131, 127 }, 0.4f);
			en_garde.PushBack({ 1461, 236, 83, 127 }, 0.4f);
			en_garde.PushBack({ 1721, 236,131, 127 }, 0.4f);
			en_garde.loop = false;
		}
}
}

ModulePlayer::~ModulePlayer(){}

// Load assets
bool ModulePlayer::Start()
{
	bool ret = true;
	LOG("Loading player textures\n");
	initial_position.x = position.x = 70 ;
	position.y = initial_position.y = 215;
	lposition = position;
	graphics = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");
	light_attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/light_attack.wav");
	light_kick_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/light_kick.wav");
	twister_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/twister.wav");
	hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Haohmaru/Hit_1.wav");
	App->ui->player1_point = 0;
	App->ui->player2_point = 0;
	state = IDLE;
	current_animation = &idle;
	if (!collider_player_up)
		collider_player_up = App->collision->AddCollider({ position.x+15, position.y-85,30,40 },COLLIDER_PLAYER,(Module*)App->player);
	if (!collider_player_down)
		collider_player_down = App->collision->AddCollider({ position.x+10, position.y-45,40,45 }, COLLIDER_PLAYER, (Module*)App->player);
	//test_collider = App->collision->AddCollider({ 150,160,30,30 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
	return ret;
}

update_status ModulePlayer::PreUpdate()
{
	if (!App->is_paused) {
		player_input.pressing_A = App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT;
		player_input.pressing_D = App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT;
		player_input.pressing_S = App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT;
		player_input.pressing_J = App->input->keyboard[SDL_SCANCODE_J] == KEY_DOWN;
		player_input.pressing_U = App->input->keyboard[SDL_SCANCODE_U] == KEY_DOWN;
		player_input.pressing_W = App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN;
		player_input.pressing_K = App->input->keyboard[SDL_SCANCODE_K] == KEY_DOWN;
		player_input.pressing_F5 = App->input->keyboard[SDL_SCANCODE_F5] == KEY_DOWN;

		//states 
		{
			if (state == IDLE) {
				if (player_input.pressing_A)
					state = BACKWARD;
				if (player_input.pressing_D)
					state = FORWARD;
				if (player_input.pressing_J) {
					state = KICK;
					hit_done++;
					App->audio->PlayFX(light_kick_fx);
				}
				if (player_input.pressing_U) {
					state = PUNCH;
					hit_done++;
					App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_W)
					state = JUMP_NEUTRAL;
				if (player_input.pressing_S)
					state = CROUCH_DOWN;
				if (player_input.pressing_K) {
					App->audio->PlayFX(twister_fx);
					hit_done++;
					state = TWISTER;
				}
			}
			if (state == BACKWARD) {
				if (!player_input.pressing_A)
					state = IDLE;
				if (player_input.pressing_U) 
				{
					hit_done++;
					state = PUNCH;
					App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_J) {
					hit_done++;
					state = KICK;
				}
				if (player_input.pressing_W)
					state = JUMP_BACKWARD;
			}
			if (state == FORWARD) {
				if (!player_input.pressing_D)
					state = IDLE;
				if (player_input.pressing_U) {
					hit_done++;
					state = PUNCH;
					App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_J) {
					state = KICK;
					hit_done++;
				}
				if (player_input.pressing_W)
					state = JUMP_FORWARD;
			}
			if (state == KICK) {
				if (current_animation->Finished()) {
					state = IDLE;
					kick.Reset();
					if (collider_player_mid != nullptr)
					{
						collider_player_mid->to_delete = true;
						collider_player_mid = nullptr;
					}
				}
			}
			if (state == PUNCH) {
				if (current_animation->Finished()) {
					state = IDLE;
					punch.Reset();
				}
			}
			if (state == JUMP_NEUTRAL)
			{
				if (player_input.pressing_A && mult == 1)
					state = JUMP_BACKWARD;
				if (player_input.pressing_D && mult == 1)
					state = JUMP_FORWARD;
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_neutral.Reset();
				}
			}
			if (state == JUMP_FORWARD)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_forward.Reset();
				}
			}
			if (state == JUMP_BACKWARD)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_backward.Reset();
				}
			}
			if (state == CROUCH_DOWN)
			{
				if (!player_input.pressing_S)
				{
					state = CROUCH_UP;
					crouch_down.Reset();
				}
				if (player_input.pressing_J) {
					hit_done++;
					state = CROUCH_KICK;
					App->audio->PlayFX(light_kick_fx);
				}
				if (player_input.pressing_U) {
					hit_done++;
					state = CROUCH_PUNCH;
					App->audio->PlayFX(light_attack_fx);
				}
			}
			if (state == CROUCH_UP)
			{
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_up.Reset();
				}
			}
			if (state == TWISTER)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					twister.Reset();
					is_tornado_created = false;
				}
			}
			if (state == CROUCH_KICK) {
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_kick.Reset();
				}
			}
			if (state == CROUCH_PUNCH) {
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_punch.Reset();
				}
			}
			if (state == HIT) {
				if (current_animation->Finished()) {
					state = IDLE;
					hit.Reset();

				}
			}
			if (state == EN_GARDE)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					en_garde.Reset();
				}
			}
		}

		if ((player_input.pressing_F5) && (collider_player_up != nullptr)) {
			collider_player_up->to_delete = true;
			collider_player_up = nullptr;

			if (collider_player_mid != nullptr)
			{
				collider_player_mid->to_delete = true;
				collider_player_mid = nullptr;
			}

			if (collider_player_down != nullptr)
			{
				collider_player_down->to_delete = true;
				collider_player_down = nullptr;
			}
		}
		else if ((player_input.pressing_F5) && (collider_player_up == nullptr))
		{
			collider_player_up = App->collision->AddCollider({ 0, 0,71,95 }, COLLIDER_PLAYER, (Module*)App->player);
			if (collider_player_down == nullptr)
			{
				collider_player_down = App->collision->AddCollider({ 0, 0,71,95 }, COLLIDER_PLAYER, (Module*)App->player);
			}
		}

		if ((state != PUNCH) && (state != KICK) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH) && (collider_player_attack != nullptr))
		{
			collider_player_attack->to_delete = true;
			collider_player_attack = nullptr;
		}
	}
	return UPDATE_CONTINUE;
}


// Update: draw background
update_status ModulePlayer::Update()
{
	lposition = position;
	if (!App->is_paused) {
		switch (state)
		{
		case IDLE:
			current_animation = &idle;
			position.y = initial_position.y;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 15, position.y - 80);
				collider_player_up->SetSize(30, 35);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x + 10, position.y - 45);
				collider_player_down->SetSize(40, 45);
			}
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 10, position.y - 80);
				collider_player_up->SetSize(30, 35);

				collider_player_down->SetPos(position.x - 15, position.y - 45);
				collider_player_down->SetSize(40, 45);
			}
			break;
		case FORWARD:
			current_animation = &forward;
			position.x += speed;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 15, position.y - 85);
				collider_player_up->SetSize(30, 40);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x + 10, position.y - 45);
				collider_player_down->SetSize(35, 45);
			}
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 10, position.y - 85);
				collider_player_up->SetSize(30, 40);

				collider_player_down->SetPos(position.x - 15, position.y - 45);
				collider_player_down->SetSize(35, 45);
			}
			break;
		case BACKWARD:
			current_animation = &backward;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 25, position.y - 85);
				collider_player_up->SetSize(35, 40);
			}
			if (collider_player_down != nullptr) {
				collider_player_down->SetPos(position.x + 20, position.y - 45);
				collider_player_down->SetSize(50, 45);
			}
			position.x -= speed;
			break;

		case CROUCH_DOWN:
			current_animation = &crouch_down;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 45, position.y - 65);
				collider_player_up->SetSize(35, 35);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x + 30, position.y - 30);
				collider_player_down->SetSize(50, 30);
			}
			break;
		case CROUCH_UP:
			current_animation = &crouch_up;
			break;
		case CROUCH_KICK:
			current_animation = &crouch_kick;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 10, position.y - 55);
				collider_player_up->SetSize(40, 35);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x+5, position.y - 20);
				collider_player_down->SetSize(75, 25);
			}
			if (collider_player_attack == nullptr) {
				collider_player_attack = App->collision->AddCollider({ position.x+15, position.y-10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
				collider_player_attack->SetSize(85,15);
			}
			break;
		case CROUCH_PUNCH:
			current_animation = &crouch_punch;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 55, position.y - 45);
				collider_player_up->SetSize(38, 35);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x+15, position.y - 15);
				collider_player_down->SetSize(60, 15);
			}
			if (collider_player_attack == nullptr)
			{
				collider_player_attack = App->collision->AddCollider({ position.x + 55, position.y - 15,80,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
			}
			break;
		case JUMP_NEUTRAL:
			current_animation = &jump_neutral;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x, position.y - 90);
				collider_player_up->SetSize(35, 35);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x, position.y - 50);
				collider_player_down->SetSize(50, 30);
			}
			position.y -= speed * 2 * mult;

			if (position.y <= 115) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_neutral.Reset();
				state = IDLE;
			}
			break;
		case JUMP_FORWARD:
			current_animation = &jump_forward;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 15, position.y - 90);
				collider_player_up->SetSize(40, 50);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x+10, position.y - 50);
				collider_player_down->SetSize(30, 50);
			}
			if (current_animation->SeeCurrentFrame() > 4)
			{
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 10, position.y - 45);
					collider_player_up->SetSize(45, 35);
				}
			}
			if (flip == SDL_FLIP_HORIZONTAL) 
			{
				//Change colliders
			}
			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed;

			if (position.y <= 105) {
				mult = -1;
			}
			else if ((position.y == initial_position.y)||(position.y == initial_position.y+2))
			{
				mult = 1;
				jump_forward.Reset();
				state = IDLE;
			}
			break;
		case JUMP_BACKWARD:
			current_animation = &jump_backward;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x, position.y - 90);
				collider_player_up->SetSize(35, 35);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x, position.y - 50);
				collider_player_down->SetSize(40, 30);
			}
			if (current_animation->SeeCurrentFrame() > 4)
			{
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 10, position.y - 45);
					collider_player_up->SetSize(35, 35);
				}
			}
			position.y -= speed * 1.75 * mult;
			position.x -= 1.25*speed;

			if (position.y <= 110) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_backward.Reset();
				state = IDLE;
			}
			break;
		case PUNCH:
			current_animation = &punch;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 35, position.y - 60);
				collider_player_up->SetSize(50, 47);
			}
			if (collider_player_up != nullptr)
			{
				collider_player_down->SetPos(position.x + 5, position.y - 10);
				collider_player_down->SetSize(70, 15);
			}
			if (collider_player_attack == nullptr)
			{
				collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
				collider_player_attack->to_delete = false;
			}
			collider_player_attack->SetPos(position.x + 60, position.y - 50);
			collider_player_attack->SetSize(67, 30);

			break;
		case KICK:
			current_animation = &kick;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 10, position.y - 70);
				collider_player_up->SetSize(50, 30);

				if (collider_player_mid == nullptr)
				{
					collider_player_mid = App->collision->AddCollider({ position.x + 30,position.y - 50 ,25,30 }, COLLIDER_PLAYER, (Module*)App->player);
					collider_player_mid->SetPos(position.x + 30, position.y - 35);
					collider_player_mid->SetSize(45, 30);
				}
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x + 20, position.y - 80);
				collider_player_down->SetSize(25, 85);
			}
			if (collider_player_attack == nullptr)
			{
				collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
				collider_player_attack->SetPos(position.x + 30, position.y - 35);
				collider_player_attack->SetSize(56, 30);
			}
			break;
		case TWISTER:
			current_animation = &twister;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x + 45, position.y - 75);
				collider_player_up->SetSize(40, 45);
			}
			if (collider_player_down != nullptr)
			{
				collider_player_down->SetPos(position.x + 30, position.y - 35);
				collider_player_down->SetSize(60, 40);
			}
			if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created) {
				App->particles->AddParticle(App->particles->tornado, position.x + 50, position.y - 205, COLLIDER_PLAYER_PARTICLES);
				is_tornado_created = true;
			}
			break;
		case HIT: 
			current_animation = &hit;
			if (collider_player_up != nullptr)
			{
				collider_player_up->SetPos(position.x+15, position.y-85);
				collider_player_down->SetPos(position.x + 10, position.y - 45);
			}
			break;
		case EN_GARDE:
			current_animation = &en_garde;
			break;
		default:
			LOG("No state found :(");
			break;
		}
	}
	
	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	if (position.x < App->player2->position.x) {
		flip = SDL_FLIP_NONE;
	}
	else {
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (flip == SDL_FLIP_HORIZONTAL) {
		App->render->Blit(graphics, position.x - current_animation->GetCurrentRect().w / 2, position.y - r.h, &r, flip);
	}
	else
		App->render->Blit(graphics, position.x, position.y - r.h, &r, flip);


	return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp() {
	LOG("Unloading player");
	App->textures->Unload(graphics);
	App->audio->UnLoadFx(light_attack_fx);
	App->audio->UnLoadFx(light_kick_fx);
	App->audio->UnLoadFx(hit_fx);
	App->audio->UnLoadFx(twister_fx);
	collider_player_up = nullptr;
	collider_player_mid = nullptr;
	collider_player_down = nullptr;
	return true;
}


void ModulePlayer::OnCollision(Collider* c1,Collider* c2) {

	switch (c2->type)
	{
	case COLLIDER_WALL_LEFT:
		if (!player_input.pressing_D)
			position.x += speed;

		break;
	case COLLIDER_WALL_RIGHT:
		if (!player_input.pressing_A)
			position.x -= speed;
		break;
	case COLLIDER_PLAYER_2:
		if (((state != KICK) && (state != PUNCH) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH)) && (state != TWISTER))
		{
			if (position.x < App->player2->position.x)
			{
				position.x = lposition.x - speed;
			}
			else
			{
			position.x = lposition.x + speed;
			}
		}
		break;
	case COLLIDER_PLAYER_2_ATTACK:
		if (!App->player2->collider_player_2_attack->to_delete) {
			App->player2->hit_percent++;
			App->audio->PlayFX(hit_fx);
			life -= 10;
			state = HIT;
			App->player2->collider_player_2_attack->to_delete = true;
			if (position.x < App->player2->position.x)
			{
				position.x += -10;
			}
			else
			{
				position.x += 10;
			}
			switch (App->player2->state2)
			{
			case States2::KICK2:
				App->ui->player2_point += 50;
				break;
			case States2::PUNCH2:
				App->ui->player2_point += 50;
				break;
			case States2::CROUCH_PUNCH2:
				App->ui->player2_point += 200;
				break;
			case States2::CROUCH_KICK2:
				App->ui->player2_point += 200;
				break;
			case States2::TWISTER2:
				App->ui->player2_point += 400;
			default:
				break;
			}
		}

		break;
	case COLLIDER_PLAYER_2_PARTICLES:
		App->audio->PlayFX(hit_fx);
		life -= 20;
		state = HIT;
		position.x -= 5;
		break;
	default:
		break;
	}
}

void ModulePlayer::PlayerCollidersCleanUp() {
	if (collider_player_up != nullptr)
	{
		collider_player_up->to_delete = true;
	}
	if (collider_player_mid != nullptr)
	{
		collider_player_mid->to_delete = true;
	}
	if (collider_player_down != nullptr)
	{
		collider_player_down->to_delete = true;
	}
}