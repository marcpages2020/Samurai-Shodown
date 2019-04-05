#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");
	//tornado particle
	{
		tornado.anim.PushBack({ 15,1216,20,17},0.3f);
		tornado.anim.PushBack({ 40,1215,22,18 },0.3f);
		tornado.anim.PushBack({ 67,1197,29,33 },0.3f);
		tornado.anim.PushBack({ 102,1199,42,31 },0.3f);
		tornado.anim.PushBack({ 150,1181,29,49 },0.3f);
		tornado.anim.PushBack({ 183,1183,42,47 },0.3f);
		tornado.anim.PushBack({ 234,1141,74,89 },0.3f);
		tornado.anim.PushBack({ 313,1141,74,89 },0.3f);
		tornado.anim.PushBack({ 392,1142,81,88 },0.3f);
		tornado.anim.PushBack({ 480,1143,80,87 },0.3f);
		tornado.anim.PushBack({ 575,1148,82,82 },0.3f);
		tornado.anim.PushBack({ 662,1150,81,80 },0.3f);
		tornado.anim.PushBack({ 749,1154,83,76 },0.3f);
		tornado.anim.PushBack({ 837,1152,83,75 },0.3f);
		tornado.anim.PushBack({ 925,1161,82,69 },0.3f);
		tornado.anim.PushBack({ 1012,1163,78,67},0.3f);
		tornado.anim.PushBack({ 1096,1162,75,67 },0.3f);
		tornado.anim.PushBack({ 1178,1154,72,76 },0.3f);
		tornado.anim.PushBack({ 1255,1153,66,76 },0.3f);
		tornado.anim.PushBack({ 1332,1148,51,82 },0.3f);
		tornado.anim.PushBack({ 1388,1147,51,82 },0.3f);//small
		tornado.anim.PushBack({ 1444,1142,40,87 },0.3f);
		tornado.anim.PushBack({ 1492,1146,43,86 },0.3f);
		tornado.anim.PushBack({ 1540,1142,61,89 },0.3f);
		tornado.anim.PushBack({ 1606,1093,45,138 },0.3f);
		tornado.anim.PushBack({ 1656,1093,45,138 },0.3f);
		tornado.anim.PushBack({ 1704,1031,44,202 },0.3f);
		tornado.anim.PushBack({ 1757,1025,44,202 },0.3f);
		tornado.anim.PushBack({ 1805,1024,56,207 },0.3f);
		tornado.anim.PushBack({ 1866,1025,44,208 },0.3f);
		tornado.anim.PushBack({ 1917,1024,56,206 },0.3f);
		tornado.anim.PushBack({ 1978,1026,44,207 },0.3f);
		tornado.life = 5000;
		tornado.speed = { 2,-1};
		if (tornado.anim.SeeCurrentFrame() < 3)
		{
			tornado.position.y = 215;
		}
		else if (tornado.anim.SeeCurrentFrame() < 5)
		{

		}
		tornado.anim.loop = false;
	}
	
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if(p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here

			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;
	active[last_particle++] = p;
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;
	return ret;
}