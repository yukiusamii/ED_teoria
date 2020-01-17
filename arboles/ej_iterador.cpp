#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class contenedor {
 private:
  vector<list<T>> datos;

 public:
  contenedor();

  class iterator {
   private:
    list<T>::iterato itElm;
    vector<list<T>>::iterator it;
    vector<list<T>>* pDatos;

   public:
    iterator(){};

    iterator& operator++() {
      ++it;
      return *this;
    }

    iterator& operator--() {
      --it;
      return *this;
    }

    T& operator*() { return *it; }

    friend class contenedor;
  };

  iterator begin() {
    iterator i;
    i.it = datos.begin();
    i.pDatos = &datos;
  }

  iterator end() {
    iterator i;
    i.it = datos.end();
    i.pDatos = &datos;
  }
};

template <typename T>
contenedor<T>::contenedor<T>(/* args */) {}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
