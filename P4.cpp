// AUTHOR: Colin Brinton
// FILENAME: P4.cpp
// DATE: 2/22/2016
// REVISION HISTORY: 1.0

/* DESCRIPTION:
* The purpose of the driver is to demonstrate the implementation of the P3 class heiarchy 
* in multiple inheritance with the addition of the review class. The functionality of each
* of the three P3 classes (imageCollage, cyclicCollage, bitCollage) is wrapped into three
* additional classes that also inherite from the review class. Each of these derived
* classes has an imageCollage heiarchy parent and review as its second parent. This design
* decission was made to allow for greater extensibility than a daimond inheritance
* implementation would allow for. To accomplish the testing of the six collage classes, 
* a heterogeneous array is used. It is allocated using the method allocateCollageArray() which
* randomly assigns one of the six classes to the 10 indices. The purpose of this array
* is to demonstate that with an imageCollage* base pointers, all six collage classes may use
* the imageCollage interface. The random distribution and initializations of this array
* demonstate a more natural usage example. Two more arrays are constructed, one of imageCollage
* pointers and one of review pointers. They both point to the address of one of each of the six
* collage class objects. This is done so that both imageCollage and review functionality
* may be accessed. The output is organized into seven pages, requiring a key press (input) 
* to clear the screen and move on to the next. The first page demonstrates the heterogeneous 
* array working with a randomly distributed assortment of class objects. Pages two through seven
* each demonstrate a class's unique behavior.

/* ASSUMPTIONS:
* For the driver to function as intended the user only needs to press a key once between each
* page and once at the end to exit the program. The fourth and seventh pages tests the behavior of 
* bitCollage and bitCollageReview respectively. One distinguishing feature of bitCollage is that 
* the replaceImage() method will only succeed on images with odd ID's. The test object is allocated 
* with randomly generated numbers and accessing the data within a bitCollage object is done through 
* the display method which randomly omits 1-3 image ID's. Because of this there is a small chance (<.05) 
* that every call to replaceImage() will succeed (or fail). If this happens please run the program
* again.
*
* Rand() is used generate random sizes of data sets stored within each object (between 5
* and 10 image ID's). It is also used to randomly distribute the objects among the first
* array used for testing. The Console is used to display output and accept
* key presses.
*/
#include "imageCollage.h"
#include "cyclicCollage.h"
#include "bitCollage.h"
#include "review.h"
#include "collageReview.h"
#include "cyclicCollageReview.h"
#include "bitCollageReview.h"

#include <iostream>
#include <string>
using namespace std;


//Global Constants Used In Multiple Functions
const int H_ARRAY_SIZE = 10; //Complete size of the testing array
const int NUM_OBJ = 6; //Used for random distribution in hetero array
const int IMAGE = 0;   //  |
const int CYCLIC = 1;  //  |
const int BIT = 2;     //  V
const int REVIEW = 3;
const int C_REVIEW = 4;
const int B_REVIEW = 5;
const int TEST_SIZE = 10; // Used for the non-random test objects
const int REPEAT = 5;  //Number of times repeatDisplay() should call imageCollage.display()

//Function Prototypes
vector<int> generateCollage(int size);
void displayCollage(vector<int> imgCol);
void displayAll(imageCollage* collageArray[]);
void repeatDisplay(imageCollage* item, int rep = REPEAT);
void allocateCollageArray(imageCollage* (&colArray)[H_ARRAY_SIZE]);
void allocateTestArray(imageCollage* (&colArray)[NUM_OBJ], review* (&revArray)[NUM_OBJ]);
void reviewCollageTestSuite(imageCollage* (&collageHeteroArray)[NUM_OBJ], review* (&reviewHeteroArray)[NUM_OBJ]);
string getObjType(int i);
void releaseMemory(imageCollage* (&colArray)[H_ARRAY_SIZE], imageCollage* (&collageHeteroArray)[NUM_OBJ]);


