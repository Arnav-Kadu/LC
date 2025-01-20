class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> v(*max_element(arr.begin(), arr.end()) + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            v[arr[i]] = i;
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mat[i][j] = v[mat[i][j]];
            }
        }
        vector<int> row(mat.size(), 0), col(mat[0].size(), 0);
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                row[i] = max(row[i], mat[i][j]);
                col[j] = max(col[j], mat[i][j]);
            }
        }
        int mx = INT_MAX;
        for (int i = 0; i < row.size(); i++) {
            mx = min(mx, row[i]);
        }
        for (int i = 0; i < col.size(); i++) {
            mx = min(mx, col[i]);
        }
        return mx;
    }
};
