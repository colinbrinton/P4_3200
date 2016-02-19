#pragma once
#include "stdafx.h"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "imageCollage.h"

class review
{
protected:
	static const unsigned DFLT_SCORE = 3;
	static const unsigned DFLT_RANK = 50;
	static const bool DFLT_FREE = true;
	static const int DFLT_DATE = 20161902;
	
	static const int RANK_OUTOF = 100;

	unsigned score;
	unsigned rank;

	int date;
	bool free;

public:
	review(unsigned scr = DFLT_SCORE, unsigned rnk = DFLT_RANK, bool fr = DFLT_FREE, int dt = DFLT_DATE);
	~review();

	virtual vector<int> getReviewDisplay();
	unsigned getRawScore();
	unsigned getWeightedScore();
};
