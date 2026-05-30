#include <iostream>
using namespace std;
int main(){
    int wybor;
    cout << " ==== Menu głowne ====" << endl;
    cout << "1. Blackjack\n";
    cout << "2. Kółko i krzyżyk\n";
    cout << "0. Wyjdź\n";
    cout << endl << "Wykonane przez Pawła Owerczuk\n";
    cin >> wybor;
    
    switch(wybor){
        case 1:
            cout << "Wybraleś Blackjacka\n";
            break;
        case 2:
            cout << "Wybrałeś Kółko i krzyżyk\n";
            int t[3][3];
            break;
        case 0:
            cout << "Wybrałeś wyjście\n";
            break;
        default:
            cout << "Brak takiej opcji- wybierz poprawną";
            break;
    }

}