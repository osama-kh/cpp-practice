#include<iostream>
#include"Game.h"



int main() {// to play the game system
    int no;
    cout << "Enter number of cards you want to play with:" << endl;
    cin >> no;  
    Game m(no);  
    m.Run(); 
    return 0; 
}