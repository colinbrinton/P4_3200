// AUTHOR: Colin Brinton
// FILENAME: bitCollage.cpp
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
#include "stdafx.h"
#include "bitCollage.h"
#include <iostream>


/*bitCollage::bitCollage(int size)
{
	active = true;
	for (int index = 0; index < size; index++)
	{
		int randomImg = rnd.Next(COL_MIN, COL_MAX);
		while (collage.Contains(randomImg))
			randomImg = rnd.Next(COL_MIN, COL_MAX);
		collage.Add(randomImg);
	}
	displaySize = collage.Count;
}*/


bitCollage::~bitCollage()
{
}

vector<int> bitCollage::getDisplay()
{
	if (active)
	{
		++displayCount;
		int omit = rand() % (MAX_OMIT - MIN_OMIT) + MIN_OMIT;
		//cout << endl << endl << "OMIT: "<< omit;
		vector<int> *omitList = new vector<int>();
		vector<int> *display = new vector<int>();
		int randomIndex;
		while (omit > 0)
		{
			randomIndex = rand() % (collage.size());
				while(find(omitList->begin(), omitList->end(), randomIndex) != omitList->end())
					randomIndex = rand() % (collage.size());
			omitList->push_back(randomIndex);
			--omit;
		}

		//cout << endl << endl << "LIST: ";
		//for (int i = 0; i < omitList->size(); i++)
		//{
		//	cout << omitList->at(i);
		//	cout << " ";
		//}

		for (int index = 0; index < collage.size(); ++index)
		{
			if (!(find(omitList->begin(), omitList->end(), index) != omitList->end()))
			{
				//cout << endl << "FOUND" << endl;
				display->push_back(collage[index]);
			}
		}
		delete omitList;
		return *display;
	}
	else
	{
		vector<int> nullDisplay;
		return nullDisplay;
	}
}

bool bitCollage::replaceImage(int imgID)
{
	if (active && ((imgID % 2) != 0))
	{
		if (find(collage.begin(), collage.end(), imgID) != collage.end())
		{
			int replacement = rand() % (COL_MAX - COL_MIN) + COL_MIN;
			while (find(collage.begin(), collage.end(), replacement) != collage.end())
				replacement = rand() % (COL_MAX - COL_MIN) + COL_MIN;
			unsigned pos = find(collage.begin(), collage.end(), imgID) - collage.begin();
			collage[pos] = replacement;
			++replaceCount;
			return true;
		}
	}
	return false;
}