#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char key;
    struct node *left;
    struct node *right;
    struct node *next;
};
typedef struct node *node;
struct BT{
    node root;
};
typedef struct BT *BT;
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
node create_node(char ch){
    node temp;
    temp = (node)malloc(sizeof(struct node));
    if(temp == NULL){
        exit(0);
    }
    temp->key = ch;
    temp->left = NULL;
    temp->right = NULL;
    temp->next = NULL;
    return temp;
}
int operand(char ch){
    if(ch >= 'a' && ch<= 'z'){
        return 1;
    }
    else{
        return 0;
    }
}
int operator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    else{
        return 0;
    }
}
node construct_tree(char *expr){
    int i=0;
    st stack;
    stack = (st)malloc(sizeof(struct stack));
    stack->head = NULL;
    node x;
    while(expr[i] != '\0'){
        x = create_node(expr[i]);
        if(operand(expr[i])){
            push(stack,x);
        }
        else if(operator(expr[i])){
             x->right = pop(stack);
             x->left = pop(stack);
             push(stack,x);
        }
        i++;
    }
    return x;
}
void inorder(node x){
    if(x == NULL){
        return;
    }
    else{
        inorder(x->left);
        printf("%c",x->key);
        inorder(x->right);
    }
}
void preorder(node x){
    if(x == NULL){
        return;
    }
    else{
        printf("%c",x->key);
        preorder(x->left);
        preorder(x->right);
    }
}
void postorder(node x){
    if(x == NULL){
        return;
    }
    else{
        postorder(x->left);
        postorder(x->right);
        printf("%c",x->key);
    }
}
int main(){
    char ch;
    char expr[10000];
    BT T;
    T = (BT)malloc(sizeof(struct BT));
    T->root = NULL;
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'e':{
                scanf(" %s",&expr);
                T->root = construct_tree(expr);
                break;
            }
            case 'i':
                inorder(T->root);
                printf("\n");
                break;
            case 'p':
                preorder(T->root);
                printf("\n");
                break; 
            case 's':
                postorder(T->root);
                printf("\n");
                break;         
            case 't':
                return 0;
                break;              
        }
    }
}