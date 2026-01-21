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
    cin >> n;
    vector<int> a(n);
    int noz = 0;//number of zeros
    int noo = 0;//number of ones
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0) noz++;
        else if(a[i]==1){
            noo++;
        }
    }
    if(noz==0){
        cout<<"NO"<<endl;
        return;
    }
    if(n==2){
        if(a[0]!=a[1]){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    
    if(noo==0){
        if(noz!=1){
            cout<<"NO"<<endl;
            return;
        }else{
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
