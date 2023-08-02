#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int N, K, B;
    cin >> N >> K >> B;
    vector<int> broken_signals(B);
    for (int i = 0; i < B; ++i) {
        cin >> broken_signals[i];
    }
    sort(broken_signals.begin(), broken_signals.end());
    int min_broken_signals = 100000000;
    int current_window = 0;
    for (int i = 1; i <= N; ++i) {
        if (find(broken_signals.begin(), broken_signals.end(), i) != broken_signals.end()) {
            current_window++;
        }
        if (i > K) {
            if (find(broken_signals.begin(), broken_signals.end(), i - K) != broken_signals.end()) {
                current_window--;
            }
        }
        if (i >= K) {
            min_broken_signals = min(min_broken_signals, current_window);
        }
    }
    cout << min_broken_signals << endl;
    
    return 0;
}
