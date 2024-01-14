class Solution {
public:
    int climbStairs(int n) {
        if(n < 3)return n;
        int srt1 = 1,srt2 = 2;
        for(int i = 3;i <= n;++i){
            int temp = srt1+srt2;
            srt1=srt2;
            srt2 = temp;
        }
        return srt2;
    }
};
