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
double calculaPostfijo(const string& cadena) {
  stack<double> pila;
  double a, b, resul;
  for (char c : cadena) {
    if (c >= '0' && c <= '9') {
      pila.push((int)c - 48);
    } else {
      b = pila.top();
      pila.pop();

      a = pila.top();
      pila.pop();
      // cout << a << c << b << endl;
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

double calculaPostfijoVariables(const string& cadena, double variables[]) {
  stack<double> pila;
  double a, b, resul;
  for (char c : cadena) {
    if (c >= 'a' && c <= 'z') {
      pila.push(variables[c - 'a']);
    } else {
      b = pila.top();
      pila.pop();

      a = pila.top();
      pila.pop();
      // cout << a << c << b << endl;
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
  cout << "53^2*2/9+ = " << calculaPostfijo("53^2*2/9+") << endl;

  cout << "26+35*+9* = " << calculaPostfijo("26+35*+9*") << endl;

  double v1[] = {5, 3, 2, 2, 9};

  cout << "ab^c*d/e+ = " << calculaPostfijoVariables("ab^c*d/e+", v1) << endl;
  ;

  double v2[] = {2, 6, 3, 5, 9};

  cout << "ab+cd*+e* = " << calculaPostfijoVariables("ab+cd*+e*", v2) << endl;

  double v3[] = {12, 4, 7, 5, 2};
  cout << "abcde+*+ = " << calculaPostfijoVariables("abcde+*+", v3) << endl;
  ;

  cout << "abcde+*+- = " << calculaPostfijoVariables("abcde+*+-", v3) << endl;
  ;
  return 0;
}
