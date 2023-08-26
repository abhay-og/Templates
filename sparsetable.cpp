class SparseTable{
    private:
        vector<vector<ll>> st;
    public:
        SparseTable(){}
        SparseTable(vector<ll>& v){constst(v);}
        void constst(vector<ll>& v){
            ll n=v.size();
            ll k=log2(n)+1;
            st.clear();
            st.assign(k,vector<ll>(n,0));
            for(ll i=0;i<n;i++)st[0][i]=v[i];
            for(ll j=1;j<=k;j++){
                for(ll i=0;i+(1<<j)<=n;i++){
                    st[j][i]=__gcd(st[j-1][i],st[j-1][i+(1<<(j-1))]);//change func here
                }
            }
        }
        ll get(ll l,ll r){ // 0-indexed [l,r] queries
            ll j=log2(r-l+1);
            return __gcd(st[j][l],st[j][r-(1<<j)+1]);//change func here
        }
};
