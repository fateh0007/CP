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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int cntOdd = 0;
    int cntEven = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            cntEven++;
        }else{
            cntOdd++;
        }
    }
    if(cntEven>=1 && cntOdd>=1){
        cout<<2<<endl;
        return;
    }
    vector<int> diff;
    for(int i=0;i<n-1;i++){
        int df = a[i+1]-a[i];
        diff.push_back(df);
    }
    int ans =0 ;
    int div = 2;
    while(div<=1e18){
        set<int> st;
        for(int j=0;j<n;j++){
            st.insert(a[j]%div);
        }
        if(st.size()==2) {
            ans = div;
            break;
        }
        div*=2;
    }
    if(ans==0){
        cout<<a[n-1]<<endl;
        return;
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
