#include "ScoreTracker.h"
#include "../Prefab/PrefabOriginals/BallPrefab.h"
#include "../GameObject/GameObject.h"
#include "../Game/Game.h"

void ScoreTracker::add_score(int score)
{
	this->score += score;
}

int ScoreTracker::get_score()
{
	return this->score;
}