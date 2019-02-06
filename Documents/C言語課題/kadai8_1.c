#include <stdio.h>

struct student {
    int   height;
    float weight;
    long  schols;
};

/* main(処理始まりの関数) */
int main(void)
{
    struct student sanaka;
    
    sanaka.height = 175;
    sanaka.weight = 62.5;
    sanaka.schols = 730000;
    
    printf("身長 =  %d\n", sanaka.height);
    printf("体重 =  %.1f\n", sanaka.weight);
    printf("奨学金 =  %ld\n", sanaka.schols);

    return 0;
}



//strcpyは文字列のコピー
