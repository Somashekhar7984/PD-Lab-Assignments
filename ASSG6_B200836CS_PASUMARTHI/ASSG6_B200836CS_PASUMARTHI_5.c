#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node{
    int key;
    struct node *next;
};
typedef struct node *node;
struct stack{
     node head;
};
typedef struct stack *st;
void push(st stack,node x){
    x->next = stack->head;
    stack->head = x;
}
node pop(st stack){
    node selected = stack->head;
    stack->head = stack->head->next;
    return selected;
}
node create_node(int k){
    node temp;
    temp = (node)malloc(sizeof(struct node));
    if(temp == NULL){
        exit(0);
    }
    temp->key = k;
    temp->next = NULL;
    return temp;
}
int digit(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    else{
        return 0;
    }
}
int evaluate_postfix(char expr[]){
    st stack;
    stack = (st)malloc(sizeof(struct stack));
    stack->head = NULL;
    int n = strlen(expr);
    for(int i = 0;i<n;i++){
        if(expr[i] == ' '){
            continue;
        }
        
        else if(digit(expr[i])){
            int num = 0;
            while(digit(expr[i])){
                num = num*10 + (int)(expr[i] - '0');
                i++;
            }
            i--;
            node x;
            x = create_node(num);
            push(stack,x);
        }
        else{
            node val1,val2;
            val2 = pop(stack);
            val1 = pop(stack);
            if(expr[i] == '+'){
                int k;
                k = val1->key + val2->key;
                node x;
                x = create_node(k);
                push(stack,x);
            }
            else if(expr[i] == '-'){
                int k;
                k = val1->key - val2->key;
                node x;
                x = create_node(k);
                push(stack,x);
            }
            else if(expr[i] == '*'){
                int k;
                k = val1->key * val2->key;
                node x;
                x = create_node(k);
                push(stack,x);
            }
            else if(expr[i] == '/'){
                int k;
                k = val1->key / val2->key;
                node x;
                x = create_node(k);
                push(stack,x);
            }
        }
    }
    node p;
    p = pop(stack);
    return p->key;
}
int main(){
    char expr[10000];
    scanf("%[^\n]s",expr); 
    int val;
    val = evaluate_postfix(expr);
    printf("%d",val);
    return 0;
}