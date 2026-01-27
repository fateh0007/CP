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

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
long long largestProperDivisor(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return n / i;
    }
    return 1; // n is prime
}

void solve() {
    int n;
    cin>>n;
    if(n%2==0){
        cout<<n/2<<" "<<n/2<<endl;
        return;
    }
    if(isPrime(n)){
        cout<<1<<" "<<n-1<<endl;
        return;
    }
    int lpd = largestProperDivisor(n);
    cout<<lpd<<" "<<n - lpd<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
