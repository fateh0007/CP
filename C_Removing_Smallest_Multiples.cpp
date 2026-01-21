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
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin>>s; 
    int cnt0 = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') cnt0++;
    }
    vector<int> mark(n,0);
    int sum =0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (s[j-1] == '1') break;
            if (!mark[j-1]) {
                mark[j-1] = 1;
                sum += i;
            }
        }
    }
    cout<<sum<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
