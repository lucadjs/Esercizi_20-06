#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>

using namespace std;


// Inizializzazione costanti globali
const string nero_on = "\033[30m";
const string rosso_on = "\033[31m";
const string verde_on = "\033[32m";
const string giallo_on = "\033[33m";
const string sfondo_giallo_on = "\033[43m";
const string blu_on = "\033[34m";
const string ciano_on = "\033[36m";
const string sfondo_ciano_on = "\033[46m";
const string grassetto_on = "\033[1m";
const string corsivo_on = "\033[3m";
const string lampeggia_on = "\033[5m";
const string reset_testo = "\033[0m";
const char grado = 248;
const string msgErroreMenuMain = rosso_on + grassetto_on + lampeggia_on + "!!! Scelta non valida !!!" + reset_testo;
const string msgErroreNumeriInteri = rosso_on + lampeggia_on + "!!! NON E' UN NUMERO !!!" + reset_testo;
const string msgErroreNumeriInteriPositivi = rosso_on + lampeggia_on + "!!! NON E' UN NUMERO INTERO POSITIVO !!!" + reset_testo;
const string msgErroreLettere = rosso_on + lampeggia_on + "!!! NON E' UNA LETTERA DELL'ALFABETO !!!" + reset_testo;

// Dichiarazioni variabili globali
char sceltaMenuEsercizi;
string nonNumero;
char conferma;

    // Procedure
// MAIN

void mainEsercizio1();
void mainEsercizio2();
void mainEsercizio3();


    // Dichiarazioni funzioni

// Controllo cin
char checkInput();

// ESERCIZIO 1
int prodotto(int primo, int secondo, int terzo);
int somma (int primo, int secondo, int terzo);
int differenza(int prod, int somma);

// ESERCIZIO 2
int lettere (int m);
char vocale(char l);

// ESERCIZIO 3
bool controllaNaturale(int cn);
int valoreAssoluto(int va);
int contaNat(int cnat);

// CONTROLLO ERRORI
bool isValidNumber(const string& str);
bool seNumeroValido(int numero);
void erroreDigitazioneMenuEsercizi();
void confermaScelta();

// Main Menù principale
int main()
{
    char sceltaMenu;

    do
    {
        do
        {
            system("cls");

            cout << sfondo_ciano_on << "   " << reset_testo << ciano_on << grassetto_on << " MENU' ESERCIZI 20/06/2024 " << reset_testo << sfondo_ciano_on << "                                   " << reset_testo << endl << endl;
            cout << "(1) " << giallo_on << "Esercizio 1 || " << reset_testo << "(2) " << giallo_on << "Esercizio 2 || " << reset_testo << "(3) " << giallo_on << "Esercizio 3 || " << reset_testo << "(0) " << giallo_on << "Esci" << reset_testo << endl << endl;
            cout << sfondo_ciano_on << "                                                                 " << reset_testo << endl << endl;
            cout << "\rScegliere una opzione: ";
            cin >> sceltaMenu;

            while(sceltaMenu < '0' || sceltaMenu > '3')
            {
                cerr << msgErroreMenuMain << endl;
                cout << "(1) " << giallo_on + "Esercizio 1 || " << reset_testo << "(2) " << giallo_on << "Esercizio 2 || " << reset_testo << "(3) " << giallo_on << "Esercizio 3 || " << reset_testo << "(0) " << giallo_on << "Esci" << reset_testo << endl << endl;
                cout << "Scegliere una opzione valida: ";
                cin >> sceltaMenu;
            }
            cout << "Confermi la scelta? s/n ";
            cin >> conferma;

            while(conferma != 's' && conferma != 'n')
            {
                cout << rosso_on << grassetto_on << "!!! Selezionare una opzione valida s/n !!!" << reset_testo;
                cin >> conferma;
            }
        }
        while (conferma == 'n');

        switch(sceltaMenu)
        {
        case '0':
        {
            break;
        }
        case '1':
        {
            do
            {
                mainEsercizio1();
                erroreDigitazioneMenuEsercizi();

                if (sceltaMenuEsercizi == '0')
                {
                    exit(0);
                }
                if (sceltaMenuEsercizi == '2')
                {
                    break;
                }
            }
            while (sceltaMenuEsercizi == '1');
            break;
        }
        case '2':
        {
            do
            {
                mainEsercizio2();
                erroreDigitazioneMenuEsercizi();
                if (sceltaMenuEsercizi == '0')
                {
                    exit(0);
                }
                if (sceltaMenuEsercizi == '2')
                {
                    break;
                }
            }
            while (sceltaMenuEsercizi == '1');
            break;
        }
        case '3':
        {
            do
            {
                mainEsercizio3();
                erroreDigitazioneMenuEsercizi();
                if (sceltaMenuEsercizi == '0')
                {
                    exit(0);
                }
                if (sceltaMenuEsercizi == '2')
                {
                    break;
                }
            }
            while (sceltaMenuEsercizi == '1');
            break;
        }
        }
    }
    while (sceltaMenu != 0);

    return 0;
}

