#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

struct casino
{
    char risp;
    int puntate;
};

int main()
{
    system("TITLE European Roulette");

    casino roulette[4];

    srand(time(NULL)); // seed per inizializzare il generatore di numeri.

    string nome, testo, testo2;
    int saldo, saldoin = 100;
    int vincita = 0;

    cout << "Fase di Sign-In/Sign-Up" << endl;
    cout << "Inserisci il tuo NOME" << endl;
    cin >> nome;

    ofstream file;
    ifstream file2;
    ofstream file3;

    file2.open("../src/data/" + nome);

    if (file2.is_open())
    {

        cout << "Accesso in corso..." << endl;
        file2 >> saldo;
        saldoin = saldo;
        file2.close();
    }
    else
    {
        ofstream file("../src/data/" + nome);
        saldo = 100;
        saldoin = saldo;
        cout << "Registrazione in corso..." << endl;
        file << saldo;
        file.close();
    }

    do
    {
        cout << saldo << endl;
        cout << "\nBenvenuto nella European Roulette by chvbs & Mich24" << endl;
        cout << "[0][3][6][9][12][15][18][21][24][27][30][33][36]\n[2][5][8][11][14][17][20][23][26][29][32][35]\n[1][4][7][10][13][16][19][22][25][28][31][34]" << endl;
        cout << "\nAccesso Effettuato con successo" << endl;
        cout << "Info Profilo: \nUTENTE: " << testo << "\nSALDO: " << saldo << "$" << endl;
        int random = rand() % 2;
        cout << "Vuoi puntare su un numero specifico? (y/n)" << endl;
        cin >> roulette[0].risp;

        if (roulette[0].risp == 'y' or roulette[0].risp == 'Y')
        {
            do
            {
                cout << "Scegli un numero da 0 a 36" << endl;
                cin >> roulette[0].puntate;
            } while (roulette[0].puntate > 36 or roulette[0].puntate < 0);
            do
            {
                cout << "Quanto vuoi puntare su: " << roulette[0].puntate << "?" << endl;
                cin >> roulette[1].puntate;
                if (roulette[1].puntate > saldo)
                {
                    cout << "Hai puntato piu' del tuo saldo DISPONIBILE - SALDO: " << saldo << "$" << endl;
                }
                if (roulette[1].puntate <= 0)
                {
                    cout << "Puntata nulla" << endl;
                }
            } while (roulette[1].puntate > saldo or roulette[1].puntate <= 0);
            saldo = saldo - roulette[1].puntate;
            cout << "Hai puntato: " << roulette[1].puntate << "$, il tuo SALDO adesso e' " << saldo << "$" << endl;
        }
        cout << "Vuoi puntare su un numero pari o dispari? (y/n)" << endl;
        cin >> roulette[1].risp;
        if (roulette[1].risp == 'y' or roulette[1].risp == 'Y')
        {
            cout << "Cosa scegli: PARI o DISPARI (p/d)" << endl;
            cin >> roulette[1].risp;
            if (roulette[1].risp == 'd' or roulette[1].risp == 'D')
            {
                cout << "Hai scelto la puntata per i numeri DISPARI" << endl;
                do
                {
                    cout << "Quanto vuoi puntare sui numeri DISPARI?" << endl;
                    cin >> roulette[2].puntate;
                    if (roulette[2].puntate > saldo)
                    {
                        cout << "Hai puntato piu' del tuo saldo DISPONIBILE - SALDO: " << saldo << "$" << endl;
                    }
                    if (roulette[2].puntate < 0)
                    {
                        cout << "Puntata nulla" << endl;
                    }
                } while (roulette[2].puntate > saldo or roulette[2].puntate < 0);

                saldo = saldo - roulette[2].puntate;
                cout << "Hai puntato: " << roulette[2].puntate << "$, il tuo SALDO adesso e' " << saldo << "$" << endl;
            }
            if (roulette[1].risp == 'p' or roulette[1].risp == 'P')
            {
                cout << "Hai scelto la puntata per i numeri PARI" << endl;
                do
                {
                    cout << "Quanto vuoi puntare sui numeri PARI?" << endl;
                    cin >> roulette[2].puntate;
                    if (roulette[2].puntate > saldo)
                    {
                        cout << "Hai puntato piu' del tuo saldo DISPONIBILE - SALDO: " << saldo << "$" << endl;
                    }
                    if (roulette[2].puntate < 0)
                    {
                        cout << "Puntata nulla" << endl;
                    }
                } while (roulette[2].puntate > saldo or roulette[2].puntate < 0);
                saldo = saldo - roulette[2].puntate;
                cout << "Hai puntato: " << roulette[2].puntate << "$, il tuo SALDO adesso e' " << saldo << "$" << endl;
            }
        }
        cout << "Vuoi puntare sui numeri maggiori/minori di 18? (y/n)" << endl;
        cin >> roulette[2].risp;
        if (roulette[2].risp == 'y' or roulette[2].risp == 'Y')
        {
            cout << "Cosa scegli: MAGGIORE di 18 o MINORE di 18 (e/g)" << endl;
            cin >> roulette[2].risp;
            if (roulette[2].risp == 'g' or roulette[2].risp == 'G')
            {
                cout << "Hai scelto la puntata per i numeri MINORI di 18" << endl;
                do
                {
                    cout << "Quanto vuoi puntare sui numeri MINORI di 18?" << endl;
                    cin >> roulette[3].puntate;
                    if (roulette[3].puntate > saldo)
                    {
                        cout << "Hai puntato piu' del tuo saldo DISPONIBILE - SALDO: " << saldo << "$" << endl;
                    }
                    if (roulette[3].puntate < 0)
                    {
                        cout << "Puntata nulla" << endl;
                    }
                } while (roulette[3].puntate > saldo or roulette[3].puntate < 0);
                saldo = saldo - roulette[3].puntate;
                cout << "Hai puntato: " << roulette[3].puntate << "$, il tuo saldo adesso e' " << saldo << "$" << endl;
            }
            if (roulette[2].risp == 'e' or roulette[2].risp == 'E')
            {
                cout << "Hai scelto la puntata per i numeri MAGGIORI di 18" << endl;
                do
                {
                    cout << "Quanto vuoi puntare sui numeri MAGGIORI di 18?" << endl;
                    cin >> roulette[3].puntate;
                    if (roulette[3].puntate > saldo)
                    {
                        cout << "Hai puntato piu' del tuo saldo DISPONIBILE - SALDO: " << saldo << "$" << endl;
                    }
                    if (roulette[3].puntate < 0)
                    {
                        cout << "Puntata nulla" << endl;
                    }
                } while (roulette[3].puntate > saldo or roulette[3].puntate < 0);
                saldo = saldo - roulette[3].puntate;
                cout << "Hai puntato: " << roulette[3].puntate << "$, il tuo SALDO adesso e' " << saldo << "$" << endl;
            }
        }

        system("CLS");
        cout << "E' uscito il numero: " << random << endl;
        if (random == roulette[0].puntate) // vincita su una puntata specifica
        {
            vincita = roulette[1].puntate * 35;
            saldo += vincita;
            cout << "HAI VINTO: " << vincita << "$"
                 << "; puntando sul " << roulette[0].puntate << endl;
        }

        if ((random % 2 == 0) and (roulette[1].risp == 'p' or roulette[1].risp == 'P')) // vincita su una puntata pari
        {
            vincita = roulette[2].puntate * 2;
            saldo += vincita;
            cout << "HAI VINTO: " << vincita << "$"
                 << "; puntando sui numeri PARI" << endl;
        }

        if ((random % 2 != 0) and (roulette[1].risp == 'd' or roulette[1].risp == 'D')) // vincita su una puntata dispari
        {
            vincita = roulette[2].puntate * 2;
            saldo += vincita;
            cout << "HAI VINTO: " << vincita << "$"
                 << "; puntando sui numeri DISPARI" << endl;
        }
        if ((random >= 18) and (roulette[2].risp == 'e' or roulette[2].risp == 'E'))
        {
            vincita = roulette[3].puntate * 2;
            saldo += vincita;
            cout << "HAI VINTO: " << vincita << "$"
                 << "; puntando sui numeri MAGGIORI di 18" << endl;
        }
        if ((random <= 18) and (roulette[2].risp == 'g' or roulette[2].risp == 'G'))
        {
            vincita = roulette[3].puntate * 2;
            saldo += vincita;
            cout << "HAI VINTO: " << vincita << "$"
                 << "; puntando sui numeri MINORI di 18" << endl;
        }

        cout << "SALDO attuale: " << saldo << "$" << endl;
        cout << "Vuoi giocare ancora? (y/n)" << endl;
        cin >> roulette[3].risp;

    } while (roulette[3].risp == 'y' or roulette[3].risp == 'Y' and saldo >= 1);
    if (saldo <= 0)
    {
        cout << "Hai terminato il SALDO, se desideri rigiocare, recati alla cassa per ricaricare il SALDO." << endl;
    }
    if (roulette[3].risp == 'n' or roulette[3].risp == 'N' and saldo >= 1)
    {
        system("CLS");
        cout << "E' terminata la tua sessione di gioco, ecco il RIEPILOGO: \nSALDO d'entrata: " << saldoin << "$\nSALDO d'uscita: " << saldo << "$" << endl;
    }

    file3.open("../src/data/" + nome, fstream::out | fstream::trunc);
    file3 << saldo;
    file3.close();

    return 0;
}