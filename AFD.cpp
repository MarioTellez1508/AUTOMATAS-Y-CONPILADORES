#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class AFD {
private:
  int numEstados;
  int estadoInicial;
  set<int> estadosAceptacion;
  unordered_map<int, unordered_map<char, int>> transiciones;

public:
  AFD(int estados, int estadoInicial, const set<int> &estadosAceptacion)
      : numEstados(estados), estadoInicial(estadoInicial),
        estadosAceptacion(estadosAceptacion) {
    if (estadoInicial >= numEstados) {
      cerr << "Error: Estado inicial fuera de rango." << endl;
    }
  }

  void agregarTransicion(int estadoActual, char simbolo, int estadoSiguiente) {
    transiciones[estadoActual][simbolo] = estadoSiguiente;
  }

  bool aceptaCadena(const string &cadena) {
    int estadoActual = estadoInicial;

    for (char simbolo : cadena) {
      if (transiciones[estadoActual].find(simbolo) ==
          transiciones[estadoActual].end()) {
        return false;
      }
      estadoActual = transiciones[estadoActual][simbolo];
    }
    return estadosAceptacion.count(estadoActual) > 0;
  }
};

int main() {
  int numEstados, tamAlfabeto, numTransiciones, estadoInicial,
      numEstadosAceptacion, numCadenas;
  cin >> numEstados >> tamAlfabeto >> numTransiciones >> estadoInicial >>
      numEstadosAceptacion >> numCadenas;

  vector<char> alfabeto(tamAlfabeto);
  for (int i = 0; i < tamAlfabeto; i++) {
    cin >> alfabeto[i];
  }

  set<int> estadosAceptacion;
  for (int i = 0; i < numEstadosAceptacion; i++) {
    int estado;
    cin >> estado;
    estadosAceptacion.insert(estado);
  }

  AFD automata(numEstados, estadoInicial, estadosAceptacion);

  for (int i = 0; i < numTransiciones; i++) {
    int estadoActual, estadoSiguiente;
    char simbolo;
    cin >> estadoActual >> simbolo >> estadoSiguiente;
    automata.agregarTransicion(estadoActual, simbolo, estadoSiguiente);
  }

  for (int i = 0; i < numCadenas; i++) {
    string cadena;
    cin >> cadena;
    if (automata.aceptaCadena(cadena)) {
      cout << "ACEPTADA" << endl;
    } else {
      cout << "RECHAZADA" << endl;
    }
  }
  return 0;
}