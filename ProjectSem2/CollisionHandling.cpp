#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "UnknownCollision.h"

#include "spaceShip.h"
#include "Chicken.h"
#include "ShootObject.h"
#include "Egg.h"
#include "Prize.h"
#include "ChickenLeg.h"
#include "Coin.h"
#include "SoundManager.h"
#include "ChickenBoss1.h"
#include "ChickenBoss2.h"
#include "ChickenBoss3.h"

// Register yourself at the regular Factory
bool ChickenBoss1::m_register = Factory::registerit("ChickenBoss1",
	[]() -> std::shared_ptr<GameObject> { return std::make_shared<ChickenBoss1>(); });

// Register yourself at the regular Factory
bool ChickenBoss2::m_register = Factory::registerit("ChickenBoss2",
	[]() -> std::shared_ptr<GameObject> { return std::make_shared<ChickenBoss2>(); });

// Register yourself at the regular Factory
bool ChickenBoss3::m_register = Factory::registerit("ChickenBoss3",
	[]() -> std::shared_ptr<GameObject> { return std::make_shared<ChickenBoss3>(); });

// Register yourself at the regular Factory
bool spaceShip::m_register = Factory::registerit("spaceShip", 
					       []() -> std::shared_ptr<GameObject> { return std::make_shared<spaceShip>(); });

// Register yourself at the regular Factory
bool Chicken::m_register = Factory::registerit("Chicken",
                           []() -> std::shared_ptr<GameObject> { return std::make_shared<Chicken>(); });

// Register yourself at the regular Factory
bool ShootObject::m_register = Factory::registerit("RedShot",
                           []() -> std::shared_ptr<GameObject> { return std::make_shared<ShootObject>(); });

// Register yourself at the random Factory.
bool ChickenLeg::_randomRegister = RandomFactory::registerit("ChickenLeg",
	[]() -> std::shared_ptr<FallingObject> { return std::make_shared<ChickenLeg>(); });

// Register yourself at the random Factory.
bool Coin::_randomRegister = RandomFactory::registerit("Coin",
	[]() -> std::shared_ptr<FallingObject> { return std::make_shared<Coin>(); });

// Register yourself at the random Factory.
bool Egg::_randomRegister = RandomFactory::registerit("Egg",
	[]() -> std::shared_ptr<FallingObject> { return std::make_shared<Egg>(); });

// Register yourself at the random Factory.
bool Egg::_regularRegister = Factory::registerit("Egg",
	[]() -> std::shared_ptr<GameObject> { return std::make_shared<Egg>(); });

// Register yourself at the random Factory.
bool Prize::_randomRegister = RandomFactory::registerit("Prize",
	[]() -> std::shared_ptr<FallingObject> { return std::make_shared<Prize>(); });

namespace { // unnamed namespace — the standard way to make function "static"

			// primary collision-processing functions

