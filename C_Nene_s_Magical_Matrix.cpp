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
using namespace std;
#define int long long
const int mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<1<<endl;
        cout<<1<<" "<<1<<" "<<1<<endl;
        return;
    }
    if(n==2){
        cout<<7<<" "<<3<<endl;
        cout<<1<<" "<<1<<" "<<1<<" "<<2<<endl;
        cout<<1<<" "<<2<<" "<<1<<" "<<2<<endl;
        cout<<2<<" "<<1<<" "<<1<<" "<<2<<endl;
        return;
    }
    vector<vector<int> > a(n,vector<int>(n));
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = max(i+1,j+1);
            sum+=a[i][j];
        }
    }
    cout<<sum<<" "<<2*n<<endl;
    for(int i=n-1;i>=0;i--){
        cout<<1<<" "<<i+1<<" ";
        for(int j=0;j<n;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
        cout<<2<<" "<<i+1<<" ";
        for(int j=0;j<n;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
