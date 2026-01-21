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

void solve(){
    int n;
    cin>>n;
    int mao = 0;
    while(n>2){
        int x = floor((double)n/3.0);
        int y = ceil((double)n/3.0);
        mao+=x;
        n-=x+y;
    }
    cout<<mao<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
