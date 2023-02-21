#include<stdio.h>
#include<string.h>

void slice(char st[],int m,int n,char sub_st[]){
     int i = 0;
     int l = strlen(st);
     char temp[l];
     for(int i = 0;i<l;i++){
         temp[i] = st[i];
     }
     while ((i+m)<n)
     {
         temp[i] = temp[i+m];
         i++;
     }
     temp[i] = '\0';
     if(strcmp(temp,sub_st) == 0){
         for(int i = 0; st[i] != '\0';i++){
                st[i+m] = st[i+n];
         }    
     }
}
int main(){
    char st[10000];
    char sub_st[1000];
    int n1,n2;
    gets(st);
    fflush(stdin);
    gets(sub_st);
    n1 = strlen(st);
    n2 = strlen(sub_st);
    for(int i = 0;i<n1-n2+1;i++){
    slice(st,i,i+n2,sub_st);
       if(st[i+n2] != '\0'){
           for(int j = i;j<n1-n2-i+1;j++){
               slice(st,j,j+n2,sub_st);
           }
       }
    }
    puts(st);
    return 0;
}