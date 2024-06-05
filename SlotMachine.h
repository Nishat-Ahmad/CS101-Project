#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <windows.h>

using namespace std;

//	Adding external variable from "BlackJack.h".
extern int earnings;

int slot1,slot2,slot3;

struct values{
	double points[8];
	string symbol[8];
}v;

void initialize() {
	v.symbol[0] = "@";
	v.points[0] = 1.25;
	
	v.symbol[1] = "$";
	v.points[1] = 1.5;
	
	v.symbol[2] = "+";
	v.points[2] = 2;
	
	v.symbol[3] = "&";
	v.points[3] = 2.5;
	
	v.symbol[4] = "G";
	v.points[4] = 3;
	
	v.symbol[5] = "#";
	v.points[5] = 4;
	
	v.symbol[6] = "%";
	v.points[6] = 5;
	
	v.symbol[7] = "?";
	v.points[7] = 10;
}

void randomizer() {
	srand(time(0));
	slot1 = rand() % 8;
	slot2 = rand() % 8;
	slot3 = rand() % 8;
}

void slotOut() {
	cout << "-----------------" << endl;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			cout << v.symbol[slot1];
		}
		cout << " ";
		for (int i = 0; i < 4; i++) {
			cout << v.symbol[slot2];
		}
		cout << " ";
		for (int i = 0; i < 4; i++) {
			cout << v.symbol[slot3];	
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}

void slotMachine() {
    char choiceSM;
    do{
        double betSM, reward;
        reward = 0;
        initialize();

        cout << endl << "Your total cash is: " << earnings << endl;
        cout << "Welcome to slot machines! enter a value to bet: $";
        cin >> betSM;
        earnings -= betSM;
        for (int i = 45; i < 75; i++) {	
            system("CLS");
            cout << "Welcome to slot machines! enter a value to bet: $" << betSM << endl;
            randomizer();
            slotOut();
            Sleep(i*0.015);
        }
        cout << '\a';
        if (slot1 == slot2) {
            reward = betSM*v.points[slot1];
        }
        if (slot1 == slot3) {
            reward = betSM*v.points[slot1];
        }
        if (slot2 == slot3) {
            reward = betSM*v.points[slot2];
        }
        if (slot1 == slot2 && slot2 == slot3) {
            reward = betSM*v.points[slot1]*10;
            cout << "JACKPOT!" << endl;
        }
        if (reward > 0) {
            cout << "congratulations, you won: $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        } else {
            cout << "You lost: $" << betSM << endl;
            earnings -= reward;
            cout << "Your new balance is: " << earnings << endl;
        }

        if(earnings <= 0){   //  Breaks the loop when the earning are < 0.
            break;
        }

        cout << endl;
        cout << "Do you want to keep playing slot machine?(Y/N):     ";
        cin >> choiceSM;
        cout << endl;
    }while(choiceSM != 'N');
}