#include <stdio.h>
#include<string.h> 

typedef struct {
    char* name;
    int height;
    int weight;
}S_MEMBER;


/* main(処理始まりの関数) */
int main(void)
{

    S_MEMBER members[3] = 
    {
        {"A", 180, 60},
        {"B", 170, 50},
        {"C", 165, 45}
      
    };
    /* 文字列 */
    char str[100];
    int i;

    printf("height = %s\n", members[1].name);
    printf("変更したい人の名前を入力してください。A or B or C :");
    scanf("%s", str);

    for(i = 0; i < 3; i++){
        if( strncmp(str,members[i].name,1)==0){ 
            printf("%sの身長は%d 体重は%dです。\n",members[i].name, members[i].height, members[i].weight);  
            break;
        }
    }
    printf("%d\n",i);

    printf("身長は何にしますか? :");
    scanf("%d", &members[i].height);

    printf("体重は何にしますか? :");
    scanf("%d", &members[i].weight);
 
    printf("更新されました。%s：身長：%d 体重：%d \n",members[i].name, members[i].height, members[i].weight);

    return 0;
}
