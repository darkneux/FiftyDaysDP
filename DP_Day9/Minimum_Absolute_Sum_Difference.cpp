class Solution {
public:
    int minbound(int key,vector<int> &vec){
        if(key<=vec[0])return vec[0];
        int i =0,j = vec.size()-1;
        int ans = 0; 
        while(i <= j){
            int mid = (i+j)/2;
            if(vec[mid] < key){
                ans = vec[mid];
                i = mid+1;
            }else if(vec[mid] > key){
                 j=mid-1;
            }else{
                ans = key;break;
            }
        }
        return ans;
    }
    int maxbound(int key,vector<int>&vec){
        if(key>=vec[vec.size()-1])return vec[vec.size()-1];
        int i = 0,j = vec.size()-1;
        int ans = 0;
        while(i <= j){
            int mid = (i+j)/2;
            if(vec[mid] > key){
              ans = vec[mid];
              j = mid-1;
            }else if(vec[mid] < key){
                   i = mid+1;
            }else{
                ans = key;break;
            }

        }
        return ans;

    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),mod=1e9+7;
        vector<int> svec(n);
        long long sum = 0;
        for(int i = 0; i < n;i++){
            svec[i] = nums1[i];
            sum=(sum%mod+(abs(nums1[i]-nums2[i])%mod))%mod;
        }
    
        sort(svec.begin(),svec.end());
       
        int ans = sum;
        int dl = 0;
        for(int i = 0;i < n;i++){
            int diff = abs(nums1[i]-nums2[i]);
            int c1 = abs(minbound(nums2[i],svec)-nums2[i]);
            int c2 = abs(maxbound(nums2[i],svec)-nums2[i]);
            int d = min(c1,c2);
            dl = max(dl, abs(d-diff));
        }
    return (ans-dl+mod)%mod;

        
    }
};
