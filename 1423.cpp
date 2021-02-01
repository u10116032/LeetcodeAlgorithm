/*
     Greedy take larger num from begin/end?
     Fail on [2,3,4,4,100,100,1], K=3
	 -----
     [2,3,4,4,100,100,1], k=3
     Rearange
     [100,100,1,2,3,4]
       ^      ^
           ^    ^
              ^   ^
     T:O(n)/S:O(1)
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int n=cardPoints.size();
        int ans=0;
        k=min(k,n);
        int l=n-k, r=n-1;
        for (int i=l; i<=r; ++i) ans+=cardPoints[i];
        int csum=ans;
        for (int i=0; i<k; ++i) {
            csum=csum+cardPoints[(++r)%n]-cardPoints[(l++)%n];
            ans=max(ans,csum);
        }
        return ans;
    }
};
