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
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        x[i] = a;
        y[i] = b;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int medX = x[n/2] - x[(n-1)/2] + 1;
    int medY = y[n/2] - y[(n-1)/2] + 1;

    int res = medX*medY;
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}