int main()
{
	const int NO_ERRORS = 0;

	//Seeding rand to clock
	unsigned seed = time(NULL);
	srand(seed);

	cout << "Creating a random heterogeneous array to test the six collage classes... ";
	imageCollage* collageHeteroArray[H_ARRAY_SIZE];
	allocateCollageArray(collageHeteroArray);
	cout << "Done." << endl << endl;
	
	cout << "Displaying all collages in the randomly allocated array: " << endl;
	displayAll(collageHeteroArray);
	cout << endl;

	cout << "Creating two corellated heterogeneous arrays of known object types...";
	imageCollage* reviewCollageHeteroArray[NUM_OBJ];
	review* reviewHeteroArray[NUM_OBJ];
	allocateTestArray(reviewCollageHeteroArray, reviewHeteroArray);
	cout << "Done." << endl << endl;

	cout << "Press Enter to clear screen and run test suite...";
	cin.get();
	system("CLS");

	reviewCollageTestSuite(reviewCollageHeteroArray, reviewHeteroArray);

	cout << endl << "End of tests. Press Enter to run clean up routine and exit program...";
	cin.get();

	releaseMemory(collageHeteroArray, reviewCollageHeteroArray);

	return NO_ERRORS;
}

//Description - Returns a string name of the specified object.
//              Used as a helper method to reviewCollageTestSuite
string getObjType(int i)
{
	const string SIMAGE = "imageCollage";
	const string SCYCLIC = "cyclicCollage";
	const string SBIT = "bitCollage";
	const string SREVIEW = "collageReview";
	const string SC_REVIEW = "cyclicCollageReview";
	const string SB_REVIEW = "bitCollageReview";
	const string SUNKNOWN = "Unknown Object";

	if (i == IMAGE)
		return SIMAGE;
	if (i == CYCLIC)
		return SCYCLIC;
	if (i == BIT)
		return SBIT;
	if (i == REVIEW)
		return SREVIEW;
	if (i == C_REVIEW)
		return SC_REVIEW;
	if (i == B_REVIEW)
		return SB_REVIEW;
	else
		return SUNKNOWN;

}

//Description - Used in main to call the appropriate number of
//				deletes to free up memory
//preconditions: Must be used with arrays of pointers, pointing to
//               dynamically allocated objects
//postconditions: Dynamically allocated memory freed
void releaseMemory(imageCollage* (&colArray)[H_ARRAY_SIZE], imageCollage* (&collageHeteroArray)[NUM_OBJ])
{
	for (int index = 0; index < H_ARRAY_SIZE; index++)
	{
		delete colArray[index];
	}

	for (int index = 0; index < NUM_OBJ; index++)
	{
		delete collageHeteroArray[index];
	}
	
}

//Description - Used as a helper method to the two allocate array methods.
//				Returns a randomly generated collage of "int size".
//preconditions: Must be called with a positive int
//postconditions: Returns collage
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

