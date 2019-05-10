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
	//idle animation
	{
		idle2.PushBack({ 27,26,118,126 }, 0.3f);
		idle2.PushBack({ 147,26,118,126 }, 0.3f);
		idle2.PushBack({ 266,26,118,126 }, 0.3f);
		idle2.PushBack({ 386,26,118,126 }, 0.3f);
		idle2.PushBack({ 505,26,118,126 }, 0.3f);
		idle2.PushBack({ 623,26,118,126 }, 0.3f);
		idle2.PushBack({ 741,40,118,110 }, 0.3f);
		idle2.PushBack({ 857,40,118,110 }, 0.3f);
		idle2.PushBack({ 973,40,118,110 }, 0.3f);
	}
}

ModulePlayer2::~ModulePlayer2() {}

// Load assets
bool ModulePlayer2::Start()
{
	bool ret = true;
	LOG("Loading player 2\n");
	player2_textures = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu.png");
	state2 = IDLE2;
	god = false;
	life = 100;
	current_animation = &idle2;
	position.x = initial_position.x = shadow_x = 280;
	position.y = initial_position.y = 215;
	lposition = position;
	if (!collider_player_2_up)
		collider_player_2_up = App->collision->AddCollider({ position.x + 15, position.y - 85,30,40 }, COLLIDER_PLAYER_2, (Module*)App->player2);
	if (!collider_player_2_down)
		collider_player_2_down = App->collision->AddCollider({ position.x + 10, position.y - 45,40,45 }, COLLIDER_PLAYER_2, (Module*)App->player2);

	App->ui->Enable();
	return ret;
}

update_status ModulePlayer2::PreUpdate()
{
	if (!App->is_paused) {
		if (controls) {
			player_input2.pressing_left = App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT;
			player_input2.pressing_right = App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT;
			player_input2.pressing_down = App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT;
			player_input2.pressing_up = App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN;
			player_input2.pressing_J = App->input->keyboard[SDL_SCANCODE_J] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][1] == KEY_DOWN;
			player_input2.pressing_K = App->input->keyboard[SDL_SCANCODE_K] == KEY_DOWN;
			player_input2.pressing_L = App->input->keyboard[SDL_SCANCODE_L] == KEY_DOWN;
			player_input2.pressing_F5 = App->input->keyboard[SDL_SCANCODE_F5] == KEY_DOWN;

			if (player_input2.pressing_left && player_input2.pressing_right) {
				player_input2.pressing_left = false;
				player_input2.pressing_right = false;
			}
		}
		

		if (state2 == IDLE2) {
			if (player_input2.pressing_left)
				state2 = FORWARD2;
			if (player_input2.pressing_right)
				state2 = BACKWARD2;
			if (player_input2.pressing_J) {
				hit_done++;
				state2 = KICK2;
				App->audio->PlayFX(light_kick_fx);
			}
			if (player_input2.pressing_K) {
				hit_done++;
				state2 = PUNCH2;
				App->audio->PlayFX(light_attack_fx);
			}
			if (player_input2.pressing_up)
				state2 = JUMP_NEUTRAL2;
			if (player_input2.pressing_down)
				state2 = CROUCH_DOWN2;
			if (player_input2.pressing_L) {
				hit_done++;
				App->audio->PlayFX(twister_fx);
				state2 = TWISTER2;
			}
		}
		if (state2 == BACKWARD2) {
			if (!player_input2.pressing_right)
				state2 = IDLE2;
			if (player_input2.pressing_K) {
				hit_done++;
				state2 = PUNCH2;
			}

			if (player_input2.pressing_J) {
				hit_done++;
				state2 = KICK2;
			}

			if (player_input2.pressing_up)
				state2 = JUMP_BACKWARD2;
		}
		if (state2 == FORWARD2) {
			if (!player_input2.pressing_left)
				state2 = IDLE2;
			if (player_input2.pressing_K) {
				hit_done++;
				state2 = PUNCH2;
			}

			if (player_input2.pressing_J) {
				hit_done++;
				state2 = KICK2;
			}

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
			if (player_input2.pressing_right && mult == 1)
				state2 = JUMP_BACKWARD2;
			if (player_input2.pressing_left && mult == 1)
				state2 = JUMP_FORWARD2;
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
			if (player_input2.pressing_J) {
				hit_done++;
				state2 = CROUCH_KICK2;
				App->audio->PlayFX(light_kick_fx);
			}
			if (player_input2.pressing_K) {
				hit_done++;
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
				hit_done++;
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
			if (position.y < initial_position.y)
			{
				position.y++;
			}
			else if(current_animation->Finished()){
				state2 = IDLE2;
				hit2.Reset();
			}
		}
		if ((player_input2.pressing_F5)) {
			god = !god;
		}

		if ((state2 != PUNCH2) && (state2 != KICK2) && (state2 != CROUCH_KICK2) && (state2 != CROUCH_PUNCH2) && (collider_player_2_attack != nullptr))
		{
			collider_player_2_attack->to_delete = true;
			collider_player_2_attack = nullptr;
		}
		if (state2 == WIN2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				win2.Reset();
			}
		}
		if (state2 == EN_GARDE2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				en_garde2.Reset();
			}
		}
	}
	
	return UPDATE_CONTINUE;
}

