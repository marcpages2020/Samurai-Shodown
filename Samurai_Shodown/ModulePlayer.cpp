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
	
	//idle animation
	{
		idle.PushBack({ 27,26,118,126 }, 0.3f);
		idle.PushBack({ 147,26,118,126 }, 0.3f);
		idle.PushBack({ 266,26,118,126 }, 0.3f);
		idle.PushBack({ 386,26,118,126 }, 0.3f);
		idle.PushBack({ 505,26,118,126 }, 0.3f);
		idle.PushBack({ 623,26,118,126 }, 0.3f);
		idle.PushBack({ 741,40,118,110 }, 0.3f);
		idle.PushBack({ 857,40,118,110 }, 0.3f);
		idle.PushBack({ 973,40,118,110 }, 0.3f);
	}
}

ModulePlayer::~ModulePlayer(){}

// Load assets
bool ModulePlayer::Start()
{
	bool ret = true;
	LOG("Loading player 1\n");
	player_textures = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu.png");
	App->ui->player1_point = 0;
	App->ui->player2_point = 0;
	state = IDLE;
	current_animation = &idle;
	initial_position.x = position.x = shadow_x = 70;
	position.y = initial_position.y = 215;
	lposition = position;
	if (!collider_player_up)
		collider_player_up = App->collision->AddCollider({ position.x+15, position.y-85,30,40 },COLLIDER_PLAYER,(Module*)App->player);
	if (!collider_player_down)
		collider_player_down = App->collision->AddCollider({ position.x+10, position.y-45,40,45 }, COLLIDER_PLAYER, (Module*)App->player);
	return ret;
}

