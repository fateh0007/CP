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
#include <numeric>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int INF = LLONG_MAX;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(gcd(a[i],a[j])<=2){
                flag = true;
                break;
            }
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
