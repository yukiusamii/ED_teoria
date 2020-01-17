#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void remplaza(list<int>& l, const list<int>& seq, const list<int>& reemp) {
  queue<int> cola;
  if (!l.empty() && !seq.empty() && !reemp.empty()) {
    /* code */

    for (auto i = seq.begin(); i != seq.end(); i++) {
      cola.push(*i);
    }

    queue<int> colaux = cola;
    list<int>::iterator desde;
    for (auto it = l.begin(); it != l.end(); it++) {
      if (colaux.size() == cola.size() && *it == colaux.front()) {
        desde = it;
      }

      if (colaux.empty()) {
        auto hasta = it;
        l.erase(desde, hasta);
        l.insert(it, reemp.begin(), reemp.end());
      }

      if (*it == colaux.front()) {
        colaux.pop();
      } else {
        colaux = cola;
      }
    }
  }
}

int main(int argc, char const* argv[]) {
  list<int> lista;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(5);
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(5);
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(5);

  list<int> seq;
  seq.push_back(4);
  seq.push_back(5);
  seq.push_back(1);

  list<int> reemp;
  reemp.push_back(9);
  reemp.push_back(7);
  reemp.push_back(3);
  reemp.push_back(5);

  cout << "********************************" << endl;
  for (auto i = lista.begin(); i != lista.end(); i++) {
    cout << *i << "  ";
  }
  cout << endl;
  remplaza(lista, seq, reemp);
  cout << "********************************" << endl;
  for (auto i = lista.begin(); i != lista.end(); i++) {
    cout << *i << "  ";
  }
  cout << endl;

  return 0;
}
