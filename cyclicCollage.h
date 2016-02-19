#pragma once
#include "imageCollage.h"
class cyclicCollage : public imageCollage
{
protected:

	const static int DEFAUL_SHIFT = 2;
	int shift;

public:
	cyclicCollage(int size = DEFAULT_SIZE, int shft = DEFAUL_SHIFT) : imageCollage(size), shift(shft) {}
	~cyclicCollage();

	bool replaceImage(int imgID) { return false; }
	vector<int> getDisplay();
};

