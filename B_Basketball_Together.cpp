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
    int n,d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int cnt = 0;
    int j = n-1;
    while(j>=0 && a[j]>d){
        cnt++;
        j--;
    }
    // cout<<j<<endl;
    if(j<0){
        cout<<cnt<<endl;
        return;
    }
    int i=0;
    while(i<j){
        int required = (d/a[j]) + 1;
        if(j-i>=required-1){
            cnt++;
            i += required-1;
            j--;
        }
        else{
            break;
        }
    }
    cout<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) solve();
}
