#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#define FPS 60
bool animationAvailable = true;
enum STATE {
	//IDLE,
	//JUMP,
	//PUNCH,
	//KICK
};
ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	//idle animation
	{
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
		idle.mframes = 12;
	}

	//forward animation
	{
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
	}

	//backward animation
	{
		backward.PushBack({ 624,608,82,121 });//9
		backward.PushBack({ 711,608,82,121 });//10
		backward.PushBack({ 798,608,82,121 });//11
		backward.PushBack({ 884,608,82,121 });//12
		backward.PushBack({ 15,614,74,114 }); //1
		backward.PushBack({ 94,614,74,114 }); //2
		backward.PushBack({ 173,614,74,114 }); //3 
		backward.PushBack({ 264,610,68,118 }); //4
		backward.PushBack({ 337,610,68,118 }); //5
		backward.PushBack({ 410,612,68,117 }); //6
		backward.PushBack({ 482,609,67,121 });//7
		backward.PushBack({ 553,608,67,121 });//8
		backward.PushBack({ 971,608,69,122 });//13
		backward.PushBack({ 1045,608,69,121 });//14
		backward.PushBack({ 1119,608,69,120 });//15
		backward.PushBack({ 1193,614,74,114 });//16
		backward.PushBack({ 1272,614,74,114 });//17
		backward.PushBack({ 1351,614,74,114 });//18
		backward.speed = 0.4f;
	}

	//jump animation
	{
		jump.PushBack({ 15, 371, 60, 112 });
		jump.PushBack({ 80, 371, 60, 112 });
		jump.PushBack({ 145, 371, 60, 112 });
		jump.PushBack({ 209, 371, 75, 92 });
		jump.PushBack({ 288, 371, 75, 92 });
		jump.PushBack({ 367, 371, 75, 92 });
		jump.PushBack({ 446, 371, 78, 83 });
		jump.PushBack({ 209, 371, 75, 92 });
		jump.PushBack({ 288, 371, 75, 92 });
		jump.PushBack({ 367, 371, 75, 92 });
		jump.PushBack({ 15, 371, 60, 112 });
		jump.PushBack({ 80, 371, 60, 112 });
		jump.PushBack({ 145, 371, 60, 112 });
		jump.PushBack({ 527, 371, 68, 112 });
		jump.PushBack({ 601, 371, 68, 112 });
		jump.PushBack({ 674, 371, 68, 112 });
		jump.speed = 0.2f;
		jump.mframes = 16;
	}

	//punch animation
	{
		punch.PushBack({ 14, 236, 69, 127 });
		punch.PushBack({ 87, 236, 69, 127 });
		punch.PushBack({ 160, 266, 79, 97 });
		punch.PushBack({ 243, 269, 79, 96 });
		punch.PushBack({ 327, 267, 79, 97 });
		punch.PushBack({ 410, 270, 129, 93 });
		punch.PushBack({ 545, 277, 130, 86 });
		punch.PushBack({ 679, 280, 130, 83 });
		punch.PushBack({ 814, 280, 129, 95 });
		punch.PushBack({ 946, 280, 130, 95 });
		punch.PushBack({ 1081, 280, 130, 95 });
		punch.PushBack({ 1213, 280, 120, 95 });
		punch.PushBack({ 1337, 280, 120, 95 });
		punch.PushBack({ 1461, 280, 83, 95 });
		punch.PushBack({ 1548, 280, 83, 95 });
		punch.PushBack({ 1635, 280, 83, 95 });
		punch.PushBack({ 1721, 277, 130, 86 });
		punch.PushBack({ 1857, 277, 130, 86 });
		punch.mframes = 18;
		punch.speed = 0.2f;
	}

	//kick animation
	{
		kick.PushBack({ 16,137,66,95 }); //initial kick frames
		kick.PushBack({ 87,137,66,95 });
		kick.PushBack({ 158,137,66,95 });
		kick.PushBack({ 229,134,86,98 }); //final kick frames
		kick.PushBack({ 320,134,86,98 });
		kick.PushBack({ 411,134,86,98 });
		kick.PushBack({ 16,137,66,95 }); //initial kick frames
		kick.PushBack({ 87,137,66,95 });
		kick.PushBack({ 158,137,66,95 });
		kick.mframes = 9;
		kick.speed = 0.2f;
	}
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
	//int frames=0,maxFrames=0;
	/*fjump.maxFrames = 10;
	fkick.maxFrames = 9;
	fpunch.maxFrames=18;*/
	int speed = 1;

	//if (animationAvailable==true){

		if (App->input->keyboard[SDL_SCANCODE_A] == 1)
		{
			current_animation = &backward;
			position.x -= speed;
			//frames = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_D] == 1)
		{
			current_animation = &forward;
			position.x += speed;
			//frames = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == 1)
		{
			current_animation = &jump;
			//maxFrames = 10*FPS;
			//animationAvailable == false;
			if (position.y < 240) {
				position.y -= speed; //goes up
			}
			else {
				position.y += speed; //goes down
			}
			
		}
		if (App->input->keyboard[SDL_SCANCODE_J] == 1)
		{
			current_animation = &kick;
			//maxFrames = 9*FPS;
			//animationAvailable = false;
		}
		if (App->input->keyboard[SDL_SCANCODE_U] == 1)
		{
			current_animation = &punch;
			//maxFrames = 18*FPS;
			//animationAvailable = false;
		}
	//}
	/*else
	{
		if (frames<maxFrames)
		{
			frames++;
		}
		else
		{
			animationAvailable = true;
		}
	}*/

	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	
	return UPDATE_CONTINUE;
}