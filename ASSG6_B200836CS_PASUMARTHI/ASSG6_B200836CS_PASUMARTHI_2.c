#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *next;
};
typedef struct node *node;
struct Queue{
    node head;
};
typedef struct Queue *Queue;
node create_node(int k){
    node temp;
    temp = (node)malloc(sizeof(struct node));
    if(temp == NULL){
        exit(0);
    }
    temp->key = k;
    temp->next = NULL;
}
void enqueue(Queue L,node x){
    node selected;
    selected = L->head;
    if(selected != NULL){
        while(selected->next != NULL){
            selected = selected->next;
        }
        selected->next = x;
    }
    else{
        L->head = x;
    }
}
void dequeue(Queue L){
    node selected = L->head;
    if(selected == NULL){
        printf("-1\n");
    }
    else{
        printf("%d\n",selected->key);
        L->head = L->head->next;
        free(selected);
    }
}
int Queue_empty(Queue Q){
    node selected = Q->head;
    if(selected == NULL){
        return -1;
    }
    else{
        return 1;
    }
}
int main(){
    char ch;
    int k;
    Queue Q;
    Q = (Queue)malloc(sizeof(struct Queue));
    Q->head = NULL;
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'i':{
                scanf(" %d",&k);
                node x;
                x = create_node(k);
                enqueue(Q,x);
                break;
            }
            case 'd':{
                dequeue(Q);
                break;
            }
            case 'e':{
               int k = Queue_empty(Q);
               printf("%d\n",k);
               break;
            }
            case 't':
                return 0;
        }
    }
}



