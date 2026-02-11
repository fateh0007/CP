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

int numberReverse(int n){
    int rev = 0;
    while(n>0){
        rev = rev*10 + n%10;
        n/=10;
    }
    return rev;
}
bool comp(int a,int b){
    int cnt1 = 0;
    int cnt2 =0;
    while(a%10==0){
        cnt1++;
        a/=10;
    }
    while(b%10==0){
        cnt2++;
        b/=10;
    }
    if(cnt1==cnt2){
        return a>b;
    }
    return cnt1>cnt2;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    string s = "";
    priority_queue<int> pq;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%10!=0){
            s+=to_string(a[i]);
        }else{
            pq.push(a[i]);
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<v.size();i++){
        if(i%2==0){
            int x = numberReverse(v[i]);
            s+=to_string(x);
        }else{
            s+=to_string(v[i]);
        }
        // cout<<v[i]<<" ";
    }
    if(s.size()>=m+1){
        cout<<"Sasha"<<endl;
    }else{
        cout<<"Anna"<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
