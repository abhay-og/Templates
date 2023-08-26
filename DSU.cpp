struct DSU{
    vector<ll>dsp,si;
    void make(ll v){
        dsp[v]=v;
        si[v]=1;
    }
    DSU(ll n){
        dsp.resize(n);
        si.resize(n);
        for(ll i=0;i<n;i++)make(i);
    }
    ll find(ll v){
        if(v==dsp[v]) return v;
        return dsp[v]=find(dsp[v]);
    }
    void unio(ll a,ll b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(si[a]<si[b]) swap(a,b);
            dsp[b]=a;
            si[a]+=si[b];
        }
    }
};
