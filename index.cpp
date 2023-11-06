#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <windows.h>

using namespace std;

using num_t = int;

// MENU Function
void menu(double Balance, double Cash);

// ATM Function
void openAtm(double Balance, double Cash);
void showBalance(double Balance, double Cash);
void depositMoney(double Balance, double Cash);
void withdrawMoney(double Balance, double Cash);

// Work Function
void workMenu(double Balance, double Cash);

//CHAOS
void chaosLegion(double Balance, double Cash);
void startChaos(double Balance, double Cash);
void tutorialChaos(double Balance, double Cash);

// CASINO
void casinoMenu(double Balance, double Cash);
//NUMFIGHT
void numFight(double Balance, double Cash);
string numFightOpponentsFinding();
void startNumFight(double Balance, double Cash);
void tutorialNumFight(double Balance, double Cash);
//GUESSNUM
void guessNum(double Balance, double Cash);
void startGuessNum(double Balance, double Cash);
void rerollNumFight(double Balance, double Cash, double Amount, string Opponents, bool Replay);
void tutorialGuessNum(double Balance, double Cash);
//ROCK PAPER SCISSORS
void rockPaperScissors(double Balance, double Cash);
void startRockPaperScissors(double Balance, double Cash);
string rpsProgramChoiceToString(int ProgramChoice);
void rpsProgramAnswer(double Balance, double Cash, double Amount);
void tutorialRockPaperScissors(double Balance, double Cash);
void rockPaperScissorsText();


//MAIN
int main(){
    double Balance = 0, Cash = 0;
    menu(Balance, Cash);
}

//MENU
void menu(double Balance, double Cash){
    int Choice = 0;
    cout << endl;
    cout << "===== Life Cycle Game =====" << endl << endl;
    cout << "Your Cash right now are : $" << setprecision(2) << fixed << Cash << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Check bank" << endl;
    cout << "2. Work" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do {
        switch (Choice){
        case 1:
            success = true;
            openAtm(Balance, Cash);
            break;
        
        case 2:
            success = true;
            workMenu(Balance, Cash);
            break;

        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Check bank" << endl;
            cout << "2. Work" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}

//ATM
void atmText(){
    cout << endl;
    cout << "========= PROS ATM ==========" << endl << endl;
    cout << "Welcome to our ATM, the most epic ATM in the universe." << endl;
}

void openAtm(double Balance, double Cash){
    int Choice = 0;
    atmText();
    cout << "Enter your choice : " << endl;
    cout << "1. Show Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;
    do{
        switch (Choice){
        case 1:
            success = true;
            showBalance(Balance, Cash); 
            break;
        case 2:
            success = true;
            depositMoney(Balance, Cash);
            break;
        case 3:
            success = true;
            withdrawMoney(Balance, Cash);
            break;
        case 4:
            success = true;
            menu(Balance, Cash);
            break;    
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 4 choices, its : " << endl;
            cout << "1. Show Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
    }
    }while(!success);


}

void showBalance(double Balance, double Cash){
    int Choice = 0;
    atmText();
    cout << "Your Balance right now are : $" << setprecision(2) << fixed << Balance << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        switch (Choice){
        case 1:
            success = true;
            openAtm(Balance, Cash);
            break;
    
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 1 choices, its : " << endl;
            cout << "1. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

        }  
    } while(!success);
}
void depositMoney(double Balance, double Cash){
    int Choice = 0;
    double Amount = 0;
    string yesno = " ";
    atmText();
    cout << "Type 1 to Exit." << endl;
    cout << "Enter the amount to Deposit your money : $";
    cin >> Amount;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        if (Amount == 1) {
            openAtm(Balance, Cash);
        } else if (Amount <= 0){
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "You cant Deposit a money that below 0." << endl;
            cout << "Pick a Choice : " << endl;
            cout << "1. Back" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your number of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

            if (Choice == 1){
                depositMoney(Balance, Cash);
            } else {
                openAtm(Balance, Cash);
            }
        } else if (Cash < Amount){
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "You cant Deposit a money that bigger than your Balance." << endl;
            cout << "Pick a Choice : " << endl;
            cout << "1. Back" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your number of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

            if (Choice == 1){
                depositMoney(Balance, Cash);
            } else {
                openAtm(Balance, Cash);
            }
        }else {
            success = true;
            Choice = 0;
            cout << endl;
            cout << "Are you sure want to Deposit $" << setprecision(2) << fixed  << Amount << " Cash to Balance? (Y/N) : ";
            getline(cin, yesno);

            if (yesno == "y" || yesno == "Y"){
                int divided = Amount * 0.1;
                Cash -= Amount;
                Balance += Amount - divided;
                cout << endl;
                cout << "Deposit $"<< Amount <<" are successfull! :D" << endl;
                    cout << "Your Cash now is : $" << setprecision(2) << fixed << Cash << endl;
                    openAtm(Balance, Cash);
            } else {
                cout << endl;
                cout << "Deposit $" << setprecision(2) << fixed << Amount <<" are cancelled :(" << endl;
                openAtm(Balance, Cash);
            }
        }
    }while(!success);
}

