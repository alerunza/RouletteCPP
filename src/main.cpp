#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

struct casino
{
    char answer; // answers
    int bet;     // bets
};

int main()
{
    system("TITLE European Roulette");

    casino roulette[4];

    srand(time(NULL)); // seed per inizializzare il generatore di numeri.

    string name;
    int balance, balancein = 100;
    int vincita = 0;

    cout << "Sign-In/Sign-Up" << endl;
    cout << "Write your Name" << endl;
    cin >> name;

    ofstream file;
    ifstream file2;
    ofstream file3;

    file2.open("../data/" + name);

    if (file2.is_open())
    {
        cout << "Logging..." << endl;
        file2 >> balance;
        balancein = balance;
        file2.close();
    }
    else
    {
        ofstream file("../data/" + name);
        balance = 100;
        balancein = balance;
        cout << "Signing-up..." << endl;
        file << balance;
        file.close();
    }

    do
    {
        cout << "\nWelcome in to European Roulette by chubs & Mich24" << endl;
        cout << "[0][3][6][9][12][15][18][21][24][27][30][33][36]\n[2][5][8][11][14][17][20][23][26][29][32][35]\n[1][4][7][10][13][16][19][22][25][28][31][34]" << endl;
        cout << "\nSuccessfully Logged-in" << endl;
        cout << "Info Profile: \nCASH: " << balance << "$" << endl;
        int random = rand() % 36;
        cout << "Do you want to bet on a specific number? (y/n)" << endl;
        cin >> roulette[0].answer;

        if (roulette[0].answer == 'y' or roulette[0].answer == 'Y')
        {
            do
            {
                cout << "Pick a number from 0 to 36" << endl;
                cin >> roulette[0].bet;
            } while (roulette[0].bet > 36 or roulette[0].bet < 0);
            do
            {
                cout << "How much do you want to bet in: " << roulette[0].bet << "?" << endl;
                cin >> roulette[1].bet;
                if (roulette[1].bet > balance)
                {
                    cout << "You have bet more than your balance AVAILABLE - CASH: " << balance << "$" << endl;
                }
                if (roulette[1].bet <= 0)
                {
                    cout << "Bet null" << endl;
                }
            } while (roulette[1].bet > balance or roulette[1].bet <= 0);
            balance = balance - roulette[1].bet;
            cout << "Your bet: " << roulette[1].bet << "$, your CASH now is " << balance << "$" << endl;
        }
        cout << "Do you want to bet on an EVEN or ODD number? (y/n)" << endl;
        cin >> roulette[1].answer;
        if (roulette[1].answer == 'y' or roulette[1].answer == 'Y')
        {
            cout << "EVEN or ODD (e/o)" << endl;
            cin >> roulette[1].answer;
            if (roulette[1].answer == 'e' or roulette[1].answer == 'E')
            {
                cout << "You have chosen the bet for the ODD numbers" << endl;
                do
                {
                    cout << "How much do you want to bet in ODD?" << endl;
                    cin >> roulette[2].bet;
                    if (roulette[2].bet > balance)
                    {
                        cout << "You have bet more than your balance AVAILABLE - CASH: " << balance << "$" << endl;
                    }
                    if (roulette[2].bet < 0)
                    {
                        cout << "Bet null" << endl;
                    }
                } while (roulette[2].bet > balance or roulette[2].bet < 0);

                balance = balance - roulette[2].bet;
                cout << "Your bet: " << roulette[2].bet << "$, your CASH now is  " << balance << "$" << endl;
            }
            if (roulette[1].answer == 'o' or roulette[1].answer == 'O')
            {
                cout << "You have chosen the bet for the EVEN numbers" << endl;
                do
                {
                    cout << "How much do you want to bet in EVEN?" << endl;
                    cin >> roulette[2].bet;
                    if (roulette[2].bet > balance)
                    {
                        cout << "You have bet more than your balance AVAILABLE - CASH: " << balance << "$" << endl;
                    }
                    if (roulette[2].bet < 0)
                    {
                        cout << "Bet null" << endl;
                    }
                } while (roulette[2].bet > balance or roulette[2].bet < 0);
                balance = balance - roulette[2].bet;
                cout << "Your bet:  " << roulette[2].bet << "$, your CASH now is  " << balance << "$" << endl;
            }
        }
        cout << "Do you want to bet on numbers greater/less than 18? (y/n)" << endl;
        cin >> roulette[2].answer;
        if (roulette[2].answer == 'y' or roulette[2].answer == 'Y')
        {
            cout << "GREATER of 18 or LESS of 18 (g/l)" << endl;
            cin >> roulette[2].answer;
            if (roulette[2].answer == 'g' or roulette[2].answer == 'G')
            {
                cout << "You have chosen the bet for the numbers OVER 18" << endl;
                do
                {
                    cout << "How much do you want to bet on numbers GREATER than 18?" << endl;
                    cin >> roulette[3].bet;
                    if (roulette[3].bet > balance)
                    {
                        cout << "You have bet more than your balance AVAILABLE - CASH: " << balance << "$" << endl;
                    }
                    if (roulette[3].bet < 0)
                    {
                        cout << "Bet null" << endl;
                    }
                } while (roulette[3].bet > balance or roulette[3].bet < 0);
                balance = balance - roulette[3].bet;
                cout << "Your bet:  " << roulette[3].bet << "$, your CASH now is  " << balance << "$" << endl;
            }
            if (roulette[2].answer == 'l' or roulette[2].answer == 'L')
            {
                cout << "You have chosen the bet for the numbers UNDER 18" << endl;
                do
                {
                    cout << "How much do you want to bet on numbers LESS than 18?" << endl;
                    cin >> roulette[3].bet;
                    if (roulette[3].bet > balance)
                    {
                        cout << "You have bet more than your balance AVAILABLE - CASH: " << balance << "$" << endl;
                    }
                    if (roulette[3].bet < 0)
                    {
                        cout << "Bet null" << endl;
                    }
                } while (roulette[3].bet > balance or roulette[3].bet < 0);
                balance = balance - roulette[3].bet;
                cout << "Your bet:  " << roulette[3].bet << "$, your CASH now is  " << balance << "$" << endl;
            }
        }

        system("CLS");
        cout << "Number: " << random << endl;

        if (random == roulette[0].bet) // vincita su una puntata specifica
        {
            vincita = roulette[1].bet * 35;
            balance += vincita;
            cout << "You WON: " << vincita << "$"
                 << "; betting on " << roulette[0].bet << endl;
        }

        if ((random % 2 == 0) and (roulette[1].answer == 'e' or roulette[1].answer == 'E')) // vincita su una puntata pari
        {
            vincita = roulette[2].bet * 2;
            balance += vincita;
            cout << "You WON: " << vincita << "$"
                 << "; betting on the EVEN numbers" << endl;
        }

        if ((random % 2 != 0) and (roulette[1].answer == 'o' or roulette[1].answer == 'O')) // vincita su una puntata dispari
        {
            vincita = roulette[2].bet * 2;
            balance += vincita;
            cout << "You WON: " << vincita << "$"
                 << "; betting on ODD numbers" << endl;
        }

        if ((random >= 18) and (roulette[2].answer == 'g' or roulette[2].answer == 'G'))
        {
            vincita = roulette[3].bet * 2;
            balance += vincita;
            cout << "You WON: " << vincita << "$"
                 << "; betting on numbers GREATER than 18" << endl;
        }

        if ((random <= 18) and (roulette[2].answer == 'l' or roulette[2].answer == 'L'))
        {
            vincita = roulette[3].bet * 2;
            balance += vincita;
            cout << "You WON: " << vincita << "$"
                 << "; betting on numbers LESS than 18" << endl;
        }

        cout << "CASH: " << balance << "$" << endl;
        cout << "Do you want to play again? (y/n)" << endl;
        cin >> roulette[3].answer;

    } while (roulette[3].answer == 'y' or roulette[3].answer == 'Y' and balance >= 1);

    if (balance <= 0)
    {
        cout << "You have finished the BALANCE, if you wish to play again, go to the cashier to recharge the BALANCE." << endl;
    }

    if (roulette[3].answer == 'n' or roulette[3].answer == 'N' and balance >= 1)
    {
        system("CLS");
        cout << "It's finished your game session, here is the SUMMARY: \nCASH-in: " << balancein << "$\nCASH-out: " << balance << "$" << endl;
    }

    file3.open("../data/" + name, fstream::out | fstream::trunc);
    file3 << balance;
    file3.close();

    system("pause");
}