#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  cout << "Holi 9" << endl;
  list<int>::iterator it, itFront;
  list<int>::reverse_iterator itBack;
  list<int> lista;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(5);
  lista.push_back(6);
  lista.push_back(7);
  lista.push_back(8);

  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
  cout << "********************" << endl;

  int size = lista.size();
  itFront = lista.begin();
  itBack = lista.rbegin();
  // cout << *itBack << endl;
  for (size_t i = 0; i < size / 2; i++) {
    int aux = *itFront;
    *itFront = *itBack;
    *itBack = aux;
    ++itFront;
    ++itBack;
  }

  for (it = lista.begin(); it != lista.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
