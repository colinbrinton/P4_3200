#include "stdafx.h"
#include "collageReview.h"
//#include <iostream>


collageReview::collageReview(vector<int> col, unsigned scr, unsigned rnk, bool fr, int dt) : 
imageCollage(col), review(scr, rnk, fr, dt)
{
	//cout << "IMA cR RECEIVED SCORE: " << scr << endl;
}


collageReview::~collageReview()
{
}


