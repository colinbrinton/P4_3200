#pragma once
#include "imageCollage.h"
class cyclicCollage : public imageCollage
{
protected:

	const static int DEFAUL_SHIFT = 2;
	int shift;

public:
	cyclicCollage(vector<int> col = NULL_COL, int shft = DEFAUL_SHIFT) : imageCollage(col), shift(shft) {}
	~cyclicCollage();

	bool replaceImage(int imgID) { return false; }
	vector<int> getDisplay();
};

