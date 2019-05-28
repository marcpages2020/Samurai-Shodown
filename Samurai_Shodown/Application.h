#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 18

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
//class ModuleHaohmaru;
//class ModuleWanFu;
class ModuleJudge;
class ModulePlayer2;
class ModulePlayer;
class ModuleAudio;
class ModuleFadeToBlack;
class Module;
class ModuleSceneWelcome;
class ModuleSceneHaohmaru;
class ModuleSceneWanFu;
class ModuleSceneCongrats;
class ModuleParticles;
class ModuleCollision;
class ModuleFonts;
class ModuleNeoGeo;
class ModuleUI;

class Application
{
public:

	Module * modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	//ModuleHaohmaru* haohmaru = nullptr;
	//ModuleWanFu* wanfu = nullptr;
	ModuleJudge* judge = nullptr;
	ModulePlayer2* player2 = nullptr;
	ModulePlayer* player = nullptr;
	ModuleAudio* audio = nullptr;
	ModuleFadeToBlack*	fade = nullptr;
	ModuleSceneWelcome* scene_welcome = nullptr;
	ModuleSceneHaohmaru* scene_haohmaru = nullptr;
	ModuleSceneWanFu* scene_wanfu = nullptr;
	ModuleSceneCongrats* scene_congrats = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleNeoGeo* neo_geo = nullptr;
	ModuleCollision* collision = nullptr;
	ModuleFonts* fonts = nullptr;
	ModuleUI* ui = nullptr;

	bool is_paused = false;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();
	void ChangePause();
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__