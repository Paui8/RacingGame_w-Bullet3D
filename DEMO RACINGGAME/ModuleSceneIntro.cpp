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
	plane = true;
	count = 0.0f;

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

	Cube platformWall(60, 2, 2);
	platformWall.SetPos(20, 12, -6);
	App->physics->AddBody(platformWall, 0);

	Cube platformWall2(60, 2, 2);
	platformWall2.SetPos(20, 12, -34);
	App->physics->AddBody(platformWall2, 0);

	//down again
	Cube wallD(110, 3, 2);
	wallD.SetPos(70, 1, -6);
	App->physics->AddBody(wallD, 0);

	Cube wallD2(80, 3, 2);
	wallD2.SetPos(70, 1, -34);
	App->physics->AddBody(wallD2, 0);

	//curve
	Cube wallC(2, 3, 50);
	wallC.SetPos(124, 1, -32);
	App->physics->AddBody(wallC, 0);

	//enlargment
	Cube wallDa(40, 3, 2);
	wallDa.SetPos(30, 1, -34);
	App->physics->AddBody(wallDa, 0);

	Cube wallDa2(145, 3, 2);
	wallDa2.SetPos(50, 1, -55);
	App->physics->AddBody(wallDa2, 0);

	//finalLine
	Cube FinalWall(2, 3, 45);
	FinalWall.SetPos(10, 1, -12);
	App->physics->AddBody(FinalWall, 1000000);

	Cube FinalWall2(2, 3, 64);
	FinalWall2.SetPos(-10, 1, -24);
	App->physics->AddBody(FinalWall2, 1000000);

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
	p.wire = false;

	 if (count >= 0.0f) {p.color.Set(0.0f, count = count + 0.01f, 1.0f);}


	

		
		


	

		


	 //------------------------
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
		wall1.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wall1.Render();

		Cube wallRini2(2, 3, 40);
		wallRini2.SetPos(-10, 1, 30);
		wallRini2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallRini2.Render();

		//false Rotonda inicial (fRot)(ini)
		//palo del medio	
		Cube fRotini(2, 3, 40);
		fRotini.SetPos(0, 1, 65);
		fRotini.SetRotation(-90, vec3(0, 1, 0));
		fRotini.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotini.Render();
		//apertura
		Cube fRotini2(2, 3, 18);
		fRotini2.SetPos(-20, 1, 50);
		fRotini2.SetRotation(-90, vec3(0, 1, 0));
		fRotini2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotini2.Render();



		Cube fRotini3(2, 3, 20);
		fRotini3.SetPos(20, 1, 50);
		fRotini3.SetRotation(-90, vec3(0, 1, 0));
		fRotini3.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotini3.Render();

		//parte izquierda
		Cube fRotinileftRb(2, 3, 10);
		fRotinileftRb.SetPos(30, 1, 75);
		fRotinileftRb.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotinileftRb.Render();

		Cube fRotinileftR2(2, 3, 20);
		fRotinileftR2.SetPos(30, 1, 60);
		fRotinileftR2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotinileftR2.Render();

		Cube fRotiniTopR(2, 3, 20);
		fRotiniTopR.SetPos(20, 1, 80);
		fRotiniTopR.SetRotation(-90, vec3(0, 1, 0));
		fRotiniTopR.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotiniTopR.Render();
		//parte derecha
		//Cube fRotiniright1(2, 3, 10);
		//fRotiniright1.SetPos(-30, 1, 75);
		//App->physics->AddBody(fRotiniright1, 1000000);

		Cube fRotiniright2(2, 3, 140);
		fRotiniright2.SetPos(-30, 1, 10);
		fRotiniright2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotiniright2.Render();



		Cube fRotiniright3(2, 3, 40);//afecta a la S
		fRotiniright3.SetPos(-30, 1, 80);
		fRotiniright3.SetRotation(-90, vec3(0, 1, 0));
		fRotiniright3.color.Set(0.0f, count = count + 0.02f, 1.0f);
		fRotiniright3.Render();



		// Rexta post rotonda (R)()
		Cube wallRR(2, 3, 60);
		wallRR.SetPos(10, 1, 110);
		wallRR.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallRR.Render();

		Cube wallRR2(2, 3, 40);
		wallRR2.SetPos(-10, 1, 100);
		wallRR2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallRR2.Render();

		//Recta a la derecha
		Cube wallRaD(2, 3, 80);
		wallRaD.SetPos(-30, 1, 140);
		wallRaD.SetRotation(-90, vec3(0, 1, 0));
		wallRaD.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallRaD.Render();

		//recta S
		Cube wallS1(2, 3, 40);
		wallS1.SetPos(-30, 1, 120);
		wallS1.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallS1.Render();

		Cube wallS2(2, 3, 40);
		wallS2.SetPos(-50, 1, 100);
		wallS2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallS2.Render();

		/*Cube wallS3(2, 3, 60);
		wallS3.SetPos(-70, 1, 110);
		App->physics->AddBody(wallS3, 1000000);*/

		//recta aceleracion con cosas(baches o algo)
		Cube wallA(2, 3, 180);
		wallA.SetPos(-70, 1, 50);
		wallA.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallA.Render();

		// giro derecha
		Cube wallG(2, 3, 120);
		wallG.SetPos(-90, 1, -60);
		wallG.SetRotation(-90, vec3(0, 1, 0));
		wallG.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallG.Render();

		Cube wallG1(2, 10, 60);
		wallG1.SetPos(-100, 1, -40);
		wallG1.SetRotation(-90, vec3(0, 1, 0));
		wallG1.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallG1.Render();

		Cube wallG2(2, 3, 60);
		wallG2.SetPos(-150, 1, -30);
		wallG2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallG2.Render();

		Cube wallG3(2, 10, 80);
		wallG3.SetPos(-110, 1, 0);
		wallG3.SetRotation(-90, vec3(0, 1, 0));
		wallG3.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallG3.Render();

		//ramp
		Cube wallRamp(60, 2, 30);
		wallRamp.SetPos(-80, 0, -20);

		wallRamp.SetRotation(20, vec3(0, 0, 1));
		wallRamp.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallRamp.Render();

		//pltform
		Cube platform(60, 2, 30);
		platform.SetPos(20, 10, -20);
		platform.color.Set(0.0f, count = count + 0.02f, 1.0f);
		platform.Render();

		Cube platformWall(60, 2, 2);
		platformWall.SetPos(20, 12, -6);
		platformWall.color.Set(0.0f, count = count + 0.02f, 1.0f);
		platformWall.Render();

		Cube platformWall2(60, 2, 2);
		platformWall2.SetPos(20, 12, -34);
		platformWall2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		platformWall2.Render();

		//down again
		Cube wallD(110, 3, 2);
		wallD.SetPos(70, 1, -6);
		wallD.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallD.Render();

		Cube wallD2(80, 3, 2);
		wallD2.SetPos(70, 1, -34);
		wallD2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallD2.Render();

		//curve
		Cube wallC(2, 3, 50);
		wallC.SetPos(124, 1, -32);
		wallC.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallC.Render();

		//enlargment
		Cube wallDa(40, 3, 2);
		wallDa.SetPos(30, 1, -34);
		wallDa.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallDa.Render();

		Cube wallDa2(145, 3, 2);
		wallDa2.SetPos(50, 1, -55);
		wallDa2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		wallDa2.Render();

		//finalLine
		Cube FinalWall(2, 3, 45);
		FinalWall.SetPos(10, 1, -12);
		FinalWall.color.Set(0.0f, count = count + 0.02f, 1.0f);
		FinalWall.Render();

		Cube FinalWall2(2, 3, 64);
		FinalWall2.SetPos(-10, 1, -24);
		FinalWall2.color.Set(0.0f, count = count + 0.02f, 1.0f);
		FinalWall2.Render();

		return UPDATE_CONTINUE;
}



void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

