// P4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "imageCollage.h"
#include "cyclicCollage.h"
#include "bitCollage.h"
#include "review.h"
#include "collageReview.h"
#include "cyclicCollageReview.h"
#include "bitCollageReview.h"

#include <iostream>
using namespace std;

const int H_ARRAY_SIZE = 13; //Complete size of the testing array (10 random slots +3)
const int NUM_COL = 3; //Used for random distribution in hetero array
const int IMAGE = 0;   //  |
const int CYCLIC = 1;  //  |
const int BIT = 2;     //  V
const int MIN_IMG = 5; // Size range for the number of images
const int MAX_IMG = 11;//     each test object should hold
const int TEST_SIZE = 10; // Used for the non-random test objects in index 10-12
const int REPEAT = 5;  //Number of times repeatDisplay() should call imageCollage.display()
const int COLLAGE_PORTION = 2; // Used in 

const int RANDOM_SIZE = H_ARRAY_SIZE - NUM_COL; //These allow the amount of random objects in
const int BIT_INDEX = H_ARRAY_SIZE - 3;         // H_ARRAY_SIZE to change without breaking
const int CYCLIC_INDEX = H_ARRAY_SIZE - 2;      //   the driver. |
const int IMAGE_INDEX = H_ARRAY_SIZE - 1;       //               v

const int SCORE_MIN = 1;
const int SCORE_MAX = 6;
const int RANK_MIN = 1;
const int RANK_MAX = 101;
const int DATE_MIN = 20000101;
const int DATE_MAX = 20160223;

vector<int> generateCollage(int size);
void displayCollage(vector<int> imgCol);
void displayAll(imageCollage* collageArray[], int size = H_ARRAY_SIZE);
void displayAllCR(imageCollage* collageArray[], review* reviewArray[], int size = H_ARRAY_SIZE);
void repeatDisplay(imageCollage* item, int rep = 5);
void repeatReviewDisplay(review* item, int rep = 5);
void repeatCyclicDisplay(cyclicCollage item, int rep = 5);
void repeatBitDisplay(bitCollage item, int rep = 5);
void allocateCollageArray(imageCollage* (&colArray)[H_ARRAY_SIZE]);
void allocateCRArray(imageCollage* (&colArray)[H_ARRAY_SIZE], review* (&revArray)[H_ARRAY_SIZE]);
void imageCollageTestSuite(imageCollage* imageCollage);
void cyclicCollageTestSuite(imageCollage* cyclicCollage);
void bitCollageTestSuite(imageCollage* bitCollage);
void reviewCollageTestSuite();
void cReviewCollageTestSuite();
void bReviewCollageTestSuite();


int main()
{
	unsigned seed = time(NULL);
	srand(seed);




	imageCollage* collageHeteroArray[H_ARRAY_SIZE];

	allocateCollageArray(collageHeteroArray);

	displayAll(collageHeteroArray);

	cout << endl << endl;

	review* reviewHeteroArray[H_ARRAY_SIZE];

	allocateCRArray(collageHeteroArray, reviewHeteroArray);

	displayAllCR(collageHeteroArray, reviewHeteroArray);

	cout << endl;

	reviewCollageTestSuite();
	cReviewCollageTestSuite();
	bReviewCollageTestSuite();




	//cout << "HERE: ";
	//review* testR = new collageReview(22);
	//displayCollage(testR->getDisplay());
	//delete testR;

	//imageCollage* testing = new bitCollageReview();

	//testing->getDisplay();

	/*review testReview(5, 50, false);

	cout << "Score: " << testReview.getRawScore() << endl;
	cout << "Weighted: " << testReview.getWeightedScore() << endl;

	collageReview testCR(8);
	bitCollageReview* testCCR = new bitCollageReview(8);

	repeatReviewDisplay(testCCR);

	delete testCCR;


	//displayCollage(testCR.getDisplay());

	//const int H_ARRAY_SIZE = 5;

	/*imageCollage* heteroCollageArray[H_ARRAY_SIZE];
	allocateCollageArray(heteroCollageArray);

	displayAll(heteroCollageArray);

	cout << endl << endl;

	//repeatDisplay(heteroCollageArray[0]);
	imageCollageTestSuite(heteroCollageArray[IMAGE_INDEX]);

	cout << endl << endl;

	cyclicCollageTestSuite(heteroCollageArray[CYCLIC_INDEX]);

	cout << endl << endl;

	bitCollageTestSuite(heteroCollageArray[BIT_INDEX]);

	/*repeatDisplay(heteroCollageArray[12]);
	cout << endl << endl;

	vector<int> replaceImg = heteroCollageArray[12]->getDisplay();
	cout << replaceImg[1];
	heteroCollageArray[12]->replaceImage(replaceImg[1]);

	cout << endl << endl;

	repeatDisplay(heteroCollageArray[12]);*/

	cin.get();


	return 0;
}

