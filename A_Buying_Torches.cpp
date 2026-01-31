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

int helper(int a,int b){
    return (a+b-1)/b;
}

void solve() {
    int x,y,k;
    cin>>x>>y>>k;
    int gain = x-1;
    int need = k*y+k-1;
    int trade = 0;
    trade+=helper(need,gain);
    trade+=k;
    cout<<trade<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
