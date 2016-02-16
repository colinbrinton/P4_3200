#pragma once
#include "stdafx.h"
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

class imageCollage
{
	
protected:

	//unsigned seed = time(NULL);
	//static Random rnd = new Random();
	//const int NULL = 0;
	const static int DEFAULT_SIZE = 5;
	static const int COL_MIN = 10000; //May be changed to accommodate an image database with a different 
	static const int COL_MAX = 100000;//  amount of images.
	vector<int> collage;
	bool active;
	int displaySize;
	int displayCount = 0;
	int replaceCount = 0;

public:
	imageCollage(int size = DEFAULT_SIZE);
	~imageCollage();

	int getDisplayCount();
	int getReplaceCount();
	void toggleActive();
	bool imgQuery(int imgID);
	virtual bool replaceImage(int imgID);
	virtual int* getDisplay();
};

