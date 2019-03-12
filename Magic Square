/******************************************************************************
* Magic Squares
*
* This program will print a magic square of the users choosing:
*   First the program will ask for input
*   After, the program will validate the input
*   If the input is invalid it will ask for input again
*   Once valid input is entered the program will create the Magic Square
*   Then it will print the magic square and the magic number
*   It will repeat this process until the user enters 0

*  Written by Juan Marquez, starting January 31, 2018.
******************************************************************************/
#include<iostream>
#include<iomanip>

using namespace std;

int inputValidation(int); //this function will validate the users input
//void createMagicSquare(userInput);
//void displayMagicSquare(int); //this function will display the Magic Square


int main()
{
	//declared variables
	int userInput = 0; //this variable will hold the user input

	//declare order so dynamic array could be used
	int order = 7;


	//use do- while loop to continue until 0 is entered
	do
	{
		//ask and accept input. This must be an odd number greater than or equal to 3. Enter 0 to end program
		cout << "Please enter an odd number greater than or equal to 3. Enter 0 to end the program.";
		cin >> userInput;
		cout << endl;

		//call function to validate the input
		userInput = inputValidation(userInput);


		if(userInput == 0) //if user input is 0 end program
		{
			break;
		}
		else // if user input is valid create and output the Magic square
		{
			 order = userInput; //set order equal to the user input

			 int* magicSquare = new int[order * order]; //create dynamic array

			 //initialize the entire square to 0
			 for(int iRow=0; iRow< order; iRow++)
			 {
			      for(int iCol=0; iCol<order; iCol++)
			      {
			    	  magicSquare[iRow * order + iCol] = 0;
			      }
			 }

			  //calculate the magic sum using the formula M= n*(((n*n)+1)/2);
			 int magicSum = order*(((order*order)+1)/2);

			  //declare variables to hold the new coordinates
			 int newRow,
			  	 newCol;

			  // set the starting position to the middle column of the first row
			 int row = 0 ;
			 int columns= order / 2;

			  // Fill each element of the array
			 for ( int value = 1; value <= order*order; value++ )
			 {
			     magicSquare[(row*order) + columns] = value; //set the starting position to 1
			     // Find the next square and wrap around if necessary.

			     newRow = (row -1) % order;
			     if(newRow == -1)//if the new row is negative set it to the last row( same thing as wrapping around from the top row)
			     {
			    	 newRow = (order -1);
			     }

			     newCol = (columns + 1) % order;

			     // If the square is empty, remember that square for the next assignment.
			     if ( magicSquare[newRow*order+ newCol] == 0 )
			     {
			        row = newRow;
			        columns = newCol;
			     }
			     else
			     {
			        // if the cell already has a number go back to original cell and down 1. Wrap around if necessary.
			        row = (row + 1) % order;
			     }

			 }

			//output the square
			 for(int iRow=0; iRow< order; iRow++)
			 {
			     for(int iCol=0; iCol<order; iCol++)
			     {
			    	 cout << setw(5) << left; //set the width to 5 and align it to the left in order to get a readable square
			         cout << magicSquare[iRow *order + iCol];
			     }
			     cout << endl;
			 }

		//output the Magic sum
		    cout << "Magic Sum: " << magicSum << endl;
		    cout << endl;

			delete [] magicSquare;
		}

	}
	while(userInput != 0); //end program if 0 is entered
	return 0;
}

int inputValidation(int input)
{
	//validate input
	//input must be odd and greater than or equal to 3.
	while ((input < 3 && input != 0) || (input % 2 == 0 && input != 0) || (cin.fail())) //cin.fail is used to detect any input that is not a number
	{

		cout << "This is an invalid input" << endl;
		cout << "Please enter an odd number greater than or equal to 3. Enter zero to stop the program ";
		cin.clear(); //clear buffer if a letter or symbol is entered
		cin.ignore(INT_MAX, '\n'); //ignore until next line
		cin >> input;//get new input
		cout << endl;

	}

	return input;
}
