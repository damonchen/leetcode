#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> &list) {
  for (vector<int>::iterator it = list.begin(); it != list.end(); it++) {
    cout << " " << *it;
  }
  cout << endl;
}

class Solution {
public:
  double listMedian(vector<int> &nums) {
    int size = nums.size();
    if (size % 2 == 0) {
      int index = size / 2;
      return (nums[index - 1] + nums[index]) / 2.0;
    } else {
      int index = size / 2;
      return nums[index];
    }
  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty()) {
      return listMedian(nums2);
    }

    if (nums2.empty()) {
      return listMedian(nums1);
    }

    vector<int> result;
    int index1 = 0;
    int index2 = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();

    while (true) {
      if (index1 < size1 && index2 < size2) {
        int val1 = nums1[index1];
        int val2 = nums2[index2];
        if (val1 == val2) {
          result.push_back(val1);
          result.push_back(val2);
          index1++;
          index2++;
        } else if (val1 > val2) {
          result.push_back(val2);
          index2++;
        } else {
          result.push_back(val1);
          index1++;
        }
      } else {

        if(index1 < size1) {
          for(int i=index1; i<size1; i++) {
            result.push_back(nums1[i]);
          }
          break;
        }

        if(index2 < size2) {
          for(int i=index2; i<size2; i++) {
            result.push_back(nums2[i]);
          }
          break;
        }
      }
    }

    // printVector(result);

    return listMedian(result);
  }
};

int main() {
  Solution s = Solution();

  vector<int> nums1;
  // nums1.push_back(1);
  // nums1.push_back(3);
  nums1.push_back(1);
  nums1.push_back(2);

  vector<int> nums2;
  // nums2.push_back(2);
  nums2.push_back(3);
  nums2.push_back(4);

  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}