#include <iostream>
#include <list>
#include <set>
using namespace std;
int main(int argc, char const *argv[]) {
  cout << "Holi 6" << endl;
  list<int> lista;
  set<int> bolsa;
  bolsa.insert(1);
  bolsa.insert(1);
  bolsa.insert(5);
  bolsa.insert(10);
  set<int>::iterator its;

  for (its = bolsa.begin(); its != bolsa.end(); ++its) {
    cout << *its << endl;
  }
  if (bolsa.find(60) != bolsa.end()) {
    cout << "HUARRAAAAY!!" << endl;
  } else {
    cout << "OOOH" << endl;
  }
  list<int>::iterator it, aux;
  lista.push_back(20);
  lista.push_back(50);
  lista.push_back(60);
  lista.push_back(40);
  lista.push_back(20);
  lista.push_back(100);
  lista.push_back(30);
  lista.push_back(20);
  return 0;
}
