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

int msbPos(int x){
    int pos= 0;
    while(x>0){
        x>>=1;
        pos++;
    }
    return pos;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int maxi = 0;
    for(int i=0;i<n;i++){
        int pos = msbPos(i);
        a[i] = pos;
        maxi = max(maxi,pos);
    }
    int idx = -1;
    for(int i=0;i<n;i++){
        if(a[i]==maxi){
            idx = i;
            break;
        }
    }
    for(int i=1;i<idx;i++){
        cout<<i<<" ";
    }
    cout<<0<<" ";
    for(int i=idx;i<n;i++){
        cout<<i<<" ";
    }

    // if(n%2!=0) cout<<n/2<<" ";
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
