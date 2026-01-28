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
    int n,k,b,s;
    cin>>n>>k>>b>>s;
    vector<int> a(n,0);
    if(k*b>s){
        cout<<-1<<endl;
        return;
    }
    if(k*b+(k-1)*n<s){
        cout<<-1<<endl;
        return;
    }
    a[0] = k*b;
    s-=k*b;
    for(int i=0;i<n;i++){
        int add = min(k-1,s);
        a[i]+=add;
        s-=add;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
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
