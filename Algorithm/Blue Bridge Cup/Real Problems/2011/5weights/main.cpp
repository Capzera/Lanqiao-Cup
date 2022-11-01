/************************************************************
 * @file     5weights/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 17:28:07
************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> weight = {81, 27, 9, 3, 1};
int n;
void dfs(int i, int sum, string ans){
    if(sum == n){
        cout << ans.substr(1);
        return;
    }
    if(i == 5) return;
    dfs(i + 1, sum + weight[i], ans + "+" + to_string(weight[i]));
    dfs(i + 1, sum, ans);
    dfs(i + 1, sum - weight[i], ans + "-" + to_string(weight[i]));
}
int main(){
    cin >> n;
    dfs(0, 0, "");
    return 0;
}
