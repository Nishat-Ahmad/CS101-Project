#include<iostream>
#include<algorithm>
#include<ctime>

using namespace std;
/*
ToDo:
1. Have 6 increases of 7 percent
2. Add the rules in UserInterface.h
*/

//	Adding external variable from "BlackJack.h".
extern int earnings;

double cases[26] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750,
                    1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 999999};

void randomShuffleArray(){
    srand(time(0));                                 //  Makes the shuffle totally random.
    random_shuffle((begin(cases)), end(cases));     //  Saves the file totally random array into cases.
}
    
void showCasesNumberWise(){
    int numOfCases = 26;
    for(int i = 0; i < numOfCases; i++){
        cout << i + 1 << endl;
    }
}


int main(){
    int PlayerCase;
    randomShuffleArray();
    showCasesNumberWise();

    cout << "Choose one of the boxes: ";
    cin >> PlayerCase;
}