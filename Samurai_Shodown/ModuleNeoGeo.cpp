#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleNeoGeo.h"
#include "ModuleAudio.h"
#include "SDL\include\SDL.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
ModuleNeoGeo::ModuleNeoGeo()
{
	Neogeo.PushBack({ 0,0,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,90,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,190,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,290,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,390,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,490,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,590,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,690,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,790,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,890,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,990,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1090,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1190,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1290,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1390,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1490,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1590,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1690,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1790,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1890,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,1990,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,2090,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,2190,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,2290,250,40 }, 0.4f);
	Neogeo.PushBack({ 0,2390,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,0,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,90,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,190,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,290,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,390,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,490,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,590,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,690,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,790,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,890,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,990,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1090,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1190,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1290,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1390,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1490,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1590,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1690,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1790,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1890,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,1990,250,40 }, 0.4f);
	Neogeo.PushBack({ 350,2090,250,40 }, 0.4f);
	Neogeo.loop = false;

	SNK.PushBack({ 601,0,72,19 }, 0.4f);
	SNK.PushBack({ 678,0,72,19 }, 0.4f);
	SNK.PushBack({ 753,0,72,19 }, 0.4f);
	SNK.PushBack({ 602,29,72,19 }, 0.4f);
	SNK.PushBack({ 678,29,72,19 }, 0.4f);
	SNK.PushBack({ 754,29,72,19 }, 0.4f);
	SNK.PushBack({ 602,55,72,19 }, 0.4f);
	SNK.PushBack({ 678,55,72,19 }, 0.4f);
	SNK.PushBack({ 754,55,72,19 }, 0.4f);
	SNK.PushBack({ 602,79,72,19 }, 0.4f);
	SNK.PushBack({ 678,79,72,19 }, 0.4f);
	SNK.PushBack({ 753,79,72,19 }, 0.4f);
	SNK.PushBack({ 601,105,72,19 }, 0.4f);
	SNK.PushBack({ 678,105,72,19 }, 0.4f);
	SNK.PushBack({ 754,105,72,19 }, 0.4f);
	SNK.PushBack({ 601,129,72,19 }, 0.4f);
	SNK.PushBack({ 678,129,72,19 }, 0.4f);
	SNK.PushBack({ 755,129,72,19 }, 0.4f);
	SNK.loop = false;

	Letters.PushBack({ 838,0,20,14 }, 0.2f);
	Letters.PushBack({ 838,0,31,14 }, 0.2f);
	Letters.PushBack({ 838,0,40,14 }, 0.2f);
	Letters.PushBack({ 838,0,57,14 }, 0.2f);
	Letters.PushBack({ 838,0,66,14 }, 0.2f);
	Letters.PushBack({ 838,0,76,14 }, 0.2f);
	Letters.PushBack({ 838,0,96,14 }, 0.2f);
	Letters.PushBack({ 838,0,103,14 }, 0.2f);
	Letters.PushBack({ 838,0,114,14 }, 0.2f);
	Letters.PushBack({ 838,0,126,14 }, 0.2f);
	Letters.loop = false;

	Letters2.PushBack({ 838,17,8,13 }, 0.2f);
	Letters2.PushBack({ 838,17,18,13 }, 0.2f);
	Letters2.PushBack({ 838,17,31,13 }, 0.2f);
	Letters2.PushBack({ 838,17,43,13 }, 0.2f);
	Letters2.PushBack({ 838,17,55,13 }, 0.2f);
	Letters2.PushBack({ 838,17,65,13 }, 0.2f);
	Letters2.PushBack({ 838,17,77,13 }, 0.2f);
	Letters2.PushBack({ 838,17,87,13 }, 0.2f);
	Letters2.PushBack({ 838,17,102,13 }, 0.2f);
	Letters2.PushBack({ 838,17,112,13 }, 0.2f);
	Letters2.PushBack({ 838,17,121,13 }, 0.2f);
	Letters2.PushBack({ 838,17,133,13 }, 0.2f);
	Letters2.loop = false;

	Copy.PushBack({ 584,160,7,7 });
	Copy.loop = false;


}

ModuleNeoGeo::~ModuleNeoGeo()
{}

// Load assets
bool ModuleNeoGeo::Start()
{
	LOG("Loading space intro");
	intro = App->textures->Load("assets/Textures/Neogeo.png");

	App->render->camera.x = App->render->camera.y = 0;

	music = App->audio->LoadMusic("assets/Audio/Music/Neo Geo Logo.ogg");

	App->audio->PlayMusic(music);

	anim = &Neogeo;
	anim2 = &SNK;
	anim3 = &Letters;
	anim4 = &Letters2;
	anim5 = &Copy;

	change = false;
	next = false;
	time2 = SDL_GetTicks();
	Neogeo.Reset();
	SNK.Reset();
	Letters.Reset();
	Letters2.Reset();
	Copy.Reset();
	time = 0;
	return true;
}

// UnLoad assets
bool ModuleNeoGeo::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(intro);
	App->audio->UnLoadMusic(music);
	change = false;
	Neogeo.Reset();
	SNK.Reset();
	Letters.Reset();
	Letters2.Reset();
	Copy.Reset();
	time = 0;


	return true;
}

// Update: draw background




update_status ModuleNeoGeo::Update()
{
	time = SDL_GetTicks() - time2;

	if (time > 1500) change = true;

	if (!change) {

		SDL_SetRenderDrawColor(App->render->renderer, 255, 255, 255, 0);
	}
	else {

		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 0);
	}

	SDL_RenderClear(App->render->renderer);



	App->render->Blit(intro, 75, 50, &(anim->GetCurrentFrame()));

	if (time > 1700)
	{
		App->render->Blit(intro, 118, 120, &(anim3->GetCurrentFrame()));
		if (Letters.SeeCurrentFrame() == 9) {
			next = true;
		}
	}
	if (next) {
		App->render->Blit(intro, 118, 137, &(anim4->GetCurrentFrame()));
	}
	if (time > 4500) {
		App->render->Blit(intro, 147, 170, &(anim2->GetCurrentFrame()));
	}
	if (SNK.SeeCurrentFrame() > 14) {
		App->render->Blit(intro, 307, 52, &(anim5->GetCurrentFrame()));
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN || time > 8000) {
		App->fade->FadeToBlack(this, (Module*)App->scene_welcome, 2.5f);
	}

	return UPDATE_CONTINUE;
}