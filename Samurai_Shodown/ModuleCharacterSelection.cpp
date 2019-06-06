#include "ModuleCharacterSelection.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleUI.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"



ModuleCharacterSelection::ModuleCharacterSelection() {
	//p1 shining square
	p1.PushBack({692,259,40,49},0.2f);
	p1.PushBack({750,259,40,48},0.2f);
	p1.loop = true;
	//p2 shining square
	p2.PushBack({692,323,40,49},0.2f);
	p2.PushBack({749,323,40,48},0.2f);
	p2.loop = true;
	//player 1 idle
	idle.PushBack({ 28,26,118,126 }, 0.15f); 
	idle.PushBack({ 150,26,118,126 }, 0.15f);
	idle.PushBack({ 272,26,118,126 }, 0.15f);
	idle.PushBack({ 394,26,118,126 }, 0.15f); 
	idle.PushBack({ 514,26,118,126 }, 0.15f);
	idle.PushBack({ 635,26,118,126 }, 0.15f);
	idle.PushBack({ 754,26,118,126 }, 0.15f); 
	idle.PushBack({ 873,26,118,126 }, 0.15f);
	idle.PushBack({ 991,26,118,126 }, 0.15f);
	idle.PushBack({ 394,26,118,126 }, 0.15f); 
	idle.PushBack({ 514,26,118,126 }, 0.15f);
	idle.PushBack({ 635,26,118,126 }, 0.15f);
	idle.loop = true;

}

ModuleCharacterSelection::~ModuleCharacterSelection() {

}

bool ModuleCharacterSelection::Init() {
	background = App->textures->Load("Assets/Sprites/Scenes/character_selection_background.png");
	character = App->textures->Load("Assets/Sprites/UI/finish_round.png");
	player1 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu.png");
	player2 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu-color2.png");
	music = App->audio->LoadMusic("Assets/Audio/Music/character_selection.ogg");
	character_selected = App->audio->LoadFX("Assets/Audio/Fx/character_selected.wav");
	App->audio->PlayMusic(music, 1);
	return true;
}

bool ModuleCharacterSelection::CleanUp() {
	App->textures->Unload(background);
	App->textures->Unload(character);
	App->textures->Unload(player1);
	App->textures->Unload(player2);
	App->audio->UnLoadMusic(music);
	App->audio->UnLoadFx(character_selected);
	return true;
}

update_status ModuleCharacterSelection::Update() {
	SDL_Rect back, face,name,origin;
	back = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
	face = { 749,207,42,48 };
	name = { 686,144,95,30 };
	origin = { 713,181,42,15 };
	//face, p1 and p2
	App->render->Blit(background, 0, 0, &back);
	App->render->Blit(character, (SCREEN_WIDTH-face.w)/2, (SCREEN_HEIGHT-face.h)/2-40, &face);
	App->render->Blit(character, (SCREEN_WIDTH - face.w) / 2, (SCREEN_HEIGHT - face.h) / 2-40,  &p2.GetCurrentFrame());
	App->render->Blit(character, (SCREEN_WIDTH - face.w) / 2, (SCREEN_HEIGHT - face.h) / 2-42,  &p1.GetCurrentFrame());
	//players
	App->render->Blit(player1, (SCREEN_WIDTH) / 16, (SCREEN_HEIGHT) * 3/ 8, &idle.GetCurrentFrame());
	App->render->Blit(player2, (SCREEN_WIDTH) *12/18, (SCREEN_HEIGHT) * 3 / 8, &idle.GetCurrentFrame(),SDL_FLIP_HORIZONTAL);
	//name and origin
	App->render->Blit(character, (SCREEN_WIDTH - name.w) / 8, (SCREEN_HEIGHT - face.h)*9/10, &name);
	App->render->Blit(character, (SCREEN_WIDTH - origin.w)/ 8 +14, (SCREEN_HEIGHT - origin.h) * 9/ 10 +5, &origin);
	App->render->Blit(character, (SCREEN_WIDTH - name.w)*7/8, (SCREEN_HEIGHT - face.h) * 9 / 10, &name);
	App->render->Blit(character, (SCREEN_WIDTH - origin.w)*7/ 8-14, (SCREEN_HEIGHT - origin.h) * 9 / 10 + 7, &origin);

	if ((SDL_GetTicks() > 9000)&&(ring_played==false))
	{
		App->audio->PlayFX(character_selected);
		ring_played = true;
	}

	if ((App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)||SDL_GetTicks()>10000)
	{
		App->fade->FadeToBlack((Module*)App->character_selection, (Module*)App->scene_wanfu, 1.5f);
	}

	return UPDATE_CONTINUE;
}