void withdrawMoney(double Balance, double Cash){
    int Choice = 0;
    double Amount = 0;
    string yesno = " ";
    atmText();
    cout << "Enter the amount to Withdraw your money : $";
    cin >> Amount;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        if (Amount == 1) {
            openAtm(Balance, Cash);
        } else if (Amount <= 0){
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "You cant Withdraw a money that below 0." << endl;
            cout << "Pick a Choice : " << endl;
            cout << "1. Back" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your number of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

            if (Choice == 1){
                withdrawMoney(Balance, Cash);
            } else {
                openAtm(Balance, Cash);
            }
        }else if (Balance < Amount) {
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "You cant Withdraw a money that bigger than your Balance." << endl;
            cout << "Pick a Choice : " << endl;
            cout << "1. Back" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your number of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

            if (Choice == 1){
                withdrawMoney(Balance, Cash);
            } else {
                openAtm(Balance, Cash);
            }
        } else {
            success = true;
            Choice = 0;
            cout << endl;
            cout << "Are you sure want to Withdraw $" << setprecision(2) << fixed  << Amount << " Balance to Cash? (Y/N) : ";
            getline(cin, yesno);

            if (yesno == "y" || yesno == "Y"){
                Cash = Cash + Amount;
                Balance -= Amount;
                cout << endl;
                cout << "Withdraw $" << setprecision(2) << fixed << Amount <<" are successfull! :D" << endl;
                    cout << "Your Cash now is : " << Cash << endl;
                    openAtm(Balance, Cash);
            } else {
                cout << endl;
                cout << "Withdraw $" << setprecision(2) << fixed << Amount <<" are cancelled :(" << endl;
                openAtm(Balance, Cash);
            }
        }
    }while(!success);
}

