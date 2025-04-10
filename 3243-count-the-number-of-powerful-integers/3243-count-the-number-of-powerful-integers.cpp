class Solution {
    long long compute(string end, string suff, int limit) {
        long long ans = 0;
        if (end.size() < suff.size()) {
            return 0;
        }
        if (end.size() == suff.size()) {
            return end >= suff ? 1 : 0;
        }
        string rem = "";
        for (int i = end.length() - suff.length(); i < end.length(); ++i) {
            rem += end[i];
        }
        
        for(int i=0;i<end.size()-suff.size();i++){
            if(limit<(end[i]-'0')){
                ans+=(long long)pow(limit+1,(int)(end.size()-suff.size())-i);
                return ans;
            }
            ans+=(long long)(end[i]-'0')*(long long)pow(limit+1,(int)(end.size()-suff.size())-1-i);
        }
        if(rem>=suff){
            ans++;
        }
        return ans;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,string s) {
        string first = to_string(start - 1);
        string second = to_string(finish);
        return compute(second, s, limit) - compute(first, s, limit);
    }
};
