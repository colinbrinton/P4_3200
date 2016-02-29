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
#pragma once
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include "imageCollage.h"

class review
{
protected:
	static const unsigned DFLT_SCORE = 3;
	static const unsigned DFLT_RANK = 50;
	static const bool DFLT_FREE = true;
	static const int DFLT_DATE = 20161902;
	static const int SCORE_MIN = 1;
	
	static const int RANK_OUTOF = 100;

	unsigned score;
	unsigned rank;

	int date;
	bool free;

public:
	review(unsigned scr = DFLT_SCORE, unsigned rnk = DFLT_RANK, bool fr = DFLT_FREE, int dt = DFLT_DATE);
	~review();

	//virtual vector<int> getDisplay();
	unsigned getRawScore();
	unsigned getWeightedScore();
	bool wasFree();
	unsigned getDate();
};
