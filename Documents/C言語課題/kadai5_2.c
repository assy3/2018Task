#include <stdio.h>

/* 関数宣言 */
static void change(long prm);


/* 関数定義 */
static void change(long prm)
{
    prm = 5;
    printf("prmのアドレス=%x\n", &prm);
}



/* main(処理始まりの関数) */
int main(void)
{
    long num = 3;

    printf("numのアドレス=%x\n", &num);
    // 関数呼び出し
    change(num);
    printf("numのアドレス=%x\n", &num);

    return 0;

}
