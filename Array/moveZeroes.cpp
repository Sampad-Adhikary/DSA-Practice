//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

//Approach 1: Using extra space (declaring ans vector)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len == 1 || len == 0){
            return;
        }
        int count = 0;
        for(int i=0;i<len;i++){
            if(nums[i] == 0){
                count ++;
            }
        }
        vector<int> ans;
        for(int i=0;i<len;i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]);
            }
        }
        while(count){
            ans.push_back(0);
            count --;
        }
        nums = ans;
    }
};

//Approach 2: 2 Pointer Approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len == 1 || len == 0){
            return;
        }
        int fast = 0;
        int slow = 0;
        for(fast=0;fast<len;fast++){
            if(nums[fast] != 0){
                swap(nums[slow],nums[fast]);
                slow++;
            }
        }
    }
};