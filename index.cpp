#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

using num_t = int;

// Global Variable
int balance = 0, cash = 0;
string stringChoice;

// Menu Function
void menu();
void openAtm();

// ATM Function
void showBalance();
void depositMoney();
void withdrawMoney();

// Work Function
void workMenu();
void workTutorial();
void startWork();


int main(){
    menu();
}

void menu(){
    
    cout << endl;
    cout << "==== Simple Banking Game ====" << endl << endl;
    cout << "Your Cash right now are : $" << cash << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Check bank" << endl;
    cout << "2. Work" << endl << endl;
    cout << "Enter your number of the choice above : ";
    getline(cin, stringChoice);

    bool success = 0;
    do {
        if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
            stringChoice = " ";
            success = true;
            openAtm();

        } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
            stringChoice = " ";
            success = true;
            workMenu();

        } else {
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Check bank" << endl;
            cout << "2. Work" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            getline(cin, stringChoice);

        }
    }while(!success);
}


// ATM


void openAtm(){

    cout << endl;
    cout << "========= PROS ATM ==========" << endl << endl;
    cout << "Welcome to our ATM, the most epic ATM in the universe." << endl;
    cout << "Enter your choice : " << endl;
    cout << "1. Show Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    getline(cin, stringChoice);

    bool success = 0;
    do {
        if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
            stringChoice = " ";
            success = true;
            showBalance(); 

        } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
            stringChoice = " ";
            success = true;
            depositMoney();

        } else if (stringChoice == "3" || stringChoice == "three" || stringChoice == "Three"){
            stringChoice = " ";
            success = true;
            withdrawMoney();

        } else if (stringChoice == "4" || stringChoice == "four" || stringChoice == "Four"){
            stringChoice = " ";
            success = true;
            menu();

        } else {
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 4 choices, its : " << endl;
            cout << "1. Show Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            getline(cin, stringChoice);

        }
    }while(!success);
}

void showBalance(){
    cout << endl;
    cout << "========= PROS ATM ==========" << endl << endl;
    cout << "Welcome to our ATM, the most epic ATM in the universe." << endl << endl;
    cout << "Your Balance right now are : $" << balance << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    getline(cin, stringChoice);

    bool success = true;
    if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
            stringChoice = " ";
            success = true;
            openAtm();

    } else {
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 1 choices, its : " << endl;
            cout << "1. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            getline(cin, stringChoice);

        }
}

