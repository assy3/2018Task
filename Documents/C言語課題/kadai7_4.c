#include <stdio.h>
#include<string.h>
/* 関数宣言 */
void str2upper(char str[]);

/* 関数定義 */
void str2upper(char str[])
{   /*
 * C言語のサンプルプログラム - Webkaru
 * - 入力したアルファベットを小文字から大文字に変換 -
 */ 
  int i; 
  /* アルファベットの小文字を大文字に変換 */
  for(i=0;i<=strlen(str);i++){
    /* アルファベットの小文字なら変換 */
    if(str[i]>=97&&str[i]<=122)
      str[i]=str[i]-32;
  }
  /* 変換した文字列を出力 */
  printf("変換した文字列 = %s\n", str);
 
    return;
}


/* main(処理始まりの関数) */
int main(void)
{
      /* 文字列 */
    char str[100];
 
    /* 英数字を入力 */
    printf("文字列（英数字）を入力 = ");
    scanf("%s", str);   
    // 関数呼び出し
    str2upper(str);

    return 0;

}    

