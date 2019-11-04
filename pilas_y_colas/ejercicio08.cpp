#include <assert.h>
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void insertarEnCola(queue<T>& cola, T elemento, int pos) {
  if (cola.empty() && pos == 0) {
    cola.push(elemento);
  } else if (pos == cola.size()) {
    cola.push(elemento);
  } else {
    assert(pos >= 0 && pos <= cola.size());

    queue<T> aux;
    int size = cola.size();

    for (int i = 0; i < size; i++) {
      if (pos == i) {
        aux.push(elemento);
      }

      aux.push(cola.front());
      cola.pop();
    }

    while (!aux.empty()) {
      cola.push(aux.front());
      aux.pop();
    }
  }
}

template <typename T>
void printCola(queue<T> cola) {
  queue<T> colaImp(cola);
  while (!colaImp.empty()) {
    cout << colaImp.front() << endl;
    colaImp.pop();
  }
}

int main(int argc, char const* argv[]) {
  queue<int> cola;

  insertarEnCola(cola, 999, 0);

  for (size_t i = 0; i < 5; i++) {
    cola.push(i);
  }

  insertarEnCola(cola, 777, 3);
  insertarEnCola(cola, 888, 7);

  printCola(cola);

  return 0;
}
