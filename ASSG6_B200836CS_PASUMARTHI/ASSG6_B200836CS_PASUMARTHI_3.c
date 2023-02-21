#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
	int top;
	int size;
	int* array;
};
typedef struct stack *stack;
stack create_stack( int size )
{
	stack stack = (struct stack*)
                    malloc(sizeof(struct stack));
	if (!stack)
		return NULL;
    
	stack->top = -1;
	stack->size = size;
	stack->array = (int*) malloc(stack->size *sizeof(int));
	return stack;
}
int empty(stack stack){
    if(stack->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
char peek(stack stack){
    return stack->array[stack->top];
}
char pop(stack stack){
    if(!empty(stack)){
        return stack->array[stack->top--];
    }
    return '#';
}
void push(stack stack,char op){
    stack->top++;
    stack->array[stack->top] = op;
}
int prec(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    return -1;
}
int operand(char ch){
    if(ch>='a' && ch<='z'){
        return 1;
    }
    else{
        return 0;
    }
}
int infix_to_postfix(char *expr){
    int i,k;
    stack stack;
    stack = create_stack(strlen(expr));
    if(!stack)
    {
        return -1;
    }

    for(i = 0,k = -1;expr[i];i++)
    {
        if(operand(expr[i])){
            k++;
            expr[k] = expr[i];
        }
        else if(expr[i] == '('){
            push(stack,expr[i]);
        }
        else if(expr[i] == ')'){
            while(!empty(stack) && peek(stack)!= '('){
                k++;
                expr[k] = pop(stack);
            }
            if(!empty(stack) && peek(stack) != '('){
                return -1;
            }
            else{
                pop(stack);
            }
        }    
        else{
            while(!empty(stack) && prec(expr[i]) <= prec(peek(stack))){
                k++;
                expr[k] = pop(stack);
            }
            push(stack,expr[i]);
        }
    }
    while(!empty(stack)){
        k++;
        expr[k] = pop(stack);
    }
    k++;
    expr[k] = '\0';
    printf("%s",expr);
}

int main(){
    char expr[500];
    scanf("%s",expr);
    infix_to_postfix(expr);
    return 0;
}