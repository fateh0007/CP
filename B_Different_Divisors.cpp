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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> primes;
	for (long long i = 2; i <= 100000; i++) 
	{
		bool is_prime = true;
		for (long long j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			primes.push_back(i);
	}
    int t;
    cin >> t;
    while (t--){
        int d;
        cin>>d;
        int p = -1;
        for(int i=0;i<primes.size();i++){
            if(primes[i]>=(1+d)){
                p = primes[i];
                break;
            }
        }
        int q = -1;
        for(int i=0;i<primes.size();i++){
            if(primes[i]>=(p+d)){
                q=primes[i];
                break;
            }
        }
        int ans = min(1LL*p*p*p, 1LL*p*q);
        cout<<ans<<endl;
    }
}
