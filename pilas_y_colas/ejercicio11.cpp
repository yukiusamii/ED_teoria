
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Persona {
  string nombre;
  string apellidos;
  int prioridad;
  Persona(string n, string a, int p) {
    nombre = n;
    apellidos = a;
    prioridad = p;
  }
};

bool operator<(const Persona& p1, const Persona& p2) {
  return p1.prioridad < p2.prioridad;
}

int main(int argc, char const* argv[]) {
  priority_queue<Persona> colaPersonas;
  Persona p1("N", "N", -2);
  Persona p2("J", "J", 50);
  Persona p3("B", "B", 10);
  Persona p4("K", "K", 30);
  Persona p5("A", "A", 145);

  colaPersonas.push(p1);
  colaPersonas.push(p2);
  colaPersonas.push(p3);
  colaPersonas.push(p4);
  colaPersonas.push(p5);

  while (!colaPersonas.empty()) {
    cout << colaPersonas.top().nombre << " ---> "
         << colaPersonas.top().prioridad << endl;
    colaPersonas.pop();
  }

  return 0;
}
