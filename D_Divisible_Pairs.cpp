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
#define int  long long 
const int mod = 1e9 + 7;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a/gcd(a,b))*b;
}


void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, map<int, int> > mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int ry = ((a[i]%y)+y)%y;
        int rx = ((a[i]%x)+x)%x;
        int need = (x-rx)%x;
        cnt += mp[ry][need];
        mp[ry][rx]++;
    }

    cout<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
