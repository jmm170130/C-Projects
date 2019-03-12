#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Read function
bool readData(char [], string); //pass the array and the file name

//Display function
void displayResults(const char [], const char []); //pass the 2 arrays

int main()
{
	//This program will be a quiz grading program.
	//It will compare the student's answers with the correct answers, and determine if the student passed the quiz or not.

	//call the read function twice, once for each input file
	//The student file should be processed first and then the answers file.
	//If both calls to the read function work then the display function should be called.
	//If either call to the read function does not work it should output a message stating that the specific file could not be opened.
	//No further processing should be done if either one of the files cannot be opened.

	//two char arrays of size 20
	const int ARRAY_SIZE = 20;
	char studentAnswers[ARRAY_SIZE]; //array with 20 elements  will hold student answers
	char correctAnswers[ARRAY_SIZE]; //array with 20 elements will hold correct answers

	//boolean Flag
	bool fileOpened = true;

	string studentFileName; //make file name a string
	cin >> studentFileName; //get input for file name


	string answersFileName; // make the file name a string
	cin>> answersFileName; //get input for file

	//call the read function to read the student file
	fileOpened = readData(studentAnswers, studentFileName);

	if(!fileOpened)//if the file could not be opened output error message and terminate program
	{
		//output error message
		cout << "File \"" << studentFileName <<"\" could not be opened" << endl;
		return 0;
	}

	//if the file opened then call the read function again
	fileOpened = readData(correctAnswers, answersFileName);

	if(!fileOpened)//if the file could not be opened output error message and terminate program
	{
		//output error message
		cout << "File \"" << answersFileName <<"\" could not be opened" << endl;
		return 0;
	}

	//call display function to display results if both files opened correctly
	displayResults(studentAnswers, correctAnswers);


	return 0;
}


bool readData(char lettersArray[], string fileName) //this function will receive an array and a file name
{
	//declare the array size as a constant
	const int ARRAY_SIZE = 20;

	//declare bool variable
	bool validFile;

	//declare input file
	ifstream inputFile;

	//set the counter to 0
	int count = 0;

	//open file
	inputFile.open(fileName);

	//validate the file
	if(!inputFile)//if the file doesn't open set the bool variable to false
	{
		validFile = false;
	}
	else //if the file opened then read in the data from the file and set bool variable to true
	{
		validFile = true;
		while(count < ARRAY_SIZE  ) //continue until the array size is reached
		{
			inputFile >> lettersArray[count];
			++count; //increment count
		}
	}
	//close the file and return bool to calling function
	inputFile.close();
	return validFile;

}

void displayResults(const char studentAnswer[],const char correctAnswer[])
{
	//this function will display
	//A list of questions missed by the student, showing the question number (1 through 20), the correct answer, and the incorrect answer.
	//The total number of questions missed by the student
	//The percentage of the questions answered correctly.
	//If the percentage of questions answered correctly is 70% or more indicate that the student passed, otherwise state that the student failed the quiz.

	//declare total answers
	const int TOTAL_ANSWERS = 20;

	int correctAnswers = 0;//will hold number of correct answers and will be used to calculate percentage correct
	int wrongAnswer = 0; //will hold number of wrong answers
	int totalQuestions = 20; //will be used in calculations

	for(int count = 0; count < TOTAL_ANSWERS; count++ ) //while count is less than total answers continue loop and increment count by 1
	{
		if( studentAnswer[count] == correctAnswer[count]) //if the answers are equal increment correct answers by 1
		{
			correctAnswers++;
		}
		else //if the answers are not equal increment wrong answers by 1 and output a message
		{
			wrongAnswer++;
			cout << "Question " << (count + 1) << " has incorrect answer '" << studentAnswer[count] << "', the correct answer is "; //output wrong answer
			cout << "'" << correctAnswer[count] << "'" << endl; //output correct answer
		}
	}

	//output questions missed
	cout << wrongAnswer << " questions were missed" << endl;
	//calculate percentage of questions answered correctly
	double percentCorrect = ((static_cast<float>(correctAnswers)/ static_cast<double>(totalQuestions)) * 100); //divide answers correct by total answers
	//I used static cast for both in order to avoid implicit conversion warning
	//if the percent correct is more or equal to  70% output that they passed else they failed
	if (percentCorrect >= 70)
	{
		cout << "The student passed" << endl;
	}
	else
	{
		cout << "The student failed" << endl;
	}
}
