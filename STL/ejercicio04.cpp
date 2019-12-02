#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, int> dicc;
typedef multimap<int, string> multiDicc;

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

multiDicc apareceXVeces(dicc cont) {
  multiDicc inversCont;
  dicc::iterator it;
  // Le damos la vuelta a la clave, valor
  for (it = cont.begin(); it != cont.end(); ++it) {
    inversCont.insert(pair<int, string>((*it).second, (*it).first));
  }
  return inversCont;
}

int main(int argc, char const *argv[]) {
  // Primera parte
  cout << "Escribe el nombre del fichero: " << endl;
  string f;
  getline(cin, f);
  dicc cont;
  cont = contadorPalabras(f);
  dicc::iterator it;
  for (it = cont.begin(); it != cont.end(); ++it) {
    cout << (*it).first << ": " << (*it).second << endl;
  }

  // Segunda parte
  multiDicc inversCont;
  inversCont = apareceXVeces(cont);

  cout << "***************************" << endl;
  cout << "Introduce un número: " << endl;
  int n;
  cin >> n;

  multiDicc::iterator multIt;
  multIt = inversCont.find(n);

  cout << "Las plabras que aparecen " << n << " veces son: " << endl;
  while (multIt != inversCont.end()) {
    cout << (*multIt).second << endl;
    ++multIt;
    if ((*multIt).first != n) {
      multIt = inversCont.end();
    }
  }
  return 0;
}
