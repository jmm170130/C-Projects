//This program will put the content of a file into an array and calculate various values based on the contents of the file.

//This function will be the main driver.
//It will create the array, read in the file name, and call all of the other functions, processing the logic as required.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MAX_COLUMNS = 5;
//Prototypes
//Calculate the average for the array
double average(double values[][MAX_COLUMNS], int numberRows);

//Calculate the average for a specified column
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows);

// read input file and populate the array
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName);

//Find the smallest value in a specified row
double smallestRowValue(double values[][MAX_COLUMNS], int numberRows, int currentRow);


//Main Function
int main()
{
	 const int MAX_ROWS = 20;

	 //make the input file name a string
	 string inputFileName;

     //get input for file name
     cin >> inputFileName;

	 //create the array
     double grades[MAX_ROWS][MAX_COLUMNS];

     //call the readFile function to read data from the file
	 int actualRows = readFile(grades, MAX_ROWS, inputFileName);

	 //if the file did not open output error message(File could not be opened) and exit the program
	 if(actualRows == -1)
	 {
		 cout << "File \"" << inputFileName << "\" could not be opened" << endl;
		 return 0;

	 }
	 // if there is 0 rows then output error message(No data in file) and exit the program
	 else if(actualRows == 0)
	{
		cout << "The input file \"" << inputFileName << "\" did not contain any data" << endl;
		return 0;
	}

	//if there are 1 to 20 rows the program should calculate the needed data
	 else if(actualRows > 0)
	{
		 cout<< "Processing " << actualRows + 1 << " rows, and " << MAX_COLUMNS << " columns" <<endl;

		//Calculate and display the average of all of values read into the array
		double totalAverage = average(grades, actualRows);
		cout << setprecision(2) << fixed << endl;
		cout << "Average for all values is " <<  totalAverage << endl;
		double columnsAverage;
		int column = 0;
		while(column < MAX_COLUMNS) //Calculate and display the average for every column in the array
		{

			columnsAverage = columnAverage(grades, column, actualRows);
			cout << "Average for column " << column << " is "  << columnsAverage << endl;
			++column;
		}

		int row = 0;
		while(row <= actualRows)		//Find and display the smallest value for every row in the array
		{
			double rowsSmallestValue = smallestRowValue( grades, actualRows, row);
			cout <<"Smallest value for row " << row << " is " << rowsSmallestValue<< endl;
			++row;
		}

	}
	return 0;

}

//Calculate the average for the array
double average(double values[][MAX_COLUMNS], int numberRows)
{
	double total = 0;
	double average = 0;
	for(int rows = 0; rows < numberRows ; rows++)
	{
		for(int columns = 0; columns < MAX_COLUMNS; columns++)
		{
			total += values[rows][columns];
		}
	}
	average = (total/ (numberRows * MAX_COLUMNS));
	return average;
}

//Calculate the average for a specified column
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
	double columnTotal = 0;
	double columnAverage = 0;
	for( int columns = 0; columns < MAX_COLUMNS; columns++)//go through all the colums
	{
		if(columns == column) //when the column is the desired column add it to the average and go to next row
		{
			for(int row = 0; row < numberRows; row++) //add the rows in the column to the column total
			{
				columnTotal += values[row][columns];
			}
		}
	}
	columnAverage = columnTotal/numberRows;
	return columnAverage;
}

// read input file and populate the array
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName)
{
	//open the file and read the data into the passed in array.
	//If the file cannot be opened the function should return -1 to the calling function.
	//If the file does not contain any data (or contains less than 5 values) it will return 0
	// Otherwise the function returns the number of row read, up to 20

	//open the file
	ifstream inputFile;
	inputFile.open(inputFileName);
	int rows = 0;
	//if the file doesnt open then return -1 to the calling function
	if(!inputFile)
	{
		rows = -1;
	}
	else //if it opens read in the data
	{
		int columns = 0;

		for( ; (rows < maxRows) && inputFile >> values[rows][5] ; rows++)
		{

			for( ;( columns < MAX_COLUMNS) && inputFile >> values[rows][columns]; columns++)
			{

				inputFile >> values[rows][columns];
			}
		}
	}


	//close the file
	inputFile.close();
	return rows;

}

//Find the smallest value in a specified row
double smallestRowValue(double values[][MAX_COLUMNS], int numberRows, int currentRow)
{
	double smallestValue = values[0][0];
	for( int rows = 0; rows < numberRows; rows++)
	{
		if(rows == currentRow)
		{
			for(int columns = 0; columns < MAX_COLUMNS; columns++)
			{
				if(values[rows][columns] < smallestValue)
				{
					smallestValue = values[rows][columns] ;
				}
			}
		}
	}
	return smallestValue;
}