void depositMoney(){
    cout << endl;
    cout << "========= PROS ATM ==========" << endl << endl;
    cout << "Welcome to our ATM, the most epic ATM in the universe." << endl;
    cout << "Every deposit will be charged 10% taxes." << endl;
    cout << "Pick a amout to Deposit your money : " << endl;
    cout << "1. 10" << endl << endl;
    cout << "2. 100" << endl << endl;
    cout << "3. 1000" << endl << endl;
    cout << "Enter your number of the choice above : ";
    getline(cin, stringChoice);

    bool success = 0;
    do {
        if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
            stringChoice = " ";
            success = true;
            cout << "Are you sure want to Deposit $10 Cash to Balance? (Y/N) : ";
            getline(cin, stringChoice);

            if (stringChoice == "y" || stringChoice == "Y"){
                stringChoice = " ";
                if (cash < 10) {
                    cout << endl;
                    cout << "============================" << endl << endl;
                    cout << "You cant Deposit a money that bigger than your cash." << endl;
                    cout << "Pick a Choice : " << endl;
                    cout << "1. Back" << endl;
                    cout << "2. Exit" << endl;
                    cout << "Enter your number of the choice above : ";
                    getline(cin, stringChoice);

                if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
                    stringChoice = " ";
                    depositMoney(); 

                } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
                    stringChoice = " ";
                    openAtm();
                } else {
                    stringChoice = " ";
                    openAtm();
                }
            } else {
                cash -= 10;
                balance += 9;
                cout << endl;
                cout << "Deposit $10 are successfull! :D" << endl;
                openAtm();
            }
            } else {
                stringChoice = " ";
                cout << endl;
                cout << "Deposit $10 are cancelled :(" << endl;
                openAtm();
            }

        } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
            stringChoice = " ";
            success = true;
            cout << "Are you sure want to Deposit $100 Cash to Balance? (Y/N) : ";
            getline(cin, stringChoice);

            if (stringChoice == "y" || stringChoice == "Y"){
                stringChoice = " ";
                if (cash < 100) {
                    cout << endl;
                    cout << "============================" << endl << endl;
                    cout << "You cant Deposit a money that bigger than your cash." << endl;
                    cout << "Pick a Choice : " << endl;
                    cout << "1. Back" << endl;
                    cout << "2. Exit" << endl;
                    cout << "Enter your number of the choice above : ";
                    getline(cin, stringChoice);

                if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
                    stringChoice = " ";
                    depositMoney(); 

                } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
                    stringChoice = " ";
                    openAtm();
                } else {
                    stringChoice = " ";
                    openAtm();
                }
            } else {
                cash -= 100;
                balance += 90;
                cout << endl;
                cout << "Deposit $100 are successfull! :D" << endl;
                openAtm();
            }
            } else {
                stringChoice = " ";
                cout << endl;
                cout << "Deposit $100 are cancelled :(" << endl;
                openAtm();
            }

        } else if (stringChoice == "3" || stringChoice == "three" || stringChoice == "Three"){
             stringChoice = " ";
            success = true;
            cout << "Are you sure want to Deposit $1000 Cash to Balance? (Y/N) : ";
            getline(cin, stringChoice);

            if (stringChoice == "y" || stringChoice == "Y"){
                stringChoice = " ";
                if (cash < 1000) {
                    cout << endl;
                    cout << "============================" << endl << endl;
                    cout << "You cant Deposit a money that bigger than your cash." << endl;
                    cout << "Pick a Choice : " << endl;
                    cout << "1. Back" << endl;
                    cout << "2. Exit" << endl;
                    cout << "Enter your number of the choice above : ";
                    getline(cin, stringChoice);

                if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
                    stringChoice = " ";
                    depositMoney(); 

                } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
                    stringChoice = " ";
                    openAtm();
                } else {
                    stringChoice = " ";
                    openAtm();
                }
            } else {
                cash -= 1000;
                balance += 900;
                cout << endl;
                cout << "Deposit $1000 are successfull! :D" << endl;
                openAtm();
            }
            } else {
                stringChoice = " ";
                cout << endl;
                cout << "Deposit $1000 are cancelled :(" << endl;
                openAtm();
            }

        }
    } while(!success);

}

