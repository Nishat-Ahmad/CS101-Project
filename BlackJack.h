#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <windows.h>

using namespace std;

bool finish = false;				//controls when the code ends
int player_total, opponent_starting, starting_cards, opponent_total, count;
int bet, earnings = 10000;			//providing an initial value of earnings so the game can be started
bool point = false;					//acts as a switch for the loop
char gameController = 'y';

int player_card(){
	int card;
	return card = 2 + rand()%10;
}

int opponent_card(){
	int card;
	return card = 2 + rand()%10;
}

void win(int opponent_total, int &earnings, int bet){
	earnings += 2*bet;
	cout<<"Congratulations! You have won the game!"<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout <<"You earned $"<<bet<<". You now have $"<<earnings<<"."<<endl;
	finish = true;
}

void lose(int opponent_total, int &earnings, int bet){
	cout<<"You have lost the game."<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout<<"You lost $"<<bet<<". You now have $"<<earnings<<"."<<endl;
	finish = true;
}

void tie(int opponent_total, int &earnings, int bet){
	earnings += bet;
	cout<<"Its a tie."<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout<<"You still have $"<<earnings<<"."<<endl;
	finish = true;
}

void jack(int opponent_total, int &earnings, int bet){
	earnings += 2*bet;
	cout<<"Congratulations! Its a natural jack!"<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout <<"You earned $"<<bet<<". You now have $"<<earnings<<"."<<endl;
	finish = true;
}

void display(int count, int &player_total, int &opponent_total, int opponent_starting, int &earnings, int bet){
	
	switch(count){
		case 1:
			player_total += player_card();
			cout<<"Your cards are now : "<<player_total<<endl;
			if(opponent_total < 17)
					opponent_total += opponent_card();
					
			if(player_total > 21){
				if(opponent_total <= 21)
					lose(opponent_total, earnings, bet);
				else if(player_total > opponent_total)
					tie(opponent_total, earnings, bet);
				else if(player_total == opponent_total)
					tie(opponent_total, earnings, bet);
				else if(opponent_total > 21)
					tie(opponent_total, earnings, bet);
				else
					win(opponent_total, earnings, bet);
				break;
			}			
			cout<<"Your opponent's cards are : "<<opponent_starting<<" + ?"<<endl;
			
			break;
			
		case 2:
			
			if(player_total == 21)
				jack(opponent_total, earnings, bet);
			else if((player_total <= 21) && (player_total > opponent_total))
				win(opponent_total, earnings, bet);
			else if(player_total == opponent_total)
				tie(opponent_total, earnings, bet);
			else if(opponent_total > 21)
				win(opponent_total, earnings, bet);
			else
				lose(opponent_total, earnings, bet);
			
			break;
		
		default:
			cout<<"Invalid option entered."<<endl;
			break;
	}
}

void blackJack(){
	cout << endl << "Welcome to Blackjack!" << endl;
	
	do{
		do {
			cout<<"Your total cash is $"<<earnings<<"\nWhat bet would you like to place?:   $";
			cin >> bet;
            cout << endl;
	        if (bet > earnings || bet <= 0) {
	            cout << "Invalid bet. Please enter a valid amount." << endl;
	        } else {
	            earnings -= bet;
	            break;
	        }
	    } 
		while (true);
	    
		while(::count != 2){
			if(point == false){
				srand(time(0));
				starting_cards = (2 + rand()%10) + (2 + rand()%9);
				opponent_starting = 2 + rand()%10;
				opponent_total = opponent_starting + (2 + rand()%9);
				player_total = starting_cards;
			
				cout<<"Your opponent has : "<<opponent_starting<<" + ?"<<endl;
				cout<<"You have : "<<starting_cards<<endl;
			
				point = true;
			}
			if(finish == false){
				cout<<"\nWhat will your next action be?\n";
				cout<<"1. Hit\n";
				cout<<"2. Stand\n";
				cin>>::count;
				display(::count, player_total, opponent_total, opponent_starting, earnings, bet);
			}
			else
				break;
		}

		if(earnings <= 0){   //  Breaks the loop when the earning are < 0.
            break;
        }
		
		cout<<"\nWould you like to continue with black jack?(Y/N)"<<endl;
		cin>>gameController;
		
		::count = 0;
		point = false;
		finish = false;

		
	} while(gameController == 'Y' || gameController == 'y');
}