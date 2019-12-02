#include <iostream>
#include <list>
using namespace std;

template <typename T>
void eliminarElemento(list<T> &l, T elemento) {
  auto it = l.begin();

  while (it != l.end()) {
    if (*it == elemento) {
      it = l.erase(it);
    } else {
      ++it;
    }
  }
}

int main(int argc, char const *argv[]) {
  list<int>::iterator it;
  list<int> lista;

  lista.push_back(20);
  lista.push_back(50);
  lista.push_back(60);
  lista.push_back(40);
  lista.push_back(20);
  lista.push_back(100);
  lista.push_back(30);
  lista.push_back(20);

  cout << "Antes de borrar: " << endl;
  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }

  cout << "***************" << endl;
  eliminarElemento(lista, 20);
  cout << "Despues de borrar el 20: " << endl;
  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
