#include <iostream>
#include <list>
using namespace std;
void addX(list<int> &lista, int x) {
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    if (*it == x) {
      auto aux = it;
      aux++;
      if (aux == lista.end()) {
        lista.push_back(*it - 1);
      } else {
        lista.insert(aux, *it - 1);
      }
    }
  }
}

template <typename T>
void printLista(const list<T> &lista) {
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
}
int main(int argc, char const *argv[]) {
  cout << "Holi 11" << endl;
  list<int> lista;
  list<int>::iterator it, aux;
  lista.push_back(20);
  lista.push_back(50);
  lista.push_back(60);
  lista.push_back(40);
  lista.push_back(20);
  lista.push_back(100);
  lista.push_back(30);
  lista.push_back(20);
  int x = 20;

  cout << "******************" << endl;
  cout << "Antes" << endl;
  printLista(lista);

  cout << "******************" << endl;
  cout << "Despues" << endl;
  addX(lista, x);
  printLista(lista);
  return 0;
}
