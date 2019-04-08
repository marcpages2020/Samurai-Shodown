#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	active[i] = nullptr;
	tornado.anim.PushBack({ 15,1026,20,207 }, 0.3f);
	tornado.anim.PushBack({ 40,1026,22,207 }, 0.3f);
	tornado.anim.PushBack({ 67,1026,29,207 }, 0.3f);
	tornado.anim.PushBack({ 102,1026,42,207 }, 0.3f);
	tornado.anim.PushBack({ 150,1026,29,207 }, 0.3f);
	tornado.anim.PushBack({ 183,1026,42,207 }, 0.3f);
	tornado.anim.PushBack({ 234,1026,74,207 }, 0.3f);
	tornado.anim.PushBack({ 313,1026,74,207 }, 0.3f);
	tornado.anim.PushBack({ 392,1026,81,207 }, 0.3f);
	tornado.anim.PushBack({ 480,1026,80,207 }, 0.3f);
	tornado.anim.PushBack({ 575,1026,82,207 }, 0.3f);
	tornado.anim.PushBack({ 662,1026,81,207 }, 0.3f);
	tornado.anim.PushBack({ 749,1026,83,207 }, 0.3f);
	tornado.anim.PushBack({ 837,1026,83,207 }, 0.3f);
	tornado.anim.PushBack({ 925,1026,82,207 }, 0.3f);
	tornado.anim.PushBack({ 1012,1026,78,207 }, 0.3f);
	tornado.anim.PushBack({ 1096,1026,75,207 }, 0.3f);
	tornado.anim.PushBack({ 1178,1026,72,207 }, 0.3f);
	tornado.anim.PushBack({ 1255,1026,66,207 }, 0.3f);
	tornado.anim.PushBack({ 1332,1026,51,207 }, 0.3f);
	tornado.anim.PushBack({ 1388,1026,51,207 }, 0.3f);//small
	tornado.anim.PushBack({ 1444,1026,40,207 }, 0.3f);
	tornado.anim.PushBack({ 1492,1026,43,207 }, 0.3f);
	tornado.anim.PushBack({ 1540,1026,61,207 }, 0.3f);
	tornado.anim.PushBack({ 1606,1026,45,207 }, 0.3f);
	tornado.anim.PushBack({ 1656,1026,45,207 }, 0.3f);
	tornado.anim.PushBack({ 1704,1026,44,207 }, 0.3f);
	tornado.anim.PushBack({ 1757,1026,44,207 }, 0.3f);
	tornado.anim.PushBack({ 1805,1026,56,207 }, 0.3f);
	tornado.anim.PushBack({ 1866,1026,44,207 }, 0.3f);
	tornado.anim.PushBack({ 1917,1026,56,207 }, 0.3f);
	tornado.anim.PushBack({ 1978,1026,44,207 }, 0.3f);
	tornado.life = 5000;
	tornado.speed = { 2,0 };
	tornado.anim.loop = false;


}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);
	// Unload fx

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
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
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				// play the audio SFX
			}
		}
	}


	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->coll = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr && active[i]->coll == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
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

Particle::~Particle()
{
	if (coll != nullptr) {
		coll->to_delete = true;
		coll = nullptr;
	}

}

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

	if (coll != nullptr)
		coll->SetPos(position.x, position.y);

	return ret;
}

