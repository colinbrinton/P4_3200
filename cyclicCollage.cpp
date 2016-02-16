#include "stdafx.h"
/*
#include "cyclicCollage.h"


cyclicCollage::cyclicCollage(int size, int shft)
{
	active = true;
	shift = shft;
	collage = new List<int>();
	for (int index = 0; index < size; index++)
	{
		int randomImg = rnd.Next(COL_MIN, COL_MAX);
		while (collage.Contains(randomImg))
			randomImg = rnd.Next(COL_MIN, COL_MAX);
		collage.Add(randomImg);
	}
	displaySize = collage.Count;
}


cyclicCollage::~cyclicCollage()
{
}

int* cyclicCollage::getDisplay()
{
	if (active)
	{
		++displayCount;
		int[] display = new int[collage.Count];
		for (int index = 0; index < collage.Count; ++index)
		{
			int shiftIndex = (index + (shift * displayCount)) % displaySize;
			display[shiftIndex] = collage[index];
		}
		return display;
	}
	else
	{
		int[] nullDisplay = new int[] { NULL };
		return nullDisplay;
	}
}
*/
