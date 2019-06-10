#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleSceneWelcome.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleSceneWanFu.h"
#include "ModuleParticles.h"
#include "ModuleSceneCongrats.h"
#include "ModuleNeoGeo.h"
#include "ModuleCollision.h"
#include "ModuleFonts.h"
#include "ModulePlayer2.h"
#include "ModuleUI.h"
#include "ModuleJudge.h"
#include "ModuleCharacterSelection.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = scene_welcome = new ModuleSceneWelcome();
	modules[i++] = neo_geo = new ModuleNeoGeo();
	modules[i++] = scene_haohmaru = new ModuleSceneHaohmaru();
	modules[i++] = scene_wanfu = new ModuleSceneWanFu();
	modules[i++] = scene_congrats = new ModuleSceneCongrats();
	modules[i++] = character_selection = new ModuleCharacterSelection();
	modules[i++] = judge = new ModuleJudge();
	modules[i++] = player2 = new ModulePlayer2();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = ui = new ModuleUI();
	modules[i++] = fade = new ModuleFadeToBlack();
}	

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();
	player2->Disable();
	judge->Disable();
	// Disable the map that you do not start with
	neo_geo->Disable();
	scene_welcome->Disable();
	scene_haohmaru->Disable();
	//scene_wanfu->Disable();
	scene_congrats->Disable();
	character_selection->Disable();
	//wanfu->Disable();
	//haohmaru->Disable();
	ui->Disable();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	if (input->keyboard[SDL_SCANCODE_F6] == KEY_DOWN)
		App->ChangePause();
	if (input->keyboard[SDL_SCANCODE_0] == KEY_DOWN)
		App->ChangePause();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp() ? modules[i]->CleanUp():true;

	return ret;
}

void Application::ChangePause()
{
	is_paused = !is_paused;
}
