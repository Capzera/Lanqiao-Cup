/************************************************************
 * @file     Upper_triangular_matrix/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 19:11:45
************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, num = 1, i = 0, j = 0, direct = 0;
    cin >> n;
    int up = 0, down = n;
    vector<vector<int> > grid(n, vector<int>(n));
    while (num <= n * (n + 1) / 2) {
        grid[i][j] = num++;
        if (direct == 0) {
            j++;
            if (j == n - i - up) {
                direct = 1;
                i++, j -= 2;
            }
        }
        else if (direct == 1) {
            i++, j--;
            if (i == down) {
                direct = 2;
                i -= 2, j++, down -= 2;
            }
        }
        else if (direct == 2) {
            i--;
            if (i == up) {
                direct = 0;
                i++, j++, up++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) cout << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}
