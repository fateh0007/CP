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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        if(a[i]<i+1){
            v.push_back(make_pair(a[i],i+1));
        }
    }
    sort(v.begin(),v.end());
    int x = v.size();
    int cnt =0;
    for(int i=0;i<x;i++){
        int idx = v[i].second;
        int lo = i+1;
        int hi = x-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(v[mid].first>idx){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        cnt+=(x- lo);
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
