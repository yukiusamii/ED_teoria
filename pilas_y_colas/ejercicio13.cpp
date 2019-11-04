
#include <cctype>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string toLowerCase(const string& cadena) {
  string cad = cadena;
  for (char& c : cad) {
    c = tolower(c);
  }

  return cad;
}

int vocales(const string& cadena) {
  string cad = toLowerCase(cadena);
  int vocales = 0;
  for (char c : cad) {
    if (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i') {
      vocales++;
    }
  }
  return vocales;
}

struct miString {
  string cadena;

  miString(const string& c) { cadena = c; }

  bool operator<(const miString& otra) const {
    bool result = false;

    if (vocales(cadena) < vocales(otra.cadena)) {
      result = true;
    } else if (vocales(cadena) == vocales(otra.cadena)) {
      result = toLowerCase(cadena) > toLowerCase(otra.cadena);
    }

    return result;
  };

  bool operator>(const miString& otra) const {
    bool result = false;
    if (vocales(cadena) > vocales(otra.cadena)) {
      result = true;
    }
    if (vocales(cadena) == vocales(otra.cadena)) {
      result = toLowerCase(cadena) > toLowerCase(otra.cadena);
    }

    return result;
  };
};

int main(int argc, char const* argv[]) {
  priority_queue<miString, vector<miString>, less<miString> > colaCadenas;

  colaCadenas.push(miString("AAA"));
  colaCadenas.push(miString("E"));
  colaCadenas.push(miString("AA"));
  colaCadenas.push(miString("OOOOOOOOO"));
  colaCadenas.push(miString("EEEEOO"));
  colaCadenas.push(miString("EEEEAA"));
  colaCadenas.push(miString("BBBBBB"));
  colaCadenas.push(miString("II"));

  while (!colaCadenas.empty()) {
    cout << colaCadenas.top().cadena << endl;
    colaCadenas.pop();
  }

  return 0;
}
