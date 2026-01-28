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

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int> > b;
    for(int i=0;i<n;i++){
        int pos = x+a[i];
        int neg = -x+a[i];
        b.push_back(make_pair(neg,pos));
    }
    int cnt =0 ;
    int l = b[0].first;
    int r = b[0].second;
    for(int i=1;i<n;i++) {
        l = max(l,b[i].first);
        r = min(r,b[i].second);
        if(l>r){
            cnt++;
            l=b[i].first;
            r = b[i].second;
        }
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
