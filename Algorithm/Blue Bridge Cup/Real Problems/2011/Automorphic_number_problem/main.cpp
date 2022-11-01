/************************************************************
 * @file     Automorphic_number_problem/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 18:51:50
************************************************************/
#include <stdio.h>
#include <stdlib.h>
void zishou() {
    int n;
    for(n = 1; n < 20 * 1000 * 1000; n++) {
        int n2 = n;
        int m = 0;
        for(;;) {
            if(n2 == 0) {
                printf("%d\n", n);
                break;
            }
            int k = n2 % 10;
            m += k * n;
            if(m % 10 != k) break;
            m = m / 10;
            n2 = n2 / 10;
        }
    }
}
int main() {
    zishou();
    return 0;
}