update_status ModulePlayer::PreUpdate()
{
	if (!App->is_paused) {
		if (controls) {
			player_input.pressing_A = App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTX) <= -10000;
			player_input.pressing_D = App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTX) >= 10000;
			player_input.pressing_C = App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][0] == KEY_DOWN;
			player_input.pressing_S = App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTY) >= 10000;
			player_input.pressing_V = App->input->keyboard[SDL_SCANCODE_V] == KEY_DOWN;
			player_input.pressing_W = App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTY) <= -10000;
			player_input.pressing_B = App->input->keyboard[SDL_SCANCODE_B] == KEY_DOWN;
			player_input.pressing_F4 = App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN;
			player_input.pressing_Q = App->input->keyboard[SDL_SCANCODE_Q] == KEY_DOWN;

			if (player_input.pressing_A && player_input.pressing_D) {
				player_input.pressing_A = false;
				player_input.pressing_D = false;
			}

		}

		//states 
		{
			if (state == IDLE) {
				if (player_input.pressing_Q) {
					state = WIN;
				}
				if (player_input.pressing_A)
					state = BACKWARD;
				if (player_input.pressing_D)
					state = FORWARD;
				if (player_input.pressing_C) {
					state = KICK;
					hit_done++;
					App->audio->PlayFX(light_kick_fx);
				}
				if (player_input.pressing_V) {
					state = PUNCH;
					hit_done++;
					App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_W)
					state = JUMP_NEUTRAL;
				if (player_input.pressing_S)
					state = CROUCH_DOWN;
				if (player_input.pressing_B) {
					App->audio->PlayFX(twister_fx);
					hit_done++;
					state = TWISTER;
				}
			}
			if (state == BACKWARD) {
				if (!player_input.pressing_A)
					state = IDLE;
				if (player_input.pressing_V)
				{
					hit_done++;
					state = PUNCH;
					App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_C) {
					hit_done++;
					state = KICK;
				}
				if (player_input.pressing_W)
					state = JUMP_BACKWARD;
			}
			if (state == FORWARD) {
				if (!player_input.pressing_D)
					state = IDLE;
				if (player_input.pressing_V) {
					hit_done++;
					state = PUNCH;
					App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_C) {
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
				if (player_input.pressing_C) {
					hit_done++;
					state = CROUCH_KICK;
					App->audio->PlayFX(light_kick_fx);
				}
				if (player_input.pressing_V) {
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
				if (position.y < initial_position.y)
				{
					position.y++;
				}
				else if (current_animation->Finished()){
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
			if (state == WIN)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					win.Reset();
				}
			}

			if ((player_input.pressing_F4)) {
				god = !god;
			}

			if ((state != PUNCH) && (state != KICK) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH) && (collider_player_attack != nullptr))
			{
				collider_player_attack->to_delete = true;
				collider_player_attack = nullptr;
			}
		}
	}
	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	lposition = position;
	shadow_x = position.x;

	if (!App->is_paused) {
		switch (state)
		{
		case IDLE:
			current_animation = &idle;
			position.y = initial_position.y;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 10, position.y - 80);
				collider_player_up->SetSize(30, 35);

				collider_player_down->SetPos(position.x - 15, position.y - 45);
				collider_player_down->SetSize(40, 45);
				shadow_x = position.x;
			}else{
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
			}
			break;
		case FORWARD:
			current_animation = &forward;
			position.x += speed;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 10, position.y - 85);
				collider_player_up->SetSize(30, 40);

				collider_player_down->SetPos(position.x - 15, position.y - 45);
				collider_player_down->SetSize(35, 45);
			}
			else {
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
			}
			break;
		case BACKWARD:
			current_animation = &backward;
			shadow_x = position.x + 10;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 25, position.y - 85);
				collider_player_up->SetSize(35, 40);
				collider_player_down->SetPos(position.x - 30, position.y - 45);
				collider_player_down->SetSize(50, 45);
				shadow_x = position.x;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 25, position.y - 85);
					collider_player_up->SetSize(35, 40);
				}
				if (collider_player_down != nullptr) {
					collider_player_down->SetPos(position.x + 20, position.y - 45);
					collider_player_down->SetSize(50, 45);
				}
			}
			position.x -= speed;
			break;

		case CROUCH_DOWN:
			current_animation = &crouch_down;
			shadow_x = position.x + 16;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 15, position.y - 80);
				collider_player_up->SetSize(35, 50);

				collider_player_down->SetPos(position.x - 20, position.y - 30);
				collider_player_down->SetSize(50, 30);
				
				collider_player_up->SetPos(position.x - 40, position.y - 65);
				collider_player_up->SetSize(35, 35);
				
				collider_player_down->SetPos(position.x - 40, position.y - 30);
				collider_player_down->SetSize(50, 30);
				shadow_x -= shadow_w / 3;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 20, position.y - 65);
					collider_player_up->SetSize(35, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 30);
					collider_player_down->SetSize(50, 30);
				}
				if (collider_player_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
					collider_player_up->SetPos(position.x + 45, position.y - 65);
					collider_player_up->SetSize(35, 35);

					collider_player_down->SetPos(position.x + 30, position.y - 30);
					collider_player_down->SetSize(50, 30);
				}
			}
			break;
		case CROUCH_UP:
			current_animation = &crouch_up;
			break;
		case CROUCH_KICK:
			current_animation = &crouch_kick;

			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr) {
					collider_player_up->SetPos(position.x - 10, position.y - 55);
					collider_player_up->SetSize(40, 35);
				}

				if (collider_player_down != nullptr) {
					collider_player_down->SetPos(position.x - 30, position.y - 20);
					collider_player_down->SetSize(75, 25);
				}
				
				if (collider_player_attack == nullptr) {
					collider_player_attack = App->collision->AddCollider({ position.x - 50, position.y - 10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetSize(85, 15);
				}
			}
			else {

				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 10, position.y - 55);
					collider_player_up->SetSize(40, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 5, position.y - 20);
					collider_player_down->SetSize(75, 25);
				}
				if (collider_player_attack == nullptr) {
					collider_player_attack = App->collision->AddCollider({ position.x + 15, position.y - 10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetSize(85, 15);
				}
			}
			break;
		case CROUCH_PUNCH:
			current_animation = &crouch_punch;
			shadow_x = position.x + 20;
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 40, position.y - 65);
				collider_player_up->SetSize(35, 35);				

				collider_player_down->SetPos(position.x - 30, position.y - 30);
				collider_player_down->SetSize(100, 30);				
				
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x - 70, position.y - 15,80,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
				}
				shadow_x -= shadow_w / 3;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 55, position.y - 45);
					collider_player_up->SetSize(38, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 15, position.y - 15);
					collider_player_down->SetSize(60, 15);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x + 55, position.y - 15,80,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
				}
			}

			break;
		case JUMP_NEUTRAL:
			current_animation = &jump_neutral;
			
			position.y -= speed * 2 * mult;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_neutral.Reset();
				state = IDLE;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x, position.y - 90);
				collider_player_up->SetSize(35, 35);

				collider_player_down->SetPos(position.x - 12, position.y - 50);
				collider_player_down->SetSize(50, 30);
			}
			else {
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
			}
			break;
		case JUMP_FORWARD:
			current_animation = &jump_forward;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 20, position.y - 90);
				collider_player_up->SetSize(40, 50);

				collider_player_down->SetPos(position.x, position.y - 50);
				collider_player_down->SetSize(30, 30);
				
				if (current_animation->SeeCurrentFrame() > 5)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x - 20, position.y - 45);
						collider_player_up->SetSize(45, 35);
					}
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 15, position.y - 100);
					collider_player_up->SetSize(40, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 60);
					collider_player_down->SetSize(30, 30);
				}
				if (current_animation->SeeCurrentFrame() > 4)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x + 10, position.y - 55);
						collider_player_up->SetSize(45, 35);
					}
				}
			}
			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_forward.Reset();
				mult = 1;
				state = IDLE;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			break;
		case JUMP_BACKWARD:
			current_animation = &jump_backward;

			position.y -= speed * 1.75 * mult;
			position.x -= 1.25*speed;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_backward.Reset();
				state = IDLE;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_backward.Reset();
				state = IDLE;
				mult = 1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			if (flip != SDL_FLIP_HORIZONTAL)
			{
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
				if (current_animation->SeeCurrentFrame() > 4) {
					collider_player_up->SetPos(position.x + 20, position.y - 45);
					collider_player_up->SetSize(35, 35);
				}
			}
			else {
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
						collider_player_up->SetPos(position.x - 20, position.y - 45);
						collider_player_up->SetSize(35, 35);
					}
				}
			}
			shadow_x = position.x;
			break;
		case PUNCH:
			current_animation = &punch;

			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 20, position.y - 60);
					collider_player_up->SetSize(50, 47);
				}
				if (collider_player_up != nullptr)
				{
					collider_player_down->SetPos(position.x - 18, position.y - 10);
					collider_player_down->SetSize(70, 15);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x - 60, position.y - 50);
					collider_player_attack->SetSize(67, 30);
				}
			}
			else {
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
					collider_player_attack->SetPos(position.x + 60, position.y - 50);
					collider_player_attack->SetSize(67, 30);
				}
			}
			break;
		case DEATH:
			current_animation = &die;
			position.y = initial_position.y + 10;
			break;
		case KICK:
			current_animation = &kick;

			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 20, position.y - 70);
				collider_player_up->SetSize(50, 30);

				collider_player_down->SetPos(position.x, position.y - 80);
				collider_player_down->SetSize(25, 85);

				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x - 43, position.y - 35,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->SetSize(56, 30);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 10, position.y - 70);
					collider_player_up->SetSize(50, 30);
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
			}
			break;
		case TWISTER:
			current_animation = &twister;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x -20, position.y - 75);
					collider_player_up->SetSize(40, 45);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x -35, position.y - 35);
					collider_player_down->SetSize(60, 40);
				}
				if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created) {
					Particle* p = App->particles->AddParticle(App->particles->tornado, position.x + 50, position.y - 205, COLLIDER_PLAYER_PARTICLES);
					is_tornado_created = true;
					p->speed = { -2,0 };
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x+15, position.y - 75);
					collider_player_up->SetSize(40, 45);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x+10, position.y - 35);
					collider_player_down->SetSize(60, 40);
				}
				if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created) {
					App->particles->AddParticle(App->particles->tornado, position.x + 50, position.y - 205, COLLIDER_PLAYER_PARTICLES);
					is_tornado_created = true;
				}
			}
			break;
		case WIN:
			current_animation = &win;
			break;
		case HIT: 
			current_animation = &hit;
			shadow_x = position.x;
			if (flip == SDL_FLIP_HORIZONTAL) {
			
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 15, position.y - 85);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 45);
				}
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
	if ((position.y < initial_position.y)&&((state != JUMP_BACKWARD)&&(state != JUMP_NEUTRAL)&&(state != JUMP_FORWARD)&&(state != HIT)))
	{
		state = JUMP_NEUTRAL;
	}
	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	SDL_Rect shadow = { 1348, 2627, 70, 17 };
	
	if (position.x < App->player2->position.x) {
		flip = SDL_FLIP_NONE;
	}
	else {
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (flip == SDL_FLIP_HORIZONTAL) {
		if (shadow_blit) {
			App->render->Blit(player_textures, shadow_x - shadow.w / 2, initial_position.y - 7, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
			App->render->Blit(player_textures, position.x - current_animation->GetCurrentRect().w / 2, position.y - r.h, &r, flip);
	}
	else {
		if (shadow_blit) {
			App->render->Blit(player_textures, shadow_x, initial_position.y - 7, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
			App->render->Blit(player_textures, position.x, position.y - r.h, &r, flip);

	}

	return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp() {
	LOG("Unloading player");
	App->textures->Unload(player_textures);
	App->audio->UnLoadFx(light_attack_fx);
	App->audio->UnLoadFx(light_kick_fx);
	App->audio->UnLoadFx(hit_fx);
	App->audio->UnLoadFx(twister_fx);
	collider_player_up = nullptr;
	collider_player_mid = nullptr;
	collider_player_down = nullptr;
	collider_player_attack = nullptr;
	return true;
}

void ModulePlayer::OnCollision(Collider* c1,Collider* c2) {

	switch (c2->type)
	{
	case COLLIDER_WALL_LEFT:
		if (!player_input.pressing_D && state != DEATH && state != WIN)
			position.x += speed;

		break;
	case COLLIDER_WALL_RIGHT:
		if (!player_input.pressing_A && state != DEATH && state != WIN)
			position.x -= speed;
		break;
	case COLLIDER_PLAYER_2:
		if (((state != KICK) && (state != PUNCH) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH)) && (state != TWISTER) && (state != DEATH) && (state != WIN))
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
		if (!App->player2->collider_player_2_attack->to_delete && !god) {
			App->player2->hit_percent++;
			App->audio->PlayFX(hit_fx);
			life -= 10;
			state = HIT;
			App->player2->collider_player_2_attack->to_delete = true;
			if ((position.x < App->player2->position.x) && (position.x > App->render->left->rect.x + 60))
			{
				position.x -= 10;
			}
			else if ((position.x > App->player->position.x) && (position.x > App->render->right->rect.x))
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

void ModulePlayer::BlockControls(bool block)
{
	controls = !block;
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