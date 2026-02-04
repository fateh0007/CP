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
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> temp;
    if(x!=1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i=0;i<n;i++) {
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    else if(k==1|| (k==2&&n%2==1)){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        cout<<n/2<<endl;
        if(n%2==1){
            cout<<3;
        }else{
            cout<<2;
        }
        for(int i=0;i<(n/2)-1;i++){
            cout<<" "<<2;
        }
        cout<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
