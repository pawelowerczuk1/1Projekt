#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;


int komputer_karty[10];
int komputer_numer = 0;
int suma_komputera = 0;

char tk[3][3] = { 
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
     };
int tb[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

void wypisanie_karty_b(string figura_karty, string kolor_karty){
    cout << "+-------+\n";
    cout << "| " << figura_karty;
    if(figura_karty == "10") cout << "    |\n";
    else cout << "     |\n";
    cout << "|       |\n";
    cout << "|   "<< kolor_karty << "   |\n";
    cout << "|       |\n";
    if(figura_karty == "10") cout << "|    " << figura_karty << " |\n";
    else cout << "|     " << figura_karty << " |\n";
    cout << "+-------+\n";



}




int losowa_karta_b(){
    int x = rand()%13;
    return tb[x];
    
        
    }

void ruch_komputera(){
    suma_komputera = 0;
    for(int i=0;i<komputer_numer;i++){
        suma_komputera += komputer_karty[i];
    }
    while(suma_komputera < 17){
        komputer_karty[komputer_numer]=losowa_karta_b();
        komputer_numer++;
        
        suma_komputera = 0;
        for(int i=0;i<komputer_numer;i++){
            suma_komputera += komputer_karty[i];
        }
    }
}

string figura_karty(int wartosc){
    if(wartosc==2) return "2";
    else if(wartosc==3) return "3";
    else if(wartosc==4) return "4";
    else if(wartosc==5) return "5";
    else if(wartosc==6) return "6";
    else if(wartosc==7) return "7";
    else if(wartosc==8) return "8";
    else if(wartosc==9) return "9";
    if(wartosc==10){
        int r= rand()%4;
        if(r==0) return "10";
        else if(r==1) return "J";
        else if(r==2) return "Q";
        else if(r==3) return "K";
    }
    if(wartosc==11) return "A";
    return "?";
}

string kolor_karty(){
    int i= rand()%4;
    if(i==0) return "♠";
    else if(i==1) return "♥";
    else if(i==2) return "♦";
    else if(i==3) return "♣";
    return "e";
    
}

void wypisz_karty_b(int karty[], int numer_karty){
   for(int i=0;i<numer_karty;i++){
        string figura = figura_karty(karty[i]);
        string kolor = kolor_karty();
        wypisanie_karty_b(figura, kolor);
   }

}
void blackjack(){
komputer_numer = 0;
suma_komputera = 0;
int numer_karty = 0;
int gracz[10];
int komputer = 0;
char wybor;

gracz[numer_karty] = losowa_karta_b();
numer_karty++;
gracz[numer_karty] = losowa_karta_b();
numer_karty++;

for(;;){
    int suma=0;
    for(int i=0;i<numer_karty;i++){
        suma += gracz[i];
    }
    cout << "Twoja suma kart: " << suma << endl;
    wypisz_karty_b(gracz, numer_karty);
    cout << "Czy chcesz dobrać kartę? (t/n): ";
    cin >> wybor;

    if(wybor == 't' || wybor == 'T'){
        gracz[numer_karty] = losowa_karta_b();
        numer_karty++;
    }
    else if(wybor == 'n' || wybor == 'N'){
        break;
    }
    else{
        cout << "Niepoprawny wybór, spróbuj ponownie.\n";
    }

    if(suma > 21){
        cout << "Przegrałeś! Twoja suma kart przekroczyła 21.\n";
        return;
    }
}
int suma=0;
for(int i=0;i<numer_karty;i++){
    suma += gracz[i];

}
if(suma > 21){
    cout << "Przegrałeś! Twoja suma kart przekroczyła 21.\n";
    return;


}

komputer_karty[komputer_numer] = losowa_karta_b();
komputer_numer++;
komputer_karty[komputer_numer] = losowa_karta_b();
komputer_numer++;
ruch_komputera();
cout << "Karty komputera:\n";
wypisz_karty_b(komputer_karty, komputer_numer);

if(suma_komputera > 21){
    cout << "Wygrałeś! Komputer przekroczył 21.\n";
    return;
}
else if(suma>suma_komputera){
    cout << "Wygrałeś!\n";
    return;
}
else if(suma<suma_komputera){
    cout << "Przegrałeś!\n";
    return;
}
else{
    cout << "Remis!\n";
    return;
}

}

void wypisanie_k(){
    cout << "   1   2   3\n" <<  " +---+---+---+\n";
    for(int i=0;i<3;i++){
            cout <<i+1 << "| ";
            for(int j=0;j<3;j++){
                cout << tk[i][j] << " | ";
            }
            cout << endl << " +---+---+---+\n";
        }
}

void ai_kolko(){
    int x,y;

    do{
        x = rand()%3;
        y = rand()%3;

    }
    while(tk[x][y] != '-' );
    tk[x][y]='X';
}

void ai_krzyzyk(){
    int x,y;

    do{
        x = rand()%3;
        y = rand()%3;

    }
    while(tk[x][y] != '-' );
    tk[x][y]='O';
}

void gracz_kolko(){
    int x,y;
    wypisanie_k();
    do
    {
        cout << "Podaj współrzędne swojego ruchu (x,y): ";
        cin >> x >> y;
        if(x<1 || x>3 || y<1 || y>3)
            cout << "Podano niepoprawne współrzędne, spróbuj ponownie\n";
    }
    while(x<1 || x>3 || y<1 || y>3);

    if(tk[x-1][y-1] == '-'){
        tk[x-1][y-1] = 'O';
    
}
    else{
        cout << "To pole jest już zajęte, wybierz inne\n";
        gracz_kolko();
        
        
}

}

void gracz_krzyzyk(){
    int x,y;
    wypisanie_k();
    do
    {
        cout << "Podaj współrzędne swojego ruchu (x,y): ";
        cin >> x >> y;
        if(x<1 || x>3 || y<1 || y>3)
            cout << "Podano niepoprawne współrzędne, spróbuj ponownie\n";
    }
    while(x<1 || x>3 || y<1 || y>3);

    if(tk[x-1][y-1] == '-'){
        tk[x-1][y-1] = 'X';
    
}
    else{
        cout << "To pole jest już zajęte, wybierz inne\n";
        gracz_krzyzyk();
        
        
}

}

int wygrana(){
    int wolne_pole=0;
    for(int i=0;i<3;i++){
        if(tk[i][0] == tk[i][1] && tk[i][1] == tk[i][2] && tk[i][0] != '-'){
            cout << "Wygrywa " << tk[i][0] << endl;
            return 1;    
        }
    }
    for(int j=0;j<3;j++){
        if(tk[0][j] == tk[1][j] && tk[1][j] == tk[2][j] && tk[0][j] != '-'){
            cout << "Wygrywa " << tk[0][j] << endl;
            return 1;
        }
    }
    if(tk[0][0] == tk[1][1] && tk[1][1] == tk[2][2] && tk[0][0] != '-'){
            cout << "Wygrywa " << tk[0][0] << endl;
            return 1;  
        }
    
    if(tk[0][2] == tk[1][1] && tk[1][1] == tk[2][0] && tk[0][2] != '-'){
            cout << "Wygrywa " << tk[0][2] << endl;
            return 1;
            
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(tk[i][j] == '-'){
                wolne_pole++;
            }
        }
    }
    if(wolne_pole == 0){
        cout << "Remis!\n";
        return 2;
        
    }
    return 0;
}



