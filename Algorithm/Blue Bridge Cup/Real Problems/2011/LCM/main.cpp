/************************************************************
 * @file     LCM/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 10:12:20
************************************************************/
#include <bits/stdc++.h>
using namespace std;
string Hpremul(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size(), jw = 0;
    vector<int> a(len1), b(len2), c(len1 + len2 + 1, 0);
    for (int i = 0; i < len1; i++) a[len1 - i - 1] = s1[i] - '0';
    for (int i = 0; i < len2; i++) b[len2 - i - 1] = s2[i] - '0';
    for (int i = 0; i < len1; i++) {
        jw = 0;
        for (int j = 0; j < len2; j++) {
            c[i + j] += a[i] * b[j] + jw;
            jw = c[i + j] / 10;
            c[i + j] %= 10;
        }
        if (jw) c[i + len2] += jw;
    }
    bool flag = false;
    s1 = "";
    for (int i = c.size() - 1; i >= 0; i--) {
        if (c[i]) flag = 1;
        if (flag) s1 += c[i] + '0';
    }
    return s1;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    iota(nums.begin(), nums.end(), 0);//预设数字数组
    //求贡献度
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j < i; j++)
            if (nums[i] % nums[j] == 0) nums[i] /= nums[j];
    }
    string fac1 = to_string(nums[1]);
    for (int i = 2; i <= n; i++) {
        string fac2 = to_string(nums[i]);
        fac1 = Hpremul(fac1, fac2);
    }
    cout << fac1 << endl;
    return 0;
}
/*
1 1
2 2
3 6
4 24
5 120
6 120
7 420 1 2 3 2 5 1 7
*/
