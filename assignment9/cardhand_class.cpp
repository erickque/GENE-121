// Eric Lin
// Assignment 9 Question 1

#include <iostream>
#include <stdlib.h>     // rand
#include <time.h>       // time

using namespace std;

const int MAX_HAND_SIZE = 26;
enum Suit {NONE, CLUBS, HEARTS, DIAMONDS, SPADES};

class Card
{
public:
    int value;
    Suit suit;
};

class CardHand
{
private:
    int handSize;
    Card hand[MAX_HAND_SIZE];     
public:
    CardHand()
    {
        handSize = 5;

        // Sets the value and suit of the entire hand to be 0 (empty)
        for (int hand_index = 0; hand_index < handSize; hand_index++)
        {
            hand[hand_index].value = 0;
            hand[hand_index].suit = NONE;
        }
    }

    CardHand(int handSize0)
    {
        if (handSize0 > 0)
            handSize = handSize0;
        else
            handSize = 5;

        for (int hand_index = 0; hand_index < handSize; hand_index++)
        {
            hand[hand_index].value = 0;
            hand[hand_index].suit = NONE;
        }
    }
    int GetHandSize() const;
    int GetCardNum() const;
    void GetHand(Card outHand[]) const;
    bool AddCard(Card new_card);
    void SortCards();
    int BetterHand(CardHand OtherHand);
    void PrintHand(ostream & out);
};

bool DealCards(CardHand hands[], int num_hands)
{
    // check if there are enough cards (only 52 cards available)
    int cards_needed = 0;
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        cards_needed += hands[hand_index].GetHandSize();
    }

    if (cards_needed > 52)
        return false;

    const int NUM_CARDS = 52;
    Card deck[NUM_CARDS];
    int current_value = 1;
    Suit current_suit = CLUBS;

    // create the deck of cards
    for (int card_index = 0; card_index < NUM_CARDS; card_index++)
    {
        deck[card_index].value = current_value;
        deck[card_index].suit = current_suit;

        current_value++;
        if (current_value > 13)
        {
            switch (current_suit)
            {
                case CLUBS: current_suit = HEARTS;
                    break;
                case HEARTS: current_suit = DIAMONDS;
                    break;
                case DIAMONDS: current_suit = SPADES;
                    break;
                default: break;
            }
            current_value = 1;
        }
    }

    // seed the random number generator
    srand(time(NULL));

    // randomly pull cards from the deck and assign them to each hand
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        for (int card_index = 0; card_index < hands[hand_index].GetHandSize();
             card_index++)
        {
            Card assign_card;
            assign_card.value = 0;
            assign_card.suit = NONE;

            while (assign_card.value == 0)
            {
                int try_card = rand() % 52;

                if (deck[try_card].value > 0)
                {
                    assign_card.value = deck[try_card].value;
                    assign_card.suit = deck[try_card].suit;
                    deck[try_card].value = 0;
                    deck[try_card].suit = NONE;
                }
            }

            hands[hand_index].AddCard(assign_card);
        }
    }

    return true;
}

int main()
{
    const int num_hands = 4;
    CardHand hands[num_hands];
    if (DealCards(hands, num_hands))
    {
        for (int player = 0; player < num_hands; player++)
        {
            cout << "Player " << player + 1 << endl;
            hands[player].PrintHand(cout);
            cout << "\n";
        }

        // Bool condition to ensure the loop ends when best player is found. 
        bool bestFound = false; 

        for (int player = 0; player < num_hands && !bestFound; player++)
        {
            int betterCount = 0;
            for (int comparison = player+1; comparison<num_hands; comparison++)
                if (hands[player].BetterHand(hands[comparison]) != -1)
                    betterCount ++;

            /* Checks if the player is better than all other players. 
            Players of smaller numbers do not need to be checked again as they
            have been already checked in previous iterations of the for loop.*/
            if (betterCount == num_hands-player-1)  
            {
                bestFound = true;
                cout << "The best player is player number " << player+1 << endl;
            }
        }
    }
    else    // There are not enough cards
        cout << "The game cannot be played with one deck of cards." << endl;

    return 0;
}

