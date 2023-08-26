vector<ll> lps_array_compute(string &s){
    vector<ll> lps(s.length(),0);
    ll len=0;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
        }
        else{
            if(len){
                i--;
                len=lps[len-1];
            }
            else lps[i]=0;
        }
    }
    return lps;
}
 
ll kmp_search(string &s, string &pat){
    vector<ll> lps=lps_array_compute(pat);
    // vector<ll> res;
    ll res=0;
    ll n=s.length(),m=pat.length(),i=0,j=0;
    while((n-i)>=(m-j)){
        if(pat[j]==s[i]){
            i++,j++;
        }
        if(j==m){ //pattern found
            // res.push_back(i-j);
            res++;
            j=lps[j-1];
        }
        else if(pat[j]!=s[i] && i<n){
            if(j)j=lps[j-1];
            else i++;
        }
    }
    return res;
}
