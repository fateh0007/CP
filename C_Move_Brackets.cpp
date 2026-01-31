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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cntOpen = 0;
    int cntClose = 0;
    int ops = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            cntOpen++;
        }else{
            cntClose++;
        }
        if(cntClose>cntOpen)ops = max(ops,abs(cntOpen-cntClose));
    }
    cout<<ops<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
