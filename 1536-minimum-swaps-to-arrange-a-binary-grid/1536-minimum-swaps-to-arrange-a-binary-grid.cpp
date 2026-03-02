class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> row(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    row[i] = j;
                }
            }
        }
        auto temp = row;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++)
        {
            if (temp[i] > i)
            {
                return -1;
            }
        }
        int swaps = 0;
        for (int i = 0; i < n; ++i)
        {
            int idx = i;
            while (idx < n && row[idx] > i)
                ++idx;
            if (idx == n)
                return -1;
            while (idx > i)
            {
                swap(row[idx], row[idx - 1]);
                ++swaps;
                --idx;
            }
        }
        return swaps;
    }
};