#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
string clasificar(const string& cadena) {
    bool esNumero = true;
    bool esPalabra = true;
    for (char c : cadena) {
        if (!isdigit(c)) {
            esNumero = false;
        }
        if (!isalpha(c)) {
            esPalabra = false;
        }
    }
    if (esNumero) {
        return "entero";
    } else if (esPalabra) {
        return "palabra";
    } else {
        return "compuesta";
    }
}
int main() {
    string input;
    while (true) {
        cout << "Introduce una cadena de caracteres (o 'salir' para terminar): ";
        getline(cin, input);
        if (input == "salir") {
            break;  // Sale del bucle si se ingresa 'salir'
        }
        istringstream stream(input);
        string palabra;
        int conteoEntero = 0, conteoPalabra = 0, conteoCompuesta = 0;
        while (stream >> palabra) {
            string tipo = clasificar(palabra);
            if (tipo == "entero") {
                conteoEntero++;
            } else if (tipo == "palabra") {
                conteoPalabra++;
            } else {
                conteoCompuesta++;
            }
        }
        if (conteoEntero > 0) {
            cout << conteoEntero << " - entero";
        }
        if (conteoPalabra > 0) {
            cout << ", " << conteoPalabra << " - palabra";
        }
        if (conteoCompuesta > 0) {
            cout << ", " << conteoCompuesta << " - compuesta";
        }
        cout << endl;
    }
    return 0;
}



