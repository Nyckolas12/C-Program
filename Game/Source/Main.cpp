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
	
	
}

