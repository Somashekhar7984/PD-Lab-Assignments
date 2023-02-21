#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct queue{
    int size;
    int head;
    int tail;
    char *arr[21];
};
int queue_full(struct queue *q){
    if((q->tail + 1)%q->size == q->head){
        return -1;
    }
    else{
        return 1;
    }
}
int queue_empty(struct queue *q){
    if(q->head == q->tail){
        return -1;
    }
    else{
        return 1;
    }
}
void enqueue(struct queue *q,char str[]){
    if(queue_full(q) == -1){
        printf("-1\n");
    }
    else{
    q->tail++;
    strcpy(q->arr[q->tail],str);
    if(q->tail == q->size - 1){
        q->tail = -1;
    }
    }
}
void dequeue(struct queue *q){
    if(queue_empty(q) == -1){
        printf("-1\n");
    }
    else{
        q->head = q->head + 1;
        printf("%s\n",q->arr[q->head]);
       
    }
}
int main(){
    char ch;
    int val;
    char str[21];
    struct queue q;
    int k;
    int n;
    scanf("%d",&n);
    q.size = n;
    for(int i=0;i<q.size;i++)
    {
        q.arr[i]= (char*)malloc(21*sizeof(char));
    }
    q.head = -1;
    q.tail = -1;
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf(" %s",str);
            enqueue(&q,str);
            break;
            case 'd':
            dequeue(&q);
            break;
            case 'f':
            k = queue_full(&q);
            printf("%d\n",k);
            break;
            case 'e':
            k = queue_empty(&q);
            printf("%d\n",k);
            break;
            case 't':
            return 0;
        }
    }
}