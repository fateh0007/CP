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
    int a,b;
    cin>>a>>b;
    int minOperations = INT_MAX;
    int prevMinOperations = minOperations;
    // int x = b;
    for(int x=0;x<=30;x++){
        int base = b+x;
        if(base==1) continue;
        int cnt = x;
        int temp = a;
        while(temp>0){
            temp/=base;
            cnt++;
        }
        minOperations = min(minOperations,cnt);
    }
    cout<<minOperations<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
