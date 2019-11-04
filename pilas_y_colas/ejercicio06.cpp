#include <assert.h>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <type_traits>
using namespace std;

// template <typename T, typename = typename std::enable_if<
//                           std::is_arithmetic<T>::value, T>::type>
// template <typename T>
int calculaPostfijo(const string& cadena) {
  stack<int> pila;
  int a, b, resul;
  for (char c : cadena) {
    if (c >= '0' && c <= '9') {
      pila.push((int)c);
    } else {
      a = pila.top();
      pila.pop();
      b = pila.top();
      pila.pop();

      switch (c) {
        case '*':
          resul = a * b;
          break;

        case '/':
          resul = a / b;
          break;

        case '+':
          resul = a + b;
          break;

        case '-':
          resul = a - b;
          break;

        case '^':
          resul = pow(a, b);
          break;
        default:
          throw "Caracter incorrecto";
          break;
      }
      pila.push(resul);
    }
  }
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
