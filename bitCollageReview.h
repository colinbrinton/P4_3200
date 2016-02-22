#pragma once
#include "review.h"
#include "bitCollage.h"
class bitCollageReview :
	public review, public bitCollage
{
public:
	bitCollageReview(vector<int> col = NULL_COL,
		unsigned scr = DFLT_SCORE, unsigned rnk = DFLT_RANK, bool fr = DFLT_FREE, int dt = DFLT_DATE);
	~bitCollageReview();

	//vector<int> getDisplay() { return this->bitCollage::getDisplay(); }
};

