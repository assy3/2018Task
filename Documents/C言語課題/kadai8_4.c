// 任意の構造体配列に対して、データの追加/削除/変更ができるソフト

typedef struct {
    char* name;
    int height;
    int weight;
}S_MEMBER;

/* 構造体に名前と身長と体重を追加する関数 */
void AddDate( struct S_MEMBER* members[], char* name, int height, int weight, int count)
{
    // 構造体配列に名前を追加
    strcpy(members[count]->name , name);
    // 構造体配列に身長をを追加
    members[count]->height = height;
    // 構造体配列に体重を追加
    members[count]->weight = weight;

    return;
}



/* main(処理始まりの関数) */
int main(void)
{

    S_MEMBER members[10] = 
    {
        {"A", 180, 60},
        {"B", 170, 50},
        {"C", 165, 45},
      
    };
    /* 文字列 */
    char str[100];
    int i;
    int j = 1;
    int k = 1;
    int l = 1;
    int m = 1;
    int height_tmp;
    int weight_tmp;
    int count = 3; //最初に登録されている人数

    while(j != 0){
        while(l != 0){
        // 追加
            printf("追加したい人の名前を入力してください。:");
            scanf("%s",str);

            printf("身長を入力してください :");
            scanf("%d", &height_tmp);

            printf("体重を入力してください :");
            scanf("%d", &weight_tmp);
 
            AddDate(members, str, height_tmp, weight_tmp, count);

            printf("追加されました。%s：身長：%d 体重：%d \n",members[count].name, members[count].height, members[count].weight);
 
        
            count++;           
            printf("追加を続けますか? 続ける:1 続けない0 ");
            scanf("%d", &l);
            
        }


        //while(k != 0){
        // 変更
            //printf("変更したい人の名前を入力してください。A or B or C :");
            //scanf("%s", str);
            //for(i = 0; i < 3; i++){
             //   if( strncmp(str,members[i].name,1)==0){ 
              //      printf("%sの身長は%d 体重は%dです。\n",members[i].name, members[i].height, members[i].weight);  
                //    break;
        //        }
         //   }
         //   printf("身長は何にしますか? :");
         //   scanf("%d", &members[i].height);

  //          printf("体重は何にしますか? :");
//            scanf("%d", &members[i].weight);
         
    //        printf("更新されました。%s：身長：%d 体重：%d \n",members[i].name, members[i].height, members[i].weight);
            
      //      printf("変更を続けますか? 続ける:1 続けない0 ");
        //    scanf("%d", &k);
     //   }       
       


    }

    return 0;
}




