//<Juan Marquez>
//This program will play the game of “Rock, Paper, Scissors, Lizard, Spock”.
	//First the program will generate a random number in the range of 0 through 4 inclusive
	//then the program will output the options available to the user
	//get input from the user.
	//validate input from the user
	//if input is not valid then ask for input again
	//output what the computer and user selected
	//output who won
	//ask if the user wants to play again
	//if the answer is "Y" or "y" repeat the program
	//if answer is "N" or "n" output the number of wins, losses and ties by the computer and player before terminating.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//this function will output the result of the match (tie, computer won or user won) and count number of ties, and wins for both the computer and user
void matchResult(char ,int, int&, int&, int&);//pass value by reference to keep track of number of ties, and wins for both the computer and user

//function that generates random number between 0 and 4 (inclusive) and returns it to calling function
int randomNumber();

//function that outputs menu to the user
void showMenu();

//function that says what the user picked
void usersChoice(char );

//function that says what the computer picked
void computerChoice( int );

//this function will display the total number of wins, losses and ties by the computer and player
void gameStats(int ,int ,int);

int main()
{
	//declare variables
	char userNumber; //holds the number that the user chose
	int computerNumber; //holds the number the computer chose
	char playAgain; // hold Y or N. If the user wants to play again or not
	int tie = 0; //this will hold the total amount of ties
	int userWin = 0; //this will hold the total amount of wins by the user
	int computerWin = 0; //this will hold the total amount of wins by the computer
  
	do
	{
		do
		{
			computerNumber = randomNumber(); //generate random number between 0 and 4 and return it to computerNumber
			showMenu(); //output menu to the user and ask for input

			cin.get(userNumber); //accepts enter as an input
			cin.ignore(INT_MAX, '\n'); //only accepts the first character and ignores the rest of the input until the newline

		}while ( (userNumber != '0') && (userNumber != '1' ) && (userNumber != '2') && (userNumber != '3') && (userNumber != '4')); //repeat while choice is invalid

		computerChoice( computerNumber); //send the value of computerNumber to the computerChoice function.Output message saying what the computer selected.

		usersChoice(userNumber); //send the value of userNumber to usersChoice function.Output message saying what the user selected

		matchResult(userNumber, computerNumber, tie, userWin, computerWin); //send the value of userNumber, computerNumber , tie , userWin, computerTie to function matchResults
																		//output message saying who won the match



		//ask if the user wants to play again and accept input
		cout << "Would you like to play again? (Y/N)";
		cin.get(playAgain); //accepts enter as an input
		cin.ignore(INT_MAX, '\n');// accepts first charactrer entered and ignores the rest of the input

		while ((playAgain != 'Y') && (playAgain != 'y') && (playAgain != 'N' ) && (playAgain != 'n')) //if input is not valid then ask and accept input again. Repeat until valid input is entered
		{
			cout << "Please enter Y or N" << endl; //output error message. The input must be Y or N
			cout << endl;
			cout << "Would you like to play again? (Y/N)";
			cin.get(playAgain); //accepts enter as an input
			cin.ignore(INT_MAX, '\n');// accepts first charactrer entered and ignores the rest of the input
		}

		if ((playAgain == 'N' ) || (playAgain == 'n')) // if input is "N" or "n" then display the number of wins, losses and ties by the computer and player
		{
			gameStats(tie ,userWin ,computerWin); // send the values of tie, userWin and computerWin to function gameStats. display total ties,wins and losses.
		}
	}while((playAgain == 'Y') || (playAgain == 'y')); //if user enters "y" or "Y" the loop will repeat
	//if user enters "N" or "n" the program will terminate

	return 0;
}

int randomNumber()//This function will get a random number from the computer between 0 and 4 and return value to calling function
{
	srand( static_cast<unsigned int>(time(NULL))); //get different seed for each program run by using current time as the seed
													// static_cast fixes implicit conversion by changing time from long long to int
	int computerNumber = rand() % 5; //get a random number between 0 and 4 inclusive
	return computerNumber; //return random number generated to the calling function

}


void showMenu()//output the options to the user and ask for input
{
	cout << endl;
	cout << "0 - rock" << endl;
	cout << "1 - paper" << endl;
	cout << "2 - scissors" << endl;
	cout << "3 - lizard" << endl;
	cout << "4 - spock" << endl;
	cout << "Please select your desired option for this round (0-4) :" ;
}

