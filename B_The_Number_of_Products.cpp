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
    int even = 1;
    int odd = 0;
    int cnt =0;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(a[i]<0) cnt++;
        if(cnt%2==0){
            sum+=even;
            even++;
        }else{
            sum+=odd;
            odd++;
        }
    }
    int neg = n*(n+1)/2 - sum;
    cout<<neg<<" "<<sum<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
