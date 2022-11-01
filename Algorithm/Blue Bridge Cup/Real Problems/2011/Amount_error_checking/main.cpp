/************************************************************
 * @file     Amount_error_checking/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 15:11:56
************************************************************/
#include <bits/stdc++.h>
using namespace std;
int n, target, sum = 0;
vector<vector<int> > ans;
vector<int> loc;
vector<bool> vis;
void dfs(int last, int cursum, vector<int>& nums) {
   if (sum - cursum == target) {
       ans.push_back(loc);
       return;
   }
   for (int i = last; i < n; i++) {
       if (sum - cursum - nums[i] < target || (i && nums[i] == nums[i - 1] && !vis[i - 1])) continue;
       loc.push_back(nums[i]);
       vis[i] = 1;
       dfs(i + 1, cursum + nums[i], nums);
       loc.pop_back();
       vis[i] = 0;
   }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> target >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    vis = vector<bool> (n);
    sort(nums.begin(), nums.end());
    dfs(0, 0, nums);
    for (auto& i : ans) {
        for (auto& j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
