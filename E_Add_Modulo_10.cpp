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
#include <numeric>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]%2!=0){
            a[i] = a[i] + a[i]%10;
        }
    }
    bool flag2 = true;
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]) {
            flag2 = false;
            break;
        }
    }
    if(flag2){
        cout<<"Yes"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]%10==0){
            cout<<"No"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        while(a[i]%10!=2){
            a[i] = a[i] + a[i]%10;
        }
        // a[i]%20;
    }
    for(int i=0;i<n;i++){
        a[i] = a[i]%20;
    }
    bool flag = true;
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]) {
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
