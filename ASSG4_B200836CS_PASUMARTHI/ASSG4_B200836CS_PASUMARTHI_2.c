#include<stdio.h>
#include<string.h>
void swap(int *a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_str(char *str1,char *str2){
    char temp[20];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}
struct s
{
    int id;
    char name[20];
    int rank;
};

void enter(struct s *student,int i,int n){
     scanf("%d %s ",&student[i].id,student[i].name);
     scanf("%d",&student[i].rank);
     for(int x = 0;x<n;x++){
         for(int y = 0;y<n;y++){
             if(student[x].rank<student[y].rank){
                 swap(&student[x].rank,&student[y].rank);
                 swap_str(student[x].name,student[y].name);
                 swap(&student[x].id,&student[y].id);
             }
         }
     }
}

void interview(struct s *student,int n){
    if(n == 0){
        printf("-1");
    }
    else{
    printf("%d ",student[0].id);
    printf("%s",student[0].name);
    for(int x = 0;x<n;x++){
        student[x].id = student[x+1].id;
        strcpy(student[x].name,student[x+1].name);
        student[x].rank = student[x+1].rank;
    }
    }
}

void list(struct s *student,int n){
    if(n <= 0){
        printf("-1");
    }
    else{
    for(int i = 0;i<n;i++){
        printf("%d ",student[i].id);
    }
    }
}

int main(){
    char ch;
    int i = 0;
    int n = 0;
    int j = 0;
    struct s student[1000];
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'e':
            n++;
            enter(student,i,n);
            i++;
            break;
            case 'i':
            interview(student,n);
            n--;
            i--;
            break;
            case 'l':
            list(student,n);
            break;
            case 't':
            return 0;
        }
    }
    return 0;
}