#include <iostream>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[]) {
  cout << "Holi 16" << endl;
  unordered_map<int, int> map;

  map.insert(pair<int, int>(5, 2));
  map.insert(pair<int, int>(1, 3));
  map.insert(pair<int, int>(7, 5));

  unordered_map<int, int>::iterator it;
  for (it = map.begin(); it != map.end(); ++it) {
    cout << (*it).first << endl;
  }
  return 0;
}
