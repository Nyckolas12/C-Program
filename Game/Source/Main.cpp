#include "Engine.h"
#include "Player.h"
#include "Scene.h"
#include "Enemy.h"
#include "SpaceGame.h"
#include "GameData.h"
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{

	g_engine.Initialize();
	//create systems

	SpaceGame* game = new SpaceGame(&g_engine);
	game->Initialize();

	while (!g_engine.IsQuit())
	{
		g_engine.Update();
		game->Update(g_engine.GetTime().GetDeltaTime());

		g_engine.GetRenderer().SetColor(0, 0, 0, 0);
		g_engine.GetRenderer().BeginFrame();

		
		
		game->Draw(g_engine.GetRenderer());


		g_engine.GetRenderer().EndFrame();
	}

	g_engine.Shutdown();
	return 0;
	/*
	
	Input input;
	input.Initialize();
	

	// create audio system
	g_engine.GetAudio().Addsound("bass.wav");
	g_engine.GetAudio().Addsound("snare.wav");
	g_engine.GetAudio().Addsound("close-hat.wav");
	g_engine.GetAudio().Addsound("open-hat.wav");
	g_engine.GetAudio().Addsound("clap.wav");
	g_engine.GetAudio().Addsound("cowbell.wav");

	




	vector<Particle> particles;
	for (int i = 0; i < 0; i++)
	{
		//particles.push_back(Particle{ {rand() % 800,rand() % 800}, {randomf(100,300),0.0f}});
	}



	vector<Vector2> points;



	float offset = 0;
	//vector<Vector2> points;
	/*points.push_back(Vector2{ 5,0 });
	points.push_back(Vector2{ -5,-5 });
	points.push_back(Vector2{ -5,5 });
	points.push_back(Vector2{ 5,0 });





	
	//actor
	Model* model = new Model { GameData::shipPoints, Color{1,0,0,} };
	Scene* scene = new Scene();

		Transform transform{ Vector2{randomf(0,800),randomf(0,600)},0,randomf(1,5) };
		Player* player = new Player(800, transform, model);
		player->SetDamping(2.0f);
		player->SetTag("Player");
		scene->AddActor(player);


		auto* enemyModel = new Model{ points, Color{1,0,1,} };
		auto* enemy = new Enemy(800,  Transform{  { g_engine.GetRenderer().GetWidth(), g_engine.GetRenderer().GetHeight()}, 0,2 },  enemyModel);
		enemy->SetDamping(1.0f);
		enemy->SetTag("Enemy");
		scene->AddActor(enemy);
	
		float spawnTimer = 2;

	
		//main loop
		
	while (!g_engine.IsQuit())
	{
		g_engine.Update();
		spawnTimer -= g_engine.GetTime().GetDeltaTime();
		if (spawnTimer <= 0)
		{
			auto* enemyModel = new Model{ points, Color{1,0,1,} };
			auto* enemy = new Enemy(800, Transform{ { g_engine.GetRenderer().GetWidth(), g_engine.GetRenderer().GetHeight()}, 0,2 }, enemyModel);
			enemy->SetDamping(1.0f);
			enemy->SetTag("Enemy");
			scene->AddActor(enemy);
			spawnTimer = 2;
		}
		//Input
		
		

		//transform.rotation = velocity.Angle(); //rotation + time.GetDeltaTime();
		

		

		//UPDATE
		scene->Update(g_engine.GetTime().GetDeltaTime());

		
		
		

		Vector2 mousePosition = input.GetMousePosition();
		if (input.GetMouseButtonDown(0))
		{
	
			//particles.push_back(Particle{ mousePosition,{randomf(-300,300),randomf(-300,300)} });
			for (int i = 0; i < 20; i++)
			{
				particles.push_back(Particle{ mousePosition,randomOnUnitCircle() * randomf(10,200) ,randomf(1,5) });
			}
			

			
		}

		
		for (Particle& particle : particles)
		{
			particle.Update(g_engine.GetTime().GetDeltaTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;

			
		}




		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_Q) && !g_engine.GetInput().GetPreviousKeyDown(SDL_SCANCODE_Q))
		{
			g_engine.GetAudio().Playsound("bass.wav");
		}
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W) && !g_engine.GetInput().GetPreviousKeyDown(SDL_SCANCODE_W))
		{
			g_engine.GetAudio().Playsound("snare.wav");
		}
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_E) && !g_engine.GetInput().GetPreviousKeyDown(SDL_SCANCODE_E))
		{
			g_engine.GetAudio().Playsound("open-hat.wav");
		}
	
	
	
		
	



	
		
		
		g_engine.GetRenderer().SetColor(0, 0, 0, 0);
		g_engine.GetRenderer().BeginFrame();

		g_engine.GetRenderer().SetColor(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
		float radius = 60;
		offset += (90 * g_engine.GetTime().GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30)
		{
			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.01f) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.01f) * radius;

			//renderer.DrawRect(400 + x, 300 +  y, 4.0f, 4.0f);

		}


		g_engine.Update();


		// draw line
		g_engine.GetRenderer().SetColor(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
		for (Particle particle : particles)
		{
			if(particle.lifespan >= 0) particle.Draw(g_engine.GetRenderer());
		}

		for (int i = 0; points.size()>1 && i < points.size()-1; i++)
		{
			g_engine.GetRenderer().DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		}

	
		g_engine.GetRenderer().SetColor(255, 255, 255 , 0);
		scene->Draw(g_engine.GetRenderer());
		// show screen
		g_engine.GetRenderer().EndFrame();
	}
	

	return 0;
	*/
	
}

