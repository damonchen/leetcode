#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.
    int findDuplicate(vector<int>& nums) {
      // 寻找数组中重复的数字，以数字作为下表，进行查找（即要求数字不能超过数组的大小）
      // 由于查找的时候，会遇到环，就成了 142 题
      int slow = nums[0];
      int fast = nums[nums[0]];

      // 有重复的时候，一定会形成环
      while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }

      int index = 0;
      while(index != slow) {
        index = nums[index];
        slow = nums[slow];
      }

      return index;
    }
};

int main() {
  vector<int> nums = {1,3,4,2,2};
  Solution s;
  int l = s.findDuplicate(nums);
  cout << l << endl;
}
