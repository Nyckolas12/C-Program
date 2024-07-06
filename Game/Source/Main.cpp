#include "../../Engine/Source/Renderer.h"
#include <iostream>
#include <SDL.h>
#include "../../Engine/Source/Vector2.h"
#include <vector>
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
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

		//main loop
		bool quit = false;
	while (!quit)
	{
		time.Tick();
		cout << time.GetTime() << endl;
		//Input
		input.Update();

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		//UPDATE
		Vector2 mousePosition = input.GetMousePosition();
		if (input.GetMouseButtonDown(0))
		{
	
			//particles.push_back(Particle{ mousePosition,{randomf(-300,300),randomf(-300,300)} });
			particles.push_back(Particle{ mousePosition,{randomf(-300,300),randomf(-300,300)},randomf(1,5) });

			
		}

		
		for (Particle& particle : particles)
		{
			particle.Update(time.GetDeltaTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;

			if (particle.lifespan != 0) particle.lifespan -= time.GetDeltaTime();
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
		

		// show screen
		renderer.EndFrame();
	}
	

	return 0;
}
