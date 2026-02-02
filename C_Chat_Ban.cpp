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
    int k,x;
    cin>>k>>x;
    int sumTillK = k*(k+1)/2;
    int totalSum = 2*sumTillK - k;
    if(x>totalSum){
        cout<<2*k-1<<endl;
    }
    else if(x<=sumTillK){
        int lo = 1;
        int hi = k;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int currSum = mid*(mid+1)/2;
            if(currSum>=x){
                hi = mid-1;
            }else{
                lo= mid+1;
            }
        }
        cout<<lo<<endl;
    }else{
        int rem = x - sumTillK;
        int lo = k+1;
        int hi = 2*k-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int currSum = k*(k-1)/2 - (2*k-1 -mid)*(2*k - mid)/2;
            if(currSum>=rem){
                hi = mid-1;
            }else{
                lo= mid+1;
            }
        }
        // cout<<lo<<endl;
        // int total = sumTillK + (k*(k-1))/2 - (2*k-1 -hi)*(2*k - hi)/2;
        cout<<lo<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
