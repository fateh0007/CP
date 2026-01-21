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
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve() {
    int n,a;
    cin>>n>>a;
    vector<int> v(n);
    int ng = 0;
    int sumg = 0;
    int ns = 0;
    int sums = 0;
    int eq = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>a){
            ng++;
            sumg+=v[i];
        }else if(v[i]<a){
            ns++;
            sums+=v[i];
        }else{
            eq++;
        }
    }
    if(ng>ns){
        cout<<a+1<<endl;
    }
    else if(ns>ng){
        cout<<a-1<<endl;
    }
    else{
        cout<<a+1<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
