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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> nextDifferent(n,-1);
    for(int i=n-2;i>=0;i--){
        if(a[i]!=a[i+1])
            nextDifferent[i]=i+1;
        else
            nextDifferent[i] = nextDifferent[i+1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(a[l]!=a[r]){
            cout<<l+1<<" "<<r+1<<endl;
            continue;
        }
        else{
            int idx = nextDifferent[l];
            if(idx!=-1 && idx<=r){
                cout<<l+1<<" "<<idx+1<<endl;
            }else{
                cout<<-1<<" "<<-1<<endl;
            }
        }
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
