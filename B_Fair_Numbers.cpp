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

bool possible(int n){
    vector<int> digits;
    int x= n;
    while(n>0){
        digits.push_back(n%10);
        n/=10;
    }
    
    for(int i=0;i<digits.size();i++){
        if(digits[i]==0) continue;
        if(x%digits[i]!=0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    int ans = 0;
    while(possible(n) == false){
        n++;
    }
    cout<<n<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
