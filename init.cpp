#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T,null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define setbits(x) __builtin_popcountll(x)
#define binstr(n,x) bitset<n>(x).to_string()
#define lzs(x) __builtin_clzll(x)
#define tzs(x) __builtin_ctzll(x)
#define msb(x) __lg(x)
#define lsb(x) __builtin_ffsll(x)-1
#define roundup(n,x) cout<<fixed<<setprecision(n)<<x
using ll=long long;
using ld=long double;
const int MOD=1e9+7;
const ll INF=1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand_ll(ll l=0, ll r=1e18){uniform_int_distribution<ll> uid(l,r);return uid(rng);}

void solve(){
    
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for (int i=1;i<=t;i++){
        // cout<<"Case #"<<i<<' ';
        solve();
    }
   return 0;
}
