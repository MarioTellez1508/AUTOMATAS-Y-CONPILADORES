#include <cctype>
#include <iostream>
#include <string>
std::string clasificar(const std::string &cadena) {
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
    return "Numero entero";
  } else if (esPalabra) {
    return "Palabra";
  } else {
    return "Compuesta";
  }
}
int main() {
  std::string entradas[] = {"5896475", "Atotonilco", "contador1", "mario@"};
  for (const auto &entrada : entradas) {
    std::cout << entrada << " -> " << clasificar(entrada) << std::endl;
  }
  return 0;
}
