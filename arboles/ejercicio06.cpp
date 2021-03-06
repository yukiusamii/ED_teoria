

#include <iostream>
#include <string>
#include <vector>
#include "bintree.h"
using namespace std;

template <typename T>
int densidad(const bintree<T>& arb, typename bintree<T>::node yo,
             int miProf = 0) {
  static vector<int> produndidades;

  if (!yo.null()) {
    // Soy hoja si no tengo ni hijo a la derecha ni a la izquierda

    if (yo.left().null() && yo.right().null()) {
      produndidades.push_back(miProf);

      if (yo.parent().null()) {
        return 0;
      }

    } else {
      densidad(arb, yo.left(), miProf + 1);
      densidad(arb, yo.right(), miProf + 1);

      if (yo.parent().null()) {
        int densidad = 0;
        for (size_t i = 0; i < produndidades.size(); i++) {
          densidad += produndidades[i];
        }
        return densidad;
      }
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

  cout << "******************\nArbol\n******************" << endl;
  recorridos(arb);
  int den = densidad(arb, arb.root());
  cout << "\n\n******************\nDensidad: " << den << "\n******************"
       << endl;
  return 0;
}
