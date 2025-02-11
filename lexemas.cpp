#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <vector>

using namespace std;

string clasificaLexema(const string &lexema) {
  if (regex_match(lexema, regex("\\d+"))) {
    return "Número";
  } else if (regex_match(lexema, regex("[a-zA-Z]+"))) {
    return "Palabra";
  } else if (regex_match(lexema, regex("[a-zA-Z0-9]+"))) {
    return "Compuesta";
  } else {
    return "Desconocida";
  }
}

void procesaArchivo(const string &nombreArchivo) {
  ifstream Archivo(nombreArchivo);
  if (!Archivo) {
    cerr << "Error al leer el archivo" << endl;
    return;
  }

  string line;
  vector<map<string, string>> resultado;
  regex pattern("\\b\\w+\\b");
  int totalConEspacios = 0;
  int totalSinEspacios = 0;
  int totalLexemas = 0, totalPalabras = 0, totalNum = 0, totalCompuestas = 0;

  while (getline(Archivo, line)) {
    totalConEspacios += line.size();
    sregex_iterator it(line.begin(), line.end(), pattern);
    sregex_iterator end;
    while (it != end) {
      string lexema = (*it).str();
      totalSinEspacios += lexema.size();
      totalLexemas++;
      string type = clasificaLexema(lexema);
      if (type == "Número")
        totalNum++;
      else if (type == "Palabra")
        totalPalabras++;
      else if (type == "Compuesta")
        totalCompuestas++;
      map<string, string> lexemeData;
      lexemeData["lexema"] = lexema;
      lexemeData["tipo"] = type;
      resultado.push_back(lexemeData);
      ++it;
    }
  }
  Archivo.close();

  cout << "Total de caracteres (con espacios): " << totalConEspacios << endl;
  cout << "Total de caracteres (sin espacios): " << totalSinEspacios << endl;
  cout << "Total de lexemas: " << totalLexemas << endl;
  cout << "Total de palabras: " << totalPalabras << endl;
  cout << "Total de números: " << totalNum << endl;
  cout << "Total de combinadas: " << totalCompuestas << endl;

  cout << "\nLexemas clasificados:" << endl;
  for (const auto &entry : resultado) {
    cout << "Lexema: " << entry.at("lexema") << ", Tipo: " << entry.at("tipo")
         << endl;
  }
}

// Función principal
int main() {
  string nombreArchivo;
  cout << "Ingrese el nombre del archivo de texto: ";
  cin >> nombreArchivo;
  procesaArchivo(nombreArchivo);

  cout << "\nPresione Enter para salir...";
  cin.ignore();
  cin.get();
  return 0;
}