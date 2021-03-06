#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	// 使用滑动窗口方式解答
    int lengthOfLongestSubstring(string s) {
      map<char, bool> cont;
      int len = s.length();

	  int left = 0;
	  int right = 0;
	  int longest = 0;
	  while(right < len) {
		  char r = s[right];
		  int sub_max = 0;
		  // 右边的先滑动
		  // cout << " left " << left << " right " << right << endl;
		  if(!cont[r]) {
			cont[r] = true;
			right++;
		  } else {
			  // 左边向右滑动
			  // 在子串中找到重复字符的位置
			  int middle = left;
			  while(middle < right) {
				  if(s[middle] == r) {
					  break;
				  }
				  middle++;
			  }
			  // cout << " left " << left << " middle " << middle << " right " << right << endl;
			  sub_max = max(middle-left, right-middle);
			  // 移除重复的
			  for(int i=left; i<=middle; i++) {
				  cont.erase(s[i]);
			  }

			  left = middle + 1;
		  }

		// 让最后没有重复的一次，能够得到计算
		 sub_max = max(sub_max, right-left);

		 longest = max(longest, sub_max); 
	  }

      return longest;
    }
};


int main() {
  string str = "abcabcbb";
  // string str=" "; 
  // string str = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  Solution s;
  int l = s.lengthOfLongestSubstring(str);
  cout << l << endl;
}
