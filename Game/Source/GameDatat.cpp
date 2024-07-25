#include "GameData.h"

namespace GameData
{

	const std::vector <Vector2 > shipPoints
	{
		//foot 
		{ 0, 0 },
		{ 10, 0 },
		{ 10, -5 },
		{ 0, -5 },
		{ 0, 0 },
		{ 10, 0 },
		{ 15, 5 },
		{ 15, -5 },
		{ 10, -5 },
		{ 10, 0 },
	};

	const std::vector<Vector2> goalPost
	{
	{ 5, 5 },   // Top-right
	{ 5, 5 },  // Bottom-right
	{ 0, 5 },  // Bottom-left
	{ 0, -5 },   // Top-left
	{ 5, -5 }
	};

	const std::vector<Vector2> enemy
	{
		{5,0},
		{4,3},
		{ 0, 5 },
		{ 2, 4 },
		{ -2, 4 },
		{ -4, 3 },
		{ -5, 0 },
		{ -4, -3 },
		{ -2, -4 },
		{ 0, -5 },
		{ 2, -4 },
		{ 4, -3 },
		{ 5, 0 },
	};

	const std::vector<Vector2> enemyAlien
	{
		 {0, 2},
		{1, 1}, {2, 0},
		{3, 0}, {4, 1},
		{5, 2}, // Top oval part

		{1, 2},
		{2, 1},
		{3, 1},
		{4, 2}, 
		{1, 3}, 
		{2, 3},
		{3, 3},
		{4, 3}, // Middle rectangular part
		{2, 4},
		{3, 4}, // Bottom part of the body
		{-1, 3 },
		{0, 2},
		{0, 3},		
		{ 5, 2 }, 
		{6, 3},
		{6, 4}

	

	};

	const std::vector<Vector2> heartLives
	{

		{0, 6}, {1, 5}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, // Top left oval part
		{7, 6}, {8, 5}, {9, 4}, {10, 4}, {11, 5}, {12, 6}, // Top right oval part

		{2, 6}, {3, 5}, {4, 5}, {5, 6}, // Left middle upper part
		{7, 6}, {8, 5}, {9, 5}, {10, 6}, // Right middle upper part

		{1, 7}, {2, 6}, {3, 6}, {4, 6}, {5, 7}, // Left middle lower part
		{7, 7}, {8, 6}, {9, 6}, {10, 6}, {11, 7}, // Right middle lower part

		{0, 8}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 8}, // Bottom left part of the body
		{7, 8}, {8, 7}, {9, 7}, {10, 7}, {11, 7}, {12, 8}, // Bottom right part of the body

		{3, 8}, {4, 8}, {5, 9}, // Left bottom part
		{7, 9}, {8, 8}, {9, 8}, {10, 8}, // Right bottom part

		{4, 9}, {5, 10}, {6, 11}, {7, 10}, {8, 9} // Tip of the heart

	};

}