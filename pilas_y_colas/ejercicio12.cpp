
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

struct miString {
  string cadena;
  miString(const string& c) { cadena = c; }

  bool operator<(const miString& otra) const {
    bool result = false;
    // cout << "Hola" << endl;
    if (cadena.size() < otra.cadena.size()) {
      result = true;
    }
    if (cadena.size() == otra.cadena.size()) {
      result = toLowerCase(cadena) > toLowerCase(otra.cadena);
    }

    return result;
  };

  bool operator>(const miString& otra) const {
    bool result = false;
    if (cadena.size() > otra.cadena.size()) {
      result = true;
    }
    if (cadena.size() == otra.cadena.size()) {
      result = toLowerCase(cadena) > toLowerCase(otra.cadena);
    }

    return result;
  };
};

int main(int argc, char const* argv[]) {
  priority_queue<miString, vector<miString>, less<miString> > colaCadenas;

  colaCadenas.push(miString("123456789"));
  colaCadenas.push(miString("123"));
  colaCadenas.push(miString("1"));
  colaCadenas.push(miString("123456789AC"));
  colaCadenas.push(miString("123456789AD"));
  colaCadenas.push(miString("123456789A"));
  colaCadenas.push(miString("123456"));
  colaCadenas.push(miString("12"));
  colaCadenas.push(miString("123456789AB"));

  while (!colaCadenas.empty()) {
    cout << colaCadenas.top().cadena << endl;
    colaCadenas.pop();
  }

  return 0;
}
