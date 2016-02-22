#include "stdafx.h"
#include "collageReview.h"


collageReview::collageReview(vector<int> col, unsigned scr, unsigned rnk, bool fr, int dt) : 
imageCollage(col), review(scr, rnk, fr, dt)
{

}


collageReview::~collageReview()
{
}


