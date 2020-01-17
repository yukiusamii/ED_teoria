#include <iostream>
#include <string>
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
int lvlNode(const bintree<T>& arb, typename bintree<T>::node nodo) {
  int count = -1;
  typename bintree<T>::node aux = nodo;

  for (aux; !aux.null(); aux = aux.parent()) {
    // cout << *aux << endl;
    count++;
  }

  return count;
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
  cout << "\n\nNODO ---> Nivel" << endl;
  cout << *a << " ---> " << lvlNode(arb, a) << endl;
  cout << *b << " ---> " << lvlNode(arb, b) << endl;
  cout << *c << " ---> " << lvlNode(arb, c) << endl;
  cout << *g << " ---> " << lvlNode(arb, g) << endl;
  cout << *h << " ---> " << lvlNode(arb, h) << endl;

  return 0;
}
