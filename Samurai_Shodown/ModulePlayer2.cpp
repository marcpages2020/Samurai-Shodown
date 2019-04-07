#include "ModulePlayer2.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModulePlayer2::ModulePlayer2()
{
	position.x = 230;
	position.y = initial_y;

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

		//jump animation
		{
			jump.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
			jump.PushBack({ 80, 371, 60, 112 }, 0.2f); //2
			jump.PushBack({ 145, 371, 60, 112 }, 0.2f); //3
			jump.PushBack({ 209, 371, 75, 92 }, 0.2f);
			jump.PushBack({ 288, 371, 75, 92 }, 0.2f);
			jump.PushBack({ 367, 371, 75, 92 }, 0.2f);
			jump.PushBack({ 446, 371, 78, 83 }, 0.2f);
			jump.PushBack({ 209, 371, 75, 92 }, 0.2f);
			jump.PushBack({ 288, 371, 75, 92 }, 0.2f);
			jump.PushBack({ 367, 371, 75, 92 }, 0.2f);
			jump.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
			jump.PushBack({ 80, 371, 60, 112 }, 0.2f);
			jump.PushBack({ 145, 371, 60, 112 }, 0.2f);
			jump.PushBack({ 527, 371, 68, 112 }, 0.2f); //8
			jump.PushBack({ 601, 371, 68, 112 }, 0.2f); //9
			jump.PushBack({ 674, 371, 68, 112 }, 0.2f); //10
		}

		//punch animation
		{
			punch.PushBack({ 14, 236, 69, 127 }, 0.5f);
			punch.PushBack({ 87, 236, 69, 127 }, 0.3f);
			punch.PushBack({ 160, 266, 79, 97 }, 0.3f);
			punch.PushBack({ 243, 269, 79, 96 }, 0.5f);
			punch.PushBack({ 327, 267, 79, 97 }, 0.5f);
			punch.PushBack({ 410, 270, 129, 93 }, 0.5f);
			punch.PushBack({ 545, 277, 130, 86 }, 0.5f);
			punch.PushBack({ 679, 280, 130, 83 }, 0.5f);
			punch.PushBack({ 814, 280, 129, 95 }, 0.5f); //9
			punch.PushBack({ 946, 280, 130, 95 }, 0.5f);
			punch.PushBack({ 1081, 280, 130, 95 }, 0.5f);
			punch.PushBack({ 1213, 280, 120, 95 }, 0.5f);
			punch.PushBack({ 1337, 280, 120, 95 }, 0.5f);
			punch.PushBack({ 1461, 280, 83, 95 }, 0.8f);
			punch.PushBack({ 1548, 280, 83, 95 }, 0.8f);
			punch.PushBack({ 1635, 280, 83, 95 }, 0.8f); //16
			//punch.PushBack({ 1721, 278,131, 96 }, 0.7f);
			//punch.PushBack({ 1856, 278, 131, 96 }, 0.7f);
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

		//crouch animation
		{
			crouch.PushBack({ 15, 732, 68, 110 }, 0.2f);
			crouch.PushBack({ 94, 732, 68, 110 }, 0.2f);
			crouch.PushBack({ 180, 732, 68, 110 }, 0.2f);
			crouch.PushBack({ 253, 766, 88, 76 }, 0.2f);
			crouch.PushBack({ 358, 766, 88, 76 }, 0.2f);
			crouch.PushBack({ 459, 766, 88, 76 }, 0.2f);
			crouch.PushBack({ 558, 766, 88, 76 }, 0.2f);
			crouch.PushBack({ 656, 766, 88, 76 }, 0.2f);
			crouch.PushBack({ 769, 732, 68, 110 }, 0.2f);
			crouch.PushBack({ 846, 732, 68, 110 }, 0.2f);
			crouch.PushBack({ 919, 732, 68, 110 }, 0.2f);
			crouch.loop = false;
		}

		//twister animation
		{
			twister.PushBack({ 15, 798, 90, 90 }, 0.6f);
			twister.PushBack({ 106, 798, 90, 90 }, 0.6f);
			twister.PushBack({ 197, 798, 90, 90 }, 0.6f);
			twister.PushBack({ 289, 798, 71, 90 }, 0.6f);
			twister.PushBack({ 362, 798, 71, 90 }, 0.6f);
			twister.PushBack({ 435, 803, 74, 86 }, 0.6f);
			twister.PushBack({ 511, 803, 74, 86 }, 0.6f);
			twister.PushBack({ 586, 795, 59, 94 }, 0.6f);
			twister.PushBack({ 646, 795, 59, 94 }, 0.6f);
			twister.PushBack({ 709, 788, 93, 101 }, 0.6f);
			twister.PushBack({ 809, 788, 93, 101 }, 0.6f);
			twister.PushBack({ 909, 788, 93, 101 }, 0.6f);
			twister.PushBack({ 1006, 734, 62, 155 }, 0.6f);
			twister.PushBack({ 1071, 734, 62, 155 }, 0.6f);
			twister.PushBack({ 1138, 734, 62, 155 }, 0.6f);
			twister.PushBack({ 1203, 787, 100, 102 }, 0.6f);
			twister.PushBack({ 1313, 787, 100, 102 }, 0.6f);
			twister.PushBack({ 1429, 787, 100, 102 }, 0.6f);
			twister.PushBack({ 1543, 795, 98, 94 }, 0.6f);
			twister.PushBack({ 1646, 795, 98, 94 }, 0.6f);
			twister.PushBack({ 1749, 795, 98, 94 }, 0.6f);
			twister.PushBack({ 15, 923, 104, 93 }, 0.6f);
			twister.PushBack({ 121, 923, 104, 93 }, 0.6f);
			twister.PushBack({ 228, 923, 104, 93 }, 0.6f);
			twister.PushBack({ 337, 923, 84, 93 }, 0.6f);
			twister.PushBack({ 425, 923, 84, 93 }, 0.6f);
			twister.PushBack({ 512, 923, 84, 93 }, 0.6f);
			twister.PushBack({ 599, 896, 72, 120 }, 0.6f);
			twister.PushBack({ 673, 896, 72, 120 }, 0.6f);
			twister.PushBack({ 748, 896, 72, 120 }, 0.6f);
			twister.loop = false;

			//Twister animation (only the twister)


			twisterAlone.loop = false;
		}
	}
}

