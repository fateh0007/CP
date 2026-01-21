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
long long factorial(int n) {
    if (n < 0) {
        return -1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result*i)%mod;
    }
    return result%mod;
}

vector<bool> generatePrimeSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

string divide_with_ndigits(long long a, long long b, int n) {
    if (b == 0) throw runtime_error("division by zero");
    bool neg = ( (a < 0) ^ (b < 0) );
    a = llabs(a);
    b = llabs(b);

    long long intpart = a / b;
    long long rem = a % b;

    string res = (neg && (intpart != 0 || rem != 0)) ? "-" : "";
    res += to_string(intpart);
    if (n == 0) return res;

    res.push_back('.');
    for (int i = 0; i < n; ++i) {
        rem *= 10;
        int digit = rem / b;
        res.push_back(char('0' + digit));
        rem %= b;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<pair<int,int> > v(n); 
    map<int,int> mp;
    bool mark = true;
    int cntDuplicates = 0;
    int dup = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        v[i]=make_pair(a[i],i);
        mp[a[i]]++;
        if(mp[a[i]]>2){
            mark = false;
        }
        if(mp[a[i]]==2){
            cntDuplicates++;
            dup=a[i];
        }
    }
    // int missing = -1;
    vector<int> missing;
    for(int i=1;i<=n;i++){
        if(mp.find(i)==mp.end()){
            missing.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    if(mp[1]>1 || mark==false || n>v[n-1].first ){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> p(n,-1);
    vector<int> q(n,-1);
    bool flag = false;
    int idx = 0;
    for(int i = 0;i<n;i++){
        if(mp[v[i].first]==1){
            p[v[i].second] = v[i].first;
            q[v[i].second] = v[i].first;
        }else{
            if(flag == false){
                if(missing[idx]>v[i].first){
                    cout<<"NO"<<endl;
                    return;
                }
                p[v[i].second] = v[i].first;
                q[v[i].second] = missing[idx];
                flag = true;
            }else{
                if(missing[idx]>v[i].first){
                    cout<<"NO"<<endl;
                    return;
                }
                p[v[i].second] = missing[idx];
                q[v[i].second] = v[i].first;
                flag = false;
                idx++;
            }

        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
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