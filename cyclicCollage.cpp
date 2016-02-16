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

int* cyclicCollage::getDisplay()
{
	if (active)
	{
		++displayCount;
		int* display = new int[collage.size()];
		for (int index = 0; index < collage.size(); ++index)
		{
			int shiftIndex = (index + (shift * displayCount)) % displaySize;
			display[shiftIndex] = collage[index];
		}
		return display;
	}
	else
	{
		int* nullDisplay = new int[] { NULL };
		return nullDisplay;
	}
}
