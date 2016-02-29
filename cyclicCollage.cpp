// AUTHOR: Colin Brinton
// FILENAME: cyclicCollage.cpp
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
#include "cyclicCollage.h"


/*cyclicCollage::cyclicCollage(int size, int shft)
{
	shift = shft;
	imageCollage::imageCollage(size);
}*/


cyclicCollage::~cyclicCollage()
{
}

vector<int> cyclicCollage::getDisplay()
{
	if (active)
	{
		++displayCount;
		vector<int> display(collage.size());
		for (int index = 0; index < collage.size(); ++index)
		{
			int shiftIndex = (index + (shift * displayCount)) % displaySize;
			display[shiftIndex] = collage[index];
		}
		return display;
	}
	else
	{
		vector<int> nullDisplay;
		return nullDisplay;
	}
}
