class Solution {
string s;
int n;
pair<long long,long long> dp[16][11][11][2];
bool vis[16][11][11][2];

private:
   pair<long long,long long> solve(int curr,int prev,int prevprev,bool isleadingzero,bool islimit){

       if(curr==n) return {1,0};

       if(!islimit && vis[curr][prev+1][prevprev+1][isleadingzero])
           return dp[curr][prev+1][prevprev+1][isleadingzero];

       int limit=islimit?s[curr]-'0':9;
       long long totalNumber=0;
       long long totalWave=0;

       for(int digit=0;digit<=limit;digit++){
           bool iszero=isleadingzero && (digit==0);

           int newprevprev=prev;
           int newprev=(iszero)?-1:digit;

           auto [remainNumbers,remainWave]=
               solve(curr+1,newprev,newprevprev,iszero,
                     islimit && (digit==limit));

           if(!iszero && prev>=0 && prevprev>=0){
               bool ispeak=prev>digit && prev>prevprev;
               bool isvalley=prev<digit && prev<prevprev;

               if(ispeak || isvalley) totalWave+=remainNumbers;
           }

           totalNumber+=remainNumbers;
           totalWave+=remainWave;
       }

       if(!islimit){
           vis[curr][prev+1][prevprev+1][isleadingzero]=true;
           dp[curr][prev+1][prevprev+1][isleadingzero]={totalNumber,totalWave};
       }

       return {totalNumber,totalWave};
   }

   long long compute(long long num){
       if(num<100) return 0;
       s=to_string(num);
       n=s.size();

       memset(vis,0,sizeof(vis));

       auto [totalNumbers,totalWave]=solve(0,-1,-1,true,true);
       return totalWave;
   }

public:
    long long totalWaviness(long long num1, long long num2) {
        return compute(num2)-compute(num1-1);
    }
};