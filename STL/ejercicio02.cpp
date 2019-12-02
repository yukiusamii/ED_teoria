#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map<char, char> dicc;

string desencripta(const dicc& map, const string& cadena) {
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
  dicc desdesencriptador;
  // El cifrado de César a la inversa
  for (size_t i = 97; i <= 122; i++) {
    char valor = i - 3;
    if (valor >= 97) {
      desdesencriptador[i] = valor;
    } else {
      desdesencriptador[i] = valor % 122 + 96;
    }
  }
  cout << "Escribe la cadena a desicriptar: " << endl;
  string cad;
  getline(cin, cad);
  cout << desencripta(desdesencriptador, cad) << endl;
  return 0;
}
