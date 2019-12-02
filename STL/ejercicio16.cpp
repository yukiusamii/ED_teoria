#include <iostream>
#include <list>
using namespace std;

// Condición: lista no vacía
template <typename T>
list<pair<T, int>> comprimir(const list<T>& lista) {
  list<pair<T, int>> lComprimida;
  pair<T, int> par;
  par.first = *lista.begin();
  par.second = 1;

  for (auto it = ++lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
    if (par.first == *it) {
      par.second++;
    } else {
      lComprimida.push_back(par);
      par.first = *it;
      par.second = 1;
    }
  }
  lComprimida.push_back(par);
  return lComprimida;
}
template <typename T>
list<T> descomprimir(const list<pair<T, int>>& lista) {
  list<T> lDes;
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    for (size_t i = 0; i < (*it).second; i++) {
      lDes.push_back((*it).first);
    }
  }
  return lDes;
}

int main(int argc, char const* argv[]) {
  list<pair<int, int>> lCom;
  list<int> l, lDes;

  l.push_back(1);
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(3);
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(5);
  cout << "*********Comp********" << endl;
  lCom = comprimir(l);
  for (auto it = lCom.begin(); it != lCom.end(); ++it) {
    cout << "(" << (*it).first << "," << (*it).second << ")" << endl;
  }
  cout << "********Descom*********" << endl;
  lDes = descomprimir(lCom);
  for (auto it = lDes.begin(); it != lDes.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
