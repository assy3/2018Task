#include <stdio.h>

/* main(処理始まりの関数) */
int main(void)
{
    char ary[3] = {1, 2, 3};
    char moji = "1";
    int ary_size = sizeof(ary) / sizeof(ary[0]);
    int i;
    for(i = 0; i < ary_size; i++)
    {
        printf("%c\n", ary[i]);
        printf("%c\n", moji);
    }

    return 0;

}

