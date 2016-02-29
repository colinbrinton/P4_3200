// AUTHOR: Colin Brinton
// FILENAME: bitCollage.h
// DATE: 2/22/2016
// REVISION HISTORY: 2.0

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
#include "imageCollage.h"
class bitCollage : public imageCollage
{
	const static int MIN_OMIT = 1;
	const static int MAX_OMIT = 4;

public:
	bitCollage(vector<int> col = NULL_COL) : imageCollage(col) {}
	~bitCollage();

	vector<int> getDisplay();
	bool replaceImage(int imgID);
};

