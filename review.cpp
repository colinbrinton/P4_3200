#include "stdafx.h"
#include "review.h"


review::review(unsigned scr, unsigned rnk, bool fr, int dt)
{
	score = scr;
	rank = rnk;
	free = fr;
	date = dt;
}


review::~review()
{
}

unsigned review::getRawScore()
{
	return score;
}

unsigned review::getWeightedScore()
{
	double fullPoints = RANK_OUTOF;
	double rankPercent = (rank / fullPoints);
	double weighted = (score * rankPercent);

	return round(weighted);
}

/*vector<int> review::getDisplay()
{
	vector<int> null;
	return null;
}*/