void kolko(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tk[i][j] = '-';
        }
    }
    int wynik=0;
    while(wynik == 0){
        gracz_kolko();
        wynik = wygrana();
        if(wynik !=0) return;
        ai_kolko();
        wynik = wygrana();
        if(wynik !=0) return;
    }
    
}


void krzyzyk(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tk[i][j] = '-';
        }
    }
    int wynik=0;
    while(wynik == 0){
        ai_krzyzyk();
        wynik = wygrana();
        if(wynik !=0) return;
        gracz_krzyzyk();
        wynik = wygrana();
        if(wynik !=0) return;
    }
    
}


void kolko_i_krzyzyk(){
    int wybierz;
    cout << "Witaj w grze kółko i krzyżyk\n" << "Wybierz swój znak: 1. O 2. X\n";
    cin >> wybierz;
    switch (wybierz){
        case 1:
            cout << "Wybrałeś O\n";
            kolko();
            break;
        case 2:
            cout << "Wybrałeś X\n";
            krzyzyk();
            break;
        default:
            cout << "Brak takiej opcji- wybierz poprawną";
            break;
    }
    
    
}


int main(){
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int wybor;
    cout << " ==== Menu głowne ====\n";
    cout << "1. Blackjack\n";
    cout << "2. Kółko i krzyżyk\n";
    cout << "3. \n";
    cout << "0. Wyjdź\n";
    cout << endl << "Wykonane przez Pawła Owerczuk\n";
    cin >> wybor;
    
    switch(wybor){
        case 1:
            cout << "Wybraleś Blackjacka\n";
            blackjack();
            break;
        case 2:
            cout << "Wybrałeś Kółko i krzyżyk\n";
            kolko_i_krzyzyk();
            break;
        case 3:
            cout << "Wybrałeś grę w ";
            break;
        case 0:
            cout << "Wybrałeś wyjście\n";
            break;
        default:
            cout << "Brak takiej opcji- wybierz poprawną";
            break;
    }

    
}