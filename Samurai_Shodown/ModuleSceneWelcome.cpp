#include "ModuleSceneWelcome.h"

ModuleSceneWelcome::ModuleSceneWelcome()
{
	{
		letters.PushBack({ 0,0,253,114 }, 0.02f);
		letters.PushBack({ 253,0,253,114 }, 0.1f);
		letters.PushBack({ 506,0,253,114 }, 0.1f);
		letters.PushBack({ 0,114,253,114 }, 0.1f);
		letters.PushBack({ 253,114,253,114 }, 0.1f);
		letters.PushBack({ 506,114,253,114 }, 0.1f);
		letters.PushBack({ 0,228,253,114 }, 0.1f);
		letters.PushBack({ 253,228,253,114 }, 0.1f);
		letters.PushBack({ 506,228,253,114 }, 0.1f);
		letters.PushBack({ 0,342,253,114 }, 0.1f);
		letters.PushBack({ 253,342,253,114 }, 0.1f);
		letters.PushBack({ 506,342,253,114 }, 0.1f);
		letters.PushBack({ 0,456,253,114 }, 0.1f);
		letters.PushBack({ 253,456,253,114 }, 0.1f);
		letters.PushBack({ 506,456,253,114 }, 0.1f);
		letters.PushBack({ 0,570,253,114 }, 0.1f);
	}

	{
		white.PushBack({ 0,0,242,130 }, 0.3F);
		white.PushBack({ 0,130,242,130 }, 0.3F);
		white.PushBack({ 0,260,242,130 }, 0.3F);
		white.PushBack({ 0,390,242,130 }, 0.3F);
		white.PushBack({ 0,520,242,130 }, 0.3F);
		white.PushBack({ 0,650,242,130 }, 0.3F);
		white.PushBack({ 0,780,242,130 }, 0.3F);
		white.PushBack({ 0,910,242,130 }, 0.3F);
		white.PushBack({ 242,0,242,130 }, 0.3F);
		white.PushBack({ 242,130,242,130 }, 0.3F);
		white.PushBack({ 242,260,242,130 }, 0.3F);
		white.PushBack({ 242,390,242,130 }, 0.3F);
		white.PushBack({ 242,520,242,130 }, 0.3F);
		white.PushBack({ 242,650,242,130 }, 0.3F);
		white.PushBack({ 242,780,242,130 }, 0.3F);
		white.PushBack({ 242,910,242,130 }, 0.3F);
		white.PushBack({ 484,0,242,130 }, 0.3F);
		white.PushBack({ 484,130,242,130 }, 0.3F);
		white.PushBack({ 484,260,242,130 }, 0.3F);
		white.PushBack({ 484,390,242,130 }, 0.3F);
		white.PushBack({ 484,520,242,130 }, 0.3F);
		white.PushBack({ 484,650,242,130 }, 0.3F);
		white.PushBack({ 484,780,242,130 }, 0.3F);
		white.PushBack({ 484,910,242,130 }, 0.3F);
		white.PushBack({ 726,0,242,130 }, 0.3F);
		white.PushBack({ 726,130,242,130 }, 0.3F);
		white.PushBack({ 726,260,242,130 }, 0.3F);
		white.PushBack({ 726,390,242,130 }, 0.3F);
		white.PushBack({ 726,520,242,130 }, 0.3F);
		white.PushBack({ 726,650,242,130 }, 0.3F);
		white.PushBack({ 726,780,242,130 }, 0.3F);
		white.PushBack({ 726,910,242,130 }, 0.3F);
		white.PushBack({ 968,0,242,130 }, 0.3F);
		white.PushBack({ 968,130,242,130 }, 0.3F);
		white.PushBack({ 968,260,242,130 }, 0.3F);
		white.PushBack({ 968,390,242,130 }, 0.3F);
		white.PushBack({ 968,520,242,130 }, 0.3F);
		white.PushBack({ 968,650,242,130 }, 0.3F);
		white.PushBack({ 968,780,242,130 }, 0.3F);
		white.PushBack({ 968,910,242,130 }, 0.3F);
		white.PushBack({ 1210,0,242,130 }, 0.3F);
		white.PushBack({ 1210,130,242,130 }, 0.3F);
		white.PushBack({ 1210,260,242,130 }, 0.3F);
		white.PushBack({ 1210,390,242,130 }, 0.3F);
		white.PushBack({ 1210,390,242,130 }, 0.3F);
		white.PushBack({ 1210,390,242,130 }, 0.3F);
		white.loop = false;
	}

}

ModuleSceneWelcome::~ModuleSceneWelcome()
{}

// Load assets
bool ModuleSceneWelcome::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/Textures/menu1.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/menu.ogg"); 
	Letters = App->textures->Load("Assets/Textures/3SamuraiShodownLetters.png");
	white_letters = App->textures->Load("Assets/Textures/white_letters.png");
	App->audio->PlayMusic(music,NULL);
	curr = &letters;
	return ret;
}

// Load assets
bool ModuleSceneWelcome::CleanUp()
{
	LOG("Unloading Welcome stage");
	App->player->Disable();
	App->textures->Unload(graphics);
	App->audio->UnLoadMusic(music);
	App->textures->Unload(Letters);
	Mix_FadeOutMusic(1250);
	//App->audio->CleanUp();
	return true;
}

// Update: draw background
update_status ModuleSceneWelcome::Update()
{
	welcome.x = 0;
	welcome.y = 0;
	welcome.w = SCREEN_WIDTH;
	welcome.h = SCREEN_HEIGHT;
	App->render->Blit(graphics, NULL, NULL, &welcome);




	if (first_anim_finished) {
		App->render->Blit(Letters, 60, 50, &curr->GetCurrentFrame());
	}
	else {
		App->render->Blit(white_letters, 68, 29, &white.GetCurrentFrame());
	}
	if (white.SeeCurrentFrame() == 45 && alpha > 10) {
		App->render->DrawQuad({ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT }, 255, 255, 255, alpha);
		alpha -= 5;
		first_anim_finished = true;
	}
	// Make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_haohmaru, 2.5f);
	}
	return UPDATE_CONTINUE;
}