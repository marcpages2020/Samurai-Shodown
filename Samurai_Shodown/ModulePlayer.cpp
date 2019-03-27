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
	
	//forward animation
	forward.PushBack({ 15,496,70,112 });
	forward.PushBack({ 89,496,70,112 });
	forward.PushBack({ 163,499,76,109 });
	forward.PushBack({ 243,499,76,109 });
	forward.PushBack({ 322,499,76,109 });
	forward.PushBack({ 402,496,69,112 });
	forward.PushBack({ 475,496,69,112 });
	forward.PushBack({ 548,496,69,112 });
	forward.PushBack({ 621,492,59,116 });
	forward.PushBack({ 684,492,59,116 });
	forward.PushBack({ 747,492,59,116 });
	forward.PushBack({ 810,492,57,116 });
	forward.PushBack({ 871,490,57,118 });
	forward.PushBack({ 933,490,56,118 });
	forward.PushBack({ 994,490,61,118 });
	forward.PushBack({ 1060,492,61,116 });
	forward.PushBack({ 1126,492,61,116 });
	forward.speed = 0.4f;

	//backward animation
	//backward.PushBack({15,614,74,114});
	//backward.PushBack({ 94,614,74,114 });
	//backward.PushBack({ 173,614,74,114 });
	//backward.PushBack({ 264,610,68,118 });
	//backward.PushBack({ 337,610,68,118 });
	//backward.PushBack({ 410,612,68,117 });
	//backward.PushBack({ 482,609,67,121 });
	backward.PushBack({ 553,608,67,121 });
	//backward.PushBack({ 624,618,82,110 });
	//backward.PushBack({ 711,618,82,110 });
	//backward.PushBack({ 798,618,82,110 });
	//backward.PushBack({ 884,618,82,110 });
	//backward.PushBack({ 971,611,69,117 });
	//backward.PushBack({ 1045,611,69,117 });
	//backward.PushBack({ 1119,610,69,118 });
	//backward.PushBack({ 1193,614,74,114 });
	//backward.PushBack({ 1272,614,74,114 });
	//backward.PushBack({ 1351,614,74,114 });
	backward.speed = 0.2f;
	//jump animation
	/*
	jump.PushBack({ x,y,w,h });
	jump.PushBack({ x,y,w,h });
	jump.PushBack({ x,y,w,h });
	*/

	//punch animation
	/*punch.PushBack({x,y,w,h});
	punch.PushBack({ x,y,w,h });
	punch.PushBack({ x,y,w,h });
	*/

	//kick animation
	kick.PushBack({ 16,137,66,95 }); //initial kick frames
	kick.PushBack({ 87,137,66,95 });
	kick.PushBack({ 158,137,66,95 });
	kick.PushBack({ 229,134,86,98 }); //final kick frames
	kick.PushBack({ 320,134,86,98 });
	kick.PushBack({ 411,134,86,98 });
	kick.PushBack({ 16,137,66,95 }); //initial kick frames
	kick.PushBack({ 87,137,66,95 });
	kick.PushBack({ 158,137,66,95 });
	kick.speed =0.2f;
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