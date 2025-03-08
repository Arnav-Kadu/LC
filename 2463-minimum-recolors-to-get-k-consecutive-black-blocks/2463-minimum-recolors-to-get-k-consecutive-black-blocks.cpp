class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int n = blocks.size();
        int start = 0;
        int end = 0;
        int white = 0;
        while(end < n) {
            if(end < k) {
                if(blocks[end] == 'W')
                    white++;
                end++;
                if(end == k)
                    ans = white;
                continue;
            }
            if(blocks[start] == 'W')
                white--;
            if(blocks[end] == 'W')
                white++;
            start++;
            end++;
            ans = min(ans, white);
        }
        return ans;
    }
};
