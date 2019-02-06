#include <stdio.h>

/* main(処理始まりの関数) */
int main(void)
{
    long num = 3;
    long* pNum = &num; //pNumはポインタを入れる箱
    long** ppNum = &pNum;
    printf("ppNumからnumの値を参照 %d\n",**ppNum);

    return 0;

}