//Description - Used as a helper method to display a collage
//preconditions: Must be passed a valid vector
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
	}

	//Description - Used as a helper method to display all collages in
	//              the passed array.
	//preconditions: Must be used with a valid array of pointers of size 
	//               H_ARRAY_SIZE
	void displayAll(imageCollage* collageArray[])
	{
		for (int index = 0; index < H_ARRAY_SIZE; index++)
		{
				cout << "Collage ";
				cout << index + 1;
				cout << ": ";
				displayCollage(collageArray[index]->getDisplay());
				cout << endl;
			
		}
	}

	//Description - Helper method to repeat the display to demonstrate
	//              cyclic and bit collage functionality
	//preconditions: Must be used with a valid pointer
	void repeatDisplay(imageCollage* item, int rep)
	{
		for (int count = 0; count < rep; ++count)
		{
			displayCollage(item->getDisplay());
			cout << endl;
		}
	}

	//Description - Used to generate a randomly distributed array of
	//              the six classes.
	//preconditions: Must be used with arrays of pointers of size
	//               H_ARRAY_SIZE
	//postconditions: array may now be used
	void allocateCollageArray(imageCollage* (&colArray)[H_ARRAY_SIZE])
	{
		const int MIN_IMG = 5; // Size range for the number of images
		const int MAX_IMG = 11;//     each test object should hold

		int collageSelector;
		int collageSize;

		for (int index = 0; index < H_ARRAY_SIZE; index++)
		{
			collageSelector = rand() % NUM_OBJ;
			collageSize = rand() % (MAX_IMG - MIN_IMG) + MIN_IMG;
	
			if (collageSelector == IMAGE)
				colArray[index] = new imageCollage(generateCollage(collageSize));
			if (collageSelector == CYCLIC)
				colArray[index] = new cyclicCollage(generateCollage(collageSize));
			if (collageSelector == BIT)
				colArray[index] = new bitCollage(generateCollage(collageSize));
			if (collageSelector == REVIEW)
				colArray[index] = new collageReview(generateCollage(collageSize));
			if (collageSelector == C_REVIEW)
				colArray[index] = new cyclicCollageReview(generateCollage(collageSize));
			if (collageSelector == B_REVIEW)
				colArray[index] = new bitCollageReview(generateCollage(collageSize));
		}
	}

	//Description - Used to generate a known array of the six classes
	//preconditions: Must be used with arrays of pointers of size
	//               NUM_OBJ
	//postconditions: array may now be used
	void allocateTestArray(imageCollage* (&colArray)[NUM_OBJ], review* (&revArray)[NUM_OBJ])
	{
		const int SCORE_MIN = 1;
		const int SCORE_MAX = 6;
		const int RANK_MIN = 1;
		const int RANK_MAX = 101;
		const int DATE_MIN = 20000101;
		const int DATE_MAX = 20160223;

		for (int collage = 0; collage < NUM_OBJ; collage++)
		{
			unsigned score = rand() % (SCORE_MAX - SCORE_MIN) + SCORE_MIN;
			unsigned rank = rand() % (RANK_MAX - RANK_MIN) + RANK_MIN;
			bool free = (rand() % 2) == 1;
			unsigned date = rand() % (DATE_MAX - DATE_MIN) + DATE_MIN;

			if (collage == IMAGE)
			{
				imageCollage* iCPtr = new imageCollage(generateCollage(TEST_SIZE));
				colArray[collage] = iCPtr;
			}
			if (collage == CYCLIC)
			{
				cyclicCollage* cCPtr = new cyclicCollage(generateCollage(TEST_SIZE));
				colArray[collage] = cCPtr;
			}
			if (collage == BIT)
			{
				bitCollage* bCPtr = new bitCollage(generateCollage(TEST_SIZE));
				colArray[collage] = bCPtr;
			}
			if (collage == REVIEW)
			{
				collageReview* cRPtr = new collageReview(generateCollage(TEST_SIZE), score, rank, free, date);
				colArray[collage] = cRPtr;
				revArray[collage] = cRPtr;
			}
			if (collage == C_REVIEW)
			{
				cyclicCollageReview* cCRPtr = new cyclicCollageReview(generateCollage(TEST_SIZE), score, rank, free, date);
				colArray[collage] = cCRPtr;
				revArray[collage] = cCRPtr;
			}
			if (collage == B_REVIEW)
			{
				bitCollageReview* bCRPtr = new bitCollageReview(generateCollage(TEST_SIZE), score, rank, free, date);
				colArray[collage] = bCRPtr;
				revArray[collage] = bCRPtr;
			}
		}
	}

	//Description - Used in main to test the known array of class objects
	//preconditions: Must be used with arrays of pointers, pointing to
	//               dynamically allocated objects one of type imageCollage
	//                the other of type review. Both must be size NUM_OBJ
	void reviewCollageTestSuite(imageCollage* (&collageHeteroArray)[NUM_OBJ], review* (&reviewHeteroArray)[NUM_OBJ])
	{
		const int COLLAGE_PORTION = 2;
		const int OFFSET = 1;
		for (int index = 0; index < NUM_OBJ; index++)
		{
			cout << "*****Testing " << getObjType(index) << " Object*****" << endl << endl;
			cout << "Calling getDisplay() on object 5 times: ";
			cout << endl;
			repeatDisplay(collageHeteroArray[index]);

			cout << endl;
			cout << "Testing replaceImage() method: ";
			cout << endl;
			cout << "Calling getDisplay() to fill a vector of images to replace...";
			vector<int> replace = collageHeteroArray[index]->getDisplay();
			cout << "Done.";
			cout << endl;
			for (int count = 0; count < (TEST_SIZE / COLLAGE_PORTION); ++count)
			{
				cout << "Attempting to replace ";
				cout << replace[count];
				cout << "...";
				if (collageHeteroArray[index]->replaceImage(replace[count])) //Each call will succeed because
					cout << "Success!";                 //   each ID is in the object
				else
					cout << "Failed!";
				cout << endl;
			}

			cout << endl;
			cout << "Calling getDisplay() on object 5 more times: ";
			cout << endl;
			repeatDisplay(collageHeteroArray[index]);

			cout << endl;
			cout << "Testing imgQuery(): ";
			cout << endl;
			cout << "Is ";
			cout << replace[(TEST_SIZE - (TEST_SIZE / COLLAGE_PORTION)) + OFFSET];
			cout << " in the collage: ";
			if (collageHeteroArray[index]->imgQuery(replace[(TEST_SIZE - (TEST_SIZE / COLLAGE_PORTION)) + OFFSET]))
				cout << "Yes!";
			else
				cout << "No!";
			cout << endl;
			cout << "Is ";
			cout << replace[IMAGE];
			cout << " in the collage: ";
			if (collageHeteroArray[index]->imgQuery(replace[IMAGE]))
				cout << "Yes!";
			else
				cout << "No!";
			cout << endl;

			cout << endl;
			cout << "getDisplay() has been called ";
			cout << collageHeteroArray[index]->getDisplayCount();
			cout << " times.";
			cout << endl;

			cout << collageHeteroArray[index]->getReplaceCount();
			cout << " images have been replaced.";
			cout << endl;

			cout << endl;
			cout << "Calling toggleActive()...";
			collageHeteroArray[index]->toggleActive();
			cout << "Done.";
			cout << endl;
			cout << "Testing isActive(): ";
			if (collageHeteroArray[index]->isActive())
				cout << "Object is active" << endl;
			else
				cout << "Object is NOT active" << endl;
			cout << "Attempting to replace ";
			cout << replace[(TEST_SIZE - (TEST_SIZE / COLLAGE_PORTION)) + OFFSET]; //This call will fail, already replaced above
			cout << "...";
			if (collageHeteroArray[index]->replaceImage(replace[(TEST_SIZE - (TEST_SIZE / COLLAGE_PORTION)) + OFFSET]))
				cout << "Success!";
			else
				cout << "Failed!";
			cout << endl;
			cout << "Attempting to display collage: ";
			displayCollage(collageHeteroArray[index]->getDisplay());
			cout << endl;

			cout << "Calling toggleActive()...";
			collageHeteroArray[index]->toggleActive();
			cout << "Done.";
			cout << endl;
			cout << "Testing isActive(): ";
			if (collageHeteroArray[index]->isActive())
				cout << "Object is active" << endl;
			else
				cout << "Object is NOT active" << endl;
			cout << "Attempting to replace ";
			cout << replace[TEST_SIZE - (TEST_SIZE / COLLAGE_PORTION)];
			cout << "...";
			if (collageHeteroArray[index]->replaceImage(replace[TEST_SIZE - (TEST_SIZE / COLLAGE_PORTION)]))
				cout << "Success!";
			else
				cout << "Failed!";
			cout << endl;
			cout << "Attempting to display collage: ";
			cout << endl;
			displayCollage(collageHeteroArray[index]->getDisplay());
			cout << endl << endl;
			
			if (index >= REVIEW)
			{
				cout << "Calling getRawScore(): " << reviewHeteroArray[index]->getRawScore() << endl;
				cout << "Calling getWeightedScore(): " << reviewHeteroArray[index]->getWeightedScore() << endl;
				cout << "Testing wasFree(): ";
				if (reviewHeteroArray[index]->wasFree())
					cout << "Free" << endl;
				else
					cout << "Not free" << endl;
				cout << "Calling getDate: " << reviewHeteroArray[index]->getDate() << endl << endl;
			}

			if ((index + 1) != NUM_OBJ)
			{
				cout << "Press Enter to clear screen and move on to " << getObjType(index + 1) << " test...";
				cin.get();
				system("CLS");
			}
		}
	}
