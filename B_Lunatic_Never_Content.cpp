#include <bits/stdc++.h>
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
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    b = a;
    reverse(b.begin(),b.end());
    if(a==b){
        cout<<0<<endl;
        return; 
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int i=0;
    int j = n-1;
    int gcdd = 0;
    
    while(i<j){
        int diff = abs(a[i]-a[j]);
        gcdd = __gcd(gcdd,diff);
         
        i++;
        j--;
    }
    cout<<gcdd<<endl;
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
