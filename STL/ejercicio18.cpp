#include <iostream>
#include <vector>
using namespace std;

// Condición: posciones existentes
template <typename T>
void intelcalar(vector<T> &v, vector<pair<int, T>> pos) {
  for (size_t i = 0; i < pos.size(); i++) {
    v.insert(v.begin() + pos[i].first, pos[i].second);
  }
}

int main(int argc, char const *argv[]) {
  vector<int> v;
  vector<pair<int, int>> pos;
  v.push_back(5);
  v.push_back(10);
  v.push_back(20);
  v.push_back(60);
  v.push_back(250);
  cout << "******ANTES******" << endl;
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  pos.push_back(pair<int, int>(0, 1));
  pos.push_back(pair<int, int>(2, 113));
  pos.push_back(pair<int, int>(4, 661));
  pos.push_back(pair<int, int>(7, 999));
  intelcalar(v, pos);

  cout << "******DESPUES******" << endl;
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  return 0;
}
