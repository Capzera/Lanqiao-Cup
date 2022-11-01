/************************************************************
 * @file     Combinatorial_number_problem/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 19:29:43
************************************************************/
#include <stdio.h>
#include <stdlib.h>

int f(int n, int m) {
    if(m > n) return 0;
    if(m == 0) return 1;
    return f(n - 1, m - 1) + f(n - 1, m);
}
int main(int argc, char* argv[]) {
    printf("%d\n", f(10, 3));
    printf("%d\n", f(5, 3));
    printf("%d\n", f(5, 2));
    return 0;
}
