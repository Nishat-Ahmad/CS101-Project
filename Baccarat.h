#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <windows.h>

using namespace std;

//	Adding external variable from "BlackJack.h".
extern int earnings;

inline void WINBT(double *reward, double *bet) {
	*reward = (*bet) * 1.5;
}

int drawCard() {
	return (rand() % 13) + 1;
}
void outCard(int cardValue) {
	if (cardValue > 1 && cardValue <= 10) {
		cout << cardValue << " ";
	}
	switch(cardValue) 
	{
		case 1:
			cout << "A "; break;
		case 11:
			cout << "J "; break;
		case 12:
			cout << "Q "; break;
		case 13:
			cout << "K "; break;
	}
}

int points(int c1, int c2) {
	int sum;
	if (c1 > 9) {
		c1 = 0;
	}
	if (c2 > 9) {
		c2 = 0;
	}
	sum = c1 + c2;
	if (sum >= 10) {
		sum -= 10;
	}
	return sum;
}

bool needMoreCards(int scoreDealer, int scorePlayer) {
	if (scoreDealer < 3 && scorePlayer != 8) {
		return 1;
	}
	if (scoreDealer = 4 && scorePlayer > 1 && scorePlayer < 8) {
		return 1;
	}
	return 0;
}

void gameEnd(int dealer, int player) {
	cout << "Player score: " << player << endl;
	cout << "Dealer score: " << dealer << endl;
}

int Baccarat() {
	char choice;
    do{
        srand(time(0));
        double bet, reward;
        int card1, card2, card3, player, dealer;
        int winCondition = -1;

        cout << endl << "Your total cash is: " << earnings << endl;

        cout << endl << "Welcome to Baccarat, enter a value to bet: $";
        cin >> bet;
        while (winCondition < 0 || winCondition > 2) {
			cout << "Enter 0 to bet on your own hand: " << endl;
			cout << "Enter 1 to bet on the dealer's hand" << endl;
            cout << "Enter 2 to bet on a draw" << endl;
			cout << "Enter choice: ";

            cin >> winCondition;
            if (winCondition != 1 && winCondition != 0 && winCondition != 2) {
                cout << "Enter a valid number." << endl;
            }
        }

        card1 = drawCard();
        card2 = drawCard();

        cout << endl << "Your hand is: ";
        outCard(card1); outCard(card2); cout << endl;

        player = points(card1, card2);
        dealer = points(drawCard(), drawCard());
        
        if (needMoreCards) {
            cout << "Dealer has drawn an additional card" << endl;
            dealer = points(dealer, drawCard());
        }
        
        gameEnd(dealer,player);
        
        if (dealer == player && winCondition == 2) {
            WINBT(&reward,&bet);
            cout << endl << "You win! $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        }else if (dealer > player && winCondition == 1) {
            WINBT(&reward,&bet);
            cout << endl << "You win! $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        }else if (dealer < player && winCondition == 0) {
            WINBT(&reward,&bet);
            cout << endl << "You win! $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        } else{
			cout << endl << "You lose! $" << bet << " lost"  << endl;
			earnings -= bet;
			cout << "Your new balance is: " << earnings << endl;
		}

		if(earnings = 0){   //  Breaks the loop when the earning are < 0.
            break;
        }
        
		if(earnings <= 0){   //  Breaks the loop when the earning are < 0.
            break;
        }

        cout << "Do you wish to keep on playing Bacarrats?(Y/N):    ";
        cin >> choice;
        cout << endl;
    }while(choice != 'N');
	if(choice == 0)
		return 0;
}