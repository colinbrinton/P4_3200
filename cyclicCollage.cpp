#include "stdafx.h"
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
