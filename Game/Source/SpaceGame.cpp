#include "SpaceGame.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "GameData.h"
#include "Audio.h"
#include "Font.h"
#include "Text.h"
#include "string.h"
#include "PickUp.h"
#include "goalPost.h"


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
            
         
         
          
        Transform transform{ Vector2{ 300.0f,330.0f},0,3 };
        Model* model = new Model{ GameData::shipPoints, Color{1,0,0,} };
        
        
        auto player = std::make_unique<Player>(800, transform, model);
        player->SetDamping(2.0f);
        player->SetTag("Player");
        m_scene->AddActor(std::move(player));

        
        
       
        
        }
        m_spawnTime = 3;
        m_spawnTimer = m_spawnTime;
        
        m_state = eState::Game;
        break;
    case SpaceGame::eState::Game:
        m_spawnTimer -= dt;
    {
        auto* goalPostModel = new Model{ GameData::goalPost, Color{1,1,1} };
        auto goalPosts = std::make_unique<goalPost>(Transform{ { 10.0f, 330.0f}, 0,5 }, goalPostModel);
        goalPosts->SetTag("Goal");
        m_scene->AddActor(std::move(goalPosts));

        auto* enemyGoalPostModel = new Model{ GameData::goalPost, Color{2,1,0} };
        auto EnemygoalPosts = std::make_unique<goalPost>(Transform{ { 780.0f, 320.0f}, 3.20f,5 }, enemyGoalPostModel);
        EnemygoalPosts->SetTag("Goals");
        m_scene->AddActor(std::move(EnemygoalPosts));
    }

        if (m_spawnTimer <= 0)
        {
            
            m_spawnTime -= 0.010f;
            m_spawnTimer = m_spawnTime;

            auto* enemyModel = new Model{ GameData::enemy, Color{1,0,1,} };
            auto enemy = std::make_unique<Enemy>(800, Transform{ { g_engine.GetRenderer().GetWidth(), g_engine.GetRenderer().GetHeight()}, 0,3 }, enemyModel);
            enemy->SetDamping(1.0f);
            enemy->SetTag("Enemy");
            m_scene->AddActor(std::move(enemy));


            auto* alienModel = new Model{ GameData::enemyAlien, Color{3,8,5,} };
            auto alien = std::make_unique<Enemy>(800, Transform{ { 700,600}, 0,4 }, alienModel);
            alien->SetDamping(1.0f);
            alien->SetTag("Alien");
            m_scene->AddActor(std::move(alien));
            

            auto* pickupModel = new Model{ GameData::heartLives, Color{1,1,1} };
            auto pickup = std::make_unique<PickUp>(Transform{ { g_engine.GetRenderer().GetWidth(), g_engine.GetRenderer().GetHeight()}, 0,4 }, pickupModel);
            pickup->SetTag("PickUp");
            m_scene->AddActor(std::move(pickup));

            
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
         m_textTitle->Create(renderer, "BOOT SPACE GAME", Color{ 1,0,0,1 });
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
