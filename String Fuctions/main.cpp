/******************************************************************************
* String Functions
*
* This program will execute the function selected by the user on the string entered:
*   First the program will display the function menu
*   After, the program will ask the user to select a function
*   After, the program will validate the input. Accepts first character entered and ignores the rest
*   If the input is invalid it will ask for input again
*   Once valid input is entered the program will ask for string input and pass it to the function selected
*   Then the selected function will return a value that is displayed to the user
*   It will repeat this process until the user enters 0
*
*Functions:
*		sumDigitsInString - sums the digits in a given string
*		consonantsInString - counts consonants in a given string
*		countVowels - counts the vowels in a string
*		countWhiteSpace - counts white space in a given string
*
*  Written by Juan Marquez, starting February 20, 2018.
******************************************************************************/
#include <iostream>
#include <string>
#include<cmath>
#include <cctype>
#include<limits>

using namespace std;

void displayMenu(); //displays menu
char inputValidation(char); //this function will validate the users input
int sumDigitsInString(string); //this function will sum the digits in the string
int consonantsInString(string); //this function will count consonants in a string
int countVowels(string); //this function will count vowels in the string
int countWhitespace(string); //this function will count white space in the string

int main()
{
	//declare variable
	char userInput; //user input
	string userString;// user input for string

	//repeat while input is not 0
	do
	{
		displayMenu();
		cin.get(userInput); //gets the first character from user input
		cin.ignore(INT_MAX, '\n'); //ignore any other input until next line

		//validate input
		userInput = inputValidation(userInput); //call function to validate user input

		//if user input is 0 break from loop
		if (userInput == '0')
		{
			break;
		}

		//request string from user
		cout << endl;
		cout << "Please Enter a string" << endl;
		getline(cin, userString);

		//call desired function
		if (userInput == '1')//if user selected function 1 execute code
		{
			//declare variable to hold sum of digits in a string
			int sumOfDigitsInString = 0;

			//call the function to sum up the digits in the string
			sumOfDigitsInString = sumDigitsInString(userString);

			//output the sum of the digits in the string
			cout << " The sum of the digits in the string is: " << sumOfDigitsInString << endl;
			cout << endl;

		}
		else if (userInput == '2') //if user selected function 2 execute code
		{
			//declare variable to hold number of consonants in a string
			int consonantCount = 0;

			consonantCount = consonantsInString(userString); //call function to count consonants in the string

			//output the number of consonants in the string
			cout << " The number of consonants in the string is: " << consonantCount << endl;
			cout << endl;
		}

		else if (userInput == '3') //if user selected function 3 execute code
		{
			//declare variable to hold number of vowels in a string
			int vowelsInString = 0;

			vowelsInString = countVowels(userString); //call function to count vowels in the string

			//output the number of vowels in the string
			cout << " The number of vowels in the string is: " << vowelsInString << endl;
			cout << endl;
		}

		else if (userInput == '4')//if user selected function 4 execute code
		{
			//declare variable to hold number of whitespace characters in a string
			int whitespaceInString = 0;

			whitespaceInString = countWhitespace(userString); // call function to count whitespace

			//output the amount of whitespace in the string
			cout << "The amount of whitespace In the string is: " << whitespaceInString << endl;
			cout << endl;
		}

	} while (userInput != '0'); //repeat until user enters 0


	return 0;
}

//this function will validate user input
char inputValidation(char input)
{
	//validate input
	//input can be any number between 0 - 4
	while ((input < '0') || (input > '4'))
	{
		cout << endl;
		cout << "This is an invalid input" << endl;
		cout << endl;
		//output menu
		displayMenu();

		cin.get(input);//get new input. Only accept the first character and ignore the rest
		cin.ignore(INT_MAX, '\n'); //ignore until next line
		cout << endl;

	}

	return input;
}
int sumDigitsInString(string userInput) //this function will sum the digits in the string
{
	int sum = 0; //set the sum to 0
	for (unsigned int count = 0; count < userInput.length(); count++)
	{
		if (isdigit(userInput[count])) //if the element is a digit continue
		{
			sum += userInput[count] - '0'; //subtract the character by the character 0 and add it to the sum
		}
	}

	return sum;
}
int consonantsInString(string userInput) //this function will count consonants in a string
{
	int numberOfConsonants = 0; //count number of consonants
	char letter;

	for (unsigned int count = 0; count < userInput.length(); count++)
	{
		if (isalpha(userInput[count]))//if the iteration is a letter then continue
		{
			letter = toupper(userInput[count]); //make the letters Upper case in order to reduce the amount of checking
			switch (letter)//if the letter is  a,e,i or u break from the loop and go to next iteration.
						   //if it is not one of those letters then it must be a consonant therefore increment consonants by 1
			{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				break;
			default:
				++numberOfConsonants;
			}
		}

	}

	return numberOfConsonants;
}
int countVowels(string userInput) //this function will count vowels in the string
{
	int numberOfVowels = 0;
	char letter;

	for (unsigned int count = 0; count < userInput.length(); count++)
	{
		if (isalpha(userInput[count]))//if the iteration is a letter then continue
		{
			letter = toupper(userInput[count]); //make the letters Upper case in order to reduce the amount of checking
			switch (letter)//if the letter is  a,e,i or u increment numberOfVowels by 1. If not then break out of the loop
			{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			case 'Y':
				++numberOfVowels;
				break;

			default:
				break;
			}
		}

	}

	return numberOfVowels;
}
int countWhitespace(string userInput) //this function will count white space in the string
{
	int amountOfWhitespace = 0;
	for (unsigned count = 0; count < userInput.length(); count++)
	{
		if (isspace(userInput[count])) //if the element is a space then increment amount of whitespace by 1
		{
			++amountOfWhitespace;
		}
	}

	return amountOfWhitespace;
}
void displayMenu() //displays menu
{
	//output menu
	cout << "1. Sum the digits in a string" << endl;
	cout << "2. Count the number of consonants in a string" << endl;
	cout << "3. Count the vowels in a string" << endl;
	cout << "4. Count the whitespace characters in a string" << endl;

	cout << endl;
	//request input
	cout << "Please select a function (1-4)" << endl;
	cout << "Enter 0 to terminate Program"<< endl;
}