//WORK
void workMenu(double Balance, double Cash){
    int Choice = 0;
    cout << endl;
    cout << "======= WORK CHOICES ========" << endl << endl;
    cout << "Choose a work you want here!" << endl;
    cout << "Pick a Choice : " << endl;
    cout << "1. Chaos Legion Office" << endl;
    cout << "2. Casino" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;
    do{
        switch (Choice)
        {
        case 1:
            success = true;
            chaosLegion(Balance, Cash);
            break;
        case 2:
            success = true;
            casinoMenu(Balance, Cash);
            break;
        case 3:
            success = true;
            menu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 3 choices, its : " << endl;
            cout << "1. Chaos Legion Office" << endl;
            cout << "2. Crypto Farming" << endl;
            cout << "3. Game Streamer" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}

//CHAOS
void chaosText(){
    cout << endl;
    cout << "==== Chaos Legion Office ====" << endl << endl;
    cout << "A place full of rubbish, we'll be bankrupt next week."<< endl;
}

void chaosLegion(double Balance, double Cash){
    int Choice = 0;
    chaosText();
    cout << "Pick a choice : " << endl;
    cout << "1. Start Working" << endl;
    cout << "2. Tutorial" << endl;
    cout << "3. Exit to the freedom" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        switch (Choice){
        case 1:
            success = true;
            startChaos(Balance, Cash);
            break;
        case 2:
            success = true;
            tutorialChaos(Balance,Cash);
            break;
        case 3:
            success = true;
            workMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 3 choices, its : " << endl;
            cout << "1. Chaos Legion Office" << endl;
            cout << "2. Crypto Farming" << endl;
            cout << "3. Game Streamer" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}

void startChaos(double Balance, double Cash){
    bool Replay = false;
    do{
        srand(time(NULL));
        int ProgramChoice = (rand() % 10) + 1;
        string Question, Answer, Choice;
        Replay = false;
        chaosText();

        if (ProgramChoice == 1){
            Question = "The mesmerizing dance of fireflies illuminated the tranquil night.";
        } else if (ProgramChoice == 2){
            Question = "As the aroma of freshly baked bread wafted through the cozy kitchen.";
        } else if (ProgramChoice == 3){
            Question = "Lost in the pages of an old, dusty book.";
        } else if (ProgramChoice == 4){
            Question = "The laughter of children playing in the park echoed through the crisp autumn air.";
        } else if (ProgramChoice == 5){
            Question = "The mysterious antique shop on the corner held an array of peculiar trinkets.";
        } else if (ProgramChoice == 6){
            Question = "With a steaming cup of coffee in hand, I watched the sunrise paint.";
        } else if (ProgramChoice == 7){
            Question = "The symphony of raindrops tapping on the windowpane provided a soothing backdrop.";
        } else if (ProgramChoice == 8){
            Question = "Beneath the vast canopy of stars, we laid on the grass, sharing stories and dreams.";
        } else if (ProgramChoice == 9){
            Question = "In the bustling city, I stumbled upon a hidden garden, a verdant oasis of serenity.";
        } else if (ProgramChoice == 10){
            Question = "Are oranges named oranges because oranges are orange or is orange named orange because oranges are orange.";
        }

        bool Loop = false;

        do{
            cout << endl;
            cout << "Type this sentences : " << Question << endl;
            cout << "Or type 1 to Exit." << endl;
            cout << "Enter : ";
            getline(cin, Answer);
            Loop = true;

            if (Answer == Question){
                Cash += 10;
                cout << endl;
                cout << "PERFECTLY CORRECT!" << endl;
                cout << "Your Cash now is : $" << setprecision(2) << fixed << Cash << endl;
                cout << "Wanna work again? (Y/N) : ";
                getline(cin, Choice);

                if (Choice == "y" || Choice == "Y" || Choice == "yes" || Choice == "Yes"){
                    Replay = true;
                    Loop = false;
                } else {
                    cout << endl;
                    cout << "Work is done now, I can relax on bed and watching some CoryXKenshin.";
                    workMenu(Balance, Cash);
                    Loop = false;
            }
            } else if(Answer == "1"){
                cout << endl;
                cout << "Work cancelled, Boss are not happy about this.." << endl;
                cout << endl;
                Loop = false;
                workMenu(Balance, Cash);
            } else {
                cout << endl;
                cout << "Try again." << endl;
                cout << "Type this sentences : " << Question << endl;
                cout << "Or type 1 to Exit." << endl;
                cout << "Enter : ";
                getline(cin, Answer);
            }
        }while(Loop);
    } while(Replay);
    
}

void tutorialChaos(double Balance, double Cash){
    int Choice = 0;
    chaosText();
    cout << "Tutorial : " << endl << endl;

    cout << "There will be a random sentences and you need to type it perfectly to earn some money." << endl;
    cout << "And yea thats it." << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Begin" << endl;
    cout << "2. Exit to the freedom" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do {
        switch (Choice)
        {
        case 1:
            success = true;
            startChaos(Balance, Cash);
            break;
        case 2:
            success = true;
            workMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Begin" << endl;
            cout << "2. Exit to the freedom" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);

}

//CASINO
void casinoText(){
    cout << endl;
    cout << "========== Casino ==========" << endl << endl;
    cout << "There are a lot of successfull people comes from there."<< endl;
}

void casinoMenu(double Balance, double Cash){
    int Choice = 0;
    casinoText();
    cout << "Pick a game to play : " << endl;
    cout << "1. Number Fight" << endl;
    cout << "2. Guessing Number" << endl;
    cout << "3. Rock Paper Scissors" << endl;
    cout << "4. Exit (only for losers)" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        switch (Choice){
        case 1:
            success = true;
            numFight(Balance, Cash);
            break;
        case 2:
            success = true;
            guessNum(Balance,Cash);
            break;
        case 3:
            success = true;
            rockPaperScissors(Balance,Cash);
            break;
        case 4:
            success = true;
            menu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 4 choices, its : " << endl;
            cout << "1. Number Fight" << endl;
            cout << "2. Guessing Number" << endl;
            cout << "3. Rock Paper Scissors" << endl;
            cout << "4. Exit (only for losers)" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}

void numFightText(){
    cout << endl;
    cout << "======= Number Fight =======" << endl << endl;
    cout << "A game that depends on your Number power!"<< endl;
}

void numFight(double Balance, double Cash){
    int Choice = 0;
    numFightText();
    cout << "Pick a choice : " << endl;
    cout << "1. Start Playing" << endl;
    cout << "2. Tutorial" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        switch (Choice){
        case 1:
            success = true;
            startNumFight(Balance, Cash);
            break;
        case 2:
            success = true;
            tutorialNumFight(Balance,Cash);
            break;
        case 3:
            success = true;
            casinoMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "Theres only a 3 choices, its : " << endl;
            cout << "1. Start Playing" << endl;
            cout << "2. Tutorial" << endl;
            cout << "3. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);

}

string numFightOpponentsFinding(){
    srand(time(NULL));
    int ProgramChoice = (rand() % 5) + 1;
    string Opponents[] = {"King of Casino", "King of Casino", "Noob Player", "Top Global 1 Casino", "mR. Billionare", "EpicNoob69"} ;

    return Opponents[ProgramChoice];
}


void startNumFight(double Balance, double Cash){
    bool Replay = 0;

    do{
        srand(time(NULL));
        double Amount;
        int Choice;
        string yesno = " ", Opponents = " ";
        Opponents = numFightOpponentsFinding();
        numFightText();

        cout << "Type 1 to Exit." << endl;
        cout << "How much money are you willing to bet on this game? : $";
        cin >> Amount;
        cin.clear();
        fflush(stdin);

        bool success = 0;
        do {
            if (Amount == 1){
                casinoMenu(Balance, Cash);

            } else if (Amount > Cash) {
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant Bet a money that bigger than your Cash." << endl;
                cout << "Pick a Choice : " << endl;
                cout << "1. Back" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter your number of the choice above : ";
                cin >> Choice;
                cin.clear();
                fflush(stdin);

                if (Choice == 1){
                    startNumFight(Balance, Cash);
                } else {
                    casinoMenu(Balance, Cash);
                }
                

            } else if (Amount < 50){
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant Bet a money that below $50.00" << endl;
                cout << "Pick a Choice : " << endl;
                cout << "1. Back" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter your number of the choice above : ";
                cin >> Choice;
                cin.clear();
                fflush(stdin);

                if (Choice == 1){
                    startNumFight(Balance, Cash);
                } else {
                    casinoMenu(Balance, Cash);
                }

            } else if (Amount > 1000){
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant Bet a money that bigger than $1000.00" << endl;
                cout << "Pick a Choice : " << endl;
                cout << "1. Back" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter your number of the choice above : ";
                cin >> Choice;
                cin.clear();
                fflush(stdin);

                if (Choice == 1){
                    startNumFight(Balance, Cash);
                } else {
                    casinoMenu(Balance, Cash);
                }
            } else {
                success = true;
                Choice = 0;
                cout << "Are you sure want to continue playing with $" << setprecision(2) << fixed  << Amount << "? (Y/N) : ";
                getline(cin, yesno);

                if (yesno == "y" || yesno == "Y"){
                    cout << endl;
                    cout << "======== Game Start ========" << endl << endl;
                    cout << "Finding opponents to play..." << endl;
                    Sleep(5000);
                    cout << "Opponents found!" << endl;
                    Sleep(1000);
                    cout << "Your opponents is " << Opponents << "!" << endl;
                    Sleep(1000);
                    rerollNumFight(Balance, Cash, Amount, Opponents, Replay);
                } else {
                    casinoMenu(Balance, Cash);
                }
            }
        }while(!success);
    }while(Replay);
}

void rerollNumFight(double Balance, double Cash, double Amount, string Opponents, bool Replay){
    string Choice = " ";

    int ProgramChoice = (rand() % 36) + 1, PlayerChoice = (rand() % 36) + 1;
    cout << Opponents << " rolled the Number..." << endl;
    Sleep(3000);
    cout << Opponents << " rolled the Number " << ProgramChoice << "." << endl;
    Sleep(1000);
    cout << "Your turn : ";
    cin.ignore();
    cout << "You rolled the Number..." << endl;
    Sleep(3000);
    cout << "You got the Number " << PlayerChoice << "." << endl << endl;
    cout << "============================" << endl << endl;

    Sleep(1000);
    if (ProgramChoice > PlayerChoice){
        Cash -= Amount;
        cout << "You Lose!" << endl;
        cout << "A winner come from a losers who doesnt give up!" << endl;
        cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";
    } else if (ProgramChoice < PlayerChoice){
        Cash += Amount;
        cout << "You Win!" << endl;
        cout << "Dont stop until you are bored of moneys!" << endl;
        cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";
    } else {
        cout << "Its a tie!" << endl;
        cout << "Restarting the Game..." << endl << endl;
        Sleep(2000);
        rerollNumFight(Balance, Cash, Amount, Opponents, Replay);       
    }

    Sleep(2000);
    cout << endl << endl;
    cout << "Wanna continue playing? (Y/N) : ";
    cin >> Choice;
    if (Choice == "Y" || Choice == "y"){
        cout << "Restarting the Game..." << endl;
        Sleep(2000);
        startNumFight(Balance, Cash);
    } else {
        casinoMenu(Balance, Cash);
    }
        
}

void tutorialNumFight(double Balance, double Cash){
    int Choice = 0;
    numFightText();
    cout << "Tutorial : " << endl << endl;

    cout << "You will competing with random player in this game." << endl;
    cout << "And then You and your Opponents will roll a random numbers." << endl;
    cout << "The biggest number will win the game." << endl;
    cout << "The number Minimal is 1 and Maximum is 36." << endl << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Begin Playing" << endl;
    cout << "2. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do {
        switch (Choice)
        {
        case 1:
            success = true;
            startNumFight(Balance, Cash);
            break;
        case 2:
            success = true;
            casinoMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Begin Playing" << endl;
            cout << "2. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}

void guessNumText(){
    cout << endl;
    cout << "======= Guess Number =======" << endl << endl;
    cout << "Best casino machine ever!"<< endl;
}

void guessNum(double Balance, double Cash){
    int Choice = 0;
    guessNumText();
    cout << "Pick a choice : " << endl;
    cout << "1. Start Playing" << endl;
    cout << "2. Tutorial" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        switch (Choice){
        case 1:
            success = true;
            startGuessNum(Balance, Cash);
            break;
        case 2:
            success = true;
            tutorialGuessNum(Balance,Cash);
            break;
        case 3:
            success = true;
            casinoMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 3 choices, its : " << endl;
            cout << "1. Start Playing" << endl;
            cout << "2. Tutorial" << endl;
            cout << "3. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);

}

string guessNumHint(){
    srand(time(NULL));
    int ProgramChoice = (rand() % 5) + 1;
    string Hints[] = {"The number its beetwen 1-10.", "The number its between 1-10.", "The number is majestic.", "Can be divided by 1.", "A number.", "I dont have a idea."};

    return Hints[ProgramChoice];
}

void guessNumProgressingAnswer(double Balance, double Cash ,int ProgramChoice, int Amount, int Tries, bool Finish){
    string Hint = guessNumHint(), yesno = " ";
    int playerGuess = 0, Choice = 0;
        cout << "Hint : " << Hint << endl;
        cout << "You got " << Tries << " tries left." << endl;
        cout << "Enter your guess : ";
        cin >> playerGuess;
        cin.clear();
        fflush(stdin);

        bool sukses = 0;
        do{
            if (playerGuess <= 0){
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant guess a number below 0." << endl;
                Sleep(1000);
                cout << "Enter your guess : ";
                cin >> playerGuess;
                cin.clear();
                fflush(stdin);
            } else if (playerGuess > 10){
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant guess a number bigger than 10." << endl;
                Sleep(1000);
                cout << "Enter your guess : ";
                cin >> playerGuess;
                cin.clear();
                fflush(stdin);
            } else {
                sukses = true;
            }
        }while(!sukses);

        if (playerGuess != ProgramChoice){
            cout << endl;
            cout << "Progressing answer..." << endl;
            Sleep(3000);
            cout << endl;
            cout << "============================" << endl << endl;
            if (Tries != 1){
                Tries -= 1;
                cout << "WRONG!" << endl;
                guessNumProgressingAnswer(Balance, Cash, ProgramChoice, Amount, Tries, Finish);
            } else {
                Finish = true;
                Cash -= Amount;
                cout << endl;
                cout << "YOU LOSE THE GAME!" << endl;
                cout << "The Program has choosen the number : " << ProgramChoice << endl;
                cout << "Your Cash now is $" << setprecision(2) << fixed << Cash << "." << endl;
                Sleep(2000);
                cout << endl << endl;
                cout << "Wanna continue playing? (Y/N) : ";
                cin >> yesno;
                cin.clear();
                fflush(stdin);
                if (yesno == "Y" || yesno == "y"){
                    cout << "Restarting the Game..." << endl;
                    Sleep(2000);
                    startGuessNum(Balance, Cash);
                } else {
                    casinoMenu(Balance, Cash);
                }
            }
        } else {
            Cash += Amount;
            cout << "Progressing answer..." << endl;
            Sleep(3000);
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "PERFECTLY RIGHT!" << endl;
            cout << "The Program has choosen the number : " << ProgramChoice << endl;
            cout << "Your Cash now is $" << setprecision(2) << fixed << Cash << "." << endl;
            Sleep(2000);
            cout << endl << endl;
            cout << "Wanna continue playing? (Y/N) : ";
            cin >> yesno;
            cin.clear();
            fflush(stdin);
            if (yesno == "Y" || yesno == "y"){
                cout << "Restarting the Game..." << endl;
                Sleep(2000);
                startGuessNum(Balance, Cash);
            } else {
                casinoMenu(Balance, Cash);
            }
        }

}

void startGuessNum(double Balance, double Cash){
        srand(time(NULL));
        int ProgramChoice = (rand() % 10) + 1, Choice = 0, Tries = 5;
        double Amount = 0;
        bool Finish = 0;
        string yesno = " ";
        guessNumText();
        cout << "Type 1 to Exit." << endl;
        cout << "How much money are you willing to bet on this game? : $";
        cin >> Amount;
        cin.clear();
        fflush(stdin);

        bool success = 0;
        do {
            if (Amount == 1){
                casinoMenu(Balance, Cash);
            } else if (Amount > Cash) {
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant Bet a money that bigger than your Cash." << endl;
                cout << "Pick a Choice : " << endl;
                cout << "1. Back" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter your number of the choice above : ";
                cin >> Choice;
                cin.clear();
                fflush(stdin);

                if (Choice == 1){
                    startGuessNum(Balance, Cash);
                } else {
                    casinoMenu(Balance, Cash);
                }
                
            }else if (Amount < 20){
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant Bet a money that below $20.00" << endl;
                cout << "Pick a Choice : " << endl;
                cout << "1. Back" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter your number of the choice above : ";
                cin >> Choice;
                cin.clear();
                fflush(stdin);

                if (Choice == 1){
                    startGuessNum(Balance, Cash);
                } else {
                    casinoMenu(Balance, Cash);
                }

            } else if (Amount > 1000){
                cout << endl;
                cout << "============================" << endl << endl;
                cout << "You cant Bet a money that bigger than $1000.00" << endl;
                cout << "Pick a Choice : " << endl;
                cout << "1. Back" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter your number of the choice above : ";
                cin >> Choice;
                cin.clear();
                fflush(stdin);

                if (Choice == 1){
                    startGuessNum(Balance, Cash);
                } else {
                    casinoMenu(Balance, Cash);
                }
            } else {
                success = true;
                Choice = 0;
                cout << "Are you sure want to continue playing with $" << setprecision(2) << fixed  << Amount << "? (Y/N) : ";
                getline(cin, yesno);

                cout << endl;

                if (yesno == "y" || yesno == "Y"){
                    cout << "Loading..." << endl;
                    Sleep(2000);
                    cout << "The program choosing a random number..." << endl;
                    Sleep(5000);
                    cout << "Program chosen the most perfect number." << endl;
                    Sleep(1000);
                    cout << endl;
                    cout << "============================" << endl << endl;
                    guessNumProgressingAnswer(Balance, Cash, ProgramChoice, Amount, Tries, Finish);
                } else {
                    casinoMenu(Balance, Cash);
                }
            }
        }while(!success);
}

void tutorialGuessNum(double Balance, double Cash){
    int Choice = 0;
    guessNumText();
    cout << "Tutorial : " << endl << endl;

    cout << "In this game, the Program will choose a Random Numbers between 1 - 10." << endl;
    cout << "And then you need to guess the Program selected Number." << endl;
    cout << "You have 5 tries to guess the number." << endl;
    cout << "If you have made 5 guesses and all are wrong, you will lose the game." << endl << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Begin Playing" << endl;
    cout << "2. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do {
        switch (Choice)
        {
        case 1:
            success = true;
            startGuessNum(Balance, Cash);
            break;
        case 2:
            success = true;
            casinoMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Begin Playing" << endl;
            cout << "2. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}


void rockPaperScissors(double Balance, double Cash){
    int Choice = 0;
    rockPaperScissorsText();
    cout << "Pick a choice : " << endl;
    cout << "1. Start Playing" << endl;
    cout << "2. Tutorial" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do{
        switch (Choice){
        case 1:
            success = true;
            startRockPaperScissors(Balance, Cash);
            break;
        case 2:
            success = true;
            tutorialRockPaperScissors(Balance,Cash);
            break;
        case 3:
            success = true;
            casinoMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 3 choices, its : " << endl;
            cout << "1. Start Playing" << endl;
            cout << "2. Tutorial" << endl;
            cout << "3. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}

void startRockPaperScissors(double Balance, double Cash){
    srand(time(NULL));
    int ProgramChoice = (rand() % 3) + 1, Choice = 0;
    string yesno = " ";
    double Amount = 0;

    rockPaperScissorsText();
    cout << "Type 1 to Exit." << endl;
    cout << "How much money are you willing to bet on this game? : $";
    cin >> Amount;
    cin.clear();
    fflush(stdin);

    bool success = 0;
    do {
        if (Amount == 1){
            casinoMenu(Balance, Cash);
        } else if (Amount > Cash) {
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "You cant Bet a money that bigger than your Cash." << endl;
            cout << "Pick a Choice : " << endl;
            cout << "1. Back" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your number of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

            if (Choice == 1){
                startRockPaperScissors(Balance, Cash);
            } else {
                casinoMenu(Balance, Cash);
            }
                   
        } else if (Amount < 50){
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "You cant Bet a money that below $50.00" << endl;
            cout << "Pick a Choice : " << endl;
            cout << "1. Back" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your number of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

            if (Choice == 1){
              startRockPaperScissors(Balance, Cash);
            } else {
              casinoMenu(Balance, Cash);
            }

        } else if (Amount > 1000){
            cout << endl;
            cout << "============================" << endl << endl;
            cout << "You cant Bet a money that bigger than $1000.00" << endl;
            cout << "Pick a Choice : " << endl;
            cout << "1. Back" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your number of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);

            if (Choice == 1){
                startRockPaperScissors(Balance, Cash);
            } else {
                casinoMenu(Balance, Cash);
            }
        } else {
            success = true;
            Choice = 0;
            cout << "Are you sure want to continue playing with $" << setprecision(2) << fixed  << Amount << "? (Y/N) : ";
            getline(cin, yesno);

            cout << endl;

            if (yesno == "y" || yesno == "Y"){
                cout << "Loading..." << endl;
                Sleep(2000);
                cout << "The Program begin to choose..." << endl;
                Sleep(5000);
                cout << "The Program has finished." << endl;
                Sleep(1000);
                cout << endl;
                cout << "======== Game Start ========" << endl << endl;
                rpsProgramAnswer(Balance, Cash, Amount);
            } else {
                casinoMenu(Balance, Cash);
            }
        }
    }while(!success);
}

void rpsProgramAnswer(double Balance, double Cash, double Amount){
    int ProgramChoice = (rand() % 3) + 1;
    string stringPlayerChoice = " ", stringProgramChoice = rpsProgramChoiceToString(ProgramChoice), Choice;
    cout << "Choose between Rock, Paper, Scissors." << endl;
    cout << "Type R for Rock." << endl;
    cout << "Type P for Paper." << endl;
    cout << "Type S for Scissors." << endl;
    Sleep(500);
    cout << "Enter your choice : ";
    cin >> stringPlayerChoice;
    cin.clear();
    fflush(stdin);

    cout << endl;
    cout << "Progressing Answer..." << endl;
    Sleep(2000);
    cout << endl;
    bool success = 0;
    do {
        if (stringPlayerChoice == "r" || stringPlayerChoice == "R"){
            stringPlayerChoice = "Rock";
            success = true;
        } else if (stringPlayerChoice == "p" || stringPlayerChoice == "P"){
            stringPlayerChoice = "Paper";
            success = true;
        } else if(stringPlayerChoice == "s" || stringPlayerChoice == "S"){
            stringPlayerChoice = "Scissors";
            success = true;
        } else {
            cout << "Invalid Choice." << endl;
            Sleep(500);
            cout << endl;
            cout << "Please only choose between Rock, Paper, Scissors." << endl;
            cout << "Type R for Rock." << endl;
            cout << "Type P for Paper." << endl;
            cout << "Type S for Scissors." << endl;
            Sleep(500);
            cout << "Enter your choice : ";
            cin >> stringPlayerChoice;
            cin.clear();
            fflush(stdin);
        }
    }while (!success);

    cout << "You has choosen " << stringPlayerChoice << "." << endl;
    Sleep(500);
    cout << "Loading result..." << endl;
    Sleep(3000);
    cout << "The bot has choosen ";
    Sleep(2000);
    cout << stringProgramChoice << endl;
    Sleep(1000);

    cout << endl;
    if (stringPlayerChoice == "Rock"){
        if (stringProgramChoice == "Rock"){
            cout << "Its a tie!" << endl;
            cout << "Restarting the Game..." << endl << endl;
            Sleep(2000);
            cout << "======== Game Start ========" << endl << endl;
            rpsProgramAnswer(Balance, Cash, Amount);
        } else if (stringProgramChoice == "Paper"){
            Cash -= Amount;
            cout << "You Lose!" << endl;
            cout << "Because you are " << stringPlayerChoice << " and The Program choosen " << stringProgramChoice << "." << endl;
            cout << "A winner come from a losers who doesnt give up!" << endl;
            cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";            
        } else if (stringProgramChoice == "Scissors"){
            Cash += Amount;
            cout << "You Win!" << endl;
            cout << "Because you are " << stringPlayerChoice << " and The Program choosen " << stringProgramChoice << "." << endl;
            cout << "Dont stop until you are bored of moneys!" << endl;
            cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";
        }
    } else if (stringPlayerChoice == "Paper"){
        if (stringProgramChoice == "Rock"){
            Cash += Amount;
            cout << "You Win!" << endl;
            cout << "Because you are " << stringPlayerChoice << " and The Program choosen " << stringProgramChoice << "." << endl;
            cout << "Dont stop until you are bored of moneys!" << endl;
            cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";
        } else if (stringProgramChoice == "Paper"){
            cout << "Its a tie!" << endl;
            cout << "Restarting the Game..." << endl << endl;
            Sleep(2000);
            cout << "======== Game Start ========" << endl << endl;
            rpsProgramAnswer(Balance, Cash, Amount);
        } else if (stringProgramChoice == "Scissors"){
            Cash -= Amount;
            cout << "You Lose!" << endl;
            cout << "Because you are " << stringPlayerChoice << " and The Program choosen " << stringProgramChoice << "." << endl;
            cout << "A winner come from a losers who doesnt give up!" << endl;
            cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";  
        }
    } else if (stringPlayerChoice == "Scissors"){
        if (stringProgramChoice == "Rock"){
            Cash -= Amount;
            cout << "You Lose!" << endl;
            cout << "Because you are " << stringPlayerChoice << " and The Program choosen " << stringProgramChoice << "." << endl;
            cout << "A winner come from a losers who doesnt give up!" << endl;
            cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";  
        } else if (stringProgramChoice == "Paper"){
            Cash += Amount;
            cout << "You Win!" << endl;
            cout << "Because you are " << stringPlayerChoice << " and The Program choosen " << stringProgramChoice << "." << endl;
            cout << "Dont stop until you are bored of moneys!" << endl;
            cout << "Your Cash now is : $" << setprecision(2) << fixed  << Cash << ".";
        } else if (stringProgramChoice == "Scissors"){
            cout << "Its a tie!" << endl;
            cout << "Restarting the Game..." << endl << endl;
            Sleep(2000);
            cout << "======== Game Start ========" << endl << endl;
            rpsProgramAnswer(Balance, Cash, Amount);
        }
    }

    Sleep(2000);
    cout << endl << endl;
    cout << "Wanna continue playing? (Y/N) : ";
    cin >> Choice;
    if (Choice == "Y" || Choice == "y"){
        cout << "Restarting the Game..." << endl;
        Sleep(2000);
        startRockPaperScissors(Balance, Cash);
    } else {
        casinoMenu(Balance, Cash);
    }
}

string rpsProgramChoiceToString(int ProgramChoice){
    string stringProgramChoice = " ";
    switch (ProgramChoice){
    case 1:
        stringProgramChoice = "Rock";
        break;
    case 2:
        stringProgramChoice = "Paper";
        break;
    case 3:
        stringProgramChoice = "Scissors";
        break;
    default:
        break;
    }

    return stringProgramChoice;
}

void tutorialRockPaperScissors(double Balance, double Cash){
    int Choice = 0;
    rockPaperScissorsText();
    cout << "Tutorial : " << endl << endl;

    cout << "This game its just about simple Rock Paper Scissors game." << endl;
    cout << "But you play it with a bot." << endl << endl;
    cout << "Pick a choice : " << endl;
    cout << "1. Begin Playing" << endl;
    cout << "2. Exit" << endl << endl;
    cout << "Enter your number of the choice above : ";
    cin >> Choice;
    cin.clear();
    fflush(stdin);

    bool success = false;

    do {
        switch (Choice)
        {
        case 1:
            success = true;
            startRockPaperScissors(Balance, Cash);
            break;
        case 2:
            success = true;
            casinoMenu(Balance, Cash);
            break;
        default:
            cout << endl;
            cout << "============================" << endl;
            cout << "Theres only a 2 choices, its : " << endl;
            cout << "1. Begin Playing" << endl;
            cout << "2. Exit" << endl << endl;
            cout << "Enter your number again of the choice above : ";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            break;
        }
    }while(!success);
}

void rockPaperScissorsText(){
    cout << endl;
    cout << "=== Rock Paper Scissors ===" << endl << endl;
    cout << "A Game that will broke your fingers!"<< endl;
}