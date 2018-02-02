// Eric Lin
// Assignment 9 Question 2

#include <iostream>
#include <cstdlib> 

using namespace std; 

int guess(int low, int high, int guesses)
{

	guesses++;
	int mid = (high + low)/2;
	char clue = ' '; 

	cout << "Is the number " << mid << "?" << endl;

	do
	{
		cout << "Enter (Y)es, (L)ower, or (H)igher: ";
		cin >> clue;
	}
	while (clue != 'Y' && clue != 'L' && clue != 'H');

	if (clue == 'Y')
		return guesses; 
	if (low == high || low == mid)	
		return 0;
	if (clue == 'L')
		return guess(low, mid, guesses);
	// if higher
	return guess(mid, high, guesses);


}
int main()
{
	cout << "Recursive Guess-A-Number" << endl;
	cout << "Think of a secret number, which I will attempt to guess." << endl;

	int low = 0, high = 0;

	cout << "Enter the lowest possible number: ";
	cin >> low;
	cout << "Enter the highest possible number: ";
	cin >> high;

	int guesses = guess(low, high, 0);

	if (guesses > 0)
		cout << "Yaay, I correctly guessed your secret number in " << guesses <<
        " guesses!" << endl;
	else
		cout << "I am unable to guess your secret number because you are not "
        << "telling the truth!" << endl;

	return EXIT_SUCCESS;
}

/* Test Cases

Test Case #1 

Recursive Guess-A-Number
Think of a secret number, which this program will attempt to guess.
Enter the lowest possible number: 3
Enter the highest possible number: 56
Is the number 29?
Enter (Y)es, (L)ower, or (H)igher: L
Is the number 16?
Enter (Y)es, (L)ower, or (H)igher: H
Is the number 22?
Enter (Y)es, (L)ower, or (H)igher: L
Is the number 19?
Enter (Y)es, (L)ower, or (H)igher: H
Is the number 20?
Enter (Y)es, (L)ower, or (H)igher: H
Is the number 21?
Enter (Y)es, (L)ower, or (H)igher: Y
Yaay, I correctly guessed your secret number in 6 guesses!

Test Case #2 

Recursive Guess-A-Number
Think of a secret number, which this program will attempt to guess.
Enter the lowest possible number: 2
Enter the highest possible number: 17
Is the number 9?
Enter (Y)es, (L)ower, or (H)igher: L
Is the number 5?
Enter (Y)es, (L)ower, or (H)igher: H
Is the number 7?
Enter (Y)es, (L)ower, or (H)igher: H
Is the number 8?
Enter (Y)es, (L)ower, or (H)igher: H
Is the number 8?
Enter (Y)es, (L)ower, or (H)igher: H
I am unable to guess your secret number because you are not telling the truth!

*/
