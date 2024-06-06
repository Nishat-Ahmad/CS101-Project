#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <windows.h>

#include "DealOrNoDeal.h"
#include "BlackJack.h"
#include "SlotMachine.h"
#include "Baccarat.h"
#include "UserInterface.h"

using namespace std;

//	Adding external variable from "BlackJack.h".
extern int earnings;

int main(){
    int choice;
    system("CLS");
    welcomeToCasino();

    do{
        if(earnings == 0){
            cout << "You are too broke to play so you have been thrown out of the casino." << endl;
            break;
        }

        cout << endl << "Enter 1 to play Black Jack." << endl;
        cout << "Enter 2 to play Slot machine." << endl;
        cout << "Enter 3 to play Bacarrats." << endl;
        cout << "Enter 4 to play deal or no deal." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << "Choice:    ";

        cin >> choice;
        cout << endl;

        switch (choice){
            case 0:
				cout << "Thank you for playing." << endl;
				cout << "Your total earnings were: " << earnings << endl;
                break;
            case 1:
                blackJackRules();
                blackJack();
                break;
            case 2:
                slotMachineRules();
                slotMachine();
                break;
            case 3:
                baccaratRules();
                Baccarat();
                break;
            case 4:
                system("CLS");
                DealOrNoDealRules();
                dealOrNoDeal();
                break;
            default:
                cout << "Not a valid option." << endl;
        }
    }while(choice != 0);
}
