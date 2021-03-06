#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class Cola {
 private:
  stack<T> entrada;
  stack<T> salida;
  void volcarEntradaEnSalida() {
    while (!entrada.empty()) {
      salida.push(entrada.top());
      entrada.pop();
    }
  }

  void volcarSalidaEnEntrada() {
    while (!salida.empty()) {
      entrada.push(salida.top());
      salida.pop();
    }
  }

 public:
  // no hace falta constructor de copia por los elemento de lo que está formada
  // la clase ya tienen la asignación sobreescrita.

  void push(T elemento) { entrada.push(elemento); }

  void pop() {
    if (!entrada.empty()) {
      volcarEntradaEnSalida();
      salida.pop();
      volcarSalidaEnEntrada();
    } else {
      throw "Pop en cola vacía";
    }
  }

  T& front() {
    if (!entrada.empty()) {
      volcarEntradaEnSalida();
      T& elemento = salida.top();
      volcarSalidaEnEntrada();
      return elemento;
    } else {
      throw "Front en cola vacía";
    }
  }

  T& back() {
    if (!entrada.empty()) {
      return entrada.top();
    } else {
      throw "Back en cola vacía";
    }
  }

  bool empty() { return entrada.empty(); }

  int size() { return entrada.size(); }
};

int main(int argc, char const* argv[]) {
  try {
    queue<int> colaa;
    Cola<int> cola;

    colaa.push(0);
    colaa.push(5);
    colaa.push(4);
    colaa.push(3);
    cout << "back: " << colaa.back() << endl;
    cout << "Size antes del pop: " << colaa.size() << endl;
    colaa.pop();
    cout << "Size después del pop: " << colaa.size() << endl;
    while (!colaa.empty()) {
      cout << colaa.front();
      colaa.pop();
    }
    cout << "\n**********" << endl;

    cola.push(0);
    cola.push(5);
    cola.push(4);
    cola.push(3);
    cout << "back: " << cola.back() << endl;
    cout << "Size antes del pop: " << cola.size() << endl;
    cola.pop();
    cout << "Size después del pop: " << cola.size() << endl;
    while (!cola.empty()) {
      cout << cola.front();
      cola.pop();
    }
    cout << "\n**********" << endl;
  } catch (const char* msg) {
    cout << msg << endl;
  }
  return 0;
}
