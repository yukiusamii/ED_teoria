#include <iostream>
#include <list>
#include <queue>
using namespace std;

template <typename T>
bool contenida(const list<T> &lista, const list<T> &lista2) {
  queue<int> cola;
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    cola.push(*it);
  }

  queue<int> cola2 = cola;
  bool contenida = false;
  for (auto it = lista2.begin(); it != lista2.end() && !contenida; ++it) {
    if (cola2.empty()) {
      contenida = true;
    } else if (cola2.front() == *it) {
      cola2.pop();
    } else {
      cola2 = cola;
    }
  }

  if (cola2.empty()) {
    contenida = true;
  }

  return contenida;
}

template <typename T>
void printLista(const list<T> &lista) {
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
}
int main(int argc, char const *argv[]) {
  cout << "Holi 12" << endl;
  list<int> lista, lista2;
  lista2.push_back(4);
  lista2.push_back(7);
  lista2.push_back(1);
  lista2.push_back(2);
  lista2.push_back(30);
  lista2.push_back(4);
  lista2.push_back(7);
  lista2.push_back(40);
  lista2.push_back(3);
  lista2.push_back(4);
  lista2.push_back(7);
  lista2.push_back(800);

  lista.push_back(4);
  lista.push_back(7);
  lista.push_back(800);
  cout << "*******************" << endl;
  cout << "LISTA 1" << endl;
  printLista(lista);

  cout << "*******************" << endl;
  cout << "LISTA 2" << endl;
  printLista(lista2);

  cout << "*******************" << endl;
  cout << "¿Está LISTA 1 en LISTA 2?" << endl;
  cout << contenida(lista, lista2) << endl;
  return 0;
}
