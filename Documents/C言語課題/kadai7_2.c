#include <stdio.h>
/* main(処理始まりの関数) */
int main(void)
{
    int i = 0;
    char str[30]; //←文字列を入れるための配列を用意する
    //char* str = &(str[0]);
    printf("文字列を入力してください\n");
    scanf("%s",str); //←scanfに配列の先頭アドレスを入れる ( この場合、29文字までしか入力できないので注意 )
    printf("%s\n",str); //←入力した文字を出力する
    // str と &(str[0]) は同じ    

while( i != sizeof(str))
{
	/* 処理 */
    printf("%s\n",str); //←入力した文字を出力する
    // printf("str[%d]の値=%d\n",i, *str); //配列の0番めのポインタの値
    printf("str[%d]の値=%c\n",i, str[i]); 
    //printf("str[%d]の文字コード=%s\n",i, str[i]);
    //printf("str[0]のアドレス=%x\n",str);
    printf("str[%d]の文字コード=%x\n",i, str[i]);
    printf("str[%d]のアドレス=%x\n",i, &str[i]);
    printf("\n");
    i++;
}
}




