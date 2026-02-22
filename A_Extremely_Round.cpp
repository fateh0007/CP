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

bool check(int n){
    int num = 0;
    int cnt =0;
    while(n){
        if(n%10==0){
            cnt++;
        }
        num++;
        n/=10;
    }
    return cnt==num-1;
}
void solve(vector<int> &round){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0;i<round.size();i++){
        if(round[i]<=n){
            ans++;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> round;
    for(int i=1;i<=999999;i++){
        if(check(i)) round.push_back(i);
    }
    int t;
    cin>>t;
    while(t--) solve(round);
}
