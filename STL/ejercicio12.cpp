#include <iostream>
#include <list>
#include <queue>
using namespace std;
int main(int argc, char const *argv[]) {
  cout << "Holi 12" << endl;

  list<int>::iterator it, it2, it3, aux;
  list<int> lista, lista2, lista3;
  lista.push_back(4);
  lista.push_back(7);
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(30);
  lista.push_back(4);
  lista.push_back(7);
  lista.push_back(40);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(7);
  lista.push_back(800);

  lista2.push_back(4);
  lista2.push_back(7);
  lista2.push_back(800);
  lista2.push_back(800);
  queue<int> cola;

  for (it = lista2.begin(); it != lista2.end(); ++it) {
    cola.push(*it);
  }

  queue<int> cola2 = cola;
  bool contenida = false;
  for (it = lista.begin(); it != lista.end() && !contenida; ++it) {
    if (cola2.front() == *it) {
      cola2.pop();
    } else if (cola2.empty()) {
      contenida = true;
    } else {
      cola2 = cola;
    }
  }

  if (cola2.empty()) {
    cout << "Estáaaa!! OLE OLE!" << endl;
  } else {
    cout << "Pues vaya..." << endl;
  }
  /*
  cola2 = cola;
  cola2.pop();
  cola2.pop();

  cout << "***** COLA 1 *****" << endl;
  int size = cola.size();
  for (size_t i = 0; i < size; i++) {
    cout << cola.front() << endl;
    cola.pop();
  }

  cout << "***** COLA 2 *****" << endl;
  size = cola2.size();
  for (size_t i = 0; i < size; i++) {
    cout << cola2.front() << endl;
    cola2.pop();
  }
  */
  return 0;
}
