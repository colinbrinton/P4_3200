// AUTHOR: Colin Brinton
// FILENAME: bitCollageReview.cpp
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
