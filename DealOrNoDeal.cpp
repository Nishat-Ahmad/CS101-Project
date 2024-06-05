#include<iostream>
#include<algorithm>
#include<ctime>

using namespace std;
/*
ToDo:
1. Have 6 increases of 7 percent
2. Add the rules in UserInterface.h
3. Change name to .h.
*/

//	Adding external variable from "BlackJack.h".
extern int earnings;

double cases[26] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750,
                    1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 999999};

//  Shuffles cases.
void randomShuffleArray(){
    srand(time(0));                                 //  Makes the shuffle totally random.
    random_shuffle((begin(cases)), end(cases));     //  Saves the file totally random array into cases.
}

//  Shows the Cases left.
void showCasesNumberWise(int &PlayerCase){
    int caseNumber = 0;

    cout << "Cases left to be open" << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            caseNumber++;
            //  cout << cases[caseNumber];
            if(caseNumber == PlayerCase){
                cout << caseNumber + 1 << " ";
                caseNumber++;
                continue;
            }
            cout << caseNumber << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//  Lets player choose a case.
void choosePlayerCase(int &PlayerCase){
    do{
        cout << endl << "Choose one of the cases [You can choose from 1 - 26]: ";
        cin >> PlayerCase;
        if(PlayerCase < 1 || PlayerCase > 26){
            cout << "Value choose out of bound." << endl;
        }
    }while(PlayerCase < 1 || PlayerCase > 26);
}

void playGame(){

}

void banker(){
    int numOfOpening[6] = {7, 5, 4, 3, 2, 1};
}

int main(){
    int PlayerCase;

    randomShuffleArray();
    choosePlayerCase(PlayerCase);
    showCasesNumberWise(PlayerCase);

}