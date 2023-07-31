#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cowsort(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int C, N;
    cin >> C >> N;

    vector<int> chickens(C);
    for (int i = 0; i < C; i++) {
        cin >> chickens[i];
    }

    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end(), cowsort);

    int pairs = 0;
    vector<bool> taken(C, false);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < C; j++) {
            if (!taken[j] && chickens[j] >= cows[i].first && chickens[j] <= cows[i].second) {
                taken[j] = true;
                pairs++;
                break;
            }
        }
    }

    cout << pairs << endl;
    return 0;
}