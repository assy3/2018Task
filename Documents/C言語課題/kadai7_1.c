#include <stdio.h>

/* main(処理始まりの関数) */
int main(void)
{
    char cAry[4] = { 10,20,30, 0 };
    char* pcAry = &(cAry[0]);
    short sAry[4] = { 100,200,300 ,0 };    
    short* psAry = &(sAry[0]);
    int i = 0;
    int j = 0;
while( *pcAry != 0 )
{
	/* 処理 */
    printf("pcAry[%d]の値=%d\n",i, *pcAry);
    printf("pcAry[%d]のアドレス=%x\n",i, pcAry);
	pcAry++;
    i++;
}

while( *psAry != 0 )
{
	/* 処理 */
    printf("psAry[%d]の値=%d\n",i, *psAry);
    printf("psAry[%d]のアドレス=%x\n",i, psAry);
    psAry++;
    j++;
}
}
