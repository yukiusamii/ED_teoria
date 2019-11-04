#include <iostream>
#include <stack>

using namespace std;

bool parentesisCorrectos(string cadena) {
  int apertura = 0;
  int cierre = 0;
  for (char c : cadena) {
    if (c == '(') {
      apertura++;
    }
    if (c == ')') {
      cierre++;
    }
  }

  return apertura == cierre;
}

int main(int argc, char const *argv[]) {
  string cadena, resul;

  cout << "Escribe una expesión con paréntesis;" << endl;

  getline(cin, cadena);

  (parentesisCorrectos(cadena)) ? resul = "Correcta" : resul = "Incorrecta";
  cout << "La configuración de parénteis es " << resul << endl;

  return 0;
}
