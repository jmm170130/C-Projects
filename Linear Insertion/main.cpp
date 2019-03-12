/******************************************************************************
* Linear Insertion Sort
*
* This program will sort a list of numbers from an input file:
*   First the program will ask for a name of a file containing data
*   If the file does not exist it will display an error and ask for another file name
*   If the file is valid then it will order the numbers in the list
*   Then it will print the sorted list
*   It will repeat this process until the user enters an asterisk *

*  Written by Juan Marquez, starting March 1, 2018.
******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

string fileValidation(string); //This function will validate the file name
int sortList(double [], const int ARRAY_SIZE, string ); //this function will sort the list in the array
void printSortedArray(double [], int); //this function will print the sorted array
void moveArray(double [], int, int); //this function will move the elements in the array down one
int insertionPoint(double [], int, double); //this function will find insertion point

int main()
{
	//declare array with a 100 elements
	const int ARRAY_SIZE = 100;
	double numberArray[ARRAY_SIZE];

	//make filename a string
	string fileName;

	//set element count to 0
	int elementCount = 0;
	do
	{
		//ask user for file name and accept input
		cout << "Please enter the name of a file containing data. Enter an asterisk (*) to close the program" << endl;
		getline(cin, fileName);

		//call file validation function
		fileName = fileValidation(fileName);

		//if the user entered an asterisk then terminate program
		if(fileName == "*")
		{
			return 0;
		}
		else//sort the list and print it
		{
			elementCount = sortList( numberArray,ARRAY_SIZE, fileName); //call function to sort the list
			printSortedArray(numberArray,elementCount); //call function to print the sorted array
		}

	}while(fileName != "*"); //repeat until the user enters an asterisk

	return 0;
}

string fileValidation(string file) //this function will validate the file
{
	//declare input file
	ifstream inputF;

	//open the input file
	inputF.open(file);

	//continue requesting input until a valid file name  is entered
	while(!inputF )
	{
		//close previous file just in case
		inputF.close();

		//if the user entered an asterisk break out of the loop
		 if(file == "*")
		 {
			 break;
		 }

		//request and accept new input
		cout << "Error opening the file." <<endl;
		cout << "Please enter the name of a file containing data. Enter an asterisk (*) to close the program" << endl;
		cout << endl;
		getline(cin, file);
		inputF.open(file);

	}

	inputF.close(); //close the file
	return file; //return the file name
}

int sortList(double listArray[], const int ARRAY_SIZE, string file) // This function will sort the list
{
	//open the file
	ifstream inputFile;
	inputFile.open(file);

	double inputValue = 0; //this variable will hold the value from the input File
	int ix = 0; // This will keep count of how many numbers are in the array
	for(; (inputFile >> inputValue) && ix < ARRAY_SIZE; ix++) //continue until eof or until there are 100 elements in the array
	{
		 if(ix == 0) //if the list is empty set the value to the first element in array
		{
			listArray[ix] = inputValue;

		}
		else //if it is not the first element execute following code
		{
			 double index = inputValue; //set index to the the input value from the file
			 int jx = ix; //set jx equal to ix

			 if(listArray[jx-1] > index) //if the new value is less than the previous value find insertion point
			 {
				 	jx = insertionPoint(listArray, jx, index); //call function to find insertion point
				 	moveArray(listArray, jx,ix); //call function to move the array elements

			 }
			 listArray[jx] = index; //put new element in the array

		}


	}
	return ix; //return the count of elements in the array to main function
}

void printSortedArray(double sortedArray[], int totalElements) //this function will print the sorted array
{
	int count = 0; //set the count equal to 0

	//while the count is less than the total number of elements actually in the array execute code
	while(count < totalElements)
	{
		cout << sortedArray[count] << endl; //print out the element
		count++; //increment count
	}
	cout << endl;
}

void moveArray(double array[], int insertionPoint, int elementCount) //this function will move the array elements down
{
	//move everything including the insertion point down in the array
	// while the current element is greater than 0 and greater than the insertion point execute code
	while( elementCount > 0 && insertionPoint < elementCount)
	{
		 //move everything in the array down 1
		 array[elementCount] = array[elementCount-1];
		 elementCount--;
	}
}

int insertionPoint(double array[], int insertionPoint, double newElement) //this function will find insertion point
{
	//while the insertionPoint is greater than 0
	//find the two elements where the top one is smaller than the one you have and the bottom one is larger
	while(insertionPoint > 0 && (array[insertionPoint -1 ] > newElement))
	{
		insertionPoint--; //decrement insertionPoint
	}
	return insertionPoint;
}
