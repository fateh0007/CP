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

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    return (a/gcd(a,b)) * b;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cntP = 0;
    int cntM = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='+') cntP++;
        else cntM++;
    }
    // int minCnt = min(cntP,cntM);
    // int maxCnt = max(cntM,cntP);
    // int mx = maxCnt;
    // int mn = minCnt;
    // while(minCnt>0 && maxCnt%minCnt!=0){
    //     cntP--;
    //     cntM--;
    //     maxCnt=max(cntP,cntM);
    //     minCnt=min(cntP,cntM);
    // }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(cntP==cntM){
            cout<<"YES"<<endl;
            continue;
        }
        if(a==b){
            cout<<"NO"<<endl;
            continue;
        }
        int l = lcm(a,b);
        int x = l/a;
        int y = l/b;
        if(abs(cntP-cntM)% abs(y-x)==0){
            int p = abs(cntP-cntM) / abs(y-x);
            if((x+y)*p<=n){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
        
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