	//-----------------------------------------------------------------------//
	//---------------------------Ship-Objects--------------------------------//
	//-----------------------------------------------------------------------//
	void shipChicken(GameObject& ship,
					 GameObject& chicken)
	{
		auto space = static_cast<spaceShip*>(&ship);
		space->setAttackBehavior(DECREASE_T);
		space->setScore(SCORE_CHICKEN_HIT);
		space->resetPosition();
		ship.decreaseLives();
		SoundManager::instance().playSound("spaceDied.ogg");
		chicken.decreaseLives();

	}
	///////////////////////////////////////////////////////////////////////////
	void shipBoss(GameObject& ship,
		GameObject& boss)
	{
		shipChicken(ship, boss);
	}
	///////////////////////////////////////////////////////////////////////////
	void shipShoot(GameObject& ship,
				   GameObject& shoot)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void shipEgg(GameObject& ship,
		GameObject& egg)
	{
		auto space = static_cast<spaceShip*>(&ship);
		space->decreaseLives();
		space->setAttackBehavior(DECREASE_T);
		space->resetPosition();
		SoundManager::instance().playSound("spaceDied.ogg");
		egg.decreaseLives();
	}
	///////////////////////////////////////////////////////////////////////////
	void shipChickenLeg(GameObject& ship,
		GameObject& leg)
	{
		SoundManager::instance().playSound("ChickenLeg.ogg");
		auto space = static_cast<spaceShip*>(&ship);
		space->setScore(SCORE_CHICKEN_LEG);
		leg.decreaseLives();
	}
	///////////////////////////////////////////////////////////////////////////
	void shipPrize(GameObject& ship,
		GameObject& prize)
	{
		SoundManager::instance().playSound("Prize.ogg");
		auto space = static_cast<spaceShip*>(&ship);
		space->setAttackBehavior(INCREASE_T);
		prize.decreaseLives();
	}
	///////////////////////////////////////////////////////////////////////////
	void shipCoin(GameObject& ship,
		GameObject& coin)
	{
		SoundManager::instance().playSound("CollectCoin.ogg");
		auto space = static_cast<spaceShip*>(&ship);
		space->setScore(SCORE_COIN);
		coin.decreaseLives();
	}
	//-----------------------------------------------------------------------//
	//------------------------Chicken-Objects--------------------------------//
	//-----------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void chickenShip(GameObject& chicken,
					 GameObject& ship)
	{
		shipChicken(ship, chicken);
	}
	///////////////////////////////////////////////////////////////////////////
	void chickenShoot(GameObject& chicken,
					  GameObject& shoot)
	{
		chicken.decreaseLives();
		shoot.decreaseLives();
		if(chicken.getLive() == 0)
			SoundManager::instance().playSound("ChickenDie.ogg");
	}
	///////////////////////////////////////////////////////////////////////////
	void chickenChicken(GameObject& chicken1,
		GameObject& chicken2)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void chickenEgg(GameObject& chicken,
		GameObject& Egg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void chickenChickenLeg(GameObject& chicken,
		GameObject& leg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void chickenPrize(GameObject& chicken,
		GameObject& prize)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void chickenCoin(GameObject& chicken,
		GameObject& coin)
	{
		//empty implamntation
	}
	//-----------------------------------------------------------------------//
	//---------------------------Boss-Objects--------------------------------//
	//-----------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void bossShip(GameObject& boss,
		GameObject& ship)
	{
		shipChicken(ship, boss);
	}
	///////////////////////////////////////////////////////////////////////////
	void bossShoot(GameObject& boss,
		GameObject& shoot)
	{
		boss.decreaseLives();
		shoot.decreaseLives();
		SoundManager::instance().playSound("ChickenDie.ogg");
	}
	///////////////////////////////////////////////////////////////////////////
	void bossChicken(GameObject& boss,
		GameObject& chicken2)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void bossEgg(GameObject& boss,
		GameObject& Egg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void bossChickenLeg(GameObject& boss,
		GameObject& leg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void bossPrize(GameObject& boss,
		GameObject& prize)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void bossCoin(GameObject& chicken,
		GameObject& coin)
	{
		//empty implamntation
	}
	//-----------------------------------------------------------------------//
	//--------------------------Shoot-Objects--------------------------------//
	//-----------------------------------------------------------------------//
	void shootShip(GameObject& shoot,
		GameObject& ship)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void shootChicken(GameObject& shoot,
		GameObject& chicken)
	{
		chickenShoot(chicken, shoot);
	}
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void shootBoss(GameObject& shoot,
		GameObject& boss)
	{
		bossShoot(boss, shoot);
	}
	///////////////////////////////////////////////////////////////////////////
	void shootshoot(GameObject& shoot1,
		GameObject& shoot2)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void shootEgg(GameObject& shoot,
		GameObject& egg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void shootChickenLeg(GameObject& shoot,
		GameObject& leg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void shootPrize(GameObject& shoot,
		GameObject& Prize)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void shootCoin(GameObject& shoot,
		GameObject& Coin)
	{
		//empty implamntation
	}
	//-----------------------------------------------------------------------//
	//----------------------------Egg-Objects--------------------------------//
	//-----------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void eggShip(GameObject& egg,
		GameObject& ship)
	{
		shipEgg(ship, egg);
	}
	///////////////////////////////////////////////////////////////////////////
	void eggChicken(GameObject& egg,
		GameObject& chicken)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void eggShoot(GameObject& egg,
		GameObject& shoot)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void EggEgg(GameObject& egg1,
		GameObject& egg2)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void EggChickenLeg(GameObject& egg,
		GameObject& leg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void EggPrize(GameObject& egg,
		GameObject& prize)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void EggCoin(GameObject& egg,
		GameObject& coin)
	{
		//empty implamntation
	}
	//-----------------------------------------------------------------------//
	//----------------------------Leg-Objects--------------------------------//
	//-----------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegShip(GameObject& leg,
		GameObject& ship)
	{
		shipChickenLeg(ship, leg);
	}
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegChicken(GameObject& leg,
		GameObject& chicken)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegBoss(GameObject& leg,
		GameObject& boss)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegShoot(GameObject& leg,
		GameObject& shoot)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegEgg(GameObject& leg,
		GameObject& egg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegChickenLeg(GameObject& leg1,
		GameObject& leg2)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegPrize(GameObject& leg,
		GameObject& prize)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void ChickenLegCoin(GameObject& leg,
		GameObject& coin)
	{
		//empty implamntation
	}
	//-----------------------------------------------------------------------//
	//----------------------------Prize-Objects------------------------------//
	//-----------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void PrizeShip(GameObject& prize,
		GameObject& ship)
	{
		shipPrize(ship, prize);
	}
	///////////////////////////////////////////////////////////////////////////
	void PrizeChicken(GameObject& prize,
		GameObject& chicken)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void PrizeBoss(GameObject& prize,
		GameObject& boss)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void PrizeShoot(GameObject& prize,
		GameObject& shoot)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void PrizeEgg(GameObject& prize,
		GameObject& egg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void PrizeChickenLeg(GameObject& prize,
		GameObject& leg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void PrizePrize(GameObject& prize1,
		GameObject& prize2)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void PrizeCoin(GameObject& prize,
		GameObject& coin)
	{
		//empty implamntation
	}
	//-----------------------------------------------------------------------//
	//---------------------------Coin-Objects--------------------------------//
	//-----------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////
	//secondary collision-processing functions that just implement symmetry: 
	//swap the parameters and call a primary function
	///////////////////////////////////////////////////////////////////////////
	void CoinShip(GameObject& coin,
		GameObject& ship)
	{
		shipCoin(ship, coin);
	}
	///////////////////////////////////////////////////////////////////////////
	void CoinChicken(GameObject& coin,
		GameObject& chicken)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void CoinBoss(GameObject& coin,
		GameObject& boss)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void CoinShoot(GameObject& coin,
		GameObject& shoot)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void CoinEgg(GameObject& coin,
		GameObject& egg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void CoinChickenLeg(GameObject& coin,
		GameObject& leg)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void CoinPrize(GameObject& coin,
		GameObject& prize)
	{
		//empty implamntation
	}
	///////////////////////////////////////////////////////////////////////////
	void CoinCoin(GameObject& coin1,
		GameObject& coin2)
	{
		//empty implamntation
	}


	//---------------------------Using---------------------------------------//
	using HitFunctionPtr = void(*)(GameObject&, GameObject&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	//------------------------Name-Spaces------------------------------------//
	HitMap initializeCollisionMap()
	{
		HitMap phm;
		//SpaceShip with all other Objects
		phm[Key(typeid(spaceShip), typeid(Chicken))] = &shipChicken;
		phm[Key(typeid(spaceShip), typeid(ChickenBoss1))] = &shipBoss;
		phm[Key(typeid(spaceShip), typeid(ShootObject))] = &shipShoot;
		phm[Key(typeid(spaceShip), typeid(Egg))] = &shipEgg;
		phm[Key(typeid(spaceShip), typeid(ChickenLeg))] = &shipChickenLeg;
		phm[Key(typeid(spaceShip), typeid(Prize))] = &shipPrize;
		phm[Key(typeid(spaceShip), typeid(Coin))] = &shipCoin;
		//Chicken with all other Objects
		phm[Key(typeid(Chicken), typeid(spaceShip))] = &chickenShip;
		phm[Key(typeid(Chicken), typeid(ShootObject))] = &chickenShoot;
		phm[Key(typeid(Chicken), typeid(Chicken))] = &chickenChicken;
		phm[Key(typeid(Chicken), typeid(Egg))] = &chickenEgg;
		phm[Key(typeid(Chicken), typeid(ChickenLeg))] = &chickenChickenLeg;
		phm[Key(typeid(Chicken), typeid(Prize))] = &chickenPrize;
		phm[Key(typeid(Chicken), typeid(Coin))] = &chickenCoin;
		//ChickenBoss1 with all other Objects
		phm[Key(typeid(ChickenBoss1), typeid(spaceShip))] = &bossShip;
		phm[Key(typeid(ChickenBoss1), typeid(ShootObject))] = &bossShoot;
		phm[Key(typeid(ChickenBoss1), typeid(Chicken))] = &bossChicken;
		phm[Key(typeid(ChickenBoss1), typeid(Egg))] = &bossEgg;
		phm[Key(typeid(ChickenBoss1), typeid(ChickenLeg))] = &bossChickenLeg;
		phm[Key(typeid(ChickenBoss1), typeid(Prize))] = &bossPrize;
		phm[Key(typeid(ChickenBoss1), typeid(Coin))] = &bossCoin;
		//ChickenBoss2 with all other Objects
		phm[Key(typeid(ChickenBoss2), typeid(spaceShip))] = &bossShip;
		phm[Key(typeid(ChickenBoss2), typeid(ShootObject))] = &bossShoot;
		phm[Key(typeid(ChickenBoss2), typeid(Chicken))] = &bossChicken;
		phm[Key(typeid(ChickenBoss2), typeid(Egg))] = &bossEgg;
		phm[Key(typeid(ChickenBoss2), typeid(ChickenLeg))] = &bossChickenLeg;
		phm[Key(typeid(ChickenBoss2), typeid(Prize))] = &bossPrize;
		phm[Key(typeid(ChickenBoss2), typeid(Coin))] = &bossCoin;
		//ChickenBoss3 with all other Objects
		phm[Key(typeid(ChickenBoss3), typeid(spaceShip))] = &bossShip;
		phm[Key(typeid(ChickenBoss3), typeid(ShootObject))] = &bossShoot;
		phm[Key(typeid(ChickenBoss3), typeid(Chicken))] = &bossChicken;
		phm[Key(typeid(ChickenBoss3), typeid(Egg))] = &bossEgg;
		phm[Key(typeid(ChickenBoss3), typeid(ChickenLeg))] = &bossChickenLeg;
		phm[Key(typeid(ChickenBoss3), typeid(Prize))] = &bossPrize;
		phm[Key(typeid(ChickenBoss3), typeid(Coin))] = &bossCoin;
		//Shoot with all other Objects
		phm[Key(typeid(ShootObject), typeid(spaceShip))] = &shootShip;
		phm[Key(typeid(ShootObject), typeid(Chicken))] = &shootChicken;
		phm[Key(typeid(ShootObject), typeid(ChickenBoss1))] = &shootBoss;
		phm[Key(typeid(ShootObject), typeid(ChickenBoss2))] = &shootBoss;
		phm[Key(typeid(ShootObject), typeid(ChickenBoss3))] = &shootBoss;
		phm[Key(typeid(ShootObject), typeid(ShootObject))] = &shootshoot;
		phm[Key(typeid(ShootObject), typeid(Egg))] = &shootEgg;
		phm[Key(typeid(ShootObject), typeid(ChickenLeg))] = &shootChickenLeg;
		phm[Key(typeid(ShootObject), typeid(Prize))] = &shootPrize;
		phm[Key(typeid(ShootObject), typeid(Coin))] = &shootCoin;
		//Egg with all other Objects
		phm[Key(typeid(Egg), typeid(spaceShip))] = &eggShip;
		phm[Key(typeid(Egg), typeid(Chicken))] = &eggChicken;
		phm[Key(typeid(Egg), typeid(ChickenBoss1))] = &shootBoss;
		phm[Key(typeid(Egg), typeid(ShootObject))] = &eggShoot;
		phm[Key(typeid(Egg), typeid(Egg))] = &EggEgg;
		phm[Key(typeid(Egg), typeid(ChickenLeg))] = &EggChickenLeg;
		phm[Key(typeid(Egg), typeid(Prize))] = &EggPrize;
		phm[Key(typeid(Egg), typeid(Coin))] = &EggCoin;
		//ChickenLeg with all other Objects
		phm[Key(typeid(ChickenLeg), typeid(spaceShip))] = &ChickenLegShip;
		phm[Key(typeid(ChickenLeg), typeid(Chicken))] = &ChickenLegChicken;
		phm[Key(typeid(ChickenLeg), typeid(ChickenBoss1))] = &ChickenLegBoss;
		phm[Key(typeid(ChickenLeg), typeid(ShootObject))] = &ChickenLegShoot;
		phm[Key(typeid(ChickenLeg), typeid(Egg))] = &ChickenLegEgg;
		phm[Key(typeid(ChickenLeg), typeid(ChickenLeg))] = &ChickenLegChickenLeg;
		phm[Key(typeid(ChickenLeg), typeid(Prize))] = &ChickenLegPrize;
		phm[Key(typeid(ChickenLeg), typeid(Coin))] = &ChickenLegCoin;
		//Prize with all other Objects
		phm[Key(typeid(Prize), typeid(spaceShip))] = &PrizeShip;
		phm[Key(typeid(Prize), typeid(Chicken))] = &PrizeChicken;
		phm[Key(typeid(Prize), typeid(ChickenBoss1))] = &PrizeBoss;
		phm[Key(typeid(Prize), typeid(ShootObject))] = &PrizeShoot;
		phm[Key(typeid(Prize), typeid(Egg))] = &PrizeEgg;
		phm[Key(typeid(Prize), typeid(ChickenLeg))] = &PrizeChickenLeg;
		phm[Key(typeid(Prize), typeid(Prize))] = &PrizePrize;
		phm[Key(typeid(Prize), typeid(Coin))] = &PrizeCoin;
		//Coin with all other Objects
		phm[Key(typeid(Coin), typeid(spaceShip))] = &CoinShip;
		phm[Key(typeid(Coin), typeid(Chicken))] = &CoinChicken;
		phm[Key(typeid(Coin), typeid(ChickenBoss1))] = &CoinBoss;
		phm[Key(typeid(Coin), typeid(ShootObject))] = &CoinShoot;
		phm[Key(typeid(Coin), typeid(Egg))] = &CoinEgg;
		phm[Key(typeid(Coin), typeid(ChickenLeg))] = &CoinChickenLeg;
		phm[Key(typeid(Coin), typeid(Prize))] = &CoinPrize;
		phm[Key(typeid(Coin), typeid(Coin))] = &CoinCoin;
		//...
		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}

} // end namespace

void processCollision(GameObject& object1, GameObject& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		throw UnknownCollision("Unkown collision");
	}
	phf(object1, object2);
}

