#include <stdio.h>

/* main(処理始まりの関数) */
int main(void)
{
    int ary[9][9];
    int ary_size = sizeof(ary[0]) / sizeof(ary[0][0]);
    int i, j;
    for(i = 1; i < ary_size+1; i++)
    {
        for(j = 1; j < ary_size+1; j++){
            ary[i][j] = i * j;
            printf("%d, ", ary[i][j]);     
        }
        printf("\n");
    }

    return 0;

}

