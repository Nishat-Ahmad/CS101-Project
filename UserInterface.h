#include<iostream>

using namespace std;

void welcomeToCasino() {
    cout << endl;

    cout <<"================================================================================================================  \n";
    cout <<"================================================================================================================  \n";
    cout << "W   W EEEEE  L      CCCCC  OOOO  M   M EEEEE     TTTTTT OOOO       CCCCC     A      SSSS   IIIIII NN   N  OOOO   \n";
    cout << "W   W E      L     C      O    O MM MM E           TT  O    O     C         A A    S         II   N N  N O    O  \n";
    cout << "W W W EEE    L     C      O    O M M M EEE         TT  O    O     C        A   A    SSSS     II   N  N N O    O  \n";
    cout << "WW WW E      L     C      O    O M   M E           TT  O    O     C       AAAAAAA       S    II   N   NN O    O  \n";
    cout << "W   W EEEEE  LLLLL  CCCCC  OOOO  M   M EEEEE       TT   OOOO       CCCCC A       A  SSSS   IIIIII N    N  OOOO   \n";
    cout <<"================================================================================================================  \n";
    cout <<"================================================================================================================  \n";
}

void slotMachineRules(){
    cout << "Rules for slot machine." << endl;
    cout << "1. If the 3 lines are different your bet goes to 0." << endl;
    cout << "2. If two of the 3 lines are similar, your bet is going to be multiplied by a random number." << endl;
    cout << "3. If the 3 lines are same, your bet is going to be multiplied by a random number and then x10." << endl;
    cout << "Enjoy :)" << endl;
}

void blackJackRules(){
    cout << "Rule for blackjack." << endl;
    cout << "1. You have 2 options to play the game 'Hit and Stand'." << endl;
    cout << "a. Choosing Hit means that a card will be drawn from the deck between (2 - 11)."<<endl;
    cout << "b. Stand means that dealer's and player's cards will be checked."<<endl;
    cout << "2. The goal is to stay below or on the 21 cards value mark and above the dealer's card value."<<endl;
    cout << "3. If you are to go above the 21 cards mark (going bust) or if the dealer's card value is above yours," << endl;
    cout <<  "   you will lose, and the betted amount will be deducted." << endl;
    cout << "4. In case of equal final scores, or both players going bust, the game will conclude in a tie."<<endl;
}

void baccaratRules(){
    cout << "Rules for Bacarrats." << endl;
	cout << "1. Player and dealer draw a card each." << endl;
	cout << "2. player can bet on dealer's hand, his own hand, or draw." << endl;
	cout << "3. Score is equal to the sum of both cards." << endl;
	cout << "4. If card is 10, J, Q, K than you get 0 points. Other cards have 1-9 value." << endl;
	cout << "5. If sum is larger than 10, than the first number is deleted." << endl;
	cout << "6. Person with the highest score wins." << endl;
}

void DealOrNoDealRules(){
    cout << "Rules for Deal or no deal." << endl;
    cout << "1. The Player will be asked to choose from 26 boxes, they have to pick one box. " << endl;
}