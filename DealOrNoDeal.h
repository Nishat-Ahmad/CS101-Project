#include<iostream>
#include<algorithm>
#include<ctime>
#include<list>
//  #include"BlackJack.h"

#include <iomanip>

using namespace std;

/*
ToDo:
3. Change name to .h // Delete the .exe before hand,
4. Force GPT to make your code better 
5. Add a README.md, make chatgpt do it?
*/

//	Adding external variable from "BlackJack.h".
extern int earnings;

double userCaseValue;
double casesLeft[26];
double cases[26] = {1, 2, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 
10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};
int numBankerOffer[8] = {7, 5, 4, 3, 2, 2, 1, 1};
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

//  Outputs all the left over cases value.
void leftCasesValue(){
    int counter = 0;

    for(int i = 0; i < 25; i++){
        if(cases[i] != 0){
            casesLeft[counter] = cases[i];
            counter++;
        }
    }
    casesLeft[counter] = userCaseValue;
    counter++;

    sort(casesLeft, casesLeft + counter);

    cout << endl << "===== Amount of money in the leftover cases =====" << endl;
    for(int i = 0; i < counter; i++){
        if(i == int(counter / 4) && counter > 10 || i == int(counter / 2) || i == int(3 * counter / 4)){
            cout << endl;
        }
        if(i == int(counter / 2) && counter <= 10){
            cout << endl;
        }
        if(casesLeft[i] == 1000000){
            cout << i + 1 << ". $1000000 ";
            continue;
        }
        cout << i + 1 << ". $" << casesLeft[i] << " ";
    }
    cout << endl << "----------------------------------------" << endl;
}

//  Prints the cases left to be opened.
void casesLeftToBeOpened(){
    int caseNumber = 0;

    cout << "===== Cases left to be open =====";
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
    leftCasesValue();
}

//  Prints what is inside the case.
void casesLeftValue(){
    int caseNumber = 0;

    cout << "===== Cases value =====";
    for(int i = 0; i < 5; i++){
        cout << endl;
        for(int j = 0; j < 5; j++){
            caseNumber++;
            if(find(PlayerChoiceForCaseList.begin(), PlayerChoiceForCaseList.end(), caseNumber) != PlayerChoiceForCaseList.end()){
                continue;
            }
            if(cases[caseNumber - 1] == userCaseValue){
                continue;
            }
            if(cases[caseNumber - 1] == 1000000){
                cout << "Case " << caseNumber << ". $1000000" << " ";
                continue;
            }
            cout << "Case " << caseNumber << ". $" << cases[caseNumber - 1] << " ";
        }
    }
    //  Condition for 26th value.
    if(find(PlayerChoiceForCaseList.begin(), PlayerChoiceForCaseList.end(), 26) == PlayerChoiceForCaseList.end()){
        if(cases[25] != userCaseValue){
            if(cases[25] == 1000000){
                cout << "Case 26. $1000000" << " ";
            }else if(cases[26] != 1000000){
                cout << "Case " << 26 << ". $" << cases[25] << " ";
            }
        }
    }
    cout << endl << "----------------------------------------" << endl;
}

//  Runs the bank offer.
double bankOffer(){
    static double percentageOffer = .28;
    double long totalMoneyLeftInCases = 0;
    int casesLeft = 0;

    if(percentageOffer <= 0.6){
        percentageOffer = percentageOffer + .07;
    }

    for(int i = 0; i < 25; i++){
        totalMoneyLeftInCases += cases[i];
    }

    casesLeft = 26 - PlayerChoiceForCaseList.size();
    cout << "Cases left to be opened: " << casesLeft << endl;

    return ((totalMoneyLeftInCases / casesLeft) * percentageOffer);
}

