#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOAd

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	//idle animation
	idle.PushBack({ 16,22,71,109 });
	idle.PushBack({ 92,22,72,109 });
	idle.PushBack({ 168,22,71,109 });
	idle.PushBack({ 245,20,72,111 });
	idle.PushBack({ 322,18,72,113 });
	idle.PushBack({ 399,19,72,112 });
	idle.PushBack({ 476,19,74,112 });
	idle.PushBack({ 554,19,74,112 });
	idle.PushBack({ 630,19,73,112 });
	idle.PushBack({ 245,20,72,111 });
	idle.PushBack({ 322,18,72,113 });
	idle.PushBack({ 399,19,72,112 });
	idle.speed = 0.5f;

	//kick animation
	kick.PushBack({ 16,137,66,95 });
	kick.PushBack({ 87,137,66,95 });
	kick.PushBack({ 158,137,66,95 });
	kick.PushBack({ 229,134,86,98 });
	kick.PushBack({ 320,134,86,98 });
	kick.PushBack({ 411,134,86,98 });
	kick.speed =0.4f;
}

ModulePlayer::~ModulePlayer(){

}

// Load assets
bool ModulePlayer::Start()
{
	bool ret = true;
	LOG("Loading player textures");

	graphics = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_A]==1)
	{
		current_animation = &backward;
		position.x -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_D]==1)
	{
		current_animation = &forward;
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_J] == 1)
	{
		current_animation = &kick;
	}
	if (App->input->keyboard[SDL_SCANCODE_U]==1)
	{
		//current_animation = &punch;
	}
	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	
	return UPDATE_CONTINUE;
}