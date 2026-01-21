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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int> > mini;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi.push(a[i]);
        mini.push(a[i]);
    }
    int l=0;
    int r = n-1;
    while(l<r){
        if(a[l]!=maxi.top() && a[l]!=mini.top() && a[r]!=maxi.top() && a[r]!=mini.top()){
            cout<<l+1<<" "<<r+1<<endl;
            return;
        }
        if(a[l]==maxi.top() || a[l]==mini.top()){
            if(a[l]==maxi.top()) maxi.pop();
            else mini.pop();
            l++;
        }
        if(a[r]==maxi.top() || a[r]==mini.top()){
            if(a[r]==maxi.top()) maxi.pop();
            else mini.pop();
            r--;
        }
    }
    cout<<-1<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
