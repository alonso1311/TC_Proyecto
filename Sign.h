#include"User.h"
#include"Ping_Pong.h"

#include<vector>
#include<algorithm>

using namespace std;

vector<User> users;
int contador_errores = 0;

void print() {
    for(auto i : users) {
        cout << "Nombre: " << i.Nombre;
        cout << "\nApellido: " << i.Apellido;
        cout << "\nUsername: " << i.Username;
        cout << "\nPassword: " << i.Password;
        cout << endl << endl;
    }
}

void sort_users() {
    sort(users.begin(), users.end(), [](User u1, User u2) {return u1.Username < u2.Username;});
}

//----------------------------SIGN IN----------------------
//
bool Check_Log_in(string username, string password) {
    auto comprobar = [username, password](User u) {
        if(username == u.Username && password == u.Password) 
            return true;
        return false;
    }; 

    auto it = find_if(users.begin(), users.end(), comprobar);

    if(it != users.end())
        return false;

    else
        return true;
}

void Sign_in() {
    cout << "\n\n-----------Sign in--------------\n";

    string temp_username, temp_password;

    cout << "Ingrese usuario: ";
    cin >> temp_username; cin.ignore();

    cout << "\nIngrese contrasena: ";
    cin >> temp_password; cin.ignore();

    if(Check_Log_in(temp_username, temp_password) == false)
        Ping_Pong(temp_username);

    else {
        contador_errores++;
        cerr << "Usuario y/o contrasena incorrecta\n";
        cout << "N° errores: " << contador_errores;
        Sign_in();
    }
}

//-----------------SIGN UP-------------------------------

bool Comprobar_Usuario(string username) {
    auto comprobar = [username](User u) {
        if(username == u.Username) 
            return true;
        return false;
    }; 

    auto it = find_if(users.begin(), users.end(), comprobar);

    if(it != users.end())
        return false;

    else
        return true;
}

void Sign_up() {
    cout << "\n\n----------Sign up-----------\n";
    User user;
    string temp_username;

    cout << "Ingrese nombre: ";
    getline(cin, user.Nombre, '\n');
    
    cout << "\nIngrese apellido: ";
    getline(cin, user.Apellido, '\n');

    do {
        cout << "\nIngrese nombre de usuario: ";
        cin >> temp_username; cin.ignore();
    } while(Comprobar_Usuario(temp_username) == false);

    user.Username = temp_username;

    cout << "\nIngrese su contrasena: ";
    cin >> user.Password; cin.ignore();

    users.push_back(user);
    sort_users(); 
    
    Ping_Pong(user.Username);
}


//------------------------SIGN-------------------------------

void Sign() {
    cout << "-------WELCOME!---------\n\n";
    char input; 

    cout << "[1] Sign in\n";
    cout << "[2] Sign up\n";
    cout << "[E] Exit\n\n";

    cout << "Ingrese opcion: ";
    cin >> input;
    cin.ignore();

    switch (input) {
        case '1':
            Sign_in();
            break;

        case '2':
            Sign_up();
            break;

        case 'E':
            break;

        default:
            cout << "No es una opcion valida\n";
            Sign();
            break;
    }
}


