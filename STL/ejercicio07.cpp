#include <iostream>
#include <list>
#include <set>
using namespace std;

template <typename T>
void eliminarDuplicados(list<T> &l) {
  auto it = l.begin();
  set<T> bolsa;
  while (it != l.end()) {
    if (bolsa.find((*it)) == bolsa.end()) {
      bolsa.insert(*it);
      ++it;
    } else {
      it = l.erase(it);
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
  lista.push_back(100);
  lista.push_back(30);
  lista.push_back(20);
  lista.push_back(10);
  lista.push_back(10);
  lista.push_back(10);
  lista.push_back(10);
  lista.push_back(10);

  cout << "Antes de borrar: " << endl;
  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }

  cout << "***************" << endl;
  eliminarDuplicados(lista);
  cout << "Despues de borrar duplicados: " << endl;
  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
