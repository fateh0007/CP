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

int a[200000];
int pre[30][200001];

int range_and(int l,int r){
    int ans = 0;
    for(int i=0;i<30;i++){
        if(pre[i][r+1]-pre[i][l]==0){
            ans += (1<<i);
        }
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int j=0;j<30;j++){
        pre[j][0]=0;
        for(int i=0;i<n;i++){
            if((1<<j)&a[i]){
                pre[j][i+1]=pre[j][i];
            }else{
                pre[j][i+1]=pre[j][i]+1;
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int l,k;
        cin>>l>>k;
        l--;
        if(a[l]<k){
            cout<<-1<<" ";
            continue;
        }
        int lo=l,hi=n-1;
        while(lo<hi){
            int mid=(lo+hi+1)/2;
            if(range_and(l,mid)>=k){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        cout<<lo+1<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
