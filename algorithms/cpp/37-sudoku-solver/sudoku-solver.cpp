#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 节点位置
struct Pos {
  int row;
  int col;
  int value;
};

const int SIZE = 9;

void printBoard(int *board) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cout << *(board + i * SIZE + j) << ",";
    }
    cout << endl;
  }
  cout << endl;
}

void printVector(vector<int> &may) {
  for (vector<int>::iterator it = may.begin(); it != may.end(); it++) {
    cout << " " << *it;
  }
  cout << endl;
}

void printMay(int row, int col, vector<int> &may) {
  cout << "row: " << row << " col: " << col << " may ";
  printVector(may);
}

void printMayBoard(int *board, int row, int col, vector<int> &may) {
  printBoard(board);
  printMay(row, col, may);
}

void printBoard(vector<vector<char>> &board) {
  for (vector<vector<char>>::iterator iter = board.begin(); iter != board.end();
       iter++) {
    vector<char> &row = *iter;
    for (vector<char>::iterator it = row.begin(); it != row.end(); it++) {
      cout << *it << ",";
    }
    cout << endl;
  }
  cout << endl;
}

class Solution {
public:

  // bool isValidRow(int *board, int row, int value) {
  //   int s = row * size;
  //   for (int i = 0; i < size; i++) {
  //     if (*(board + s + i) == value) {
  //       return false;
  //     }
  //   }
  //   return true;
  // }

  // bool isValidCol(int *board, int col, int value) {
  //   for (int i = 0; i < size; i++) {
  //     if (*(board + i * size + col) == value) {
  //       return false;
  //     }
  //   }
  //   return true;
  // }

  // bool isValidSmallBoard(int *board, int row, int col, int value) {
  //   int r = (row / 3) * 3;
  //   int c = (col / 3) * 3;

  //   for (int i = 0; i < size / 3; i++) {
  //     for (int j = 0; j < size / 3; j++) {
  //       if (*(board + (r + i) * size + c + j) == value) {
  //         return false;
  //       }
  //     }
  //   }
  //   return true;
  // }

  // bool isValidBoard(int *board, int row, int col, int value) {
  //   if (!isValidRow(board, row, value)) {
  //     return false;
  //   }

  //   if (!isValidCol(board, col, value)) {
  //     return false;
  //   }

  //   if (!isValidSmallBoard(board, row, col, value)) {
  //     return false;
  //   }

  //   return true;
  // }

  bool exist(vector<int> &v, int key) {
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == key) {
        return true;
      }
    }
    return false;
  }

  vector<int> findValidNumber(int *board, int row, int col) {
    // 用true来表示有效，false表示无效，数组的索引恰好就是行或者列的可用的数值
    int rowValid[SIZE] = {0};
    int colValid[SIZE] = {0};

    vector<int> rowNum;
    for (int i = 0; i < SIZE; i++) {
      int v = *(board + row * SIZE + i);
      if (v != 0) {
        rowNum.push_back(v);
      }
    }

    vector<int> rowMay;
    for (int i = 0; i < SIZE; i++) {
      if (!exist(rowNum, i + 1)) {
        rowMay.push_back(i + 1);
      }
    }

    vector<int> colNum;
    for (int i = 0; i < SIZE; i++) {
      int v = *(board + i * SIZE + col);
      if (v != 0) {
        colNum.push_back(v);
      }
    }

    vector<int> colMay;
    for (int i = 0; i < SIZE; i++) {
      if (!exist(colNum, i + 1)) {
        colMay.push_back(i + 1);
      }
    }

    vector<int> bb;
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;
    // cout << "row: " << row << " col: " << col << endl;
    for (int i = 0; i < SIZE / 3; i++) {
      for (int j = 0; j < SIZE / 3; j++) {
        // cout << "bb "
        //      << "r " << (r + i) << " ;c " <<  c + j << endl;
        int v = *(board + (r + i) * SIZE + c + j);
        if (v != 0) {
          bb.push_back(v);
        }
      }
    }

    vector<int> bbMay;
    for (int i = 0; i < SIZE; i++) {
      if (!exist(bb, i + 1)) {
        bbMay.push_back(i + 1);
      }
    }

    // cout << "row: " << row << " col: " << col << endl;
    // cout << "row may" << endl;
    // printVector(rowMay);

    // cout << "col may" << endl;
    // printVector(colMay);

    // cout << "bb may" << endl;
    // printVector(bbMay);

    vector<int> find;
    for (vector<int>::iterator it = rowMay.begin(); it != rowMay.end(); it++) {
      if (exist(colMay, *it) && exist(bbMay, *it)) {
        find.push_back(*it);
      }
    }

    // cout << "may" << endl;
    // printVector(find);

    return find;
  }

  bool solveSudoku(int *board, int row, int col, bool &allFilled) {
    vector<int> may = findValidNumber(board, row, col);
    if (may.empty()) {
      // 表明上一次填写是错误的
      return false;
    }

    // 是否填充过
    bool filled = false;
    for (vector<int>::iterator it = may.begin(); it != may.end(); it++) {
      int value = *it;
      *(board + (row * SIZE) + col) = value;
      filled = true;
      // printBoard(board);

      allFilled = true;
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          int *p = board + (i * SIZE) + j;
          if (*p == 0) {
            allFilled = false;
            if (!solveSudoku(board, i, j, allFilled)) {
              *(board + (row * SIZE) + col) = 0;
              // 需要下一次may的处理了
              filled = false;
              goto nextMay;
            }
          }
        }

        // if(filled) {
        //   break;
        // }
      }

      if (allFilled) {
        return true;
      }

    nextMay:;
    }

    return filled;
  }

  bool solveSudoku(int *board) {
    // 递归暴力破解
    bool allFilled = false;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        int *p = board + (i * SIZE) + j;
        if (*p == 0) {
          solveSudoku(board, i, j, allFilled);
        }
      }
    }

    return true;
  }

  void solveSudoku(vector<vector<char>> &board) {
    int newBoard[SIZE * SIZE] = {0};

    int i = 0, j = 0;
    for (vector<vector<char>>::iterator iter = board.begin();
         iter != board.end(); iter++, i++) {
      vector<char> row = *iter;
      vector<int> newRow;
      j = 0;
      for (vector<char>::iterator it = row.begin(); it != row.end();
           it++, j++) {
        if (*it == '.') {
          *(newBoard + i * SIZE + j) = 0;
        } else {
          *(newBoard + i * SIZE + j) = *it - 48;
        }
      }
    }

    // printBoard(newBoard);

    if (solveSudoku(newBoard)) {
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          board[i][j] = *(newBoard + i * SIZE + j) + 48;
        }
      }
    }
  }
};

// http://www.sudokufans.org.cn/forums/topic/6/

vector<vector<char>> createBoard() {
  char question[9][9] = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };

  vector<vector<char>> board;
  for (int i = 0; i < 9; i++) {
    vector<char> row(question[i], question[i] + 9);
    board.push_back(row);
  }
  return board;
}

// [
//  ["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]
// ]

int main() {
  Solution s = Solution();
  vector<vector<char>> board = createBoard();
  s.solveSudoku(board);
  printBoard(board);
}
