#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  string entrada = ":)";
  map<pair<float, float>, int> coordenadas;
  cout << "Introduce 'F' si desea finalizar" << endl;
  do {
    int a;
    int b;
    cout << "Introduce una coordenada: " << endl;
    cout << "a: ";
    cin >> a;

    cout << "b:";
    cin >> b;

    pair<float, float> par(a, b);
    auto it = coordenadas.find(par);
    if (it != coordenadas.end()) {
      (*it).second++;
    } else {
      coordenadas.insert(pair<pair<float, float>, int>(par, 1));
    }
    getline(cin, entrada);
    cout << "F?: ";
    getline(cin, entrada);
  } while (entrada != "F");
  cout << "(a,b) ----> Aparición" << endl;
  for (auto it = coordenadas.begin(); it != coordenadas.end(); ++it) {
    cout << "(" << (*it).first.first << "," << (*it).first.second << ")"
         << " ----> " << (*it).second << endl;
  }

  return 0;
}