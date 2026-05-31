class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        long long sum=mass;
        for(int i=0;i<n;i++){
            if(sum>=asteroids[i]) sum+=asteroids[i];
            if(sum<asteroids[i]) return false;
        }
        return true;
    }
};