ModulePlayer2::~ModulePlayer2() {}

// Load assets
bool ModulePlayer2::Start()
{
	bool ret = true;
	LOG("Loading player textures\n");
	graphics = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");
	//state = IDLE;
	current_animation = &idle;
	if (!collider_player2)
		collider_player2 = App->collision->AddCollider({ 0, 0,71,95 }, COLLIDER_PLAYER_2, (Module*)App->player);
	return ret;
}

update_status ModulePlayer2::PreUpdate()
{

	/*
	if (state == IDLE) {
		if (player_input.pressing_A)
			state = BACKWARD;
		if (player_input.pressing_D)
			state = FORWARD;
		if (player_input.pressing_J)
			state = KICK;
		if (player_input.pressing_U)
			state = PUNCH;
		if (player_input.pressing_W)
			state = JUMP;
		if (player_input.pressing_S)
			state = CROUCH;
		if (player_input.pressing_K)
			state = TWISTER;
			
	}
	
	if (state == BACKWARD) {
		if (!player_input.pressing_A)
			state = IDLE;
	}
	if (state == FORWARD) {
		if (!player_input.pressing_D)
			state = IDLE;
	}
	if (state == KICK) {
		if (current_animation->Finished()) {
			state = IDLE;
			kick.Reset();
		}
	}
	if (state == PUNCH) {

		if (current_animation->Finished()) {
			state = IDLE;
			punch.Reset();
		}
	}
	if (state == JUMP)
	{
		if (current_animation == &jump && current_animation->Finished())
		{
			state = IDLE;
			jump.Reset();
		}
	}
	if (state == CROUCH)
	{
		if (current_animation->Finished())
		{
			state = IDLE;
			crouch.Reset();
		}
	}
	if (state == TWISTER)
	{
		if (current_animation->Finished())
		{
			state = IDLE;
			twister.Reset();
		}
	}
	if ((player_input.pressing_F5) && (god_mode == false))
		god_mode = true;
	else if ((player_input.pressing_F5) && (god_mode == true))
		god_mode = false;
		*/
	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	lposition = position;
	/*switch (state)
	{
	case IDLE:
		current_animation = &idle;
		position.y = initial_y;
		break;
	case PUNCH:
		current_animation = &punch;
		if (((int)punch.SeeCurrentFrame() >= 7) && ((int)punch.SeeCurrentFrame() <= 17))
		{
			position.y = initial_y + 11.5;
		}
		else { position.y = initial_y; }
		break;
	case JUMP:
		current_animation = &jump;
		position.y -= speed * 1.75 * mult;
		if (position.y <= 120) {
			mult = -1;
		}
		else if (position.y == initial_y)
		{
			mult = 1;
			jump.Reset();
			state = IDLE;
		}
		break;
	case KICK:
		current_animation = &kick;
		break;
	case FORWARD:
		current_animation = &forward;
		position.x += speed;
		break;
	case BACKWARD:
		current_animation = &backward;
		position.x -= speed;
		break;
	case CROUCH:
		current_animation = &crouch;
		break;
	case TWISTER:
		current_animation = &twister;
		if (current_animation->SeeCurrentFrame() == 10)
			App->particles->AddParticle(App->particles->tornado, position.x + 50, position.y - 205);
		//			collider_player_particles = App->collision->AddCollider({ position.x + 50,position.y - 205,83,207 }, COLLIDER_PLAYER_PARTICLES, (Module*)App->player);
		break;
	default:
		LOG("No state found :(");
		break;
	}*/

	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	//if (god_mode == false)
	//{
		collider_player2->SetPos(position.x, position.y - 95);
	//}
	//else if (god_mode == true)
	//{
		//collider_player2->SetPos(2000, 2000);
	//}

	//collider_player_particles->SetPos(App->particles->tornado.position.x, App->particles->tornado.position.y);
	return UPDATE_CONTINUE;
}

bool ModulePlayer2::CleanUp() {
	LOG("Unloading player");
	App->textures->Unload(graphics);
	collider_player2 = nullptr;
	return true;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	switch (c2->type)
	{
	case COLLIDER_WALL:
		position.x = lposition.x;
		break;
	default:
		break;
	}

}
