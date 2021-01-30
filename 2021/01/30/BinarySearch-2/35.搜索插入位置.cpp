/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        int l=0,r=nums.size()-1,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
};
// @lc code=end

