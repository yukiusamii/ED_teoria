#include <iostream>
#include <list>
using namespace std;
template <typename T>
list<T> listaInvertida(const list<T> &l) {
  auto it = l.rbegin();
  list<T> li;
  for (it = l.rbegin(); it != l.rend(); ++it) {
    li.push_back(*it);
  }
  return li;
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
  cout << "Copia invertida: " << endl;
  list<int> listaInv = listaInvertida(lista);
  for (it = listaInv.begin(); it != listaInv.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
