/************************************************************
 * @file     LCM2/main.cpp
 *
 * @author   陈启航<1786126188@qq.com>
 * @date     2022/11/01 19:09:38
************************************************************/
#include <stdio.h>
#include <stdlib.h>
int f(int a, int b) {
    int i;
    for(i=a;;i += a)
    {
        if(i%b==0) return i;
    }
}
int main(int argc, char* argv[]) {
    printf("%d\n", f(12,15));
    return 0;
}
