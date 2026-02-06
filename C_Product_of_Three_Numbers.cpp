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
int k;
vector<int> divisorTillN(int n) {
    vector<int> temp;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            temp.push_back(i);
            if(i!=n/i) temp.push_back(n/i);
        }
    }
    return temp;
}

void solve() {
    int n;
    cin>>n;
    vector<int> divisors = divisorTillN(n);
    // map<int,int> mp;
    // for(int i=0;i<divisors.size();i++) {
    //     mp[n/divisors[i]]++;
    // }
    for(int i=0;i<divisors.size();i++) {
        for(int j=i+1;j<divisors.size();j++) {
            for(int k=j+1;k<divisors.size();k++) {
                if(divisors[i]*divisors[j]*divisors[k]==n) {
                    cout<<"YES"<<endl;
                    cout<<divisors[i]<<" "<<divisors[j]<<" "<<divisors[k]<<endl;
                    return;
                }
            }   
        }
    }
    cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
