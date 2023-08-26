struct segtree{
    vector<ll> t;
    ll sz;
    segtree(ll n){
        sz=1;
        while(sz<n)sz=sz*2;
        t.assign(2*sz,0);
    }
    segtree(vector<ll>&a){
        sz=1;
        while(sz<a.size())sz*=2;
        t.assign(2*sz,0);
        build(0,0,sz,a);
    }
    void build(ll node_pos,ll lx,ll rx,vector<ll>&a){
        if(rx==lx+1){
            t[node_pos]=a[lx];
            return;
        }
        ll mid=(lx+rx)/2;
        build(2*node_pos+1,lx,mid,a);
        build(2*node_pos+2,mid,rx,a);
        t[node_pos]=t[2*node_pos+1]+t[2*node_pos+2];
    }
    void set(ll pos,ll val){
        set(0,0,sz,pos,val);
    }
    void set(ll node_pos,ll lx,ll rx,ll pos,ll val){
        if(rx==lx+1){
            t[node_pos]=val;
            return;
        }
        ll mid=(lx+rx)/2;
        if(pos<mid)set(2*node_pos+1,lx,mid,pos,val);
        else set(2*node_pos+2,mid,rx,pos,val);
        t[node_pos]=t[2*node_pos+1]+t[2*node_pos+2];
    }
    void update(ll pos,ll val){
        update(0,0,sz,pos,val);
    }
    void update(ll node_pos,ll lx,ll rx,ll pos,ll val){
        if(rx==lx+1){
            t[node_pos]+=val;
            return;
        }
        ll mid=(lx+rx)/2;
        if(pos<mid)update(2*node_pos+1,lx,mid,pos,val);
        else update(2*node_pos+2,mid,rx,pos,val);
        t[node_pos]=t[2*node_pos+1]+t[2*node_pos+2];
    }
    ll query(ll l,ll r){
        if(l>=r)return 0;
        return query(l,r,0,0,sz);
    }
    ll query(ll l,ll r,ll node_pos,ll lx,ll rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l && rx<=r)return t[node_pos];
        ll mid=(lx+rx)/2;
        return query(l,r,2*node_pos+1,lx,mid)+query(l,r,2*node_pos+2,mid,rx);
    }
};
