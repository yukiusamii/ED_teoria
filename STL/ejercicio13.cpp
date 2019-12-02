#include <iostream>
#include <list>
using namespace std;

// La he hecho de enteros porque no me dejaba poner "list<T>::const_iterator"
// Tampoco he enteido muy bien el ejercicio, esto es lo más parecido a lo que he
// interpretado.
list<int> contenidoIteradores(const list<int> &lista,
                              const list<list<int>::iterator> &lista2) {
  list<int> listaRet;
  for (auto it = lista2.begin(); it != lista2.end(); ++it) {
    listaRet.push_back(*(*it));
  }
  return listaRet;
}

int main(int argc, char const *argv[]) {
  list<int> lista, lista3;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(5);
  lista.push_back(6);
  lista.push_back(7);
  lista.push_back(8);

  // Guardamos solo los pares
  list<list<int>::iterator> listaIt;
  for (auto it = lista.begin(); it != lista.end(); ++it) {
    if (*it % 2 == 0) {
      listaIt.push_back(it);
    }
  }

  // Recogemos la info y la mostramos
  lista3 = contenidoIteradores(lista, listaIt);
  for (auto it = lista3.begin(); it != lista3.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
