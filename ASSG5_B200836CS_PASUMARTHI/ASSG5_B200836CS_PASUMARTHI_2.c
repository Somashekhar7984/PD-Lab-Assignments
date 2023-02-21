#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *prev;
    struct node *next;
};
struct node *LL = NULL;
void list_insert_front(){
    int k;
    struct node *insert;
    insert = (struct node*)malloc(sizeof(struct node));
    scanf(" %d",&k);
    insert->key = k;
    insert->prev = NULL;
    insert->next = LL;
    LL = insert;
}
void list_insert_tail(){
    int k;
    struct node *insert;
    struct node *head;
    insert = (struct node*)malloc(sizeof(struct node*));
    insert->prev = NULL;
    insert->next = NULL;
    scanf(" %d",&k);
    insert->key = k;
    insert->next = NULL;
    head = LL;
    if(LL == NULL){
        LL = insert;
    }
    else{
        while(head->next != NULL){
            head = head->next;
        }
        insert->prev = head;
        head->next = insert;
    }
}
void list_delete_initial(){
    struct node*temp;
    if(LL == NULL){
        printf("Not Found\n");
    }
    else{
        temp = LL;
        LL = LL->next;
        if(LL != NULL){
            LL->prev = NULL;
        }
        free(temp);
    }
}
void list_delete_last(){
    struct node* temp;
    if(LL == NULL){
        printf("Not Found");
    }
    temp = LL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("%c\n",temp->key);
    if(LL->next == NULL){
        LL = NULL;
    }
    else{
        temp->prev->next = NULL;
        free(temp);
    }
}
void PRINT_list(){
    struct node* begin;
    begin = LL;
    while(begin != NULL){
        printf("%d ",begin->key);
        begin = begin->next;
    }
    printf("\n");
}
void print_reverse(){
    struct node *temp = NULL;
    struct node *current;
    current = LL;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL){
        LL = temp->prev;
    }
    PRINT_list();
}
int main(){
    char ch;
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'f':
            list_insert_front();
            break;
            case 't':
            list_insert_tail();
            break;
            case 'i':
            list_delete_initial();
            break;
            case 'l':
            list_delete_last();
            break;
            case 'r':
            print_reverse();
            break;
            case 'e':
            return 0;
        }
    }
}