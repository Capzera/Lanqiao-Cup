/************************************************************
 * @file     Playfair_Code/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 15:48:25
************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);//取消输入输出缓存，提速
    string origin, str;
    cin >> origin >> str;
    vector<vector<char>> code(5, vector<char>(5));//定义密码阵
    map<char, pair<int, int> > um;//映射字符对应的密码阵坐标
    set<char> alpha;//记录每个字母是否出现
    for (int i = 0; i < 26; i++) alpha.insert(i + 97);//填充26个字母
    int k = 0, n = origin.size();//k为origin游标
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            code[i][j] = k < n ? origin[k++] : *alpha.begin();
            um[code[i][j]] = {i, j};//记录映射
            alpha.erase(code[i][j]);
        }
    }
    char last = *alpha.begin();//没在字母阵出现过的字母
    n = str.size();
    for (int i = 0; i < n; i += 2) {
        if (i + 1 == n) break;//还剩1个字母，直接退
        char a1 = str[i], a2 = str[i + 1];
        if (a1 == last || a2 == last || a1 == a2) continue;//字母对出现last或字母相同，不处理
        int x1 = um[a1].first, y1 = um[a1].second;
        int x2 = um[a2].first, y2 = um[a2].second;
        if (x1 == x2 || y1 == y2) swap(str[i], str[i + 1]);//同列||同行 直接交换
        else {
            str[i] = code[x1][y2];
            str[i + 1] = code[x2][y1];
        }
    }
    cout << str << endl;
    return 0;
}
