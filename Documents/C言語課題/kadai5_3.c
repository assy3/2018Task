#include <stdio.h>

/* 関数宣言 */
static void change(long *prm);


/* 関数定義 */
static void change(long *prm) //引数でポインタ(アドレス)をもらうよっていう
{
    *prm = 5;
    printf("prmのアドレス=%x\n", prm);
    printf("prmの値=%x\n", *prm);
}



/* main(処理始まりの関数) */
int main(void)
{
    long num = 3;
    long* pNum = NULL; //pNumはポインタを入れる箱
    pNum = &num;

    printf("numのアドレス=%x\n", &num);
    printf("numの値=%x\n", num);
    // 関数呼び出し
    change(pNum);
    printf("numのアドレス=%x\n", &num);
    printf("numの値=%x\n", num);

    return 0;

}