vector<int> generateCollage(int size)
{
	const int COL_MIN = 10000; //May be changed to accommodate an image database with a different 
	const int COL_MAX = 100000;//  amount of images.

	vector<int> collage;
	for (int index = 0; index < size; index++)
	{
		int randomImg = rand() % (COL_MAX - COL_MIN) + COL_MIN;
		while (find(collage.begin(), collage.end(), randomImg) != collage.end())
			randomImg = rand() % (COL_MAX - COL_MIN) + COL_MIN;
		collage.push_back(randomImg);
	}

	return collage;
}

	void displayCollage(vector<int> imgCol)
	{
		if (imgCol.size() == 0)
		{
			cout << "Nothing to display.";
		}
		
		else
		{
			int index = 0;
			cout << imgCol[index];
			for (unsigned index = 0; index < imgCol.size(); index++)
			{
				if (index != 0)
				{
					cout << ", ";
					cout << imgCol[index];
				}
			}
		}
		//delete imgCol;
	}


	void displayAll(imageCollage* collageArray[], int size)
	{
		for (int index = 0; index < H_ARRAY_SIZE; index++)
		{
			if (index < RANDOM_SIZE)
			{
				cout << "Collage ";
				cout << index + 1;
				cout << ": ";
				displayCollage(collageArray[index]->getDisplay());
				cout << endl;
			}
		}
	}

	void displayAllCR(imageCollage* collageArray[], review* reviewArray[], int size)
	{
		for (int index = 0; index < H_ARRAY_SIZE; index++)
		{
			if (index < RANDOM_SIZE)
			{
				cout << "Collage ";
				cout << index + 1;
				cout << ": ";
				displayCollage(collageArray[index]->getDisplay());
				cout << endl;
				cout << "Raw review score: ";
				cout << reviewArray[index]->getRawScore() << endl;
				cout << "Weighted review score: ";
				cout << reviewArray[index]->getWeightedScore() << endl;
				cout << "Free Review: ";
				if (reviewArray[index]->wasFree())
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
				cout << "Review Date: " << reviewArray[index]->getDate() << endl << endl;
			}
		}
	}

	void repeatDisplay(imageCollage* item, int rep)
	{
		for (int count = 0; count < rep; ++count)
		{
			displayCollage(item->getDisplay());
			cout << endl;
		}
	}

	void repeatCyclicDisplay(cyclicCollage item, int rep)
	{
		for (int count = 0; count < rep; ++count)
		{
			displayCollage(item.getDisplay());
			cout << endl;
		}
	}

	void repeatBitDisplay(bitCollage item, int rep)
	{
		for (int count = 0; count < rep; ++count)
		{
			displayCollage(item.getDisplay());
			cout << endl;
		}
	}

	void allocateCollageArray(imageCollage* (&colArray)[H_ARRAY_SIZE])
	{
		int collageSelector;
		int collageSize;

		for (int index = 0; index < H_ARRAY_SIZE; index++)
		{
			collageSelector = rand() % NUM_COL;
			collageSize = rand() % (MAX_IMG - MIN_IMG) + MIN_IMG;
			vector<int> collage = generateCollage(collageSize);
			if (index < RANDOM_SIZE) //Random portion of array
			{
				if (collageSelector == IMAGE)
					colArray[index] = new imageCollage(collage);
				if (collageSelector == CYCLIC)
					colArray[index] = new cyclicCollage(collage);
				if (collageSelector == BIT)
					colArray[index] = new bitCollage(collage);
			}
			if (index >= RANDOM_SIZE) // Constant portion of array used in test suites
			{
				colArray[index] = new bitCollage(generateCollage(TEST_SIZE));
				++index;
				colArray[index] = new cyclicCollage(generateCollage(TEST_SIZE));
				++index;
				colArray[index] = new imageCollage(generateCollage(TEST_SIZE));
			}
		}
	}

	void allocateCRArray(imageCollage* (&colArray)[H_ARRAY_SIZE], review* (&revArray)[H_ARRAY_SIZE])
	{
		int collageSelector;
		int collageSize;
		unsigned score;
		unsigned rank;
		unsigned date;
		bool free;

		for (int index = 0; index < H_ARRAY_SIZE; index++)
		{
			collageSelector = rand() % NUM_COL;
			collageSize = rand() % (MAX_IMG - MIN_IMG) + MIN_IMG;

			score = rand() % (SCORE_MAX - SCORE_MIN) + SCORE_MIN;
			//cout << endl << "GENERATED SCORE: " << score << endl << endl;
			rank = rand() % (RANK_MAX - RANK_MIN) + RANK_MIN;
			free = (rand() % 2) == 1;
			date = rand() % (DATE_MAX - DATE_MIN) + DATE_MIN;
	

			if (index < RANDOM_SIZE) //Random portion of array
			{
				vector<int> collage = generateCollage(collageSize);
				if (collageSelector == IMAGE)
				{
					collageReview *cR = new collageReview(collage, score, rank, free, date);
					colArray[index] = cR;
					revArray[index] = cR;
				}
				if (collageSelector == CYCLIC)
				{
					cyclicCollageReview *cCR = new cyclicCollageReview(collage, score, rank, free, date);
					colArray[index] = cCR;
					revArray[index] = cCR;
				}
				if (collageSelector == BIT)
				{
					bitCollageReview *bCR = new bitCollageReview(collage, score, rank, free, date);
					colArray[index] = bCR;
					revArray[index] = bCR;
				}
			}
			if (index >= RANDOM_SIZE) // Constant portion of array used in test suites
			{
				bitCollageReview *bCR = new bitCollageReview(generateCollage(TEST_SIZE), score, rank, free, date);
				colArray[index] = bCR;
				revArray[index] = bCR;
				score = rand() % (SCORE_MAX - SCORE_MIN) + SCORE_MIN;
				rank = rand() % (RANK_MAX - RANK_MIN) + RANK_MIN;
				free = (rand() % 2) == 1;
				date = rand() % (DATE_MAX - DATE_MIN) + DATE_MIN;
				++index;
				cyclicCollageReview *cCR = new cyclicCollageReview(generateCollage(TEST_SIZE), score, rank, free, date);
				colArray[index] = cCR;
				revArray[index] = cCR;
				score = rand() % (SCORE_MAX - SCORE_MIN) + SCORE_MIN;
				rank = rand() % (RANK_MAX - RANK_MIN) + RANK_MIN;
				free = (rand() % 2) == 1;
				date = rand() % (DATE_MAX - DATE_MIN) + DATE_MIN;
				++index;
				collageReview *cR = new collageReview(generateCollage(TEST_SIZE), score, rank, free, date);
				colArray[index] = cR;
				revArray[index] = cR;
			}
		}
	}

	// Description - Tests the functionality of imageCollage. Calls every method in
	//                in imageCollage under different conditions.
	void imageCollageTestSuite(imageCollage* imageCollage)
	{
		//const int TEST_SIZE = 10;
		//const int COLLAGE_PORTION = 2;
		//const int IMAGE = 0;

		cout << "Calling getDisplay() on imageCollage object: ";
		cout << endl;
		displayCollage(imageCollage->getDisplay());
		cout << endl;

		cout << endl;
		cout << "Testing replaceImage() imageCollage method: ";
		cout << endl;
		cout << "Calling getDisplay() to fill a vector of images to replace...";
		vector<int> replace = imageCollage->getDisplay();
		cout << "Done.";
		cout << endl;
		for (int index = 0; index < (TEST_SIZE / COLLAGE_PORTION); ++index)
		{
			cout << "Attempting to replace ";
			cout << replace[index];
			cout << "...";
			if (imageCollage->replaceImage(replace[index])) //Each call will succeed because
				cout << "Success!";                 //   each ID is in the object
			else
				cout << "Failed!";
			cout << endl;
		}

		cout << endl;
		cout << "Calling getDisplay() on imageCollage object: ";
		cout << endl;
		displayCollage(imageCollage->getDisplay());
		cout << endl;

		cout << endl;
		cout << "Testing imgQuery(): ";
		cout << endl;
		cout << "Is ";
		cout << replace[TEST_SIZE - 1];
		cout << " in the collage: ";
		if (imageCollage->imgQuery(replace[TEST_SIZE - 1]))
			cout << "Yes!";
		else
			cout << "No!";
		cout << endl;
		cout << "Is ";
		cout << replace[IMAGE];
		cout << " in the collage: ";
		if (imageCollage->imgQuery(replace[IMAGE]))
			cout << "Yes!";
		else
			cout << "No!";
		cout << endl;

		cout << endl;
		cout << "getDisplay() has been called ";
		cout << imageCollage->getDisplayCount();
		cout << " times.";
		cout << endl;

		cout << imageCollage->getReplaceCount();
		cout << " images have been replaced.";
		cout << endl;

		cout << endl;
		cout << "Calling toggleActive()...";
		imageCollage->toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Attempting to replace ";
		cout << replace[TEST_SIZE - 1]; //This call will fail, already replaced above
		cout << "...";
		if (imageCollage->replaceImage(replace[TEST_SIZE - 1]))
			cout << "Success!";
		else
			cout << "Failed!";
		cout << endl;
		cout << "Attempting to display collage: ";
		displayCollage(imageCollage->getDisplay());
		cout << endl;

		cout << "Calling toggleActive()...";
		imageCollage->toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Attempting to replace ";
		cout << replace[TEST_SIZE - 1];
		cout << "...";
		if (imageCollage->replaceImage(replace[TEST_SIZE - 1]))
			cout << "Success!";
		else
			cout << "Failed!";
		cout << endl;
		cout << "Attempting to display collage: ";
		cout << endl;
		displayCollage(imageCollage->getDisplay());
		cout << endl;


	}

	void reviewCollageTestSuite()
	{
		unsigned score = rand() % (SCORE_MAX - SCORE_MIN) + SCORE_MIN;
		unsigned rank = rand() % (RANK_MAX - RANK_MIN) + RANK_MIN;
		bool free = (rand() % 2) == 1;
		unsigned date = rand() % (DATE_MAX - DATE_MIN) + DATE_MIN;
		collageReview cR(generateCollage(TEST_SIZE), score, rank, free, date);

		cout << "Calling getDisplay() on collageReview object: ";
		cout << endl;
		displayCollage(cR.getDisplay());
		cout << endl;

		cout << endl;
		cout << "Testing replaceImage() collageReview method: ";
		cout << endl;
		cout << "Calling getDisplay() to fill a vector of images to replace...";
		vector<int> replace = cR.getDisplay();
		cout << "Done.";
		cout << endl;
		for (int index = 0; index < (TEST_SIZE / COLLAGE_PORTION); ++index)
		{
			cout << "Attempting to replace ";
			cout << replace[index];
			cout << "...";
			if (cR.replaceImage(replace[index])) //Each call will succeed because
				cout << "Success!";                 //   each ID is in the object
			else
				cout << "Failed!";
			cout << endl;
		}

		cout << endl;
		cout << "Calling getDisplay() on collageReview object: ";
		cout << endl;
		displayCollage(cR.getDisplay());
		cout << endl;

		cout << endl;
		cout << "Testing imgQuery(): ";
		cout << endl;
		cout << "Is ";
		cout << replace[TEST_SIZE - 1];
		cout << " in the collage: ";
		if (cR.imgQuery(replace[TEST_SIZE - 1]))
			cout << "Yes!";
		else
			cout << "No!";
		cout << endl;
		cout << "Is ";
		cout << replace[IMAGE];
		cout << " in the collage: ";
		if (cR.imgQuery(replace[IMAGE]))
			cout << "Yes!";
		else
			cout << "No!";
		cout << endl;

		cout << endl;
		cout << "getDisplay() has been called ";
		cout << cR.getDisplayCount();
		cout << " times.";
		cout << endl;

		cout << cR.getReplaceCount();
		cout << " images have been replaced.";
		cout << endl;

		cout << endl;
		cout << "Calling toggleActive()...";
		cR.toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Testing isActive(): ";
		if (cR.isActive())
			cout << "Object is active" << endl;
		else
			cout << "Object is NOT active" << endl;
		cout << "Attempting to replace ";
		cout << replace[TEST_SIZE - 1]; //This call will fail, already replaced above
		cout << "...";
		if (cR.replaceImage(replace[TEST_SIZE - 1]))
			cout << "Success!";
		else
			cout << "Failed!";
		cout << endl;
		cout << "Attempting to display collage: ";
		displayCollage(cR.getDisplay());
		cout << endl;

		cout << "Calling toggleActive()...";
		cR.toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Testing isActive(): ";
		if (cR.isActive())
			cout << "Object is active" << endl;
		else
			cout << "Object is NOT active" << endl;
		cout << "Attempting to replace ";
		cout << replace[TEST_SIZE - 1];
		cout << "...";
		if (cR.replaceImage(replace[TEST_SIZE - 1]))
			cout << "Success!";
		else
			cout << "Failed!";
		cout << endl;
		cout << "Attempting to display collage: ";
		cout << endl;
		displayCollage(cR.getDisplay());
		cout << endl << endl;

		cout << "Calling getRawScore(): " << cR.getRawScore() << endl;
		cout << "Calling getWeightedScore(): " << cR.getWeightedScore() << endl;
		cout << "Testing wasFree(): ";
		if (cR.wasFree())
			cout << "Free" << endl;
		else
			cout << "Not free" << endl;
		cout << "Calling getDate: " << cR.getDate() << endl;
	}

	// Description - Tests the functionality of cyclicCollage. Calls every
	//               overridden method except for replaceImage(). 
	//               replaceImage() is not intended to be used with
	//               cyclicCollage and will always return false when called.
	void cyclicCollageTestSuite(imageCollage* cyclicCollage)
	{
		cout << "Calling getDisplay() on cyclicCollage object 5 times: ";
		cout << endl;
		repeatDisplay(cyclicCollage);
		cout << endl;

		cout << "getDisplay() has been called ";
		cout << cyclicCollage->getDisplayCount();
		cout << " times.";
		cout << endl;

		cout << endl;
		cout << "Calling toggleActive()...";
		cyclicCollage->toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Attempting to display collage: ";
		displayCollage(cyclicCollage->getDisplay());
		cout << endl;

		cout << "Calling toggleActive()...";
		cyclicCollage->toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Attempting to display collage: ";
		cout << endl;
		displayCollage(cyclicCollage->getDisplay());
		cout << endl;
	}

	void cReviewCollageTestSuite()
	{
		unsigned score = rand() % (SCORE_MAX - SCORE_MIN) + SCORE_MIN;
		unsigned rank = rand() % (RANK_MAX - RANK_MIN) + RANK_MIN;
		bool free = (rand() % 2) == 1;
		unsigned date = rand() % (DATE_MAX - DATE_MIN) + DATE_MIN;
		cyclicCollageReview cCR(generateCollage(TEST_SIZE), score, rank, free, date);

		cout << "Calling getDisplay() on cyclicCollageReview object 5 times: ";
		cout << endl;
		repeatCyclicDisplay(cCR);
		cout << endl;

		cout << "getDisplay() has been called ";
		cout << cCR.getDisplayCount();
		cout << " times.";
		cout << endl;

		cout << endl;
		cout << "Calling toggleActive()...";
		cCR.toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Testing isActive(): ";
		if (cCR.isActive())
			cout << "Object is active" << endl;
		else
			cout << "Object is NOT active" << endl;
		cout << "Attempting to display collage: ";
		displayCollage(cCR.getDisplay());
		cout << endl;

		cout << "Calling toggleActive()...";
		cCR.toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Testing isActive(): ";
		if (cCR.isActive())
			cout << "Object is active" << endl;
		else
			cout << "Object is NOT active" << endl;
		cout << "Attempting to display collage: ";
		cout << endl;
		displayCollage(cCR.getDisplay());
		cout << endl << endl;

		cout << "Calling getRawScore(): " << cCR.getRawScore() << endl;
		cout << "Calling getWeightedScore(): " << cCR.getWeightedScore() << endl;
		cout << "Testing wasFree(): ";
		if (cCR.wasFree())
			cout << "Free" << endl;
		else
			cout << "Not free" << endl;
		cout << "Calling getDate: " << cCR.getDate() << endl;
	}

	// Description - Tests the functionality of bitCollage. Calls every
	//                overridden method.
	void bitCollageTestSuite(imageCollage* bitCollage)
	{

		cout << "Calling getDisplay() on bitCollage object 5 times: ";
		cout << endl;
		repeatDisplay(bitCollage);
		cout << endl;

		cout << "Testing replaceImage() bitCollage method: ";
		cout << endl;
		cout << "Calling getDisplay() to fill an array of images to replace...";
		vector<int> replace = bitCollage->getDisplay();
		cout << "Done.";
		cout << endl;
		for (unsigned index = 0; index < replace.size(); index++)
		{
			cout << "Attempting to replace ";
			cout << replace[index];
			cout << "...";
			if (bitCollage->replaceImage(replace[index]))
				cout << "Success!";
			else
				cout << "Failed!";
			cout << endl;
		}

		cout << endl;
		cout << "Calling getDisplay() on bitCollage object 5 more times: ";
		cout << endl;
		repeatDisplay(bitCollage);

		cout << endl;
		cout << "getDisplay() has been called ";
		cout << bitCollage->getDisplayCount();
		cout << " times.";
		cout << endl;

		cout << bitCollage->getReplaceCount();
		cout << " images have been replaced.";
		cout << endl;

		cout << endl;
		cout << "Calling toggleActive()...";
		bitCollage->toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Attempting to display collage: ";
		displayCollage(bitCollage->getDisplay());
		cout << endl;

		cout << "Calling toggleActive()...";
		bitCollage->toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Attempting to display collage: ";
		cout << endl;
		displayCollage(bitCollage->getDisplay());
		cout << endl;
	}

	void bReviewCollageTestSuite()
	{
		unsigned score = rand() % (SCORE_MAX - SCORE_MIN) + SCORE_MIN;
		unsigned rank = rand() % (RANK_MAX - RANK_MIN) + RANK_MIN;
		bool free = (rand() % 2) == 1;
		unsigned date = rand() % (DATE_MAX - DATE_MIN) + DATE_MIN;
		bitCollageReview bCR(generateCollage(TEST_SIZE), score, rank, free, date);

		cout << "Calling getDisplay() on bitCollageReview object 5 times: ";
		cout << endl;
		repeatBitDisplay(bCR);
		cout << endl;

		cout << "Testing replaceImage() bitCollageReview method: ";
		cout << endl;
		cout << "Calling getDisplay() to fill an array of images to replace...";
		vector<int> replace = bCR.getDisplay();
		cout << "Done.";
		cout << endl;
		for (unsigned index = 0; index < replace.size(); index++)
		{
			cout << "Attempting to replace ";
			cout << replace[index];
			cout << "...";
			if (bCR.replaceImage(replace[index]))
				cout << "Success!";
			else
				cout << "Failed!";
			cout << endl;
		}

		cout << endl;
		cout << "Calling getDisplay() on bitCollageReview object 5 more times: ";
		cout << endl;
		repeatBitDisplay(bCR);

		cout << endl;
		cout << "getDisplay() has been called ";
		cout << bCR.getDisplayCount();
		cout << " times.";
		cout << endl;

		cout << bCR.getReplaceCount();
		cout << " images have been replaced.";
		cout << endl;

		cout << endl;
		cout << "Calling toggleActive()...";
		bCR.toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Testing isActive(): ";
		if (bCR.isActive())
			cout << "Object is active" << endl;
		else
			cout << "Object is NOT active" << endl;
		cout << "Attempting to display collage: ";
		displayCollage(bCR.getDisplay());
		cout << endl;

		cout << "Calling toggleActive()...";
		bCR.toggleActive();
		cout << "Done.";
		cout << endl;
		cout << "Testing isActive(): ";
		if (bCR.isActive())
			cout << "Object is active" << endl;
		else
			cout << "Object is NOT active" << endl;
		cout << "Attempting to display collage: ";
		cout << endl;
		displayCollage(bCR.getDisplay());
		cout << endl << endl;

		cout << "Calling getRawScore(): " << bCR.getRawScore() << endl;
		cout << "Calling getWeightedScore(): " << bCR.getWeightedScore() << endl;
		cout << "Testing wasFree(): ";
		if (bCR.wasFree())
			cout << "Free" << endl;
		else
			cout << "Not free" << endl;
		cout << "Calling getDate: " << bCR.getDate() << endl;
	}