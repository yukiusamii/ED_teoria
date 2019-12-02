#include <iostream>
#include <list>
#include <set>
using namespace std;

template <typename T>
list<T> mezclar(const list<T> &lista, const list<T> &lista2) {
  // Para ordenar el contenido
  multiset<T> multiBolsa;
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    multiBolsa.insert(*it);
  }
  for (auto it = lista2.begin(); it != lista2.end(); ++it) {
    multiBolsa.insert(*it);
  }
  list<T> listaRet;

  for (auto it = multiBolsa.begin(); it != multiBolsa.end(); ++it) {
    listaRet.push_back(*it);
  }
  return listaRet;
}

template <typename T>
void printLista(const list<T> &lista) {
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
}

int main(int argc, char const *argv[]) {
  list<int> lista, lista2, lista3;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(30);
  lista.push_back(40);

  lista2.push_back(3);
  lista2.push_back(4);
  lista2.push_back(7);
  lista2.push_back(800);

  lista3 = mezclar(lista, lista2);

  cout << "*********************" << endl;
  cout << "Lista 1" << endl;
  printLista(lista);

  cout << "*********************" << endl;
  cout << "Lista 2" << endl;
  printLista(lista2);

  cout << "*********************" << endl;
  cout << "Lista 1 + lista 2" << endl;
  printLista(lista3);

  return 0;
}
