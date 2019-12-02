#include <iostream>
#include <list>
#include <set>
using namespace std;
int main(int argc, char const *argv[]) {
  cout << "Holi 10" << endl;
  list<int>::iterator it, it2, it3, aux;
  list<int> lista, lista2, lista3;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(30);
  lista.push_back(40);

  lista2.push_back(3);
  lista2.push_back(4);
  lista2.push_back(7);
  lista2.push_back(800);

  it = lista.begin();
  it2 = lista2.begin();
  int totalSize = lista.size() + lista2.size();

  return 0;
}
