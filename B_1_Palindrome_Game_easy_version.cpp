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
    string s;
    cin>>s;
    if(s.find('0')==string::npos){
        cout<<"DRAW"<<endl;
        return;
    }
    int cnt0 = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') cnt0++;
    }
    if(cnt0%2==0 || cnt0==1){
        cout<<"BOB"<<endl;
    }
    else{
        cout<<"ALICE"<<endl;    
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
