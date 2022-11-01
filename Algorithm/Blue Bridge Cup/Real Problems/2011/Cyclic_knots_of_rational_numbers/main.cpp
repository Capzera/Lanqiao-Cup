#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, t, z;
    scanf("%d,%d",&a, &b);
    vector<int> ans(110);
    int fate=__gcd(a,b);
    a /= fate, b /= fate;
    z = a / b, t = a % b;
    if(t==0) {
        cout<<z;
        return 0;
    }
    if(b % 2 == 0 || b % 5 == 0) {
        cout << z << '.';
        int aa;
        while(t) {
            t *= 10;
            aa = t / b;
            t %= b;
            cout << aa;
        }
        return 0;
    }
    cout << z << ".[";
    int i = 1;
    t *= 10;
    ans[i] = t / b;
    t %= b;
    cout << ans[i];
    i++;
    t *= 10;
    ans[i] = t / b;
    t %= b;
    if(ans[i] == ans[1]) {
        cout << ']';
        return 0;
    }
    cout << ans[i];
    i++;
    while(1) {
        t *= 10;
        ans[i] = t / b;
        t %= b;
        if(ans[i] == ans[1] && t * 10 / b == ans[2]) break;
        cout << ans[i];
        i++;
    }
    cout<<']';
    return 0;
}
