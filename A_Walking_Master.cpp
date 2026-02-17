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

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int cnt =0;
    if(b>d){
        cout<<-1<<endl;
        return;
    }
    while(b<d){
        b++;
        a++;
        cnt++;
    }
    if(a==c && b==d){
        cout<<cnt<<endl;
        return;
    }
    if(c>a){
        cout<<-1<<endl;
        return;
    }
    while(a>c){
        a--;
        cnt++;
    }
    cout<<cnt<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
