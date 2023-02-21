#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *next;
};
typedef struct node *node;
struct LL{
    node head;
};
typedef struct LL *LL;
node create_node(int k){
    node temp;
    temp = (node)malloc(sizeof(struct node));
    if(temp == NULL){
        exit(0);
    }
    temp->data = k;
    temp->next = NULL;
    return temp;
}
void push(LL L,node x){
    x->next = L->head;
    L->head = x;
}
void pop(LL L){
    node selected = L->head;
    if(selected == NULL){
        printf("-1\n");
    }
    else{
        printf("%d\n",selected->data);
        L->head = L->head->next;
        free(selected);
    }
}
int stack_empty(LL L){
    if(L->head == NULL){
        return -1;
    }
    else{
        return 1;
    }
}
int main(){
    char ch;
    int k;
    LL S;
    S = (LL)malloc(sizeof(struct LL));
    S->head = NULL;
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'i':{
                scanf(" %d",&k);
                node x;
                x = create_node(k);
                push(S,x);
                break;
            }
            case 'd':{
                pop(S);
                break;
            }
            case 'e':{
                int k = stack_empty(S);
                printf("%d\n",k);
                break;
            }
            case 't':
                return 0;
        }
    }
}