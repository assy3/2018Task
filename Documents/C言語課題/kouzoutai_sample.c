#include <stdio.h>
#include<string.h> 

struct seiseki {
    int no;
    char name[20];
    double average;
};

void seidesp2(struct seiseki *sei);

struct seiseki seiset(void);
struct seiseki seiset2(void);

int main(void){
    int i;
    int j;
    int k;
    int index;
    int flag;
    struct seiseki seito2[10] = {{1001, "中田", 76.5},{1002, "橋本", 65.2},{1003, "綿", 82.8}};

    
    seidesp2(seito2);

    // 構造体の値を追加
    for(i = 3; i < 10; i++){
        seito2[i] = seiset();
        
        printf("追加を続ける:0 続けない 1 ");
        scanf("%d", &flag);
        if(flag == 1){
            break;
        }    
    }
    seidesp2(seito2);

    // 構造体の値を削除(値を初期化)
    for(j = 0; j < 10; j++){
    printf("削除したいインデックス： \n");
    scanf("%d", &index);
    seito2[index] = seiset2();
    printf("削除を続ける:0 続けない 1 \n");
    scanf("%d", &flag);
        if(flag == 1){
            break;
        }  
    }

    seidesp2(seito2);

    // 構造体の値を更新
    for(k = 0; k < 10; k++){
    printf("更新したいインデックス： \n");
    scanf("%d", &index);
    seito2[index] = seiset();
    printf("更新を続ける:0 続けない 1 \n");
    scanf("%d", &flag);
        if(flag == 1){
            break;
        }  
        
    }
    
    seidesp2(seito2);


    return 0;
}

// 関数定義

void seidesp2(struct seiseki *sei)
{
    int i; 
    // 構造体に追加
    for(i=0; i<10; i++){
        printf("%d %s %f\n", sei->no, sei->name, sei->average);
        sei++;
    }

}

// 追加
struct seiseki seiset(void){
    struct seiseki sei2;
    int num;
    char name[20];
    int avg;

    printf("番号を入力してください :");
    scanf("%d", &num);
    printf("追加したい人の名前を入力してください。:");
    scanf("%s",name);
    printf("平均を入力してください :");
    scanf("%d", &avg);

    
    sei2.no = num;
    strcpy(sei2.name, name);
    sei2.average = avg;

    return sei2;

}

// 削除(初期化)
struct seiseki seiset2(void){
    struct seiseki sei2;
    
    sei2.no = 0;
    strcpy(sei2.name, "");
    sei2.average = 0.000000;

    return sei2;

}



