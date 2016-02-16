// P4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "imageCollage.h"

#include <iostream>
using namespace std;

void displayCollage(int imgCol[], int size);
void displayAll(imageCollage collageArray[], int size = 5);


int main()
{
	unsigned seed = time(NULL);
	srand(seed);

	const int H_ARRAY_SIZE = 5;

	imageCollage heteroCollageArray[H_ARRAY_SIZE];
	for (int index = 0; index < H_ARRAY_SIZE; index++)
	{
		imageCollage newCollage = imageCollage();
		heteroCollageArray[index] = newCollage;
	}

	displayAll(heteroCollageArray);

	cin.get();


	return 0;
}

	void displayCollage(int imgCol[], int size = 5)
	{
		int index = 0;
		cout << imgCol[index];
		for (int index = 0; index < size; index++)
		{
			if (index != 0)
			{
				cout << ", ";
				cout << imgCol[index];
			}
		}
		delete[] imgCol;
	}

	void displayAll(imageCollage collageArray[], int size)
	{
		for (int index = 0; index < size; index++)
		{
			//if (index < RANDOM_SIZE)
			//{
				cout << "Collage ";
				cout << index + 1;
				cout << ": ";
				displayCollage(collageArray[index].getDisplay());
				cout << endl;
			//}
		}
	}