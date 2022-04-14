
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
    int largestRectangleArea(vector<int>& heights) {
      int size = heights.size();
      if(size == 1) {
        return heights[0];
      }

      vector<int> rect;
      for(int i=0; i<size; i++) {
        vector<int> sub;
        int minVal = heights[i];
        sub.push_back(minVal);

        for(int j=i+1; j<size; j++) {
          sub.push_back(heights[j]);
          if(minVal > heights[j] ) {
            minVal = heights[j];
            break;
          }
        }

        // 两种情况，第一种情况，第一个最小，第二种情况，最后一个最小
        int subSize = sub.size();
        if(subSize == 1) {
          rect.push_back(sub[0]);
          continue;
        }


        if(sub[0] < sub[subSize-1]) {
          int largest = sub[0] * subSize;
          rect.push_back(largest);
        } else {
          // 最后一个最小
          int v1 = sub[0] * (subSize-1);
          int v2 = sub[subSize-1] * subSize;
          rect.push_back(v1 > v2 ? v1: v2);
        }

        // int largest = largestRectangleArea(sub);

        // cout << "minVal: " << minVal << endl;
        // rect.push_back(largest);
      }

      // printVector(rect);

      size = rect.size();
      if(size == 0) {
        return 0;
      }
      int largest = rect[0];
      for(int i=0; i<size; i++) {
        if(largest < rect[i]) {
          largest = rect[i];
        }
      }

      return largest;
    }
};

int main() {
  Solution s = Solution();

  vector<int> heights;
  heights.push_back(2);
  heights.push_back(4);
  // heights.push_back(2);
  // heights.push_back(1);
  // heights.push_back(5);
  // heights.push_back(6);
  // heights.push_back(2);
  // heights.push_back(3);

  cout << s.largestRectangleArea(heights) << endl;
}