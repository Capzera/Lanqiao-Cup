/************************************************************
 * @file     Move_Letter/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 20:01:48
************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  set<string> m;
  string s("ABCDE*"),re;
  int n;
  cin>>n;
  vector<int> d = {-3, +3, -1, +1};
  while(n--){
    cin>>re;
    if(m.find(re)!=m.end()){
      cout<<1<<endl;
      continue;
    }
    queue<string> q;
    q.push(re);
    while(!q.empty()){
      string p=q.front();
      if(p==re){
        cout<<1<<endl;
        break;
      }
      q.pop();
      int pos=p.find('*');
      for(int i=0;i<4;i++){
        if(i==0&&pos<3) continue;
        if(i==1&&pos>2) continue;
        if(i==2&&pos%3==0) continue;
        if(i==3&&pos%3==2) continue;
        string nxt=p;
        char c=*(p.begin()+pos);
        *(p.begin()+pos)=*(p.begin()+d[i]);
        *(p.begin()+d[i])=c;
        if(m.find(nxt)!=m.end()) continue;
        m.insert(nxt);
        q.push(nxt);
      }
    }
    if(q.empty()){
      cout<<0<<endl;
    }
  }
  return 0;
}
