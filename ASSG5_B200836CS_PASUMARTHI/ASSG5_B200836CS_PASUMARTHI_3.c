#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stack_empty(char s[],int n,int *top){
    if(*top == -1)
        return -1;
    else
        return 1;    
}
int stack_full(char s[],int n,int *top){
    if(*top == n-1){
        return -1;
    }
    else{
        return 1;
    }
}
void push(char s[],char k,int n,int *top){
    scanf(" %c",&k);
    if(stack_full(s,n,top) == -1){
     printf("-1\n");
    }
    else{
    *top = *top + 1;
    s[*top] = k;
    }
}
void pop(char s[],int n,int *top){
    if(stack_empty(s,n,top) == -1){
        printf("-1");
    }
    else{
        *top = *top - 1;
        printf("%c",s[(*top)+1]);
    }
    printf("\n");
}

void peek(char s[],int n,int *top){
    if(stack_empty(s,n,top) == -1){
        printf("-1");
    }
    else{
    printf("%c",s[*top]);
    }
    printf("\n");
}

int main(){
    char ch;
    char k;
    int n;
    int top = -1;
    scanf("%d",&n);
    char s[n];
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            push(s,k,n,&top);
            break;
            case 'd':
            pop(s,n,&top);
            break;
            case 'p':
            peek(s,n,&top);
            break;
            case 't':
            return 0;
        }
    }
}