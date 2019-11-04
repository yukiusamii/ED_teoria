
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
class Pila {
 private:
  queue<T> entrada;
  queue<T> salida;

 public:
  // no hace falta constructor de copia por los elemento de lo que está formada
  // la clase ya tienen la asignación sobreescrita.

  void push(T elemento) { entrada.push(elemento); }

  void pop() {
    if (!entrada.empty()) {
      int size = entrada.size();

      for (int i = 0; i < size - 1; i++) {
        salida.push(entrada.front());
        entrada.pop();
      }

      entrada.pop();

      while (!salida.empty()) {
        entrada.push(salida.front());
        salida.pop();
      }
    } else {
      throw "Pop en pila vacía";
    }
  }

  T& top() {
    if (!entrada.empty()) {
      return entrada.back();
    } else {
      throw "Top en pila vacía";
    }
  }

  bool empty() { return entrada.empty(); }

  int size() { return entrada.size(); }
};
int main(int argc, char const* argv[]) {
  try {
    Pila<int> pila;
    stack<int> pilaa;

    for (size_t i = 0; i < 10; i++) {
      pila.push(i);
    }

    cout << "Size de pila: " << pila.size() << endl;

    while (!pila.empty()) {
      cout << pila.top() << " ";
      pila.pop();
    }
    cout << "****************" << endl;

    for (size_t i = 0; i < 10; i++) {
      pilaa.push(i);
    }

    cout << "Size de pilaa: " << pilaa.size() << endl;
    ;

    while (!pilaa.empty()) {
      cout << pilaa.top() << " ";
      pilaa.pop();
    }
    cout << "****************" << endl;
  } catch (const char* msg) {
    cout << msg << endl;
  }
  return 0;
}
