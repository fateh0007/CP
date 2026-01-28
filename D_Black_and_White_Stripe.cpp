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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i=0;
    int j=0;
    int flips = 0;
    int minFlips = INT_MAX;
    while(j<n){
        if(s[j]=='W'){
            flips++;
        }
        if(j-i+1>k){
            if(s[i]=='W'){
                flips--;
            }
            i++;
        }
        if(j-i+1==k){
            minFlips = min(minFlips,flips);
        }
        j++;
    }
    cout<<minFlips<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
