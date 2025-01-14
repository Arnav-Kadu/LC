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
        int n = A.size();
        vector<int> ans;
        vector<int> bit(n + 1, 0);
        vector<bool> seen(n + 1, false); 
        for (int i = 0; i < n; i++) {
            if (seen[A[i]]) {
                update(bit, A[i], n);  
            }
            seen[A[i]] = true;
            if (seen[B[i]]) {
                update(bit, B[i], n);  
            }
            seen[B[i]] = true;
            ans.push_back(query(bit, n));
        }
        
        return ans;
    }
};