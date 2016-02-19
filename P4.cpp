// P4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "imageCollage.h"
#include "cyclicCollage.h"
#include "bitCollage.h"

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

void displayCollage(vector<int> imgCol);
void displayAll(imageCollage* collageArray[], int size = H_ARRAY_SIZE);
void repeatDisplay(imageCollage* item, int rep = 5);
void allocateCollageArray(imageCollage* (&colArray)[H_ARRAY_SIZE]);
void imageCollageTestSuite(imageCollage* imageCollage);


int main()
{
	unsigned seed = time(NULL);
	srand(seed);

	//const int H_ARRAY_SIZE = 5;

	imageCollage* heteroCollageArray[H_ARRAY_SIZE];
	allocateCollageArray(heteroCollageArray);

	displayAll(heteroCollageArray);

	cout << endl << endl;

	//repeatDisplay(heteroCollageArray[0]);
	imageCollageTestSuite(heteroCollageArray[IMAGE_INDEX]);

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
			for (int index = 0; index < imgCol.size(); index++)
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

	void repeatDisplay(imageCollage* item, int rep)
	{
		for (int count = 0; count < rep; ++count)
		{
			displayCollage(item->getDisplay());
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
			if (index < RANDOM_SIZE) //Random portion of array
			{
				if (collageSelector == IMAGE)
					colArray[index] = new imageCollage(collageSize);
				if (collageSelector == CYCLIC)
					colArray[index] = new cyclicCollage(collageSize);
				if (collageSelector == BIT)
					colArray[index] = new bitCollage(collageSize);
			}
			if (index >= RANDOM_SIZE) // Constant portion of array used in test suites
			{
				colArray[index] = new bitCollage(TEST_SIZE);
				++index;
				colArray[index] = new cyclicCollage(TEST_SIZE);
				++index;
				colArray[index] = new imageCollage(TEST_SIZE);
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