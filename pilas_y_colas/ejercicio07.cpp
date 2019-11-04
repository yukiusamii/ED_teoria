#include <assert.h>
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void insertarEnPila(stack<T>& pila, T elemento, int pos) {
  if (pila.empty() && pos == 0) {
    pila.push(elemento);
  } else if (pos == pila.size()) {
    pila.push(elemento);
  } else {
    assert(pos >= 0 && pos <= pila.size());

    stack<T> aux;
    int size = pila.size();

    for (int i = 0; i < size; i++) {
      if (pos == i) {
        aux.push(elemento);
      }

      aux.push(pila.top());
      pila.pop();
    }

    while (!aux.empty()) {
      pila.push(aux.top());
      aux.pop();
    }
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

  insertarEnPila(pila, 999, 0);

  for (size_t i = 0; i < 5; i++) {
    pila.push(i);
  }

  insertarEnPila(pila, 777, 3);
  insertarEnPila(pila, 888, 7);

  printPila(pila);

  return 0;
}
