#include "stdafx.h"
#include "bitCollageReview.h"


bitCollageReview::bitCollageReview(vector<int> col, unsigned scr, unsigned rnk, bool fr, int dt) :
bitCollage(col), review(scr, rnk, fr, dt)
{
}


bitCollageReview::~bitCollageReview()
{
}
