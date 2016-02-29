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

#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

class imageCollage
{
	
protected:
	const static int DEFAULT_SIZE = 5;
	static const int COL_MIN = 10000; //May be changed to accommodate an image database with a different 
	static const int COL_MAX = 100000;//  amount of images.
	static const vector<int> NULL_COL;
	vector<int> collage;
	bool active;
	int displaySize;
	int displayCount = 0;
	int replaceCount = 0;

public:
	imageCollage(vector<int> col = NULL_COL);
	~imageCollage();

	int getDisplayCount();
	int getReplaceCount();
	void toggleActive();
	bool imgQuery(int imgID);
	virtual bool replaceImage(int imgID);
	virtual vector<int> getDisplay();
	bool isActive();
};

