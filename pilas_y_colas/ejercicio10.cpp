
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool isPalindromo(string cadena) {
  queue<char> cola;
  stack<char> pila;
  for (char c : cadena) {
    cola.push(c);
    pila.push(c);
  }

  for (size_t i = 0; i < pila.size(); i++) {
    if (cola.front() != pila.top()) {
      return false;
    }
    cola.pop();
    pila.pop();
  }

  return true;
}

int main(int argc, char const *argv[]) {
  string cadena, result;
  cout << "Introduce una palabra o cadena" << endl;
  getline(cin, cadena);
  (isPalindromo(cadena)) ? result = "SÍ" : result = "NO";
  cout << "La palabra o cadena introducida " << result << " es palíndromo"
       << endl;
  return 0;
}
