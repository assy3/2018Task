#include <stdio.h>

/* main(処理始まりの関数) */
int main(void)
{
    char ary[5];
    int ary_size = sizeof(ary) / sizeof(ary[0]);
    int i;
    for(i = 0; i < ary_size; i++)
    {
        printf("アドレス%d %x\n",i, &ary[i]);
    }
    return 0;

}
