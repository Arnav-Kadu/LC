class Solution {
public:
    int maxDiff(int num) {
        // for nine first non nine 
        int first_non_nine=-1;
        string temp=to_string(num);
        string temp_=temp;
        for(int i=0;i<temp.size();i++){
            if(temp[i]-'0'!=9){
                first_non_nine=temp[i]-'0';
                break;
            }
        }
        for(auto &i:temp){
            if(i-'0'==first_non_nine){
                i='9';
            }
        }
        // for mini first should be one and if it is already one make zero for the just non zero after the first character 
        if(temp_[0]=='1'){
           int non_zero=-1;
           for(int i=1;i<temp_.size();i++){
            if(temp_[i]-'0'!=0 && temp_[i]-'0'!=1){
                non_zero=temp_[i]-'0';
                break;
            }
        }
        for(auto &i:temp_){
            if(i-'0'==non_zero){
                i='0';
            }
        }
        }else{
            char replace=temp_[0];
            for(auto &i:temp_){
                if(replace==i){
                    i='1';
                }
            }
        }

        return stoi(temp)-stoi(temp_);

    }
};