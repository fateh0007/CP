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
    char c;
    cin>>n;
    cin>>c;
    string s;
    cin>>s;
    bool check = true;
    for(int i=0;i<n;i++){
        if(s[i]!=c) check = false;
    }
    if(check){
        cout<<0<<endl;
        return;
    }
    for(int x =n/2 +1;x<=n;x++){
        if(s[x-1] == c){
            cout<<1<<endl;
            cout<<x<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<n-1<<" "<<n<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