void usersChoice(char playerChoice)// will output message saying what the user chose
{
	switch(playerChoice)
	{
		case '0': cout <<"The user selected rock." << endl;
				break;
		case '1': cout <<"The user selected paper." << endl;
				break;
		case '2': cout <<"The user selected scissors." << endl;
				break;
		case '3': cout <<"The user selected lizard." << endl;
				break;
		case '4': cout <<"The user selected spock." << endl;
				break;
	}
}

void computerChoice(int computerChoice)// will output message saying what the computer chose
{
	switch(computerChoice)
	{
		case 0: cout <<"The computer selected rock." << endl;
				break;
		case 1: cout <<"The computer selected paper." << endl;
				break;
		case 2: cout <<"The computer selected scissors." << endl;
				break;
		case 3: cout <<"The computer selected lizard." << endl;
				break;
		case 4: cout <<"The computer selected spock." << endl;
				break;
	}
}

void matchResult(char playerChoice,int compChoice, int& tie, int& userWin, int& computerWin)//output a message saying who won the match or if it was a tie.
{

	//if any of this cases are true output message and increment tie by 1
	if (( playerChoice == '0' && compChoice == 0 ) || //rock and rock
		( playerChoice == '1' && compChoice == 1 ) || //paper and paper
	   	( playerChoice == '2' && compChoice == 2 ) || //scissors and scissors
		( playerChoice == '3' && compChoice == 3 ) || // lizard and lizard
		( playerChoice == '4' && compChoice == 4 ) ) //spock and spock
	{
		cout << endl;
		cout << "The game was a tie" << endl; //if both player and computer had the same choice output tie
		cout << endl;
		++tie; // increment tie by 1 every time the game is a tie
	}

	//if any of this cases are true then output message and increment user wins by 1
	else if (( playerChoice == '2' && compChoice == 1 ) || //scissors and paper
         ( playerChoice == '1' && compChoice == 0 ) || //paper and rock
         ( playerChoice == '0' && compChoice == 3 ) || // rock and scissors
         ( playerChoice == '3' && compChoice == 4 ) || // lizard and spock
         ( playerChoice == '4' && compChoice == 2 ) || // spock and scissors
         ( playerChoice == '2' && compChoice == 3 ) || // scissors and lizard
         ( playerChoice == '3' && compChoice == 1 ) || // lizard and paper
         ( playerChoice == '1' && compChoice == 4 ) || // paper and spock
         ( playerChoice == '4' && compChoice == 0 ) || // spock and rock
         ( playerChoice == '0' && compChoice == 2 )) // rock and scissors
    {
    	 cout << endl;
        cout << "The user won :)" << endl; //if the player wins then output user won
        cout << endl;
        ++userWin; //increment user wins by 1
    }


	//if any of this cases are true then output message and increments computer wins by 1
	else if (( playerChoice == '1' && compChoice == 2 ) || //paper an scissors
        ( playerChoice == '0' && compChoice == 1 ) || // rock and paper
        ( playerChoice == '3' && compChoice == 0 ) || // lizard and rock
		( playerChoice == '4' && compChoice == 3 ) || //spock and lizard
        ( playerChoice == '2' && compChoice == 4 ) || //scissors and spock
        ( playerChoice == '3' && compChoice == 2 ) || // lizard and scissors
        ( playerChoice == '1' && compChoice == 3 ) || // paper and lizard
        ( playerChoice == '4' && compChoice == 1 ) || //spock and rock
        ( playerChoice == '0' && compChoice == 4 ) || // rock and spock
        ( playerChoice == '2' && compChoice == 0 )) //scissors and rock
    {
    	cout << endl;
        cout << "The computer won :(" << endl; //if computer won then output computer won
        cout << endl;
        ++computerWin;//increments computer wins by 1
    }
}
void gameStats(int ties, int userWins, int computerWins) //this will display the number of wins, losses and ties by the computer and player
{
	cout << endl;
	int computerLoss = userWins; // total games loss by the computer is equal to total wins by user
	int userLoss = computerWins; //total games loss by the user is equal to total wins by the computer

	cout << "Computer won " << computerWins << " times" << endl;//output how many games the computer won
	cout <<	"Computer lost " << computerLoss << " times" << endl; //output how many games the computer loss
	cout << "User won " << userWins << " times" << endl; //output how many wins the user had
	cout <<	"User lost " << userLoss << " times" << endl;//output how many games the user loss
	cout << "There was(were) " << ties << " tie(s)" << endl; //output total number of ties
}


