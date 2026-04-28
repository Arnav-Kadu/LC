class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        int dir[5] = {0, 1, 0, -1, 0};
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int d = top[0], r = top[1], c = top[2];
            
            if(d > dist[r][c]) continue;
            
            if(r == m-1 && c == n-1) return d;
            
            for(int i=0;i<4;i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int newDist = max(d, abs(heights[nr][nc] - heights[r][c]));
                    
                    if(dist[nr][nc] > newDist){
                        dist[nr][nc] = newDist;
                        pq.push({newDist, nr, nc});
                    }
                }
            }
        }
        
        return 0;
    }
};