void withdrawMoney(){
    cout << endl;
    cout << "========= PROS ATM ==========" << endl << endl;
    cout << "Welcome to our ATM, the most epic ATM in the universe." << endl;
    cout << "There is no taxes on every Withdraw you do." << endl;
    cout << "Pick a amout to Withdraw your money : " << endl;
    cout << "1. 10" << endl << endl;
    cout << "2. 100" << endl << endl;
    cout << "3. 1000" << endl << endl;
    cout << "Enter your number of the choice above : ";
    getline(cin, stringChoice);

    bool success = 0;
    do {
        if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
            stringChoice = " ";
            success = true;
            cout << "Are you sure want to Withdraw $10 Cash to Balance? (Y/N) : ";
            getline(cin, stringChoice);

            if (stringChoice == "y" || stringChoice == "Y"){
                stringChoice = " ";
                if (balance < 10) {
                    cout << endl;
                    cout << "============================" << endl << endl;
                    cout << "You cant Withdraw a money that bigger than your cash." << endl;
                    cout << "Pick a Choice : " << endl;
                    cout << "1. Back" << endl;
                    cout << "2. Exit" << endl;
                    cout << "Enter your number of the choice above : ";
                    getline(cin, stringChoice);

                if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
                    stringChoice = " ";
                    withdrawMoney(); 

                } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
                    stringChoice = " ";
                    openAtm();
                } else {
                    stringChoice = " ";
                    openAtm();
                }
            } else {
                cash += 10;
                balance -= 9;
                cout << endl;
                cout << "Withdraw $10 are successfull! :D" << endl;
                openAtm();
            }
            } else {
                stringChoice = " ";
                cout << endl;
                cout << "Withdraw $10 are cancelled :(" << endl;
                openAtm();
            }

        } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
            stringChoice = " ";
            success = true;
            cout << "Are you sure want to Withdraw $100 Cash to Balance? (Y/N) : ";
            getline(cin, stringChoice);

            if (stringChoice == "y" || stringChoice == "Y"){
                stringChoice = " ";
                if (balance < 100) {
                    cout << endl;
                    cout << "============================" << endl << endl;
                    cout << "You cant Withdraw a money that bigger than your cash." << endl;
                    cout << "Pick a Choice : " << endl;
                    cout << "1. Back" << endl;
                    cout << "2. Exit" << endl;
                    cout << "Enter your number of the choice above : ";
                    getline(cin, stringChoice);

                if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
                    stringChoice = " ";
                    withdrawMoney(); 

                } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
                    stringChoice = " ";
                    openAtm();
                } else {
                    stringChoice = " ";
                    openAtm();
                }
            } else {
                cash += 100;
                balance -= 100;
                cout << endl;
                cout << "Withdraw $100 are successfull! :D" << endl;
                openAtm();
            }
            } else {
                stringChoice = " ";
                cout << endl;
                cout << "Withdraw $100 are cancelled :(" << endl;
                openAtm();
            }

        } else if (stringChoice == "3" || stringChoice == "three" || stringChoice == "Three"){
             stringChoice = " ";
            success = true;
            cout << "Are you sure want to Withdraw $1000 Cash to Balance? (Y/N) : ";
            getline(cin, stringChoice);

            if (stringChoice == "y" || stringChoice == "Y"){
                stringChoice = " ";
                if (balance < 1000) {
                    cout << endl;
                    cout << "============================" << endl << endl;
                    cout << "You cant Withdraw a money that bigger than your cash." << endl;
                    cout << "Pick a Choice : " << endl;
                    cout << "1. Back" << endl;
                    cout << "2. Exit" << endl;
                    cout << "Enter your number of the choice above : ";
                    getline(cin, stringChoice);

                if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
                    stringChoice = " ";
                    withdrawMoney(); 

                } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
                    stringChoice = " ";
                    openAtm();
                } else {
                    stringChoice = " ";
                    openAtm();
                }
            } else {
                cash += 1000;
                balance -= 1000;
                cout << endl;
                cout << "Withdraw $1000 are successfull! :D" << endl;
                openAtm();
            }
            } else {
                stringChoice = " ";
                cout << endl;
                cout << "Withdraw $1000 are cancelled :(" << endl;
                openAtm();
            }

        }
    } while(!success);
}


// WORK

void workMenu(){
    cout << endl;
    cout << "==== Chaos Legion Office ====" << endl << endl;
    cout << "A place full of rubbish, we'll be bankrupt next week."<< endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Start Working" << endl;
    cout << "2. Tutorial" << endl;
    cout << "3. Exit to the freedom" << endl << endl;
    cout << "Enter your number of the choice above : ";
    getline(cin, stringChoice);

    bool success = 0;
    do {
        if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
            stringChoice = " ";
            success = true;
            startWork();

        } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
            stringChoice = " ";
            success = true;
            workTutorial();

        }  else if (stringChoice == "3" || stringChoice == "three" || stringChoice == "Three"){
            stringChoice = " ";
            success = true;
            menu();

        } else {
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Start Working" << endl;
            cout << "2. Exit to the freedom" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            getline(cin, stringChoice);
        }
    }while(!success);
}

