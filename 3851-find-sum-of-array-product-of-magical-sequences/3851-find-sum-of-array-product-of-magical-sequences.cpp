using ll = long long;
const ll M = 1000000007;

ll pw(ll a, ll b){
    ll r = 1 % M;
    a %= M;
    while(b){
        if(b & 1) r = r * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return r;
}

struct K {
    int a, b, c;
    long long d;
    bool operator==(K const& o) const {
        return a==o.a && b==o.b && c==o.c && d==o.d;
    }
};

struct H {
    size_t operator()(K const& k) const noexcept {
        size_t h = k.a;
        h = h * 1315423911u + k.b;
        h = h * 1315423911u + k.c;
        h ^= std::hash<long long>()(k.d) + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
        return h;
    }
};

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& v) {
        // maa ki chut problem ki aur media.net ki
        int n = v.size();
        vector<ll> f(m+1), inv(m+1);
        f[0]=1;
        for(int i=1;i<=m;i++) f[i]=f[i-1]*i%M;
        inv[m]=pw(f[m], M-2);
        for(int i=m;i>0;i--) inv[i-1]=inv[i]*i%M;
        auto C=[&](int a,int b){return (b<0||b>a)?0LL:f[a]*inv[b]%M*inv[a-b]%M;};
        unordered_map<K,ll,H> mp;
        function<ll(int,int,int,long long)> go=[&](int r,int o,int i,long long c)->ll{
            if(r<0||o<0) return 0;
            int p=__builtin_popcountll(c);
            if(r+p<o) return 0;
            if(r==0) return o==p;
            if(i>=n) return 0;
            K key{r,o,i,c};
            if(mp.count(key)) return mp[key];
            ll ans=0;
            for(int t=0;t<=r;t++){
                ll w=C(r,t)*pw(v[i],t)%M;
                long long nc=c+t;
                ans=(ans+w*go(r-t,o-(nc%2),i+1,nc/2))%M;
            }
            return mp[key]=ans;
        };
        return (int)go(m,k,0,0);
    }
};
