// AUTHOR: Colin Brinton
// FILENAME: cyclicCollage.h
// DATE: 2/22/2016
// REVISION HISTORY: 2.0

/* DESCRIPTION:
* Extends the functionality of imagCollage. It uses an overridden getDisplay()
* to cycle through its image IDs based on the given shift value during construction.
* Defaults to 2 in this example. replaceImage is overridden to always return false
* and will not modify any cyclicCollage data.
*/

/* ASSUMPTIONS:
* User will only want to set shift value once at construction. replaceImage() will
* not be used.
*/
#pragma once
#include "imageCollage.h"
class cyclicCollage : public imageCollage
{
protected:

	const static int DEFAUL_SHIFT = 2;
	int shift;

public:
	cyclicCollage(vector<int> col = NULL_COL, int shft = DEFAUL_SHIFT) : imageCollage(col), shift(shft) {}
	~cyclicCollage();

	bool replaceImage(int imgID) { return false; }
	vector<int> getDisplay();
};

