// AUTHOR: Colin Brinton
// FILENAME: imageCollage.h
// DATE: 2/22/2016
// REVISION HISTORY: 2.0

/* DESCRIPTION:
* The intended use of imageCollage is to "display" a selection of random images
* stored within an external database. It generates an array of image ID's,
* represented as an array of ints. It returns an array of ints to the user
* which may then be used trigger the real life display of images in a database.
* The images in the database must be numbered consecutively 10000-99999.
* It is not intended for imageCollage to store images but rather select images
* to be displayed from a central storage area. Each object may be toggled "on"
* or "off." After it's initialization, getDisplay() will return its image ID's
* in the same order. Each call to getDisplay() is counted in a protected data
* member which value can be returned via an accessor method. An image may be
* replaced with another by passing the image ID to replaceImage(). The number
* of successfully replaced images is counted in a protected data member which
* may also be returned via a public method. Finally, imgQuery() returns a bool
* of true or false, the passed image ID is in the collage.
*/

/* ASSUMPTIONS:
* Because a unique list of IDs is generated for each imageCollage object, it is
* assumed that the class will be used as a trigger for a central database that
* stores images. This is my interpretation of, "You do not need to actually store
* images: each image can be represented by a unique id" in the requirements. In
* this example it is assumed that the image database holds 89999 images, labeled
* consecutively 10000-99999. It is assumed that all images in the database are of
* equal desire and therefore the images are selected randomly.
*/
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