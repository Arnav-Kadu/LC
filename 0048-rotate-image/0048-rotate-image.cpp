class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int top = 0;
        int bottom = n - 1;
        while (top < bottom) {
            swap(matrix[top], matrix[bottom]);
            top++;
            bottom--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
