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
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int cntPos = 0;
    int cntNeg = 0;
    int sum =0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0) cntNeg++;
        else cntPos++;
        sum+=a[i];
    }
    int cnt = 0;
    while(cntPos<cntNeg){
        cntNeg--;
        cntPos++;
        cnt++;
    }
    if(cntNeg%2!=0){
        cnt++;
    }
    cout<<cnt<<endl;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
