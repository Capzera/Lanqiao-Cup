/************************************************************
 * @file     With_fraction/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 20:09:14
************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<bool> sentry;
vector<int> ans;
int cnt=0;
int N;
void equal(int first, int end)
{	int s1 = 0, s2 = 0, s3 = 0;
    for(int j=0; j<9; ++j){
        if(j<=first)
        {
            s1 = s1*10;
            s1 += ans[j];
        }
        if(first<j && j<end){
            s2 = s2*10;
            s2 += ans[j];
        }
        if(j >= end){
            s3 = s3*10;
            s3 += ans[j];
        }
    }
    if(s2 % s3 == 0 && N == s1 + (s2/s3))
        cnt++;
}

void check()
{
    for(int first = 0; first < 9; first++){
        for(int end = first + 2; end < 9; end++){
            equal(first, end);
        }
    }

}

void dfs(int index)
{
    if(index == 9) {
        check();
        return;
    }

    for(int i=1; i<=9; i++){
        if(sentry[i]) continue;
        sentry[i] = true;
        ans[index] = i;
        dfs(index+1);
        sentry[i] = false;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ans = vector<int> (9);
    sentry = vector<bool> (9);
    cin>>N;
    dfs(0);
    cout<<cnt;
    system("pause");
    return 0;
}
