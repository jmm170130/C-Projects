
/******************************************************************************
* Rectangle class
*
* This program will execute the function selected by the user from a menu:
*   First the program will display the function menu
*   After, the program will ask the user to select a function
*   After, the program will validate the input.
*   If the input is invalid it will ask for input again
*   Once valid input is entered the program will execute the function selected
*   It will repeat this process until the user enters 0

*  Written by Juan Marquez, starting March 12, 2018.
******************************************************************************/
#include <iostream>
#include <limits>
#include <string>
#include "Rectangle.h"

using namespace std;

void displayMenu(); //displays menu

int main()
{
	//declare variable
	int userInput; //user input
	bool bFail = true;
	const int ARRAY_SIZE = 10;
	Rectangle *array[ARRAY_SIZE];
	int count = 0;


	//repeat while input is not 0
	do
	{
		do //input validation
		{
			displayMenu();
			cin >> userInput; //gets the input from user

			bFail = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');

		}while(bFail == true || userInput < 0 || userInput > 3);

		//if user input is 0 break from loop
		if (userInput == 0)
		{
			break;
		}


		//call desired function
		if (userInput == 1)//if user selected function 1 execute code
		{
			//ask for height and length
			double height = 0;
			double length = 0;

			//ask the user for the height and length
			cout << "what is the height of the Rectangle?";
			cin >> height;
			cout << "what is the length of the Rectangle?";
			cin >> length;
			cout << endl;

			//dynamic allocation of rectangle
			Rectangle *rctptr;
			rctptr = new Rectangle;
			rctptr->setLength(length);
			rctptr->setHeight(height);

			array[count]= rctptr;
			++count;



		}
		else if (userInput == 2) //if user selected function 2 execute code
		{
			if(count == 0) //if count is 0 output error message
			{
				cout << "There are no rectangles created yet" << endl;
				cout << endl;
			}
			else//if there exist a rectangle then execute following code
			{

				//use for loop to display data for all the rectangles
				for(int ix = 0; ix < count ; ix++)
				{
					cout << "rectangle " << ix +1 ;
					cout << " length: " << array[ix]->getLength();
					cout << " height: " << array[ix]->getHeight();
					cout << " area: " << array[ix]->getArea();
					cout << " perimeter: " << array[ix]->getPerimeter();
					cout << endl;

				}
				//display total number of rectangles allocated
				cout << "Total number of rectangles created: " << count << endl;
				cout << endl;
			}

		}

		else if (userInput == 3) //if user selected function 3 execute code
		{
			if(count == 0) //if no triangle have been created output error message
			{
				cout << "There are no rectangles created yet" << endl;
				cout << endl;
			}
			else
			{
				//output dimensions for the most recently created rectangle
				cout << "Height: " << array[count-1]->getHeight();
				cout << " Length : " << array[count-1]->getLength() << endl;
				delete array[count-1];
				array[count-1]= NULL;

				count--; //decrement total number of rectangles

				//output amount of rectangles remaining
				cout << "Total number of rectangles Remaining: " << count << endl;
				cout << endl;
			}
		}
	} while (userInput != 0); //repeat until user enters 0


	return 0;
}


void displayMenu() //displays menu
{
	//output menu
	cout << "1. Set height and length for new Rectangle" << endl;
	cout << "2. Display information of all the Rectangles created" << endl;
	cout << "3. Display information of most recently-created rectangle and delete it " << endl;

	cout << endl;
	//request input
	cout << "Please select a function (1-3)" << endl;
	cout << "Enter 0 to terminate Program"<< endl;
}





