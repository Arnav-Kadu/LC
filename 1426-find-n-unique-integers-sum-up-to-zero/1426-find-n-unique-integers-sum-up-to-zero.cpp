class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int temp=n;
        int first = 0;
        int last = n - 1;
        for (int i = 0; i < temp / 2; i++) {
            ans[first] = n;
            ans[last] = -n;
            n--;
            first++;
            last--;
            // cout<<first<<" "<<last<<endl;
        }
        return ans;
    }
};