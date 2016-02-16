#include "stdafx.h"
/*
#include "bitCollage.h"


bitCollage::bitCollage(int size)
{
	active = true;
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


bitCollage::~bitCollage()
{
}

int* bitCollage::getDisplay()
{
	if (active)
	{
		++displayCount;
		int omit = rnd.Next(MIN_OMIT, MAX_OMIT);
		List<int> omitList = new List<int>();
		int[] display = new int[collage.Count - omit];
		int randomIndex;
		while (omit > 0)
		{
			randomIndex = rnd.Next(0, (collage.Count - 1));
			while (omitList.Contains(randomIndex))
				randomIndex = rnd.Next(0, (collage.Count - 1));
			omitList.Add(randomIndex);
			--omit;
		}

		int displayIndex = 0;
		for (int index = 0; index < collage.Count; ++index)
		{
			if (!omitList.Contains(index))
			{
				display[displayIndex] = collage[index];
				++displayIndex;
			}
		}
		return display;
	}
	else
	{
		int[] nullDisplay = new int[] { NULL };
		return nullDisplay;
	}
}

bool bitCollage::replaceImage(int imgID)
{
	if (active && ((imgID % 2) != 0))
	{
		if (collage.Contains(imgID))
		{
			int replacement = rnd.Next(COL_MIN, COL_MAX);
			while (collage.Contains(replacement))
				replacement = rnd.Next(COL_MIN, COL_MAX);
			collage[collage.IndexOf(imgID)] = replacement;
			++replaceCount;
			return true;
		}
	}
	return false;
}
*/