void workTutorial(){
    cout << endl;
    cout << "==== Chaos Legion Office ====" << endl << endl;
    cout << "A place full of rubbish, we'll be bankrupt next week."<< endl;
    cout << "Tutorial : " << endl << endl;

    cout << "There will be a random sentences and you need to type it perfectly to earn some money." << endl;
    cout << "And yea thats it." << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Begin" << endl;
    cout << "2. Exit to the freedom" << endl << endl;
    cout << "Enter your number of the choice above : ";
    getline(cin, stringChoice);

     bool success = 0;
    do {
        if (stringChoice == "1" || stringChoice == "one" || stringChoice == "One"){
            stringChoice = " ";
            success = true;
            startWork();

        } else if (stringChoice == "2" || stringChoice == "two" || stringChoice == "Two"){
            stringChoice = " ";
            success = true;
            menu();

        } else {
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Begin" << endl;
            cout << "2. Exit to the freedom" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            getline(cin, stringChoice);
        }
    }while(!success);
}

void startWork(){
    bool replay = false;
    do {
        srand(time(NULL));
        int programChoice = (rand() % 10) + 1;
        string question, answer;
        cout << endl;
        cout << "==== Chaos Legion Office ====" << endl << endl;
        cout << "A place full of rubbish, we'll be bankrupt next week."<< endl;

        if (programChoice == 1){
            question = "The mesmerizing dance of fireflies illuminated the tranquil night.";
        } else if (programChoice == 2){
            question = "As the aroma of freshly baked bread wafted through the cozy kitchen.";
        } else if (programChoice == 3){
            question = "Lost in the pages of an old, dusty book.";
        } else if (programChoice == 4){
            question = "The laughter of children playing in the park echoed through the crisp autumn air.";
        } else if (programChoice == 5){
            question = "The mysterious antique shop on the corner held an array of peculiar trinkets.";
        } else if (programChoice == 6){
            question = "With a steaming cup of coffee in hand, I watched the sunrise paint.";
        } else if (programChoice == 7){
            question = "The symphony of raindrops tapping on the windowpane provided a soothing backdrop.";
        } else if (programChoice == 8){
            question = "Beneath the vast canopy of stars, we laid on the grass, sharing stories and dreams.";
        } else if (programChoice == 9){
            question = "In the bustling city, I stumbled upon a hidden garden, a verdant oasis of serenity.";
        } else if (programChoice == 10){
            question = "Are oranges named oranges because oranges are orange or is orange named orange because oranges are orange.";
        }

        bool loop = false;


       do {
        cout << endl;
        cout << "Type this sentences : " << question << endl;
        cout << "Or type 1 to Exit." << endl;
        cout << "Enter : ";
        getline(cin, answer);
        loop = true;

        if (answer == question){
            cash += 10;
            cout << endl;
            cout << "PERFECTLY CORRECT!" << endl;
            cout << "Wanna work again? (Y/N) : ";
            getline(cin, stringChoice);

            if (stringChoice == "y" || stringChoice == "Y" || stringChoice == "yes" || stringChoice == "Yes"){
                stringChoice = " ";
                replay = true;
                loop = false;
            } else {
                stringChoice = " ";
                cout << endl;
                cout << "Work is done now, I can relax on bed and watching some CoryXKenshin.";
                workMenu();
                loop = false;
            }
        } else if(answer == "1"){
            cout << endl;
            cout << "Work cancelled, Boss are not happy about this.." << endl;
            cout << endl;
            workMenu();
        } else {
            cout << endl;
            cout << "Try again." << endl;
            cout << "Type this sentences : " << question << endl;
            cout << "Or type 1 to Exit." << endl;
            cout << "Enter : ";
            getline(cin, answer);
        }
       } while (loop);
    } while (replay);
}