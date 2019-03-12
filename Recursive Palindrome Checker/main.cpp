/******************************************************************************
* Recursive Palindrome Checker
*
* This program will determine if an input string is a palindrome using recursion:
*   First the program will ask for input
*   If the input is an empty string it will break from loop and end the program
*   else it will call the editString function and return a string with only digits and letters
*   then it will call the isPalindrome function to determine if the string is a palindrome and return either true or false
*   Using the bool value returned the program will output the appropriate message
*   It will repeat this process until the user enters a string with a length of zero

*  Written by Juan Marquez, starting April 9, 2018.
******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

bool isPalindrome(string); //this function will check if input is a palindrome
string editString(string); //this function will edit the input string.
						// the edited string with have all capital letters,no spaces, and no punctuation
int main()
{
	bool palindrome = false;
	string inputString = "";

	do
	{
		//ask for input
		cout << "Please enter a String. Enter an empty string to end the program" << endl;
		getline(cin, inputString);

		if(inputString.length() == 0) //if the length of the string is zero break from loop
		{
			break;
		}

		inputString = editString(inputString); //call function to edit the string
		palindrome = isPalindrome(inputString); //call function to check if its a palindrome

		//output result
		if(palindrome == false) // String is not a  palindrome
		{
				cout << "This string is not a Palindrome" << endl;
				cout << endl;
		}
		else //string is a palindrome
		{
			cout << "This string is a Palindrome" << endl;
			cout << endl;
		}
	}while(	inputString.length() != 0 ); //repeat while length of the string is not zero

	return 0;
}

bool isPalindrome(string inputS)  //this function will check if input is a palindrome
{

	//get length of the string
	int length = inputS.length();

	//get the first and last letter in the string using substr function
	string firstLetter = inputS.substr(0,1); //get first letter
	string lastLetter = inputS.substr((length - 1), 1); //get last letter. subtract 1 from the length to avoid getting the null terminator

	//compare first and last letter until the length of the string is 1
	if(firstLetter == lastLetter)//if the first and last letters are the same then execute the following code
	{
		if(length <= 1) //if the length of the string equal or less than 1 then return true
		{
			return true;
		}
		else //if not call the isPalindrome function again with a shorter string
		{
			inputS = inputS.substr(1, (length - 2));
			return isPalindrome(inputS);
		}

	}
	else //if the first and last letter are not the same then return false to the main function
	{
		return false;
	}

}

string editString(string inputS) //this function will edit the input string.
									// the edited string with have all capital letters,no spaces, and no punctuation
{
	string editedS; //edited string
	int count = 0;
	for(; inputS[count] != '\0' ; count++) //continue until the null terminator is reached
	{
		if(isalnum(inputS[count])) //if it a letter or a digit execute the following code
		{
			 //add the letter or digit to the edited string
			editedS += toupper(inputS[count]);
		}
	}
	editedS[count] = '\0'; //set null terminator at the end of the edited string


	return editedS; //return edited string to the main function
}
