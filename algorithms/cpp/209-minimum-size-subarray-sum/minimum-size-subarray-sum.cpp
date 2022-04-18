#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int left = 0;
      int right = 0;
      int count = nums.size();
      int sum = 0;
      int min_sub = count;
      bool has_sub = false;

      while( right < count ) {
        if(sum >= target) {
          has_sub = true;
          cout << "left " << left << " right " << right << " sub " << min_sub << endl;
          min_sub = min(right - left, min_sub);
          sum -= nums[left];
          left++;
        } else {
          sum += nums[right];
          right++;
        }
      }

      // 最后一次的判定
      while(sum >= target) {
        has_sub = true;
        cout << "left " << left << " right " << right << " sub " << min_sub << endl;
        min_sub = min(right - left, min_sub);
        sum -= nums[left];
        left++;
      }

      return has_sub ? min_sub : 0;
    }

};


int main() {
  // int target = 7;
  // vector<int> nums = {2,3,1,2,4,3};
  // int target = 4;
  // vector<int> nums = {1,4,4};
  // int target = 11;
  // vector<int> nums = {1,1,1,1,1,1,1,1};
  int target = 15;
  vector<int> nums = {5,1,3,5,10,7,4,9,2,8};
  // nums.push_back(1);

  Solution s;
  int l = s.minSubArrayLen(target, nums);
  cout << l << endl;
}
