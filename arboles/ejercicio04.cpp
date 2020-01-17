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

void toPosOrden(string pre, string in) {
  if (!pre.empty() && !in.empty()) {
    int posRaiz = in.find(pre[0]);

    string izIn = in.substr(0, posRaiz);
    string drIn = in.substr(posRaiz + 1, in.length());

    string izPre = pre.substr(1, izIn.length());
    string drPre = pre.substr(izIn.length() + 1, pre.length());

    toPosOrden(izPre, izIn);
    toPosOrden(drPre, drIn);

    cout << pre[0] << " ";
  }
}
int main(int argc, char const* argv[]) {
  /* code */

  // Creación del arbol
  // LVL 0
  bintree<string> arb("G");

  // LVL 1
  arb.insert_left(arb.root(), "E");
  arb.insert_right(arb.root(), "M");

  // LVL 2
  arb.insert_left(arb.root().left(), "A");
  arb.insert_left(arb.root().right(), "C");
  arb.insert_right(arb.root().right(), "K");

  // LVL 3
  arb.insert_left(arb.root().left().left(), "I");
  arb.insert_right(arb.root().left().left(), "B");
  arb.insert_left(arb.root().right().left(), "L");
  arb.insert_right(arb.root().right().left(), "F");
  arb.insert_right(arb.root().right().right(), "J");

  // LVL 4
  arb.insert_right(arb.root().right().left().left(), "D");
  arb.insert_left(arb.root().right().right().right(), "H");
  cout << "******************\nArbol\n******************" << endl;
  recorridos(arb);

  // Recorrido en PostOrden
  // 4

  cout << "\n\n******************\nRecorrido en postOrden Según preOrden e "
          "inOrden\n******************"
       << endl;
  toPosOrden("GEAIBMCLDFKJH", "IABEGLDCFMKHJ");
  cout << endl;
  return 0;
}
