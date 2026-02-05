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

int largest_proper_divisor(int n){
    int num = 1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            num = i;
            break;
        }
    }
    if(num==1) return 1;
    return n/num;
}

void solve() {
    int n;
    cin>>n;
    int largest_divisor = largest_proper_divisor(n);
    cout<<largest_divisor<<" "<<n-largest_divisor<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
