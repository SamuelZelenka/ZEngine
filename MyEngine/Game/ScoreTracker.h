#pragma once
#include "SDL.h"

class ScoreTracker
{
public:
	ScoreTracker()
	{
		score = 0;
	}
	void add_score(int score);
	int get_score();
private:
	int score;
};