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
    int idx = -1;
    vector<int> preCnt2(n),suffCnt2(n);
    preCnt2[0] = (a[0]%2==0?1:0);
    for(int i=1;i<n;i++){
        preCnt2[i] = preCnt2[i-1]+(a[i]%2==0?1:0);
    }
    suffCnt2[n-1] = (a[n-1]%2==0?1:0);
    for(int i=n-2;i>=0;i--){
        suffCnt2[i] = suffCnt2[i+1]+(a[i]%2==0?1:0);
    }

    
    for(int i=0;i<n-1;i++){
        if(preCnt2[i]==suffCnt2[i+1]){
            idx = i;
            break;
        }
    }
    if(idx==-1){
        cout<<-1<<endl;
        return;
    }
    cout<<idx+1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
