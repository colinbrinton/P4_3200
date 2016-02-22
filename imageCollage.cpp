#include "stdafx.h"
#include "imageCollage.h"
#include <iostream>


imageCollage::imageCollage(vector<int> col)
{
	//srand(seed);
	if (col.size() > 0)
		active = true;
	for (int index = 0; index < col.size(); index++)
	{
		collage.push_back(col[index]);
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
		if (find(collage.begin(), collage.end(), imgID) != collage.end());
		{
			int replacement = rand() % (COL_MAX - COL_MIN) + COL_MIN;
			while (find(collage.begin(), collage.end(), replacement) != collage.end())
				replacement = rand() % (COL_MAX - COL_MIN) + COL_MIN;
			int pos = find(collage.begin(), collage.end(), imgID) - collage.begin();
			collage[pos] = replacement;
			++replaceCount;
			return true;
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
		vector<int> nullDisplay;
		return nullDisplay;
	}
}

bool imageCollage::isActive()
{
	return active;
}