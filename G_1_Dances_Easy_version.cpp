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
    int n,m;
    cin>>n>>m;
    vector<int> a,b(n);
    a.push_back(1);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;
    int j=0;
    int cnt =0;
    while(i<n && j<n){
        while(j<n && a[i]>=b[j]){
            j++;
        }
        if(i<n && j<n && a[i]<b[j]){
            cnt++;
            i++;
            j++;
        }
    }
    if(cnt==0){
        cout<<n<<endl;
        return;
    }
    cout<<n-cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
