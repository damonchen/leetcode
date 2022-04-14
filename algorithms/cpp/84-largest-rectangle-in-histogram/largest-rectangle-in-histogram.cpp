
#include<bits/stdc++.h>
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
      // 递增栈
      stack<int> s;
      int largest = 0;
      heights.push_back(0);     // 退出条件
      int size = heights.size();

      for(int i=0; i<size; i++) {
        if(s.empty() || heights[s.top()] < heights[i]) {
          s.push(i);
        } else {
          int tp = s.top();
          s.pop();

          // cout << heights[tp]  << " i " << i << " " << (s.empty() ? i : i - s.top() - 1 ) << endl;

          int v =  heights[tp] * (s.empty() ? i : i - s.top() - 1);
          largest = largest > v ? largest : v;
          i--;
        }
      }

      return largest;
    }
};

int main() {
  Solution s = Solution();

  vector<int> heights;
  // heights.push_back(2);
  // heights.push_back(1);
  // heights.push_back(2);
  heights.push_back(4);
  heights.push_back(2);
  // heights.push_back(1);
  // heights.push_back(5);
  // heights.push_back(6);
  // heights.push_back(2);
  // heights.push_back(3);

  cout << s.largestRectangleArea(heights) << endl;
}