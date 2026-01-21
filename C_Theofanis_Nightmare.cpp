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
using namespace std;
#define int long long
const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        vector<int> suff(n+1,0);
        suff[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = a[i] + suff[i+1];
        }
        int ans = suff[0];
        for(int i=0;i<n;i++){
            cout<<suff[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<n;i++){
            if(suff[i]>0) ans+=suff[i];
        }
        cout<<ans<<endl;
    } 
}