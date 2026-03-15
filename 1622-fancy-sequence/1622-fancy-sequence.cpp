class Fancy {
public:
    long long mod=1e9+7;
    long long multi=1;
    long long sum=0;
    vector<int>a;
    long long power(long long base,long long exp){
       long long ans=1;
       base%=mod;
       while(exp){
        if(exp&1)ans=(ans*base)%mod;
        exp/=2;
        base=(base*base)%mod;
       }
       return ans;
    }
    long long modInverse(long long n){
        return power(n,mod-2);
    }
    Fancy() {
    }
    
    void append(int val) {
        long long temp=val;
        // temp=(a*mul+sum)
        long long base=((temp-sum+mod)%mod*modInverse(multi))%mod;
        a.push_back(base);
    }
    
    void addAll(int inc) {
        sum=(sum+inc)%mod;
    }
    
    void multAll(int m) {
        multi=(multi*m)%mod;
        sum=(sum*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=a.size()){
            return -1;
        }        
        return (a[idx]*multi+sum)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */