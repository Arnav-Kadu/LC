class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        vector<int> xCount(cols);
        vector<int> yCount(cols);
        auto count = 0;
        for (auto row = 0; row < rows; ++row) {
            auto rowX = 0;
            auto rowY = 0;
            for (auto col = 0; col < cols; ++col) {
                rowX += grid[row][col] == 'X';
                rowY += grid[row][col] == 'Y';
                xCount[col] += rowX;
                yCount[col] += rowY;
                if (xCount[col] && xCount[col] == yCount[col]) ++count;
            }
        }
        return count;
    }
};