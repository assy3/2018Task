#include <stdio.h>
#include <time.h>
#define swap(type, x, y) do {type t; t=x; x=y; y=t; } while (0)

/* 関数宣言 */
void insert_sort(int randAry[], int ary_size);
void select_sort(int randAry[], int ary_size);
void buble_sort(int randAry[], int ary_size);

    
    // 挿入ソード関数
    void insert_sort(int randAry[], int ary_size){
        int i;
        int j;
        int x;
        // 挿入ソート前
        for(i = 0; i < ary_size; i++)
        {
            printf("%d ",randAry[i]);
        
        }    

        // 挿入ソートアルゴリズム
        for(i = 0; i < ary_size; i++)
        {
            x = randAry[i];

            j = i;
            while ((randAry[j - 1] > x) && (j > 0)){
                randAry[j] = randAry[j - 1];
                j = j - 1;
            }        
            randAry[j] = x;
            
        }

        printf("\n");
        // 挿入ソート後
        for(j = 0; j < ary_size; j++)
        {
            printf("%d ",randAry[j]);
        
        }
        printf("\n");
    }


    // 選択ソート関数    
    void select_sort(int randAry[], int ary_size){
        int i;
        int j;
        int k;
        int max;
        int max_index;
        // 選択ソート前
        for(i = 0; i < ary_size; i++)
        {
            printf("%d ",randAry[i]);
        
        }    

        // 選択ソートアルゴリズム
        for(i = ary_size - 1; i > 0; i--)
        {
            max=randAry[0]; max_index = 0;
            for(j = 1; j <= i; j++){
                if(randAry[j] >= max) { max = randAry[j]; max_index=j;}
            
            }
            swap(int, randAry[max_index], randAry[i]);
            
        }

        printf("\n");
        // 選択ソート後
        for(k = 0; k < ary_size; k++)
        {
            printf("%d ",randAry[k]);
        
        }

        printf("\n");

    }

    // バブルソート関数    
    void buble_sort(int randAry[], int ary_size){
        int i;
        int j;
        int k;
        int temp;
        // バブルソート前
        for(i = 0; i < ary_size; i++)
        {
            printf("%d ",randAry[i]);
        
        }    

        // バブルソートアルゴリズム
        for(i = 0; i < ary_size; i++)
        {
            for(j = ary_size - 1; j > i; j--){
                if(randAry[j] < randAry[j-1]) {
                    temp = randAry[j];
                    randAry[j] = randAry[j-1];
                    randAry[j-1] = temp; 
                }
            
            }
        }

        printf("\n");
        // バブルソート後
        for(k = 0; k < ary_size; k++)
        {
            printf("%d ",randAry[k]);
        
        }

        printf("\n");

    }




/* main(処理始まりの関数) */
int main(void)
{
    int randAry[] = {24, 71, 35, 82, 50, 63, 77, 71, 1, 15, 24, 85, 99, 3, 57};
    int temp_Ary1[] = {24, 71, 35, 82, 50, 63, 77, 71, 1, 15, 24, 85, 99, 3, 57};
    int temp_Ary2[] = {24, 71, 35, 82, 50, 63, 77, 71, 1, 15, 24, 85, 99, 3, 57};
    int ary_size = sizeof(randAry) / sizeof(randAry[0]);
    time_t start,end;
    clock_t c1,c2;
    

    c1 = clock();    
    //start = time(NULL);
    // 選択ソート呼び出し
    select_sort(randAry, ary_size);    
    //end = time(NULL);    
    //printf("time = %d[s]\n", (int)(end-start)); 
    c2 = clock();
    printf("select_sort_time = %f[s]\n", (double)(c2-c1)/CLOCKS_PER_SEC);   

    c1 = clock();
    //start = time(NULL);    
    // 挿入ソート呼び出し
    insert_sort(temp_Ary1, ary_size);
    //end = time(NULL);
    //printf("time = %d[s]\n", (int)(end-start));
    c2 = clock();
    printf("insert_sort_time = %f[s]\n", (double)(c2-c1)/CLOCKS_PER_SEC);

    c1 = clock();    
    //start = time(NULL);
     // バブルソート呼び出し
    buble_sort(temp_Ary2, ary_size);
    //end = time(NULL);
    //printf("time = %d[s]\n", (int)(end-start));
    c2 = clock();
    printf("buble_sort_time = %f[s]\n", (double)(c2-c1)/CLOCKS_PER_SEC);

    

    

    

    return 0;

}



 

