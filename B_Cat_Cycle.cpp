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
    int n,k;
    cin>>n>>k;
    k--;
    if(n%2==0){
        k++;
        int x = k%n;
        if(x==0){
            cout<<n<<endl;
        }
        else{
            cout<<x<<endl;
        }
    }else{
        int d = n/2;
        int ans = (k+(k/d))%n;
        cout<<ans+1<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
