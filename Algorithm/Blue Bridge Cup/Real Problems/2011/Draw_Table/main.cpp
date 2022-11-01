/************************************************************
  * @file     Draw_Table/main.cpp
  *
  * @author   陈启航<1786126188@qq.com>
  * @date     2022/11/01 18:17:46
************************************************************/
#include <bits/stdc++.h>
using namespace std;
vector<string> sign = {"┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘", "│", "─", " "};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i <= 2 * m; i++) {
    if (!i) {//首行
      cout << sign[0];
      for (int j = 0; j < 2 * n - 1; j++)
        cout << (j % 2 ? sign[1] : sign[10]);
      cout << sign[2] << endl;
    }
    else if (i == 2 * m) {//末行
      cout << sign[6];
      for (int j = 0; j < 2 * n - 1; j++)
        cout << (j % 2 ? sign[7] : sign[10]);
      cout << sign[8] << endl;
      break;
    }
    else if (i % 2) {//奇数行
      for (int j = 0; j <= 2 * n - 1; j++)
          cout << (j % 2 ? sign[11] : sign[9]);
      cout << sign[9] << endl;
    }
    else {//偶数行
      cout << sign[3];
      for (int j = 0; j < 2 * n - 1; j++)
        cout << (j % 2 ? sign[4] : sign[10]);
      cout << sign[5] << endl;
    }
  }
  return 0;
}
