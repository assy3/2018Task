#include <stdio.h>

/* 関数宣言 */
static void change(long prm);

/* 関数定義 */
static void change(long prm)
{
    prm = 5;
    printf("prmの値=%d\n", prm);
    return;
}


/* main(処理始まりの関数) */
int main(void)
{
    long num = 3;

    printf("numの値=%d\n", num);
    // 関数呼び出し
    change(num);
    printf("numの値=%d\n", num);

    return 0;

}
