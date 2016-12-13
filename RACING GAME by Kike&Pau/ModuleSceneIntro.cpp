#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"



ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;


	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// Rexta inicial (R)(ini)
	Cube wallRini(2, 3, 40);
	wallRini.SetPos(10, 1, 30);
	App->physics->AddBody(wallRini, 1000000);

	Cube wallRini2(2, 3, 40);
	wallRini2.SetPos(-10, 1, 30);
	App->physics->AddBody(wallRini2, 1000000);

	
	//false Rotonda inicial (fRot)(ini)
//palo del medio	
	Cube fRotini(2, 3, 40);
	fRotini.SetPos(0, 1, 65);
	fRotini.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(fRotini, 1000000);
//apertura
	Cube fRotini2(2, 3, 20);
	fRotini2.SetPos(-20, 1, 50);
	fRotini2.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(fRotini2, 1000000);
	
	Cube fRotini3(2, 3, 20);
	fRotini3.SetPos(20, 1, 50);
	fRotini3.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(fRotini3, 1000000);
//parte izquierda
	Cube fRotinileftRb(2, 3, 10);
	fRotinileftRb.SetPos(30, 1, 75);
	App->physics->AddBody(fRotinileftRb, 1000000);

	Cube fRotinileftR2(2, 3, 20);
	fRotinileftR2.SetPos(30, 1, 60);
	App->physics->AddBody(fRotinileftR2, 1000000);

	Cube fRotiniTopR(2, 3, 20);
	fRotiniTopR.SetPos(20, 1, 80);
	fRotiniTopR.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(fRotiniTopR, 1000000);
//parte derecha
	Cube fRotiniright1(2, 3, 10);
	fRotiniright1.SetPos(-30, 1, 75);
	App->physics->AddBody(fRotiniright1, 1000000);

	Cube fRotiniright2(2, 3, 20);
	fRotiniright2.SetPos(-30, 1, 60);
	App->physics->AddBody(fRotiniright2, 1000000);

	Cube fRotiniright3(2, 3, 20);
	fRotiniright3.SetPos(-20, 1, 80);
	fRotiniright3.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(fRotiniright3, 1000000);

	// Rexta post rotonda (R)()
	Cube wallRR(2, 3, 40);
	wallRR.SetPos(10, 1, 100);
	App->physics->AddBody(wallRR, 1000000);

	Cube wallRR2(2, 3, 40);
	wallRR2.SetPos(-10, 1, 100);
	App->physics->AddBody(wallRR2, 1000000);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	


	/*Cube wall2b(2, 3, 10);
	wall2b.SetPos(-15, 1, 54);
	wall2b.SetRotation(-45, vec3(0, 1, 0));
	wall2b.Render();*/
	/*Cube wall2(2, 3, 10);
	wall2.SetPos(0, 1, 54);
	wall2.SetRotation(-45, vec3(0, 1, 0));
	wall2.Render();*/
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

