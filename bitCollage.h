#pragma once
#include "imageCollage.h"
class bitCollage : public imageCollage
{
	const static int MIN_OMIT = 1;
	const static int MAX_OMIT = 4;

public:
	bitCollage(int size = DEFAULT_SIZE) : imageCollage(size) {}
	~bitCollage();

	vector<int> getDisplay();
	bool replaceImage(int imgID);
};

