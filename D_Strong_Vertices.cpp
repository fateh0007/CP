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
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> v(n);
    int maxi = -1e18;
    for(int i=0;i<n;i++){
        v[i] = a[i]-b[i]; 
        maxi = max(maxi,v[i]);
    }
    int cnt =0;
    vector<int> idx;
    for(int i=0;i<n;i++){
        if(v[i]==maxi){
            cnt++;
            idx.push_back(i+1);
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<idx.size();i++){
        cout<<idx[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
