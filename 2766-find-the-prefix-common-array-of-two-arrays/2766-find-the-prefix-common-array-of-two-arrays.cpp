class Solution {
private:
    void update(vector<int>& bit, int idx, int n) {
        while (idx <= n) {
            bit[idx] += 1;
            idx += (idx & -idx);
        }
    }
    int query(vector<int>& bit, int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>cnt(51,0);
        
        int count=0;
        int n=A.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
           cnt[A[i]]++;
           if(cnt[A[i]]==2) count++;
           cnt[B[i]]++;
           if(cnt[B[i]]==2) count++;
           ans[i]=(count);
        }
        return ans;
    }
};