#include<iostream>
#include<algorithm>
#include<ctime>
#include<list>

using namespace std;

/*
ToDo:
#. Add bankers functionality.
$. Add a way to swap the case when the banker gives an offer.

1. Have 6 increases of 7 percent
2. Add the rules in UserInterface.h
3. Change name to .h.
4. Add a README.md, make chatgpt do it?
*/

//	Adding external variable from "BlackJack.h".
extern int earnings;

double cases[26] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750,
                    1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000,
                    400000, 500000, 750000, 999999};

int numOfOpening[8] = {7, 5, 4, 3, 2, 2, 1, 1};

list<int> PlayerChoiceForCaseList;

//  Shuffles cases.
void randomShuffleArray(){
    srand(time(0));                                 //  Makes the shuffle totally random.
    random_shuffle((begin(cases)), end(cases));     //  Saves the file totally random array into cases.
}

//  Lets player choose a case.
int choosePlayerCase(int &PlayerCase){
    do{
        cout << endl << "Choose one of the cases [You can choose from 1 - 26]: ";
        cin >> PlayerCase;
        if(PlayerCase < 1 || PlayerCase > 26){
            cout << "Value choose out of bound." << endl;
        }
    }while(PlayerCase < 1 || PlayerCase > 26);
    return cases[PlayerCase];
}

//  Checks if the case that the player chose has already been opened or not.
void checkPlayerCase(int &PlayerChoiceForCase){
    bool checker;

    cout << "Choose a case to open: ";

    do{
        cin >> PlayerChoiceForCase;
        checker = true;
        //  Checks if the case is already opened.
        if (find(PlayerChoiceForCaseList.begin(), PlayerChoiceForCaseList.end(), PlayerChoiceForCase) != PlayerChoiceForCaseList.end()) {
            cout << "You already choose this case." << endl;
            cout << "Choose another case to open: ";
            checker = false;
            continue;
        }
        //  Checks if the case trying to be opened is out of bound or not.
        if(PlayerChoiceForCase < 1 || PlayerChoiceForCase > 26){
            cout << "Value choose out of bound." << endl;
            cout << "Choose another case to open: ";
            checker = false;
            continue;
        }
        PlayerChoiceForCaseList.push_back(PlayerChoiceForCase);
    } while (!checker);
}

//  Prints the cases left to be opened.
void casesLeftToBeOpened(){
    int caseNumber = 0;

    cout << "Cases left to be open" << endl;
    for(int i = 0; i < 5; i++){
        cout << endl;
        for(int j = 0; j < 5; j++){
            caseNumber++;
            if(find(PlayerChoiceForCaseList.begin(), PlayerChoiceForCaseList.end(), caseNumber) != PlayerChoiceForCaseList.end()){
                continue;
            }
            cout << caseNumber << " ";
        }
    }
    if(find(PlayerChoiceForCaseList.begin(), PlayerChoiceForCaseList.end(), 26) == PlayerChoiceForCaseList.end()){
        cout << 26 << endl;
    }
    cout << "----------------------------------------" << endl;
}

void banker(){}

//  Runs the main crux of the game.
void gameController(int &playerCase){
    int PlayerChoiceForCase;

    PlayerChoiceForCaseList.push_back(playerCase);
    cases[playerCase - 1] = -1;
    
    for(int i = 0; i < 8; i++){
        for(int j = numOfOpening[i]; j >= 1; j--){
            cout << endl << "You have " << j << " cases left to open before bankers offer." << endl;

            checkPlayerCase(PlayerChoiceForCase); //  Checks if the case that the player chose has already been opened or not.

            //  Outputs info about the case opened.
            cout << "----------------------------------------" << endl;
            cout << "The case you choose had : $" << cases[PlayerChoiceForCase - 1] << endl;
            cases[PlayerChoiceForCase - 1] = -1;
            cout << "----------------------------------------" << endl;

            casesLeftToBeOpened();  //  Prints the cases left to be opened.
        }
    }
}

int main(){
    int PlayerCase;
    int playerCaseValue;

    randomShuffleArray();
    playerCaseValue = choosePlayerCase(PlayerCase);
    gameController(PlayerCase);
}