pair<ll,ll>fibonacci_number(ll n){
    if (n==0)return {0, 1};
    auto p=fibonacci_number(n >> 1);
    int c=(p.first*(2*p.second-p.first))%MOD;
    int d=(p.first*p.first+p.second*p.second)%MOD;
    if (n&1)return {d,c+d};
    else return {c,d};
}
