class Solution {
    int dr[4] = {-1,-1,1,1};
    int dc[4] = {-1,1,1,-1};
    int n,m;
    inline int idx(int r,int c,int d,int t,int p){ return (((r*m + c)*4 + d)*2 + t)*2 + p; }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid){
        n = grid.size();
        if(n==0) return 0;
        m = grid[0].size();
        int states = n*m*4*2*2;
        vector<int> dp(states, -1);
        vector<char> flag(states, 0);
        auto valid = [&](int r,int c,int parity)->bool{
            if(r<0 || c<0 || r>=n || c>=m) return false;
            int expected = (parity==0)?2:0;
            return grid[r][c] == expected;
        };
        auto compute = [&](int start)->void{
            if(start < 0 || start >= states) return;
            if(dp[start] != -1) return;
            vector<pair<int,int>> st;
            st.emplace_back(start,0);
            while(!st.empty()){
                auto [s,phase] = st.back();
                st.pop_back();
                if(phase==0){
                    if(dp[s] != -1) continue;
                    if(flag[s] == 1) continue;
                    flag[s] = 1;
                    st.emplace_back(s,1);
                    int tmp = s;
                    int parity = tmp % 2; tmp /= 2;
                    int turn = tmp % 2; tmp /= 2;
                    int dir = tmp % 4; tmp /= 4;
                    int cell = tmp;
                    int r = cell / m;
                    int c = cell % m;
                    if(!valid(r,c,parity)){
                        dp[s] = 0;
                        flag[s] = 2;
                        continue;
                    }
                    int nr = r + dr[dir], nc = c + dc[dir];
                    if(valid(nr,nc,1-parity)){
                        int dep = idx(nr,nc,dir,turn,1-parity);
                        if(dp[dep] == -1 && flag[dep] == 0) st.emplace_back(dep,0);
                    }
                    if(turn){
                        int nd = (dir + 1) % 4;
                        int tr = r + dr[nd], tc = c + dc[nd];
                        if(valid(tr,tc,1-parity)){
                            int dep2 = idx(tr,tc,nd,0,1-parity);
                            if(dp[dep2] == -1 && flag[dep2] == 0) st.emplace_back(dep2,0);
                        }
                    }
                } else {
                    int tmp = s;
                    int parity = tmp % 2; tmp /= 2;
                    int turn = tmp % 2; tmp /= 2;
                    int dir = tmp % 4; tmp /= 4;
                    int cell = tmp;
                    int r = cell / m;
                    int c = cell % m;
                    if(!valid(r,c,parity)){
                        dp[s] = 0;
                        flag[s] = 2;
                        continue;
                    }
                    int best = 0;
                    int nr = r + dr[dir], nc = c + dc[dir];
                    if(valid(nr,nc,1-parity)){
                        int dep = idx(nr,nc,dir,turn,1-parity);
                        best = max(best, dp[dep]);
                    }
                    if(turn){
                        int nd = (dir + 1) % 4;
                        int tr = r + dr[nd], tc = c + dc[nd];
                        if(valid(tr,tc,1-parity)){
                            int dep2 = idx(tr,tc,nd,0,1-parity);
                            best = max(best, dp[dep2]);
                        }
                    }
                    dp[s] = 1 + best;
                    flag[s] = 2;
                }
            }
        };
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 1) continue;
                for(int d=0; d<4; d++){
                    int ni = i + dr[d], nj = j + dc[d];
                    if(ni<0 || nj<0 || ni>=n || nj>=m) {
                        ans = max(ans, 1);
                        continue;
                    }
                    int start = idx(ni,nj,d,1,0);
                    compute(start);
                    if(start>=0 && start < (int)dp.size()) ans = max(ans, 1 + dp[start]);
                }
            }
        }
        return ans;
    }
};