class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int ans=0,cur=0;
        for (int g:gain) {
            cur+=g;
            ans=max(ans,cur);
        }
        return ans;
    }
};