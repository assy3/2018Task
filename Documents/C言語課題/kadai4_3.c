#include <stdio.h>
#include <math.h>

/* 関数宣言 */
void select(int number);

/* 関数定義 */
void select(int number)
{
    int div_num[] = {3, 5, 7, 11, 13, 17};
    int i;
    for(i = 0; i < (sizeof(div_num) / sizeof(div_num[0])); i++)
    {
        if(number % div_num[i] == 0)
        {
            printf("%dは%dで割り切れます\n", number, div_num[i]);
        }    
    }

    return;
}


/* main(処理始まりの関数) */
int main(void)
{
    int input;

    printf("整数を入力してください。");
    scanf("%d", &input);
    
    // 関数呼び出し
    select(input);

    return 0;

}
