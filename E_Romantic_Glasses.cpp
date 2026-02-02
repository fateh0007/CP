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
    vector<int> prefEven(n,0),prefOdd(n,0);
    prefEven[0] = a[0];
    map<int,int> mp;
    mp[prefOdd[0]-prefEven[0]]++;
    for(int i=1;i<n;i++){
        prefEven[i] += prefEven[i-1];
        prefOdd[i] += prefOdd[i-1];
        if(i%2==0){
            prefEven[i] += a[i];
        }else{
            prefOdd[i]+=a[i];
        }
        if(mp.find(prefOdd[i]-prefEven[i])!=mp.end() || prefOdd[i]-prefEven[i]==0){
            cout<<"YES"<<endl;
            return;
        }    
        mp[prefOdd[i]-prefEven[i]]++; 
    }
    cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
