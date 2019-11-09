#ifndef Ping_Pong_H
#define Ping_Pong_H

#include<iostream>
#include<string>

using namespace std;

void Ping_Pong(string username) {
    size_t saques;
    int number;

    cout << "\nBienvenido " << username << "\n\n";

    cout << "Empezando juego ...\n\n";

    cout << "Ingrese numero saques: ";
    cin >> saques; cin.ignore();

    cout << "\nIngrese numero inicial: ";
    cin >> number; cin.ignore();

    for(; saques > 0; saques--) {
        cout << "Computador 1 ==> " << number << endl;  

        number *= 2;
        cout << "\t\t\t\t\t" << number << " <== Computador 2\n"; 
    }

    char option;
    cout << "Desea volver a jugar [s/n]: ";
    cin >> option; cin.ignore();

    switch(option) {
        case 's':
            Ping_Pong(username);
            break;

        case 'n':
            break;

        default:
            cout << "No es una opcion válida\n";
    }
}

#endif //Ping_Pong_H
