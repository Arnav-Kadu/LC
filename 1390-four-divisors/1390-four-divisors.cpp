class Solution {
    const int MAX = 1e5; 
    vector<int>divisors[(int)1e5 + 1];
private:
    void sieve_divisors() {
        for (int i = 1; i <= MAX; ++i) {
            for (int j = i; j <= MAX; j += i) {
                divisors[j].push_back(i);
            }
        }
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        sieve_divisors();
        int count=0;
        for(auto i:nums){
            if(divisors[i].size()==4){
                count+=accumulate(divisors[i].begin(),divisors[i].end(),0);
            }
        }
        return count;
    }
};