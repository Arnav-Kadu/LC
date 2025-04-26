class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        int n=a.size();
        bool mn=false;
        bool mx=false;
        int prev_mx=0;
        int prev_mn=0;
        long long ans=0;
        int nahi_lena_tujhe=0;
        for(int i=0;i<n;i++){
            if(a[i]>maxK || a[i]<minK){
                nahi_lena_tujhe=i+1;
            }
            if(a[i]==maxK){
                mx=true;
                prev_mx=i;
            }
            if(a[i]==minK){
                mn=true;
                prev_mn=i;
            }
            if(mn && mx){
                ans+=max(0,min(prev_mn,prev_mx)-nahi_lena_tujhe+1);
            }
        }
        return ans;
    }
};