//-------------- INIZIO ESERCIZIO 1 ---------------------------------------
void mainEsercizio1()
{
    system("cls");

    int n[3];
    cout << sfondo_giallo_on << "   " << reset_testo << giallo_on << grassetto_on << " ESERCIZIO 1 " << reset_testo << sfondo_giallo_on << "                                                                    " << reset_testo << endl << endl;
    cout << "Digitare tre numeri interi:" << endl;

    for(int i = 1; i < 4; i++)
    {
// --------------- Chiama funzione che verifica se è un numero -----------------------------------------------
        while(true){
        cout << reset_testo << i << grado << " numero intero: " << giallo_on;
        cin >> nonNumero;

        if (isValidNumber(nonNumero)) {
            n[i] = stoi(nonNumero);
            break;
        } else {
            cerr << msgErroreNumeriInteri << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
//------------------- fine ----------------------------------------------------------------
    }

    int p = prodotto(n[1], n[2], n[3]);
    cout << endl;
    cout << reset_testo << "Prodotto: " << giallo_on << n[1] << reset_testo << " x " << giallo_on << n[2] << reset_testo << " x " << giallo_on << n[3] << reset_testo << " = " << verde_on << p << reset_testo << endl << endl;

    int s = somma(n[1],n[2],n[3]);
    cout << "Somma: " << giallo_on << n[1] << reset_testo << " + " << giallo_on << n[2] << reset_testo << " + " << giallo_on << n[3] << reset_testo << " = " << verde_on << s << reset_testo << endl << endl;

    int d = differenza(p, s);
    cout << "Differenza: ";
    cout << giallo_on << p << reset_testo << " - " << giallo_on << s << reset_testo << " = " << verde_on << d << reset_testo << endl << endl;
}

int prodotto(int primo, int secondo, int terzo)
{
    return primo*secondo*terzo;
}

int somma (int primo, int secondo, int terzo)
{
    return primo+secondo+terzo;
}

int differenza(int prod, int somma)
{
    return prod - somma;
}

// INIZIO ESERCIZIO 2
void mainEsercizio2()
{
    system("cls");
    int lettere (int m);
    char vocale(char l);
    int matrice;
    cout << sfondo_giallo_on << "   " << reset_testo << giallo_on << grassetto_on << " ESERCIZIO 2 " << reset_testo << sfondo_giallo_on << "                                                                    " << reset_testo << endl << endl;

    for(int j = 1; j < 3; j++)
    {
        int vocali = 0;

// --------------- Chiama funzione che verifica se è un numero -----------------------------------------------
        while(true){
        cout << "Inserire un numero intero positivo: ";
        cin >> nonNumero;

      if (isValidNumber(nonNumero)) {
            matrice = stoi(nonNumero);
            break;
        } else {
            cerr << msgErroreNumeriInteri << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
        while (matrice < 0)
        {
            cerr << msgErroreNumeriInteriPositivi << endl;
            cin >> matrice;
        }

        vocali = lettere (matrice);

        if(vocali > 0)
        {
            cout << verde_on << "Al " << j << grado <<" giro contate " << vocali << " vocali." << reset_testo << endl << endl;
        }
        else
        {
            cout << verde_on << "Al " << j << grado <<" giro non ci sono vocali." << reset_testo << endl << endl;
        }
    }
}

int lettere (int m)
{
    char v;
    int conto(0);
    char lettera;

    cout << "Inserire " << m << " lettere, maiuscole o minuscole, dell'alfabeto." << endl;

    for(int i = 0; i < m; i++)
    {
        cin >> lettera;

        while (!((lettera >= 'a' && lettera <= 'z') || (lettera >= 'A' && lettera <= 'Z')))
        {
            cerr << msgErroreLettere << endl;
            cin >> lettera;
        }

        v = vocale(lettera);

        if(v=='v')
        {
            conto++;
        }
    }

    return conto;
}

char vocale(char l)
{
    if(l=='a' || l=='e' || l=='i' || l=='o' || l=='u'|| l=='A' || l=='E' || l=='I' || l=='O' || l=='U')
    {
        return 'v';
    }
    else
    {
        return 'c';
    }
}

// INIZIO ESERCIZIO 3
void mainEsercizio3()
{
    system("cls");
    cout << sfondo_giallo_on << "   " << reset_testo << giallo_on << grassetto_on << " ESERCIZIO 3 " << reset_testo << sfondo_giallo_on << "                                                                    " << reset_testo << endl << endl;

    int numero;
    int numeriNaturali = 0;
    int numNat;
    int converti;

while(true){
    cout << "Inserire un numero: ";
    cin >> nonNumero;

      if (isValidNumber(nonNumero)) {
            numero = stoi(nonNumero);
            break;
        } else {
            cout << msgErroreNumeriInteri << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if(numero < 0)
    {
        cerr << grassetto_on << rosso_on << lampeggia_on << "!!! ATTENZIONE " << numero << " NON E' UN NUMERO NATURALE !!! \n" << reset_testo << "ORA LO CONVERTO." << reset_testo << endl;

        converti = valoreAssoluto(numero);
        numero = converti;
    }

    while(controllaNaturale(numero))
    {
         if(numero == 0)
        {
            cout << verde_on << corsivo_on << "OK " << numero << " e' un numero naturale." << reset_testo << endl;
            break;;
        }
        if(numero > 1)
        {
            cout << verde_on << corsivo_on << "OK " << numero << " e' un numero naturale." << reset_testo << endl;

            numNat = contaNat(numero);

            cout << "Rilevati " << verde_on << grassetto_on << lampeggia_on << "N" << grado << " " << numNat << reset_testo << " numeri naturali." << endl << endl;
        }
        else if(numero = 1)
        {
            cout << "Rilevato " << verde_on << grassetto_on << lampeggia_on << "N" << grado << " " << numNat << reset_testo << " numero naturale." << endl << endl;
        }
            break;
    }
}

bool controllaNaturale(int cn)
{
    return cn >= 0;
}

int valoreAssoluto(int va)
{
    return -va;
}

int contaNat(int cnat)
{
    int Naturali = 0;
    int n;
    int nonNaturali = 0;

    if(cnat > 1)
    {
        cout << "Digitare " << giallo_on << cnat << reset_testo << " numeri." << endl;
    }
    else
    {
        cout << "Digitare " << giallo_on << cnat << reset_testo << " numero." << endl;
    }

    int contenitore[cnat];

    for(int i= 1; i < cnat+1; i++)
    {
        cout << reset_testo << i << grado << " numero: " << giallo_on;
        cin >> n;

     while (true) {

            if(seNumeroValido(n)){
              if(controllaNaturale(n))
        {
            Naturali++;
        }
        break;
        }else{

        cout << msgErroreNumeriInteri << endl;

        cout << reset_testo << i << grado << " numero: " << giallo_on;
        cout.flush();
        cin >> n;
    }
     }


    }
    return Naturali;

}

void erroreDigitazioneMenuEsercizi()
{
    do
    {
        cout << sfondo_giallo_on << nero_on << " (0) Esce dal programma || (1) Ripete l'esercizio || (2) Torna al Menu' principale: ";
        cin >> sceltaMenuEsercizi;
        cout << reset_testo;
        if(sceltaMenuEsercizi != '0' && sceltaMenuEsercizi != '1' && sceltaMenuEsercizi != '2')
        {
            cerr << rosso_on << lampeggia_on << "!!! Scelta non valida !!!" << reset_testo << endl;
            cout << sfondo_giallo_on << nero_on << " (0) Esce dal programma || (1) Ripete l'esercizio || (2) Torna al Menu' principale: ";
            cin >> sceltaMenuEsercizi;
            cout << reset_testo;
        }
    }
    while(sceltaMenuEsercizi != '0' && sceltaMenuEsercizi != '1' && sceltaMenuEsercizi != '2');
}

//------------- Variabile che verifica se input è un numero -----------------------
bool isValidNumber(const string& str) {
    if (str.empty()) return false;
    int start = (str[0] == '-') ? 1 : 0;

    for (int i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    if (start == 1 && str.size() == 1) return false;

    return true;
}


//------ Funzione che rende errore se l'input non è un numero --------------------------
bool seNumeroValido(int numero) {
    if (numero) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora eventuali input aggiuntivi sulla stessa riga
        return true;
    } else {
        cin.clear(); // Resetta lo stato di errore di cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora l'input non valido
        return false;
    }
}

//------------------- Funzione di conferma scelta menù ----------------------------------------------------------
//void confermaScelta(){
//
//
//while(conferma != 's' && conferma != 'n')
//            {
//                cout << rosso_on << grassetto_on << "!!! Selezionare una opzione valida s/n !!!" << reset_testo;
//                cin >> conferma;
//            }
//        }
//        while (conferma == 'n');
//
//}
