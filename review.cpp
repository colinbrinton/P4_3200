// AUTHOR: Colin Brinton
// FILENAME: review.h
// DATE: 2/22/2016
// REVISION HISTORY: 1.0

/* DESCRIPTION:
* Extends the functionality of imageCollage. It uses an overridden getDisplay()
* to display a subset of its image IDs which is randomly determined to be between.
* one and three less than its original set. replaceImage is overridden all will only
* successfully replace odd image ID's.
*/

/* ASSUMPTIONS:
* replaceImage() will not be used on even image ID's.
*/
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

	if (weighted < SCORE_MIN)
		weighted = SCORE_MIN;
	return round(weighted);
}

bool review::wasFree()
{
	return free;
}

unsigned review::getDate()
{
	return date;
}

/*vector<int> review::getDisplay()
{
	vector<int> null;
	return null;
}*/