#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char key;
    struct node *next;
};
struct node* LL = NULL;
void list_insert_front(){
    char k;
    struct node* insert;
    insert = malloc(sizeof(struct node));
    scanf(" %c",&k);
    insert->key = k;
    insert->next = LL;
    LL = insert;
}
void list_insert_tail(){
    char k;
    struct node *insert, *head;
    insert = malloc(sizeof(struct node));
    scanf(" %c", &k);
    insert->next = 0;
    insert->key = k;
    head = LL;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = insert;
}
void list_delete_first(){
    struct node* temp;
    if (LL == NULL)
        printf("-1\n");
    else {
        temp = LL;
        printf("%c\n",temp->key);
        LL = LL->next;
        free(temp);
    }
}
void list_delete_last(){
    struct node *temp, *prevnode;
    if (LL == NULL)
        printf("-1\n");
    else {
        temp = LL;
        while (temp->next != 0) {
            prevnode = temp;
            temp = temp->next;
        }
        printf("%c\n",temp->key);
        free(temp);
        prevnode->next = 0;
    }
}
void list_insert_after(){
    char x,y;
    scanf(" %c %c",&x,&y);
    struct node *insert,*present;
    insert = (struct node*)malloc(sizeof(struct node));
    present = LL;
    while(present->key != y){
        present = present->next;
    }
    insert->next = present->next;
    present->next = insert;
    insert->key = x;
}
void list_insert_before(){
    char x,y;
    scanf(" %c %c",&x,&y);
    struct node *insert,*present;
    insert = (struct node*)malloc(sizeof(struct node));
    present = LL;
    while (present->key != y)
    {
        present = present->next;
    }
    insert->key = present->key;
    present->key = x;
    insert->next = present->next;
    present->next = insert;
}
void list_delete(){
    char x;
    struct node *delete,*present;
    scanf(" %c",&x);
    delete = (struct node*)malloc(sizeof(struct node));
    present = LL;
    while(present->key != x){
        if(present->next == NULL){
            break;
        }
        present = present->next;
    }
    if(present->key == x){
        if(present->next == NULL){
            free(present);
            printf("-2\n");
        }
        else{
        delete = present->next;
        present->key = delete->key;
        present->next = delete->next;
        printf("%c\n",present->key);
       }
    }
    else{
        printf("-1\n");
    }
}
void print_list(){
    struct node *selected1 = LL;
    while(selected1 != NULL){
        printf("%c ",selected1->key);
        selected1 = selected1->next;
    }
    printf("\n");
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
            list_delete_first();
            break;
            case 'l':
            list_delete_last();
            break;
            case 'a':
            list_insert_after();
            break;
            case 'b':
            list_insert_before();
            break;
            case 'd':
            list_delete();
            break;
            case 'p':
            print_list();
            break;
            case 'e':
            return 0;
        }
    }
}