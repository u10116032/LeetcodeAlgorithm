/******************** recursive solution ********************/
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        /*
            ex:
            T(n)=T(n/2)+O(1) <-- O(logN)
            1 2 3 3 3 4 5 6 6  l<r
                    ^
            5 6 6 1 2 3 3 3 4  l>r&&mid<l
                    ^
            6 1 2 3 3 3 4 5 6  l==r&&mid<l
                    ^
            3 4 5 6 6 1 2 3 3  l>r&&mid>l
                    ^
            3 3 3 4 5 6 6 1 2  l==r&&mid>l
                    ^
            T(n)=2T(n/2)+O(1) <-- O(N)
            3 1 2 3 3 3 3 3 3  l==r&&mid==l
                    ^
            3 3 3 3 3 3 1 2 3  l==r&&mid==l
                    ^
        */
        return help(nums,0,nums.size()-1);
    }

    int help(vector<int>& nums, int l, int r)
    {
        // cout<<l<<","<<r<<endl;
        if(l>=r) return nums[l];
        if(nums[l]<nums[r]) return nums[l];
        int mid=(l+r)/2;
        if (nums[l]==nums[r]&&nums[mid]==nums[l])
            return min(help(nums,l,mid),help(nums,mid+1,r));
        else if (nums[l]>=nums[r]&&nums[mid]<nums[l])
            return help(nums,l,mid);
        else //if (nums[l]>=nums[r]&&nums[mid]>=nums[l])
            return help(nums,mid+1,r);

    }
};
/*
[5,6,6,1,2,3,3,3,4]
[6,1,2,3,3,3,4,5,6]
[3,1,2,3,3,3,3,3,3]
[3,3,3,3,3,1,2,3,3]
[2,2,2,0,1]
[1,2,3,3,3,4,5,6,6]
[3,4,5,6,6,1,2,3,3]
[3,3,3,4,5,6,6,1,2]
*/

/******************** iterative solution ********************/
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left+(right-left)/2;
            if (nums[left] > nums[mid]){
                left++;
                right=mid;
            }
            else if (nums[mid] > nums[right]){
                left=mid+1;
            }
            else {
                if(nums[left] < nums[right])
                    return nums[left];
                else // nums[l]==nums[mid]==nums[r], handling duplicated nums
                    right--; // remove the tail of duplicate till other case.
            }
        }
        return nums[left];
    }
};