//  Adds value to earnings, checks values & outputs what you won.
void swapCaseHandler(){
    char userChoice;
    int caseLeft;

    cout << "Do you want to swap the box [Y or N]: ";
    cin >> userChoice;

    //  Finds the left over case.
    for(int i = 0; i < 25; i++){
        if(cases[i] != 0){
            caseLeft = cases[i];
            break;
        }
    }

    //  If the user opts to swap the case.
    if(userChoice == 'y' || userChoice == 'Y'){
        cout << "You swapped your case." << endl;
        if(caseLeft != 1000000 && userCaseValue != 1000000){
            cout << "Congratulations! you won: " << caseLeft << endl;
            cout << "The box you left had: " << userCaseValue << endl;
            earnings += caseLeft;
        } else if(caseLeft == 1000000){
            cout << "Congratulations! you won: $1000000." << endl;
            cout << "The box you left had: " << userCaseValue << endl;
            earnings += caseLeft;
        } else if(userCaseValue == 1000000){
            cout << "Congratulations! you won: " << caseLeft << endl;
            cout << "The box you left had: $1000000" << endl;
            earnings += caseLeft;
        }
    //  If the user does not opts to swap the case.
    } else if (userChoice == 'n' || userChoice == 'N'){
        if(caseLeft != 1000000 && userCaseValue != 1000000){
            cout << "Congratulations! you won: " << userCaseValue << endl;
            cout << "The box you left had: " << caseLeft << endl;
            earnings += userCaseValue;
        } else if(userCaseValue == 1000000){
            cout << "Congratulations! you won: $1000000." << endl;
            cout << "The box you left had: " << caseLeft << endl;
            earnings += userCaseValue;
        } else if(caseLeft == 1000000){
            cout << "Congratulations! you won: " << userCaseValue << endl;
            cout << "The box that was left had: $1000000" << endl;
            earnings += userCaseValue;
        }
    }
}

//  Runs the main crux of the game.
void gameController(int &playerCase){
    int PlayerChoiceForCase;
    char userChoice = 'n';
    int caseLeft;

    PlayerChoiceForCaseList.push_front(playerCase);
    userCaseValue = cases[playerCase - 1];
    cases[playerCase - 1] = 0;
    
    for(int i = 0; i < 7; i++){
        //  Can open cases till the next bank offer.
        for(int j = numBankerOffer[i]; j >= 1; j--){
            cout << endl << "You have " << j << " cases left to open before bankers offer." << endl;

            checkPlayerCase(PlayerChoiceForCase); //  Checks if the case that the player chose has already been opened or not.

            //  Outputs info about the case opened.
            cout << "----------------------------------------" << endl;
            if(cases[PlayerChoiceForCase - 1] == 1000000){
                cout << "The case you choose had: $1000000" << endl;
                cases[PlayerChoiceForCase - 1] = 0;
            } else {
                cout << "The case you choose had: $" << cases[PlayerChoiceForCase - 1] << endl;
                cases[PlayerChoiceForCase - 1] = 0;
            }
            cout << "----------------------------------------" << endl;
            casesLeftToBeOpened();  //  Prints the cases left to be opened.
        }

        //  Stops the bank from giving inf offer.
        if(i == 6){
            break;
        }

        //  Banks offers management.
        cout << "The banker offers: " << bankOffer() << endl;
        cout << "Do you accept(Y / N): ";
        cin >> userChoice;

        if(userChoice == 'y' || userChoice == 'Y'){
            earnings += bankOffer();
            casesLeftValue();
            cout << "Your own case contained: $" << userCaseValue << endl;
            cout << "Thank you for playing." << endl;
            cout << "----------------------------------------" << endl;
            break;
        }else if (userChoice == 'n' || userChoice == 'N'){
            continue;
        }
    }

    //  Checks if the user swapper case or not.
    if(userChoice == 'n' || userChoice == 'N'){
        swapCaseHandler();
    }
}

int dealOrNoDeal(){
    int PlayerCase;
    int playerCaseValue;

    randomShuffleArray();
    playerCaseValue = choosePlayerCase(PlayerCase);
    gameController(PlayerCase);
}