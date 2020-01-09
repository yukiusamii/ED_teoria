
#include <iostream>
#include <string>
#include "bintree.h"
using namespace std;

template <typename T>
void reflexion(bintree<T> arb, typename bintree<T>::node yo) {
  if (!yo.null()) {
    if (!(yo.left().null() && yo.right().null())) {
      typename bintree<T>::node aux;
      bintree<T> arbDr;
      arb.prune_right(yo, arbDr);

      bintree<T> arbIz;
      arb.prune_left(yo, arbIz);

      arb.insert_left(yo, arbDr);
      arb.insert_right(yo, arbIz);

      reflexion(arb, yo.left());
      reflexion(arb, yo.right());
    }
  }
}

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

  cout << "***********************\nAntes de la "
          "Reflexion\n***********************"
       << endl;
  recorridos(arb);

  reflexion(arb, arb.root());

  cout << "\n\n\n***********************\nTras la "
          "Refrexion\n***********************"
       << endl;
  recorridos(arb);
  return 0;
}
