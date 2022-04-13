#include <iostream>
#include <vector>
using namespace std;

void printMatrix(int n, vector<vector<int> >& matrix) {
    for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

class Solution {
public:
    int fillMatrix(vector<vector<int> > &matrix, int start, int end, int value) {
      int row = start;
      int col = start;
      int count = end - start;

      if (count == 1) {
        matrix[row][col] = value++;
        return value;
      }

      // top
      for(int i=0; i<count-1; i++) {
        matrix[row][i+col] = value++;
      }

      // right
      for(int i=0; i<count-1; i++) {
        matrix[row+i][end-1] = value++;
      }


      // bottom
      for(int i=0; i<count-1; i++) {
        matrix[end-1][end-1-i] = value++;
      }

      // left
      for(int i=0; i<count-1; i++) {
        matrix[end-1-i][col] = value++;
      }

      return value;
    }

    vector<vector<int> > generateMatrix(int n) {
      vector<vector<int> > matrix(n);
      for(int i=0; i<n; i++) {
        matrix[i] = vector<int>(n);
      }

      int value = 1;
      int i = 0;
      while(true) {
        // 通过递归的方式填充
        value = fillMatrix(matrix, i, n-i, value);
        if(value > n*n) {
          break;
        }
        i++;
      }

      return matrix;
    }
};




int main() {
  Solution s = Solution();
  int n = 6;
  vector<vector<int> > matrix = s.generateMatrix(n);
  printMatrix(n, matrix);
}
