#include "stdafx.h"
#include "GameScene_01.h"
#include "GameManager.h"

#include "Player.h"
#include "Babe.h"
#include "Bar.h"
#include "GameObject.h"
#include "Mirror.h"
#include "Locker_1.h"
#include "Phone.h"

Scene* GameScene_01::createScene()
{
    auto scene = Scene::create();

    auto layer = GameScene_01::create();

    scene->addChild(layer);

    return scene;
}

bool GameScene_01::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto dir = Director::getInstance();
	auto size = dir->getVisibleSize();
	auto origin = dir->getVisibleOrigin();

	//backround
	auto room = TMXTiledMap::create("myRoom.tmx");
	room->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	room->setPosition(size.width / 2, size.height / 2);
	addChild(room, 0);

	auto pain = Sprite::create("pain.png");
	pain->setPosition(room->getPosition());
	pain->setScale(0.75f);
	pain->setOpacity(0);
	addChild(pain, -1);

	//ui
	auto playerBar = Bar::create();
	playerBar->SetSprite("player_bar_current.png", "player_bar_capacity.png", "player_bar_icon.png");
	playerBar->setPosition(Vec2(200, 50));
	addChild(playerBar, 5);

	//player
	auto player = Player::create();
	player->setPosition(400, 150);
	player->SetBar(playerBar);
	player->SetMap(room);
	room->addChild(player, 2);

	//babe
	auto babe = Babe::create();
	babe->setPosition(babe->BABE_INIT_POS);
	room->addChild(babe, 3);

	//game objects
	m_gm = new GameManager();
	m_gm->RegisterData(player, babe, playerBar, /*missionBar,*/ room, pain);

	auto mirror = Mirror::create();
	mirror->setPosition(Vec2(345, 210)); 
	m_gm->RegisterGameObject(mirror);
	room->addChild(mirror, 1);

	auto locker_1 = Locker_1::create();
	locker_1->setPosition(Vec2(600, 95));
	m_gm->RegisterGameObject(locker_1);
	room->addChild(locker_1, 1);

	auto cellPhone = Phone::create(room);
	cellPhone->setPosition(Vec2(500, 95));
	m_gm->RegisterGameObject(cellPhone);
	room->addChild(cellPhone, 1);

	scheduleUpdate();
	
    return true;
}

void GameScene_01::update(float dt)
{
	m_gm->Play();
}
