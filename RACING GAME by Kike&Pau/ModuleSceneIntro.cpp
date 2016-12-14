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
	bool plane = true;
	count = 0;

	App->camera->Move(vec3(1.0f, 100.0f, 60.0f));
	App->camera->LookAt(vec3(0, 0, 60));

	// Rexta inicial (R)(ini)
	Cube wallRini(2, 3, 40);
	wallRini.SetPos(10, 1, 30);
	App->physics->AddBody(wallRini, 1000000);
	wallRini.wire = true;
	wallRini.color = Red;
	wallRini.axis = true;





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
	Cube fRotini2(2, 3, 18);
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
	//Cube fRotiniright1(2, 3, 10);
	//fRotiniright1.SetPos(-30, 1, 75);
	//App->physics->AddBody(fRotiniright1, 1000000);

	Cube fRotiniright2(2, 3, 140);
	fRotiniright2.SetPos(-30, 1, 10);
	App->physics->AddBody(fRotiniright2, 1000000);

	Cube fRotiniright3(2, 3, 40);//afecta a la S
	fRotiniright3.SetPos(-30, 1, 80);
	fRotiniright3.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(fRotiniright3, 1000000);

	// Rexta post rotonda (R)()
	Cube wallRR(2, 3, 60);
	wallRR.SetPos(10, 1, 110);
	App->physics->AddBody(wallRR, 1000000);

	Cube wallRR2(2, 3, 40);
	wallRR2.SetPos(-10, 1, 100);
	App->physics->AddBody(wallRR2, 1000000);

	//Recta a la derecha
	Cube wallRaD(2, 3, 80);
	wallRaD.SetPos(-30, 1, 140);
	wallRaD.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(wallRaD, 1000000);

	//recta S
	Cube wallS1(2, 3, 40);
	wallS1.SetPos(-30, 1, 120);
	App->physics->AddBody(wallS1, 1000000);

	Cube wallS2(2, 3, 40);
	wallS2.SetPos(-50, 1, 100);
	App->physics->AddBody(wallS2, 1000000);

	/*Cube wallS3(2, 3, 60);
	wallS3.SetPos(-70, 1, 110);
	App->physics->AddBody(wallS3, 1000000);*/

	//recta aceleracion con cosas(baches o algo)
	Cube wallA(2, 3, 180);
	wallA.SetPos(-70, 1, 50);
	App->physics->AddBody(wallA, 1000000);

	// giro derecha
	Cube wallG(2, 3, 120);
	wallG.SetPos(-90, 1, -60);
	wallG.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(wallG, 1000000);

	Cube wallG1(2, 10, 60);
	wallG1.SetPos(-100, 1, -40);
	wallG1.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(wallG1, 1000000);

	Cube wallG2(2, 3, 60);
	wallG2.SetPos(-150, 1, -30);
	App->physics->AddBody(wallG2, 1000000);

	Cube wallG3(2, 10, 80);
	wallG3.SetPos(-110, 1, 0);
	wallG3.SetRotation(-90, vec3(0, 1, 0));
	App->physics->AddBody(wallG3, 1000000);

	//ramp
	Cube wallRamp(60, 2, 30);
	wallRamp.SetPos(-80, 0, -20);
	
	wallRamp.SetRotation(20, vec3(0, 0, 1));
	App->physics->AddBody(wallRamp, 0);

	//pltform
	Cube platform(60, 2, 30);
	platform.SetPos(20, 10, -20);
	App->physics->AddBody(platform, 0);

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
	
	//if (plane) {

	//	p.c

	//}
	
	p.Render();



	Cube wall6(2.2f, 3, 40);
	wall6.SetPos(0, 0, 30);

	wall6.wire = false;
	wall6.color = Green;
	wall6.Scale(1, 0, 1);
	wall6.Render();
	
	// Rexta inicial (R)(ini)
	Cube wall1(2.2f, 3, 40);
	wall1.SetPos(10, 1.3f, 30);

	wall1.wire = false;
	wall1.color = Red;
	wall1.Render();





	Cube wall2(2, 3, 40);
	wall2.SetPos(-10, 1, 30);
	wall2.Render();

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

