#include "stdafx.h"
#include "bitCollageReview.h"


bitCollageReview::bitCollageReview(int sz, unsigned scr, unsigned rnk, bool fr, int dt) :
bitCollage(sz), review(scr, rnk, fr, dt)
{
}


bitCollageReview::~bitCollageReview()
{
}
