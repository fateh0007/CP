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
const int mod = 1e9+7;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    set<int> hs;
    int j = n-1;
    while(k--){
        if(a[j]>n){
            cout<<"No"<<endl;
            return;
        }
        if(hs.count(j)){
            cout<<"Yes"<<endl;
            return;
        }
        hs.insert(j);
        j-=a[j];
        j=(j+n)% n;

    }
    cout<<"Yes"<<endl;

} 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    } 
}