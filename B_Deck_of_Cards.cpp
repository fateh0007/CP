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
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        int cnt2 = 0;
        vector<char> a(n,'#');
        int l = 0;
        int r = n-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                a[l] = '-';
                l++;
            }
            else if(s[i]=='1'){
                a[r]='-';
                r--;
            }else if(s[i]=='2'){
                cnt2++;
            }
        }
        // cout<<cnt2<<endl;
        while(cnt2>0 && l<=r){
            a[l]='?';
            a[r] = '?';
            cnt2--;
            l++;
            r--;
        }
        for(int i=0;i<n;i++){
            if(a[i]=='#'){
                a[i] = '+';
            }
        }
        string st = "";
        for(int i=0;i<n;i++){
            st+=a[i];
            // cout<<a[i]<<" ";
        }
        if(n==1){
            cout<<"-"<<endl;
            continue;
        }
        cout<<st<<endl;
        // cout<<endl;
    }
}