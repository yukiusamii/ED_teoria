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
    cout << *aux << endl;
    count++;
  }

  return count;
}

void toPosOden(string pre, string in) {
  if (!pre.empty() && !in.empty()) {
    int posRaiz = in.find(pre[0]);

    string izIn = in.substr(0, posRaiz);
    string drIn = in.substr(posRaiz + 1, in.length());

    string izPre = pre.substr(1, izIn.length());
    string drPre = pre.substr(izIn.length() + 1, pre.length());
    cout << "Iz de " << pre[0] << " [" << izPre << "]" << endl;
    toPosOden(izPre, izIn);
    cout << "Dr de " << pre[0] << " [" << drPre << "]" << endl;
    toPosOden(drPre, drIn);
    cout << "pre: " << pre << endl;
    cout << pre[0] << endl;
  }
}

int main() {
  /**
   *        5
   *       /
   *      22
   *      /\
   *     25 125
   *
   * **/
  // bintree<int> arb(5);
  // arb.insert_left(arb.root(), 22);
  // bintree<int>::node n = arb.root().left();

  // arb.insert_left(n, 25);
  // arb.insert_right(n, 125);

  // cout << lvlNode(arb, arb.root().left().left()) << endl;
  // recorridos(arb);

  // bintree<int> arb2 = arb, aux;
  // if (arb2 == arb)
  //   cout << "Iguales" << endl;
  // else
  //   cout << "Distintos" << endl;

  // arb2.prune_right(arb2.root().left(), aux);
  // // *(arb.root().left().right()) = 131;
  // recorridos(arb2);

  // if (arb2 == arb)
  //   cout << "Iguales" << endl;
  // else
  //   cout << "Distintos" << endl;

  // recorridos(aux);

  // arb.insert_right(arb.root(), arb2);

  // recorridos(arb);
  // // arb.clear();
  // aux.assign_subtree(arb, arb.root().left());
  // recorridos(aux);
  // aux.replace_subtree(aux.root().right(), arb, arb.root());

  // recorridos(aux);
  // recorridos(arb);

  bintree<string> arb("G");
  auto lvl1 = arb.root();
  arb.insert_left(arb.root(), "E");
  arb.insert_left(arb.root().left(), "A");
  arb.insert_left(arb.root().left().left(), "I");
  arb.insert_right(arb.root().left().left(), "B");
  recorridos(arb);
  arb.insert_right(arb.root(), "M");
  arb.insert_left(arb.root().right(), "C");
  arb.insert_left(arb.root().right().left(), "L");
  arb.insert_right(arb.root().right().left().left(), "D");
  arb.insert_right(arb.root().right().left(), "F");
  arb.insert_right(arb.root().right(), "K");
  arb.insert_right(arb.root().right().right(), "J");
  arb.insert_left(arb.root().right().right().right(), "H");
  recorridos(arb);

  toPosOden("GEAIBMCLDFKJH", "IABEGLDCFMKHJ");
  cout << endl;
  return 0;
}
