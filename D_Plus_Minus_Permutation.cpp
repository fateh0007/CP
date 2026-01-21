#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map> 
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include<numeric>
using namespace std;
#define int long long 
const int mod = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int sum_first_k(int k) {
    return k * (k + 1) / 2;
}

int sum_last_k(int n, int k) {
    return sum_first_k(n) - sum_first_k(n - k);
}

void solve() {
    int n,x,y;     
    cin >>n>>x>>y;

    int l = (x/gcd(x,y))*y;

    int cx = n/x-n/l;
    int cy = n/y-n/l;

    int sum1 = sum_last_k(n, cx);
    int sum2 = sum_first_k(cy);

    cout << sum1 - sum2 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
