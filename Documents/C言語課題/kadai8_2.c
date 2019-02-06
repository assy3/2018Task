#include <stdio.h>

typedef struct {
    int a;
    int b;
    int result;
}S_PLUS;


void change(S_PLUS* psp, S_PLUS sp){
    printf("sp = %d\n", sp);
    printf("psp = %d\n", *psp);
    sp.result = sp.a + sp.b;
    printf("sp.result = %d\n", sp.result);
    psp->result = psp->a + psp->b;
    printf("psp->result = %d\n", psp->result);
    return;
}



/* main(処理始まりの関数) */
int main(void)
{
    S_PLUS sp;
    S_PLUS psp;

    sp.a = 3;
    sp.b = 5;
    psp.a = 3;
    psp.b = 5;
    
    change( &psp, sp);

    // 値渡し
    printf("sp.result = %d\n", sp.result);

    // ポインタ渡し
    printf("psp.result = %d\n", psp.result);

    return 0;
}
