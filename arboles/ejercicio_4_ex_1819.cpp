#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "bintree.h"
using namespace std;

template <typename T>
void recorridos(const bintree<T>& arb) {
  cout << endl << "Tamaño: " << arb.size() << endl;
  cout << "preorden: ";
  for (auto it = arb.begin_preorder(); it != arb.end_preorder(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "postorden: ";
  for (auto it = arb.begin_postorder(); it != arb.end_postorder(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "inorden: ";
  for (auto it = arb.begin_inorder(); it != arb.end_inorder(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "niveles: ";
  for (auto it = arb.begin_level(); it != arb.end_level(); ++it)
    cout << *it << " ";
  cout << endl;
}

template <typename T>
list<T> lvlMasPoblado(const bintree<T>& arb) {
  vector<list<T>> historial;

  list<T> lista;
  lvlMasPobladoAux(arb, arb.root(), 0, historial);
  if (!historial.empty()) {
    /* code */

    lista = historial[0];
    for (size_t i = 0; i < historial.size(); i++) {
      if (historial[i].size() > lista.size()) {
        lista = historial[i];
      }
    }
  }
  return lista;
}

template <typename T>
void lvlMasPobladoAux(const bintree<T>& arb, typename bintree<T>::node yo,
                      int miLvl, vector<list<T>>& historial) {
  if (!yo.null()) {
    if (miLvl == historial.size()) {
      list<T> lista;
      lista.push_back(*yo);
      historial.push_back(lista);
    } else {
      historial[miLvl].push_back(*yo);
    }
    lvlMasPobladoAux(arb, yo.left(), miLvl + 1, historial);
    lvlMasPobladoAux(arb, yo.right(), miLvl + 1, historial);
  }
}

int main(int argc, char const* argv[]) {
  bintree<string> arb("A");
  // LVL 1
  arb.insert_left(arb.root(), "B");
  arb.insert_right(arb.root(), "E");

  // LVL 2
  arb.insert_left(arb.root().left(), "C");
  arb.insert_right(arb.root().left(), "D");
  arb.insert_left(arb.root().right(), "F");
  arb.insert_right(arb.root().right(), "J");

  // LVL 3
  arb.insert_left(arb.root().right().left(), "G");
  arb.insert_right(arb.root().right().left(), "I");

  // LVL 4
  arb.insert_left(arb.root().right().left().left(), "H");

  typename bintree<string>::node a = arb.root();
  typename bintree<string>::node b = arb.root().left();
  typename bintree<string>::node c = arb.root().left().left();
  typename bintree<string>::node g = arb.root().right().left().left();
  typename bintree<string>::node h = arb.root().right().left().left().left();
  cout << "******************\nArbol\n******************" << endl;
  recorridos(arb);

  cout << "\n\n***************** MAS POBLADO *****************" << endl;
  list<string> lista = lvlMasPoblado(arb);
  for (auto i = lista.begin(); i != lista.end(); i++) {
    cout << *i << "  ";
  }
  cout << endl;

  return 0;
}
