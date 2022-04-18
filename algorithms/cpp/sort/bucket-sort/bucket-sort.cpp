#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

struct Solution {

  void bucket_sort(vector<int> &nums) {
    // 分n个桶
    int min_value=nums[0], max_value=nums[0], bucket_count;
    for(int i=1; i<nums.size(); i++) {
      min_value = min(nums[i], min_value);
      max_value = max(nums[i], max_value);
    }

    // 大约每个桶3个数字
    bucket_count = nums.size() / 3;
    int bucket_value = (max_value - min_value) / bucket_count;

    // 实际上此处的vector<int>应该是引用的形式，算法原理搞清楚就ok了
    vector<vector<int>> r;
    for(int i=0; i<bucket_count; i++) {
      vector<int> va;
      r.push_back(va);
    }

    for(int i=0; i<nums.size(); i++) {
      int index = nums[i] / bucket_value;
      r[index].push_back(nums[i]);
    }


    // 对每个桶进行排序
    for(int i=0; i<bucket_count; i++) {
      vector<int> v = r[i];
      sort(v.begin(), v.end());
      r[i] = v;
    }

    int index = 0;
    // 把每个桶中的元素赋值回去
    for(int i=0; i<bucket_count; i++) {
      vector<int> v = r[i];
      for(int j=0; j<v.size(); j++){
        nums[index++] = v[j];
      }
    }

    return;
  }

};



int main() {
  Solution s = Solution();
  vector<int> nums = {1, 4, 6, 74, 22, 43, 10, 30, 50, 12, 33};
  s.bucket_sort(nums);

  printVector(nums);
  return 0;
}
