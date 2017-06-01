//This program receives input for six test scores from the user, drops the lowest one,
//and then calculates the average of the remaining five scores.
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
void getScore(int &);
void calcAverage(int, int, int, int, int, int);
int findLowest(int, int, int, int, int, int);

int main()
{
	int score1, score2, score3, score4, score5, score6;		//To hold the six scores as input by the user
	int counter = 1;										//Used to repeat the getScore() function until allWelcome test scores are input			

	//Tell the user what the program is supposed to do.
	cout << "Welcome to the test score average program!\n";
	cout << "This program will ask you to input six test scores.\n";
	cout << "Then, it will drop the lowest one\n"
		<< "and calculate the average of the remaining five scores.\n\n";

	cout << "Please enter the test scores now.\n\n";

	//Get the scores from the user.
	cout << "Score #1: ";
	getScore(score1);
	cout << "Score #2: ";
	getScore(score2);
	cout << "Score #3: ";
	getScore(score3);
	cout << "Score #4: ";
	getScore(score4);
	cout << "Score #5: ";
	getScore(score5);
	cout << "Score #6: ";
	getScore(score6);

	calcAverage(score1, score2, score3, score4, score5, score6);

	cout << "Thank you for using this program!\n";
	cout << endl;
	system("PAUSE");
	return 0;
}

void getScore(int &value)
{
	cin >> value;
	while (value < 0 || value > 100)
	{
		cout << "Error: Score must be between 0 and 100.  Please try again.\n";
		cout << "Score: ";
		cin >> value;
	}
}

int findLowest(int compare1, int compare2, int compare3, int compare4, int compare5, int compare6)
{
	int lowest = compare1;		//Set the first test score as a baseline for comparison.

	//Go through each value, determining if it is lower than the one before it.
	if (compare2 < lowest)
		lowest = compare2;
	if (compare3 < lowest)
		lowest = compare3;
	if (compare4 < lowest)
		lowest = compare4;
	if (compare5 < lowest)
		lowest = compare5;
	if (compare6 < lowest)
		lowest = compare6;

	//Send the lowest value of the six back to the calcAverage() function for subtraction.
	return lowest;
}

void calcAverage(int num1, int num2, int num3, int num4, int num5, int num6)
{
	double average;

	//Set the formatting for output.
	cout << fixed << showpoint << setprecision(2);

	cout << endl << "Calculating average score now...\n\n";
	
	//Use the findLowest() function to figure out which is the lowest of the six scores.
	int lowest = findLowest(num1, num2, num3, num4, num5, num6);

	//Calculate the average of the test scores, subtracting the lowest one.
	average = (num1 + num2 + num3 + num4 + num5 + num6 - lowest) / 5;

	//Display the information for the user.
	cout << "Your lowest score was a " << lowest << ".\n"
		<< "After dropping that one, the average of your remaining five test scores is " << average << ".\n";
}