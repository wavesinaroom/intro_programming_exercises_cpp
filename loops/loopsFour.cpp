#include <iostream>

using namespace std;

/*Write a program that prints all possible cards from a standard deck
of cards without jokers (there are 52 cards; 4 suits of 13 cards)*/

int main(int argc, char const *argv[])
{
    const int SUITE = 4;
    const int CARD_NUMBER = 14;
        
    string cardString;
    string suiteString; 

    for (size_t suiteCount = SUITE; suiteCount>0; suiteCount--)
    {
        switch (suiteCount)
        {
        case 4:
            suiteString = " of Spades";
            break;
        case 3:
            suiteString = " of Hearts";
            break;
        case 2:
            suiteString = " of Diamonds";
            break;
        case 1:
            suiteString = " of Clubs";
            break;
        }
            for (size_t cardCount = CARD_NUMBER; cardCount>1; cardCount--)
            {
                switch (cardCount)
                {
                case 14:
                    cardString = "A";
                    break;
                case 13:
                    cardString = "K";
                    break;
                case 12:
                    cardString = "Q";
                    break;
                case 11:
                    cardString = "J";
                    break;
                case 10:
                    cardString = "10";
                    break;
                case 9:
                    cardString = "9";
                    break;
                case 8:
                    cardString = "8";
                    break;
                case 7:
                    cardString = "7";
                    break;
                case 6:
                    cardString = "6";
                    break; 
                case 5:
                    cardString = "5";
                    break;
                case 4:
                    cardString = "4";
                    break;
                case 3:
                    cardString = "3";
                    break;
                case 2:
                    cardString = "2";
                    break;
                default:
                    break;
                }
                cout<<cardString<<suiteString<<endl; 
            }
    }
    return 0;
}