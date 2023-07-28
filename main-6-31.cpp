#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cmath>
using namespace std;

int a;
vector<int> c(100000, 0);

int real(double g)
{
    int i = 0;
    int total = 0;
    double best;
    double current;
    for (i = 0; i < a; i++)
    {
        total += c[i];
    }
    best = c[1] - g;
    current = best;
    for (i = 2; i < a - 1; i++)
    {
        if (current < 0)
        {
            current = 0;
        }
        current += c[i] - g;
        if (current > best)
        {
            best = current;
        }
    }
    return best >= total - g * a;
}

double solve(void)
{
    double low = 1.0, high = 1000000000.0;
    while (high - low > 0.0001)
    {
        if (real((low + high) / 2))
        {
            high = (low + high) / 2;
        }
        else
        {
            low = (low + high) / 2;
        }
    }
    return low;
}

int main(void)
{
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> c[i];
    }
    double low = solve();
    cout << fixed << setprecision(3) << low;
    return 0;
}
