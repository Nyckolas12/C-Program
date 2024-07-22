#include "SpaceGame.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "GameData.h"
#include "Font.h"
#include "Text.h"
#include "string.h"
#include "PickUp.h"


using namespace std;


bool SpaceGame::Initialize()
{
    m_scene = new Scene(this);
    m_font = new Font();
    m_font->Load("ReliableSource.ttf", 20);

    m_textScore = new Text(m_font);
    m_textLives = new Text(m_font);
    m_textTitle = new Text(m_font);
    return false;
}

void SpaceGame::Shutdown()
{
}

void SpaceGame::Update(float dt)
{
    switch (m_state)
    {
    case SpaceGame::eState::Title:
      
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
        {
            m_state = eState::StartGame;
        }
        break;
    case SpaceGame::eState::StartGame:
        m_score = 0;
        m_lives = 3;
        m_state = eState::StartLevel;

        break;
    case SpaceGame::eState::StartLevel:
        m_scene->RemoveAll();
        {
        Transform transform{ Vector2{randomf(0,800),randomf(0,600)},0,randomf(1,5) };
        Model* model = new Model{ GameData::shipPoints, Color{1,0,0,} };
        
        Player* player = new Player(800, transform, model);
        player->SetDamping(2.0f);
        player->SetTag("Player");
        m_scene->AddActor(player);
        }
        m_spawnTime = 3;
        m_spawnTimer = m_spawnTime;
        m_state = eState::Game;
        break;
    case SpaceGame::eState::Game:
        m_spawnTimer -= dt;

        if (m_spawnTimer <= 0)
        {
            m_spawnTime -= 0.2f;
            m_spawnTimer = m_spawnTime;

            auto* enemyModel = new Model{ GameData::shipPoints, Color{1,0,1,} };
            auto* enemy = new Enemy(8000, Transform{ { g_engine.GetRenderer().GetWidth(), g_engine.GetRenderer().GetHeight()}, 0,2 }, enemyModel);
            enemy->SetDamping(1.0f);
            enemy->SetTag("Enemy");
            m_scene->AddActor(enemy);

            auto* pickupModel = new Model{ GameData::shipPoints, Color{1,1,1} };
            auto* pickup = new PickUp(Transform{ { random(g_engine.GetRenderer().GetWidth()), random(g_engine.GetRenderer().GetHeight())}, 0,2 }, pickupModel);
        }

        break;
    case SpaceGame::eState::PlayerDead:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
        m_state = eState::StartLevel;

        }
        break;
    case SpaceGame::eState::GameOver:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
            
        m_state = eState::Title;

        }
        break;
    default:
        break;
    }
    
    m_scene->Update(dt);
}

void SpaceGame::Draw(Renderer& renderer)
{
    switch (m_state)
    {
    case SpaceGame::eState::Title:
        //draw text "Game Title"
         m_textTitle->Create(renderer, "Title GAME", Color{ 1,0,0,1 });
        m_textTitle->Draw(renderer, 260, 400);

        break;
   
    case SpaceGame::eState::GameOver:
        //draw text Game Over
        m_textTitle->Create(renderer, "Game Over", Color{ 1,0,0,1 });
        m_textTitle->Draw(renderer, 400, 400);
        break;
    default:
        break;
    }
    //draw score
    string text = "Score " + std::to_string(m_score);
    m_textScore->Create(renderer, text, { 0,1,0,1 });
    m_textScore->Draw(renderer, 20, 20);
    //draw lives

std::string lives = "LIVES " + std::to_string(m_lives);
    m_textScore->Create(renderer, lives, { 0,1,0,1 });
    m_textScore->Draw(renderer, 600, 20);

    m_scene->Draw(renderer);
}

void SpaceGame::OnPlayerDeath()
{
    m_lives--;
    m_state = (m_lives == 0) ? eState::GameOver : eState::PlayerDead;
    m_stateTimer = 3;
}
