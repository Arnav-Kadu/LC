class Solution {
public:
int maxTurbulenceSize(vector<int>& arr) {
    int n=arr.size();
    if(n==1)return 1;
    int maxsize=1;
    int len=1;
    int flag=0;
    /*
    flag=0 , no condition
    flag=1 , arr[i]>arr[i+1]
    flag=2 , arr[i]<arr[i+1]
    */
    for (int i = 0; i <n-1; i++)
    {
        if((flag==0 || flag==2) && arr[i]>arr[i+1]){
            flag=1;
            len++;
            maxsize=max(len,maxsize);
        }
        else if ((flag==0 || flag==1) && arr[i]<arr[i+1])
        {
            flag=2;
            len++;
            maxsize=max(maxsize,len);
        }
        else{
            if(arr[i]==arr[i+1]){
                len=1;
            }
            else len=2;
        }
    }   
   return maxsize;        
}
};