//Eric Lin and Jonathan Lin

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string ready = "";

    do 
    {
        cout << "Think of a number between 1 and 7. Enter 'ready' when ready to " <<
                "start: ";
        cin >> ready;
    }
    while (ready != "ready");
    
    int guess = 4;	
    char clue = ' ';    
    cout << "Is the number " << guess << "?\n" << 
            "(Enter 'y' if the guess is correct.\n" << 
            "Enter 'h' if the computer should guess higher.\n" <<
            "Enter 'l' if the computer should guess lower.)" << endl;
    cin >> clue;
    
    int i = 2;
    
    while (clue != 'y' && i > 0)
    {
        if (clue == 'h')
        {
            compGuess += i;
            cout << "Is the number " << compGuess << "?" << endl;
            cin >> clue;
        }
        else if (clue == 'l')
        {
            compGuess -= i;
            cout << "Is the number " << compGuess << "?" << endl;
            cin >> clue;
        }  
        i--;
    }
    
    if (i >= 0 && clue == 'y')	
    	//Makes sure number was guessed both correctly and within 3 guesses. 
    	cout << "Your secret number was " << compGuess << "!" << endl;	
    else
    	cout << "You are either lying or you forgot your number!" << endl;
    	
	return EXIT_SUCCESS;
}

/*
Test case #1: Number guessed correctly in two tries or less. 

Think of a number between 1 and 7. Enter 'ready' when ready to start: ready
Is the number 4?
(Enter 'y' if the guess is correct.
Enter 'h' if the computer should guess higher.
Enter 'l' if the computer should guess lower.)
h
Is the number 6?
y
Your secret number was 6!

--------------------------------
Process exited after 6.094 seconds with return value 0

Test case #2: Number guessed correctly on the third try. 

Think of a number between 1 and 7. Enter 'ready' when ready to start: ready
Is the number 4?
(Enter 'y' if the guess is correct.
Enter 'h' if the computer should guess higher.
Enter 'l' if the computer should guess lower.)
h
Is the number 6?
h
Is the number 7?
y
Your secret number was 7!

--------------------------------
Process exited after 4.8 seconds with return value 0

Test case #3: User is not truthful and program cannot guess number. 

Think of a number between 1 and 7. Enter 'ready' when ready to start: ready
Is the number 4?
(Enter 'y' if the guess is correct.
Enter 'h' if the computer should guess higher.
Enter 'l' if the computer should guess lower.)
h
Is the number 6?
h
Is the number 7?
h
You are either lying or you forgot your number!

--------------------------------
Process exited after 5.591 seconds with return value 0


*/
