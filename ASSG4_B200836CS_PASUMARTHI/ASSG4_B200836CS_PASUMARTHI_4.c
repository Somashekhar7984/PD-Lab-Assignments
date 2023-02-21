#include<stdio.h>
#include<string.h>

void swap(int *a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert_patient(int Q[],int i,int n){
    scanf("%d",&Q[i]);
    for(int j = 0;j<n;j++){
        for(int k = 0;k<n;k++){
            if(Q[j]<Q[k]){
                swap(&Q[j],&Q[k]);
            }
        }
    }
}

void extract_next_patient(int Q[],int n){
    int k;
    if(n==0){
        printf("-1");
    }
    else{
    printf("%d",Q[0]);
    for(k = 0;k<n-1;k++){
        Q[k] = Q[k+1];
    }
    }
}

void get_next_patient(int Q[],int i,int n){
    if(n == 0){
        printf("-1");
    }
    else{
    printf("%d",Q[i]);
    }
}

void display_queue(int Q[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",Q[i]);
    }
}

void change_token_number(int Q[],int k,int x,int n){
    scanf("%d %d",&k,&x);
    for(int i = 0;i<n;i++){
        if(Q[i] == k){
            Q[i] = x;
        }
    }
    for(int j = 0;j<n;j++){
        for(int k = 0;k<n;k++){
            if(Q[j]<Q[k]){
                swap(&Q[j],&Q[k]);
            }
        }
    }
    
}

int main(){
    char ch;
    int Q[1000];
    int i = 0;//i is for index of array
    int j = 0;
    int n = 0;
    int k,x;
    while(1){
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            n++;
            insert_patient(Q,i,n);
            i++;// incrementing for storing the next element
            //increasing for the size
            break;
            case 'e':
            extract_next_patient(Q,n);
            n--;
            i--;
            break;
            case 'm':
              get_next_patient(Q,j,n);
              break;
            case 'c':
               change_token_number(Q,k,x,n); 
               break;  
            case 'd':
            display_queue(Q,n);
            break;
            case 's':
               return 0;
        }
    }
    return 0;
}