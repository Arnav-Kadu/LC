class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt[123]={0};
        int mark[26]={0};

        for(auto i:word){
            cnt[i]++;

            if('a'<=i && i<='z'){
                if(cnt[i-'a'+'A']>=1){
                    mark[i-'a']=1;
                }
            }
            else{
                if(cnt[i-'A'+'a']>=1){
                    mark[i-'A']=1;
                }
            }
        }

        int count=0;

        for(int i=0;i<26;i++){
            count+=mark[i];
        }

        return count;
    }
};