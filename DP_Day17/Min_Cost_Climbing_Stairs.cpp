class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
	    int fst = cost[0] , snd = cost[1];
	    if (n < 3) return min(fst, snd);
	    for (int i=2; i<n; i++) {
		    int ccost = cost[i] + min(fst, snd);
		    fst = snd;
		    snd = ccost;
	    }
	return min(fst, snd);
    }
};
