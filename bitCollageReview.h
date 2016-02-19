#pragma once
#include "review.h"
#include "bitCollage.h"
class bitCollageReview :
	public review, public bitCollage
{
public:
	bitCollageReview(int sz = DEFAULT_SIZE,
		unsigned scr = DFLT_SCORE, unsigned rnk = DFLT_RANK, bool fr = DFLT_FREE, int dt = DFLT_DATE);
	~bitCollageReview();

	vector<int> getReviewDisplay() { return this->getDisplay(); }
};

