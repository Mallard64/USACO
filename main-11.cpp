#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string h;
    cin >> h;
    set<char> m;
    int total = 0;
    for (int i = 0; i < h.length(); i++) {
      m.clear();
      for (int j = i + 1; j < h.length(); j++) {
        if (m.find(h[j]) != m.end()) {
          m.erase(h[j]);
        }
        else if (h[j] != h[i]) {
          m.insert(h[j]);
        }
        else if (h[j] == h[i]) {
          total += m.size();
          break;
        }
      }
    }
    cout << int(total/2) << endl;
    
    return 0;
}
