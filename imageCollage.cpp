#include "stdafx.h"
#include "imageCollage.h"


imageCollage::imageCollage(int size)
{
	//srand(seed);
	active = true;
	for (int index = 0; index < size; index++)
	{
		int randomImg = rand() % (COL_MAX - COL_MIN) + COL_MIN;
		while (find(collage.begin(), collage.end(), randomImg) != collage.end())
			randomImg = rand() % (COL_MAX - COL_MIN) + COL_MIN;
		collage.push_back(randomImg);
	}
	displaySize = collage.size();
}


imageCollage::~imageCollage()
{
}

int imageCollage::getDisplayCount()
{
	if (active)
		return displayCount;
	else return NULL;
}

int imageCollage::getReplaceCount()
{
	if (active)
		return replaceCount;
	else return NULL;
}

void imageCollage::toggleActive()
{
	if (active)
		active = false;
	else
		active = true;
}

bool imageCollage::imgQuery(int imgID)
{
	if (active)
	{
		if (find(collage.begin(), collage.end(), imgID) != collage.end())
			return true;
	}
	return false;
}

bool imageCollage::replaceImage(int imgID)
{
	if (active)
	{
		if (find(collage.begin(), collage.end(), imgID) != collage.end())
		{
			int replacement = rand() % (COL_MAX - COL_MIN) + COL_MIN;
			while (find(collage.begin(), collage.end(), replacement) != collage.end())
				replacement = rand() % (COL_MAX - COL_MIN) + COL_MIN;
			unsigned pos = find(collage.begin(), collage.end(), imgID) - collage.begin();
			if (pos >= collage.size()) 
			{
				collage[pos] = replacement;
				++replaceCount;
				return true;
			}
		}
	}
	return false;
}

vector<int> imageCollage::getDisplay()
{
	if (active)
	{
		++displayCount;
		vector<int> display;
		for (int index = 0; index < collage.size(); ++index)
		{
			display.push_back(collage[index]);
		}
		return display;
	}
	else
	{
		int* nullDisplay = new int[] { NULL };
		//return nullDisplay;
	}
}