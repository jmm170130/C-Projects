//This program will be reading numbers from a file, validate the numbers and calculating the average of all of the valid numbers

//read in file name
//open file
//if file doesn't open output error message
//read in and validate the numbers from file. Also, calculate average of the valid numbers(Type double)
//numbers are from 0 - 110 inclusive
//output file name. Number of total,valid and invalid numbers. And average or error message
//output the numbers to a file called "invalid-numbers.txt". with 2 digits of precision after the decimal point

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
0
int main()
{
	//declare and open output file
	ofstream outputFile;
	outputFile.open("invalid-numbers.txt");

	//declare input file
	ifstream inputFile;

	//declare variables that I will get from input File.
	double number; //number from the input file

	//make file name a string
	string fileName;

	//accept input for file name
	cin >> fileName;

	//open the file
	inputFile.open(fileName);

	//validate file
	if(!inputFile) //if it doesn't open then output error message
	{
		cout << "File \"" <<  fileName << "\" could not be opened" << endl;
		inputFile.close(); //close file just in case a file is open
		return 0;

	}

	//if the inputFile opens then continue
	else if (inputFile)
	{
		//declare variable for average, total, number of invalid values and number of valid values. Initialize all to 0
		double average = 0; // will be used to output average
		int invalidValues = 0; //will count number of invalid entries
		int validValues = 0; // will count number of valid entries
		double total = 0;  //this will accumulate the total of all the valid numbers
		 int count = 0; //will count number of total values
		//use the for loop to count total number of numbers until the end of file by incrementing count by 1
		for(; !inputFile.eof() ; count++)
		{
			//if its the end of the file then stop the loop
			if(inputFile.eof())
			{
				count -= 1; //subtract 1 from total
				break;
			}
			//get number from file
			inputFile >> number;

			//if nothing is entered the stop and go to next iteration
			if(!inputFile.good())
			{
				continue;
			}
			//validate numbers
			else if( (number < 0) || (number > 110) ) //if number is under 0 or over 110 then continue
			{
				invalidValues++; //increment number of invalid values by 1

				//output invalid number to file with 2 digits of precision after the decimal point
				outputFile << setprecision(2) << fixed;
				outputFile << number << endl;
			}

			else //if number is valid then continue
			{
				validValues++; // increment number of valid values by one
				total += number; //total will equal total + number
				average = total/validValues;
			}
		}
		//output the name of the file that is being read
		cout << "Reading from file \"" << fileName << "\"" << endl;

		//output number of total values
		cout << "Total values: " << count << endl;

		//output number of invalid values
		cout << "Invalid values: " << invalidValues << endl;

		//output number of valid values
		cout << "Valid values: " << validValues << endl;

		//if validValues isn't 0 then output average with 2 digits of precision after the decimal point
		if( validValues == 0 )
		{
			cout << "An average cannot be calculated" << endl;
		}
		else //if the number of valid values is 0 then output error message for the average
		{
			cout << setprecision(2) << fixed;
			cout << "Average of valid values: " << average << endl;
		}
	}

	inputFile.close(); //close input file
	outputFile.close(); //close output file
	return 0;
}


