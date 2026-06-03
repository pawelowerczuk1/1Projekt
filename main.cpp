#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char t[3][3] = { 
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
                cout << t[i][j] << " | ";
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
    while(t[x][y] != '-' );
    t[x][y]='X';
}

void kolko(){
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

    if(t[x-1][y-1] == '-'){
        t[x-1][y-1] = 'O';
    
}
    else{
        cout << "To pole jest już zajęte, wybierz inne\n";
        kolko();
        
        
}
}

void krzyzyk(){
    
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