int CardHand::GetHandSize() const
{
    return handSize;
}

void CardHand::GetHand(Card outHand[]) const
{
    // Copies the cards stored in the array into the output array. 
    for (int c = 0; c < handSize; c++)
        outHand[c] = hand[c];
}

int CardHand::GetCardNum() const
{
    // Checks through the entire hand to count the number of "non-zero" cards.  
    int cardNum = 0;
    for (int hand_index = 0; hand_index < handSize; hand_index++)
        if (hand[hand_index].value != 0 && hand[hand_index].suit != 0)
            cardNum++;
    return cardNum;
}

bool CardHand::AddCard(Card new_card)
{
    int cardNum = GetCardNum();

    if (cardNum < handSize)
    {
        hand[cardNum] = new_card;
        return true;
    }
    else
        return false;
}

void CardHand::SortCards()
{
    bool sorted = false;
    int cardNum = GetCardNum();
    
    while (!sorted)
    {
        sorted = true;
        
        for (int c = 0; c < cardNum-1; c++)
        {
            if (hand[c].suit <  hand[c+1].suit)
            {
                Suit temp = hand[c].suit;
                hand[c].suit = hand[c+1].suit;
                hand[c+1].suit = temp;
                sorted = false;
            }
            if (hand[c].value <  hand[c+1].value)
            {
                int temp = hand[c].value;
                hand[c].value = hand[c+1].value;
                hand[c+1].value = temp;
                sorted = false;
            }
        }

    }
}

int CardHand::BetterHand(CardHand OtherHand)
{
    // Hand with the larger total sum of values is the better hand. 
    
    int SumThis = 0, SumOther = 0;
    int CardNumThis = GetCardNum(), CardNumOther = OtherHand.GetCardNum();

    for (int c = 0; c < CardNumThis; c++)
    {
        SumThis += hand[c].value;
    }

    Card OtherCards[OtherHand.GetHandSize()];
    OtherHand.GetHand(OtherCards);

    for (int c = 0; c < CardNumOther; c++)
    {
        SumOther += OtherCards[c].value;
    }

    if (SumThis < SumOther)
    {
        return -1;
    }

    if (SumThis == SumOther)
    {
        return 0;
    }

    return (SumThis > SumOther);
}

string GetSuit(Suit suitNum)
{
    if (suitNum == 1)
        return "CLUBS";
    else if (suitNum == 2)
        return "HEARTS";
    else if (suitNum == 3)
        return "DIAMONDS";
    else if (suitNum == 4)
        return "SPADES";
    else
        return "NONE";
}

void CardHand::PrintHand(ostream & out)
{
    int cardNum = GetCardNum();
    out << "start of hand" << endl;
    SortCards();
    for (int c = 0; c < cardNum; c++)
    {
        if (hand[c].value > 1 && hand[c].value < 11)
        {
            out << hand[c].value << " " << GetSuit(hand[c].suit) << endl;
        }
        else if (hand[c].value == 1)
        {
            out << "A " << GetSuit(hand[c].suit) << endl;
        }
        else if (hand[c].value == 11)
        {
            out << "J " << GetSuit(hand[c].suit) << endl;
        }
        else if (hand[c].value == 12)
        {
            out << "Q " << GetSuit(hand[c].suit) << endl;
        }
        else if (hand[c].value == 13)
        {
            out << "K " << GetSuit(hand[c].suit) << endl;
        }
    }
    out << "end of hand" << endl;
}



/* Output

Player 1
start of hand
Q SPADES
9 SPADES
6 SPADES
5 DIAMONDS
A DIAMONDS
end of hand

Player 2
start of hand
K SPADES
J SPADES
9 HEARTS
5 HEARTS
4 CLUBS
end of hand

Player 3
start of hand
K DIAMONDS
9 DIAMONDS
8 HEARTS
6 HEARTS
A CLUBS
end of hand

Player 4
start of hand
10 SPADES
7 DIAMONDS
7 HEARTS
A HEARTS
A CLUBS
end of hand

The best player is player number 2

*/

