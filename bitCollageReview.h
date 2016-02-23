// AUTHOR: Colin Brinton
// FILENAME: bitCollageReview.h
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

