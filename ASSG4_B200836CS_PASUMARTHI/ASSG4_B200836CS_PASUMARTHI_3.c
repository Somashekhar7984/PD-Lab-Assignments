#include<stdio.h>
#include<string.h>
struct a
{
  char name[20];
  int size;
};
void swap(int *a,int *b){
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
void read(struct a *ameoba,int n){
    for(int i = 0;i<n;i++){
        scanf("%s %d",ameoba[i].name,&ameoba[i].size);
    }
}
void insert(struct a *ameoba,int n){
    for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
        if(ameoba[j].size<ameoba[i].size){
            swap(&ameoba[j].size,&ameoba[i].size);
            swap_str(ameoba[i].name,ameoba[j].name);
        }
        if(ameoba[i].size==ameoba[j].size){
            if(strcmp(ameoba[i].name,ameoba[j].name) == 1) {
                 swap_str(ameoba[i].name,ameoba[j].name);
            }
         }
        }
    }
}
void combine(struct a *ameoba,int n){
       for(int i = 0;i<n-1;i++){
        printf("%s %s ",ameoba[i].name,ameoba[i+1].name);
        printf("%d",ameoba[i].size+ameoba[i+1].size);
        ameoba[i].size = ameoba[i].size+ameoba[i+1].size;
        insert(ameoba,n);
        printf("\n");
    }
    printf("%s %d",ameoba[n-1].name,ameoba[n-1].size);
}
int main(){
    int n;
    scanf("%d",&n);
    fflush(stdin);
    struct a ameoba[n];
    read(ameoba,n);
    insert(ameoba,n);
    combine(ameoba,n);
    return 0;
}