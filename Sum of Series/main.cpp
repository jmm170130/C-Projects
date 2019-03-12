/******************************************************************************
* Sum of a Series Program.
*
* This program sums a simple series:
*   First the program will ask for input
*   After, the program will validate the input
*   If the input is invalid it will ask for input again
*   Once valid input is entered the program will calculate the sum of the series
*   Then it will display the original number and the sum of the series
*   It will repeat this process until the user enters 0

*  Written by Juan Marquez, starting January 21, 2018.
NetID: jmm170130
******************************************************************************/

#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
	//Declare variables
	double inputValue = 0.0; //variable will hold the user input

							 //use do- while loop to continue until 0 is entered
	do
	{
		//ask and accept input greater than 1 to calculate the sum of the series. Enter 0 to stop the program.
		cout << "Please enter a number greater than 1. Enter zero to stop the program ";
		cin >> inputValue;

		cout << endl;

		//validate input
		// if a number equal to 1 or less than 0 is entered give an error and request another number
		while ((inputValue == 1) || (inputValue < 0) || (cin.fail())) //cin.fail is used to detect any input that is not a number
		{
			cout << "This is an invalid input" << endl;
			cout << "Please enter a number greater than 1. Enter zero to stop the program ";
			cin.clear(); //clear buffer if a letter or symbol is entered
			cin.ignore(INT_MAX, '\n'); //ignore until next line
			cin >> inputValue;//get new input
			cout << endl;
		}
		//if the number is greater than 1 continue
		if (inputValue > 1)
		{
			//calculate the sum of the series
			double sum = 0.0; //declare variable to hold the sum of the series
			for (int ix = 1; ix <= inputValue; ix++) //use for loop to add up the sum of the series until the iteration number and the input value is equal
			{
				sum += ix / (inputValue - ix + 1); //divide the iteration number(ix) by the input value subtracted by the iteration number(inputValue - ix).
												   //add 1 to the denominator so the sum starts with 0
			}
			//output original number
			cout << "Original Number: ";
			cout << inputValue;

			cout << endl;
			//output the sum
			cout << "Sum of Series: ";
			cout << sum;

			cout << endl;
			cout << endl;

		}


	} while (inputValue != 0);//if the number entered is 0 stop the program

	return 0;
}
