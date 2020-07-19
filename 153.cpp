class Solution {
public:
    int findMin(vector<int>& nums)
    {
        /*
            T:O(n) to iterate over all nums annd find out mim integer.
            sorted -> T:O(logn)
            ex:
            0 1 2 3 4 5 6 // l<r
                  ^
            6 0 1 2 3 4 5 // l>r && mid<l
                  ^
            3 4 5 6 0 1 2 // l>r && mid>l
                  ^
            Assume we have no duplicate number here, and no null input.
        */
        int l=0; int r=nums.size()-1;
        while(l<r) {
            int mid=(l+r)/2;
            if (nums[l]<nums[r]) return nums[l];
            else if (nums[mid]<nums[l]) r=mid;
            else l=mid+1;
        }
        return nums[l];
    }
};