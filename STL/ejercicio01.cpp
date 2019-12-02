#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<char, char> dicc;

string encripta(const dicc& map, const string& cadena) {
  dicc::const_iterator it;
  string cadenaE = "";
  for (size_t i = 0; i < cadena.length(); i++) {
    it = map.find(tolower(cadena[i]));
    if (it != map.end()) {
      cadenaE += (*it).second;
    } else {
      cadenaE += cadena[i];
    }
  }

  return cadenaE;
}

int main(int argc, char const* argv[]) {
  dicc encriptador;
  // El cifrado de César
  for (size_t i = 97; i <= 122; i++) {
    char valor = i + 3;
    if (valor <= 122) {
      encriptador[i] = valor;
    } else {
      encriptador[i] = valor % 122 + 96;
    }
  }

  cout << "Escribe la cadena a encriptar: " << endl;
  string cad;
  getline(cin, cad);

  cout << encripta(encriptador, cad) << endl;
  return 0;
}
