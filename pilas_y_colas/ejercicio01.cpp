#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void sustituyeXPorY(stack<T>& p, T x, T y) {
  stack<T> auxST;
  while (!p.empty()) {
    T aux = p.top();
    p.pop();
    if (aux == x) {
      aux = y;
      auxST.push(aux);
    } else {
      auxST.push(aux);
    }
  }
  while (!auxST.empty()) {
    p.push(auxST.top());
    auxST.pop();
  }
}

template <typename T>
void printPila(stack<T> pila) {
  stack<T> pilaImp(pila);
  while (!pilaImp.empty()) {
    cout << pilaImp.top() << endl;
    pilaImp.pop();
  }
}

int main(int argc, char const* argv[]) {
  stack<int> pila;
  pila.push(0);
  pila.push(2);
  pila.push(2);
  pila.push(3);
  pila.push(0);
  pila.push(6);
  pila.push(7);
  pila.push(9);

  printPila(pila);
  cout << "**************" << endl;
  sustituyeXPorY(pila, 0, 99);

  printPila(pila);
  return 0;
}
