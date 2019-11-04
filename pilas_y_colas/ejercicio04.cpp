#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Cola {
 private:
  stack<T> entrada;
  stack<T> salida;

 public:
  // Contructor por defecto
  Cola<T>();
  // no hace falta constructor de copia por los elemento de lo que está formada
  // la clase ya tienen la asignación sobreescrita.

  push(T elemento) { entrada.push(elemento); }

  pop() {}

  front() {}

  back() {}
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
