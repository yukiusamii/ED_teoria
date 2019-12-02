#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, int> dicc;

string toLowerCase(const string cadena) {
  string cad = cadena;
  for (char &c : cad) {
    c = tolower(c);
  }

  return cad;
}

dicc contadorPalabras(string nombreF) {
  dicc cont;
  ifstream f(nombreF);
  if (!f) {
    cout << "No existe el fichero " << nombreF << endl;
  }
  string palabra;
  dicc::iterator it;
  while (!f.eof()) {
    f >> palabra;
    palabra = toLowerCase(palabra);
    it = cont.find(palabra);
    if (it != cont.end()) {
      (*it).second++;
    } else {
      cont[palabra] = 1;
    }
  }
  return cont;
}

int main(int argc, char const *argv[]) {
  cout << "Escribe el nombre del fichero: " << endl;
  string f;
  getline(cin, f);
  dicc cont;
  cont = contadorPalabras(f);
  dicc::iterator it;
  for (it = cont.begin(); it != cont.end(); ++it) {
    cout << (*it).first << ": " << (*it).second << endl;
  }

  return 0;
}