update_status ModulePlayer2::Update()
{
	lposition = position;
	if (!App->is_paused) {
		switch (state2)
		{
		case IDLE2:
			current_animation = &idle2;
			position.y = lposition.y;
			shadow_x = position.x;
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 15, position.y - 80);
				collider_player_2_up->SetSize(30, 35);

				collider_player_2_down->SetPos(position.x + 10, position.y - 45);
				collider_player_2_down->SetSize(40, 45);
				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 10, position.y - 80);
					collider_player_2_up->SetSize(30, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 15, position.y - 45);
					collider_player_2_down->SetSize(40, 45);
				}
			}
			break;
		case FORWARD2:
			current_animation = &forward2;
			position.x -= speed;
			shadow_x = position.x;
			
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 15, position.y - 85);
				collider_player_2_up->SetSize(30, 40);

				collider_player_2_down->SetPos(position.x + 10, position.y - 45);
				collider_player_2_down->SetSize(35, 45);
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 10, position.y - 85);
					collider_player_2_up->SetSize(30, 40);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 15, position.y - 45);
					collider_player_2_down->SetSize(35, 45);
				}
			}
			break;
		case BACKWARD2:
			current_animation = &backward2;
			shadow_x = position.x;
			
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 25, position.y - 85);
				collider_player_2_up->SetSize(35, 40);

				collider_player_2_down->SetPos(position.x + 20, position.y - 45);
				collider_player_2_down->SetSize(50, 45);
				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 25, position.y - 85);
					collider_player_2_up->SetSize(35, 40);
				}
				if (collider_player_2_down != nullptr) {
					collider_player_2_down->SetPos(position.x - 30, position.y - 45);
					collider_player_2_down->SetSize(50, 45);
				}
			}
			position.x += speed;
			break;

		case CROUCH_DOWN2:
			current_animation = &crouch_down2;
			shadow_x = position.x-5;
			
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 20, position.y - 65);
				collider_player_2_up->SetSize(35, 35);

				collider_player_2_down->SetPos(position.x + 10, position.y - 30);
				collider_player_2_down->SetSize(50, 30);

				collider_player_2_up->SetPos(position.x + 45, position.y - 65);
				collider_player_2_up->SetSize(35, 35);

				collider_player_2_down->SetPos(position.x + 30, position.y - 30);
				collider_player_2_down->SetSize(50, 30);
				shadow_x = position.x+shadow_w/3;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 80);
					collider_player_2_up->SetSize(35, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 20, position.y - 30);
					collider_player_2_down->SetSize(50, 30);
				}
				if (collider_player_2_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
					collider_player_2_up->SetPos(position.x - 40, position.y - 65);
					collider_player_2_up->SetSize(35, 35);

					collider_player_2_down->SetPos(position.x - 40, position.y - 30);
					collider_player_2_down->SetSize(50, 30);
				}
			}
			break;
		case CROUCH_UP2:
			current_animation = &crouch_up2;
			break;
		case CROUCH_KICK2:
			current_animation = &crouch_kick2;
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr) {
					collider_player_2_up->SetPos(position.x + 10, position.y - 55);
					collider_player_2_up->SetSize(40, 35);
				}
				if (collider_player_2_down) {
					collider_player_2_down->SetPos(position.x + 5, position.y - 20);
					collider_player_2_down->SetSize(75, 25);
				}

				if (collider_player_2_attack == nullptr) {
					collider_player_2_attack = App->collision->AddCollider({ position.x + 15, position.y - 10,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
					collider_player_2_attack->SetSize(85, 15);
					shadow_x = position.x;
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 10, position.y - 55);
					collider_player_2_up->SetSize(40, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 20);
					collider_player_2_down->SetSize(75, 25);
				}
				if (collider_player_2_attack == nullptr) {
					collider_player_2_attack = App->collision->AddCollider({ position.x - 50, position.y - 10,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
					collider_player_2_attack->SetSize(85, 15);
				}
			}
			break;
		case CROUCH_PUNCH2:
			current_animation = &crouch_punch2;
			shadow_x = position.x;
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 55, position.y - 45);
				collider_player_2_up->SetSize(38, 35);

				collider_player_2_down->SetPos(position.x + 15, position.y - 15);
				collider_player_2_down->SetSize(60, 15);

				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x + 55, position.y - 15,80,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
				}
				shadow_x = position.x+shadow_w/3;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 40, position.y - 65);
					collider_player_2_up->SetSize(35, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 30);
					collider_player_2_down->SetSize(100, 30);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x - 70, position.y - 15,80,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
				}
			}
			break;
		case JUMP_NEUTRAL2:
			current_animation = &jump_neutral2;			
			position.y -= speed * 2 * mult;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{

				mult = 1;
				jump_neutral2.Reset();
				state2 = IDLE2;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x, position.y - 90);
				collider_player_2_up->SetSize(35, 35);

				collider_player_2_down->SetPos(position.x, position.y - 50);
				collider_player_2_down->SetSize(50, 30);
				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x, position.y - 90);
					collider_player_2_up->SetSize(35, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 12, position.y - 50);
					collider_player_2_down->SetSize(50, 30);
				}
			}
			break;
		case JUMP_FORWARD2:
			current_animation = &jump_forward2;
			
			position.y -= speed * 1.75 * mult;
			position.x -= 1.25*speed;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_forward2.Reset();
				state2 = IDLE2;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
				jump_forward2.Reset();
				state2 = IDLE2;
			}
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 15, position.y - 1000);
				collider_player_2_up->SetSize(40, 50);
				
				collider_player_2_down->SetPos(position.x + 10, position.y - 60);
				collider_player_2_down->SetSize(30, 30);
				
				if (current_animation->SeeCurrentFrame() > 4)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x + 10, position.y - 55);
						collider_player_2_up->SetSize(45, 35);
					}
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 20, position.y - 90);
					collider_player_2_up->SetSize(40, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x, position.y - 50);
					collider_player_2_down->SetSize(30, 30);
				}
				if (current_animation->SeeCurrentFrame() > 5)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x - 20, position.y - 45);
						collider_player_2_up->SetSize(45, 35);
					}
				}
			}
			shadow_x = position.x;
			break;
		case JUMP_BACKWARD2:
			current_animation = &jump_backward2;
			
			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_backward2.Reset();
				state2 = IDLE2;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
				jump_backward2.Reset();
				state2 = IDLE2;
			}
			if (flip != SDL_FLIP_HORIZONTAL) 
			{				
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x, position.y - 90);
					collider_player_2_up->SetSize(35, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x, position.y - 50);
					collider_player_2_down->SetSize(40, 30);
				}
				if (current_animation->SeeCurrentFrame() > 4) {
					collider_player_2_up->SetPos(position.x + 20, position.y - 45);
					collider_player_2_up->SetSize(35, 35);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x, position.y - 90);
					collider_player_2_up->SetSize(35, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x, position.y - 50);
					collider_player_2_down->SetSize(40, 30);
				}
				if (current_animation->SeeCurrentFrame() > 4)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x - 20, position.y - 45);
						collider_player_2_up->SetSize(35, 35);
					}
				}
			}
			shadow_x = position.x;
			break;
		case PUNCH2:
			current_animation = &punch2;

			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x +20, position.y - 60);
					collider_player_2_up->SetSize(50, 47);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x, position.y - 10);
					collider_player_2_down->SetSize(70, 15);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x + 60, position.y - 50);
					collider_player_2_attack->SetSize(67, 30);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 20, position.y - 60);
					collider_player_2_up->SetSize(50, 47);
				}
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 10, position.y - 10);
					collider_player_2_down->SetSize(70, 15);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x - 500, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x - 60, position.y - 50);
					collider_player_2_attack->SetSize(67, 30);
				}
			}
			break;
		case KICK2:
			current_animation = &kick2;

			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr) {
					collider_player_2_up->SetPos(position.x + 10, position.y - 70);
					collider_player_2_up->SetSize(50, 30);
				}
				if (collider_player_2_down != nullptr) {
					collider_player_2_down->SetPos(position.x + 20, position.y - 80);
					collider_player_2_down->SetSize(25, 85);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
					collider_player_2_attack->SetPos(position.x + 30, position.y - 35);
					collider_player_2_attack->SetSize(56, 30);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 20, position.y - 70);
					collider_player_2_up->SetSize(50, 30);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x, position.y - 80);
					collider_player_2_down->SetSize(25, 85);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x - 43, position.y - 35,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetSize(56, 30);
				}
			}
			break;
		case TWISTER2:
			current_animation = &twister2;

			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x+15, position.y - 75);
					collider_player_2_up->SetSize(40, 45);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x+5, position.y - 35);
					collider_player_2_down->SetSize(60, 40);
				}
				if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created2) {
					Particle* p = App->particles->AddParticle(App->particles->tornado, position.x, position.y - 205, COLLIDER_PLAYER_2_PARTICLES);
					is_tornado_created2 = true;
					p->speed = { -2,0 };
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x-20, position.y - 75);
					collider_player_2_up->SetSize(40, 45);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x-30, position.y - 35);
					collider_player_2_down->SetSize(60, 40);
				}
				if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created2) {
					App->particles->AddParticle(App->particles->tornado, position.x, position.y - 205, COLLIDER_PLAYER_2_PARTICLES);
					is_tornado_created2 = true;
				}
			}
			break;
		case DEATH2:
			current_animation = &die2;
			position.y = initial_position.y + 10;
			break;
		case EN_GARDE2:
			current_animation = &en_garde2;
			break;
		case WIN2:
			current_animation = &win2;
			break;
		case HIT2:
			current_animation = &hit2;
			shadow_x = position.x;
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 15, position.y - 85);
				collider_player_2_down->SetPos(position.x + 20, position.y - 45);
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x-15, position.y - 85);						
				}
				if (collider_player_2_down != nullptr) 
				{
					collider_player_2_down->SetPos(position.x-30, position.y - 45);
				}
			}
			break;
		}
	}

	if ((position.y < initial_position.y) && ((state2 != JUMP_BACKWARD2) && (state2 != JUMP_NEUTRAL2) && (state2 != JUMP_FORWARD2) && (state2 != HIT2)))
	{
		state2 = JUMP_NEUTRAL2;
	}

	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	SDL_Rect shadow = { 1348, 2627, 70, 17 };

	if (position.x < App->player->position.x) {
		flip = SDL_FLIP_NONE;
	}
	else {
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (flip == SDL_FLIP_HORIZONTAL) {
		if (shadow_blit) {
			App->render->Blit(player2_textures, shadow_x - shadow.w / 2, initial_position.y - 7, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		App->render->Blit(player2_textures, position.x - current_animation->GetCurrentRect().w / 2, position.y - r.h, &r, flip);
	}
	else {
		if (shadow_blit) {
			App->render->Blit(player2_textures, shadow_x, initial_position.y - 7, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		App->render->Blit(player2_textures, position.x, position.y - r.h, &r, flip);

	}

	return UPDATE_CONTINUE;
}

bool ModulePlayer2::CleanUp() {
	LOG("Unloading player");

	App->audio->UnLoadFx(light_attack_fx);
	App->audio->UnLoadFx(light_kick_fx);
	App->audio->UnLoadFx(twister_fx);
	App->audio->UnLoadFx(hit_fx);
	App->collision->CleanUp();
	collider_player_2_up = nullptr;
	collider_player_2_mid = nullptr;
	collider_player_2_down = nullptr;
	collider_player_2_attack = nullptr;
	App->ui->Disable();
	return true;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {
	if (state2 != DEATH2) {
		switch (c2->type)
		{
		case COLLIDER_WALL_LEFT:
			if (!player_input2.pressing_right && state2 != DEATH2 && state2 != WIN2)
				position.x += speed;

			break;
		case COLLIDER_WALL_RIGHT:
			if (!player_input2.pressing_left && state2 != DEATH2 && state2 != WIN2)
				position.x -= speed;
			break;
		case COLLIDER_PLAYER:
			if (((state2 != KICK2) && (state2 != PUNCH2) && (state2 != CROUCH_KICK2) && (state2 != CROUCH_PUNCH2)) && (state2 != TWISTER2) && (state2 != DEATH2) && (state2 != WIN2))
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
			if (!App->player->collider_player_attack->to_delete && !god) {
				App->player->hit_percent++;
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
					break;				
				default:
					break;
				}
				App->audio->PlayFX(hit_fx);
				life -= 10;
				state2 = HIT2;
				App->player->collider_player_attack->to_delete = true;
				if ((position.x < App->player->position.x)&&(position.x>App->render->left->rect.x+60))
				{
					position.x -= 10;
				}
				else if ((position.x > App->player->position.x) && (position.x > App->render->right->rect.x))
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

void ModulePlayer2::BlockControls(bool block)
{
	controls = !block;
}
