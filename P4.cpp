// P4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "imageCollage.h"
#include "cyclicCollage.h"
#include "bitCollage.h"

#include <iostream>
using namespace std;

void displayCollage(vector<int> imgCol, int size);
void displayAll(imageCollage* collageArray[], int size = 5);
void repeatDisplay(imageCollage* item, int rep = 5);


int main()
{
	unsigned seed = time(NULL);
	srand(seed);

	const int H_ARRAY_SIZE = 5;

	imageCollage* heteroCollageArray[H_ARRAY_SIZE];
	for (int index = 0; index < H_ARRAY_SIZE; index++)
	{
		heteroCollageArray[index] = new bitCollage();
	}

	displayAll(heteroCollageArray);

	cout << endl << endl;

	repeatDisplay(heteroCollageArray[0]);

	cin.get();


	return 0;
}

	void displayCollage(vector<int> imgCol, int size = 5)
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
		//delete imgCol;
	}

	void displayAll(imageCollage* collageArray[], int size)
	{
		for (int index = 0; index < size; index++)
		{
			//if (index < RANDOM_SIZE)
			//{
				cout << "Collage ";
				cout << index + 1;
				cout << ": ";
				displayCollage(collageArray[index]->getDisplay());
				cout << endl;
			//}
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