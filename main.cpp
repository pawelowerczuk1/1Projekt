#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char tk[3][3] = { 
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
     };
void blackjack(){

}

void wypisanie(){
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
    wypisanie();
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
    wypisanie();
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