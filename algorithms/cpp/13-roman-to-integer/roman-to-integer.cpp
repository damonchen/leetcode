#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      int length = s.size();
      int sum = 0;
      for(int i=0; i<length; i++) {
        char v = s[i];
        if( i < length-1 ) {
          char next = s[i+1];
          bool compound = false;
          switch(v) {
            case 'I':
              if(next == 'V') {
                sum += 4;
                compound = true;
              }
              if(next == 'X') {
                sum += 9;
                compound = true;
              }
              break;
            case 'X':
              if(next == 'L') {
                sum += 40;
                compound = true;
              }
              if(next == 'C') {
                sum += 90;
                compound = true;
              }
              break;
            case 'C':
              if(next == 'D') {
                sum += 400;
                compound = true;
              }
              if(next == 'M') {
                sum += 900;
                compound = true;
              }
              break;
            default:
              break;
          }

          // 如果是组合的话，跳过当前的和下一个
          if(compound) {
            i++;
            continue;
          }
        }

        switch(v) {
          case 'I':
            sum += 1;
            break;
          case 'V':
            sum += 5;
            break;
          case 'X':
            sum += 10;
            break;
          case 'L':
            sum += 50;
            break;
          case 'C':
            sum += 100;
            break;
          case 'D':
            sum += 500;
            break;
          case 'M':
            sum += 1000;
            break;
        }
      }

      return sum;
    }
};


int main() {
  Solution s = Solution();
  cout << s.romanToInt("MCMXCIV") << endl;
  cout << s.romanToInt("III") << endl;
  cout << s.romanToInt("LVIII") << endl;
}