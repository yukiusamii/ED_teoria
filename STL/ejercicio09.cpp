#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <typename T>
void listaInvertida(list<T> &lista) {
  int size = lista.size();
  auto itFront = lista.begin();
  // Para recorrer desde el final
  auto itBack = lista.rbegin();

  for (size_t i = 0; i < size / 2; i++) {
    int aux = *itFront;
    *itFront = *itBack;
    *itBack = aux;
    ++itFront;
    ++itBack;
  }
}
int main(int argc, char const *argv[]) {
  list<int>::iterator it;
  list<int> lista;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(5);
  lista.push_back(6);
  lista.push_back(7);
  lista.push_back(8);
  cout << "Antes de invertir: " << endl;
  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
  cout << "******************" << endl;
  cout << "Despues de invertir: " << endl;
  listaInvertida(lista);
  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
