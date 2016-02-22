#include "stdafx.h"
#include "bitCollageReview.h"
//#include <iostream>


bitCollageReview::bitCollageReview(vector<int> col, unsigned scr, unsigned rnk, bool fr, int dt) :
bitCollage(col), review(scr, rnk, fr, dt)
{
	//cout << "IMA bCR RECEIVED SCORE: " << scr << endl;
}


bitCollageReview::~bitCollageReview()
{
}
