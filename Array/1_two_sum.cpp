// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Learn Map
// https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


//BRUTE FORCE APPROACH
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> answer;
        //brute force
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp = target - nums[i];
                if(temp == nums[j] && j != i){
                    return {i,j};
                }
            }
        }
        return {};
    }
};


//Using HashMap O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> answer;
        //using hashmap

        map<int,int> hash_map;
        for(int i=0;i<n;i++){
            hash_map[nums[i]] = i;
        }
        for(int i=0;i<n;i++){
            int compliment = target - nums[i];
            if(hash_map.find(compliment) != hash_map.end()){
                if(i != hash_map[compliment]){
                    int j = hash_map[compliment];
                    return {i,j};
                }
            }
        }
        return {};
    }
};