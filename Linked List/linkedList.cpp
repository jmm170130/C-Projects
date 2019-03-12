/******************************************************************************
* Linked List insertion sort
*
* This program will sort a list of numbers from a file using linear insertion sort and a linked list:
*   First the program will ask for the name of the input file
*   After, the program will validate the input file
*   If the input file does not exist the program will display an error and ask for a new file name
*   Once a valid input file is entered the program will read the numbers from the file and sort them
*   Then it will display the sorted list and the number of items in the list
*   Then the program will delete the list
*   It will repeat this process until the user enters an asterisk (*)

*  Written by Juan Marquez starting April 19, 2018.
******************************************************************************/
#include <iostream>
#include <fstream>
#include "NumberList.h"

using namespace std;

void fileValidation(string); //this function will verify that the input file exist

int main()
{
	string fileName; //variable for file name
	NumberList list; //define a NumberList object
	double number; //variable holds the input from the inputFile

	do
	{
		int count = 0; //variable used to keep count of items in the list

		//ask the user for the name of the input file
		cout << endl;
		cout << "Please enter the file name" << endl;
		getline(cin, fileName);

		if(fileName == "*") //if the user enters an asterisk then break from the loop
		{
			break;
		}

		//validate the input file and catch any potential errors
		try
		{
			//call file validation function
			fileValidation(fileName);

			//if the file exist continue with the program

			//open the input file
			ifstream inputFile;
			inputFile.open(fileName);

			//read the file content
			while(inputFile >> number)
			{
				list.insertNode(number); //insert an sort the input value
				count++;//increment count
			}
			list.printList( count); //display the list
			list.deleteList(); //destroy the linked list to release all the memory used.

		}
		catch(string &exceptionString) //output "file not found" error
		{
			cout << exceptionString;
			cout << endl;
		}

	}while(fileName != "*"); //repeat until the user enters an asterisk

	return 0;
}

void fileValidation(string inputF ) //this function will verify that the input file exist
{
	 ifstream inputFile;

	 //try opening the file
	 inputFile.open(inputF, ios::in);

	 //if the file does not open then throw "file not found" error
	 if(inputFile.fail())
	 {
		 inputFile.close(); //close file just in case
		 string exceptionString = "File not Found" ;
		 throw exceptionString;
	 }

	 inputFile.close(); //close file
}
