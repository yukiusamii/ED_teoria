
#include <iostream>
#include <stack>
#include <string>
#include "bintree.h"
using namespace std;

template <typename T>
void recorridos(const bintree<T>& arb) {
  cout << endl << "Tamaño: " << arb.size() << endl;
  cout << "preorden: ";
  for (auto it = arb.begin_preorder(); it != arb.end_preorder(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "postorden: ";
  for (auto it = arb.begin_postorder(); it != arb.end_postorder(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "inorden: ";
  for (auto it = arb.begin_inorder(); it != arb.end_inorder(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "niveles: ";
  for (auto it = arb.begin_level(); it != arb.end_level(); ++it)
    cout << *it << " ";
  cout << endl;
}

bintree<char> arbolExpPostFija(string expresion) {
  stack<bintree<char>> pila;
  for (char c : expresion) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
      bintree<char> operando(c);
      operando.insert_right(operando.root(), pila.top());
      pila.pop();

      operando.insert_left(operando.root(), pila.top());
      pila.pop();

      pila.push(operando);
    } else {
      pila.push(c);
    }
  }
  return pila.top();
}

int main(int argc, char const* argv[]) {
  bintree<char> expresion;
  string ex = "";
  cout << "************* Expresione matemática *************" << endl;
  cout << "Se consideran válidos los siguientes caracteres: A-Z y los simbolos "
          "+ |- | * | /"
       << endl;
  cout << "*************************************************" << endl;
  cout << "Escribe una expresión matemática en postOrden: ";
  getline(cin, ex);
  cout << "\n\n************* Arbol en base a la expresión *************"
       << endl;
  expresion = arbolExpPostFija(ex);
  recorridos(expresion);
  return 0;
}
