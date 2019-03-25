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

	kick.PushBack({ 1506,167,62,97 });
	kick.PushBack({ 1578,168,79,98 });
	kick.PushBack({ 1657,170,99,100 });
	kick.PushBack({ 1756,167,110,97 });
	kick.PushBack({ 1866,168,79,98 });
	kick.PushBack({ 1945,167,62,97 });
	kick.speed = 0.2f;
}

ModulePlayer::~ModulePlayer(){

}

// Load assets
bool ModulePlayer::Start()
{
	bool ret = true;
	LOG("Loading player textures");

	haohmaruSpreadsheet = App->textures->Load("Assets/Sprites/Characters/Haohmaru/spritesHaohmaru.png");

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//Animation* current_animation = &idle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_J] == 1)
	{
		//current_animation = &kick;
		App->render->Blit(haohmaruSpreadsheet, 150, 100, &(kick.GetCurrentFrame()));
	}

	//Draw everything
	//SDL_Rect r = current_animation->GetCurrentFrame();

	//App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	
	return UPDATE_CONTINUE;
}