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
void nodoProfundo(const bintree<T>& arb, typename bintree<T>::node yo,
                  int miProf) {
  static int maxProf = 0;
  static typename bintree<T>::node nodoProf;

  if (!yo.null()) {
    // Soy hoja si no tengo ni hijo a la derecha ni a la izquierda

    if (yo.left().null() && yo.right().null()) {
      if (miProf > maxProf) {
        maxProf = miProf;
        nodoProf = yo;
      }
      // SI soy raiz
      if (yo.parent().null()) {
        cout << *yo << " " << maxProf << endl;
      }

      // cout << miProf << " HOJA " << *yo << endl;

    } else {
      nodoProfundo(arb, yo.left(), miProf + 1);
      nodoProfundo(arb, yo.right(), miProf + 1);

      if (yo.parent().null()) {
        cout << *nodoProf << " " << maxProf << endl;
      }
    }
  }
}

int main(int argc, char const* argv[]) {
  /**
   *
         A
       /
  */

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

  cout << "****************************\nEl Albol en distintos "
          "recorridos\n****************************"
       << endl;

  recorridos(arb);
  cout << "\n\n****************************\nNodo más profundo y su "
          "profundidad\n****************************"
       << endl;
  nodoProfundo(arb, arb.root(), 0);

  return 0;
}
