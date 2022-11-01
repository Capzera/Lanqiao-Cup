/************************************************************
 * @file     Interest_calculation/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 17:24:39
************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    double money = 1000;
    int n = 5;
    int i;
    for(i = 0; i < n; i++) {
        money = money + money * 0.03;
        money -= 100;
    }
    printf("%.2f\n", money);

    return 0;
}
