#include "../../Engine/Source/Renderer.h"
#include <iostream>
#include <SDL.h>
#include "../../Engine/Source/Vector2.h"
#include <vector>
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "MathUtils.h"
#include "Model.h"
#include "Transform.h"
#include <fmod.h>
using namespace std;


int main(int argc, char* argv[])
{
	//create systems
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);
	Input input;
	input.Initialize();
	Time time;

	// create audio system
	FMOD::System* audio;
	FMOD::System_Create(&audio);

	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);


	FMOD::Sound* sound = nullptr;
	audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

	audio->playSound(sound, 0, false, nullptr);

	vector<FMOD::Sound*> sounds;
	audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);
	
	audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);
	
	audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);




	vector<Particle> particles;
	for (int i = 0; i < 0; i++)
	{
		//particles.push_back(Particle{ {rand() % 800,rand() % 800}, {randomf(100,300),0.0f}});
	}

	//Vector2 v1{ 400,300 };
	//Vector2 v2{ 700,500 };

	vector<Vector2> points;
	/*for (int i = 0; i < 100; i++)
		{
			points.push_back(Vector2{ rand() % 800, rand() % 600 });
		}*/


	float offset = 0;
	//vector<Vector2> points;
	/*points.push_back(Vector2{ 5,0 });
	points.push_back(Vector2{ -5,-5 });
	points.push_back(Vector2{ -5,5 });
	points.push_back(Vector2{ 5,0 });*/

	// Body
	points.push_back(Vector2{ 0, 0 });
	points.push_back(Vector2{ 10, 0 });
	points.push_back(Vector2{ 10, -5 });
	points.push_back(Vector2{ 0, -5 });
	points.push_back(Vector2{ 0, 0 });

	// Head
	points.push_back(Vector2{ 10, 0 });
	points.push_back(Vector2{ 15, 5 });
	points.push_back(Vector2{ 15, -5 });
	points.push_back(Vector2{ 10, -5 });
	points.push_back(Vector2{ 10, 0 });



	
	
	Model model{ points, Color{1,0,0,} };

	Transform transform{ {renderer.GetWidth() >>1 ,renderer.GetHeight() >>1 },0,5};


	

		//main loop
		bool quit = false;
	while (!quit)
	{
		time.Tick();
		cout << time.GetTime() << endl;
		//Input
		input.Update();
		float thrust = 0;
		if (input.GetKeyDown(SDL_SCANCODE_LEFT)) transform.rotation -= Math::DegToRad(100) * time.GetDeltaTime();
		if (input.GetKeyDown(SDL_SCANCODE_RIGHT)) transform.rotation += Math::DegToRad(100) * time.GetDeltaTime();

		if (input.GetKeyDown(SDL_SCANCODE_DOWN)) thrust = -100;
		if (input.GetKeyDown(SDL_SCANCODE_UP)) thrust = 100;

		Vector2 velocity = Vector2{ thrust, 0.0f }.Rotate(transform.rotation);
		transform.position +=  velocity * time.GetDeltaTime();
		transform.position.x = Math::Wrap(transform.position.x, (float)renderer.GetWidth());
		transform.position.y = Math::Wrap(transform.position.y, (float)renderer.GetHeight());

		//transform.rotation = velocity.Angle(); //rotation + time.GetDeltaTime();
		

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		//UPDATE
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
			particle.Update(time.GetDeltaTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;

			
		}




		if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPreviousKeyDown(SDL_SCANCODE_Q))
		{
			 audio->playSound(sounds[0], 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPreviousKeyDown(SDL_SCANCODE_W))
		{
			audio->playSound(sounds[1], 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPreviousKeyDown(SDL_SCANCODE_E))
		{
			audio->playSound(sounds[2], 0, false, nullptr);
		}
	
	
	
		
	



		//cout << mousePosition.x << " " << mousePosition.y << endl;
		/*if (input.GetMouseButtonDown(0)&& !input.GetPreviousMouseButtonDown(0))
		{
			cout << "mouse down\n";
			points.push_back(mousePosition);

		}
		if (input.GetMouseButtonDown(0) && input.GetPreviousMouseButtonDown(0))
		{
			float distance = (points.back() - mousePosition).Length();
			if (distance > 50)
			{
				points.push_back(mousePosition);
			}
			points.push_back(mousePosition);
		}*/
		/*Vector2 speed{ 0.2f, -0.2f };
		for (Vector2& point : points)
		{
			point = point + 0.002f;

		}*/
		
		// clear screen
		
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
		float radius = 60;
		offset += (90 * time.GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30)
		{
			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.01f) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.01f) * radius;

			//renderer.DrawRect(400 + x, 300 +  y, 4.0f, 4.0f);

		}


		audio->update();


		// draw line
		renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
		for (Particle particle : particles)
		{
			if(particle.lifespan >= 0) particle.Draw(renderer);
		}

		for (int i = 0; points.size()>1 && i < points.size()-1; i++)
		{
			renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		}

		//renderer.DrawLine(v1.x, v1.y, v2.x, v2.y);

		/*for (int i = 0; i < 1000; i++)
		{
			renderer.SetColor( rand() % 256, rand() % 256, rand() % 256, 0);
			renderer.DrawLine( rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000);
		}
		*/
		renderer.SetColor(255, 255, 255 , 0);
		model.Draw(renderer,transform);
		// show screen
		renderer.EndFrame();
	}
	

	return 0;
}
