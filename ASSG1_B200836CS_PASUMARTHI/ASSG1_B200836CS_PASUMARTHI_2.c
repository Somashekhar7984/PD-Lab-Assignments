#include<stdio.h>
#include<string.h>
void reccurence(int a,int arr[],int n){
    int count = 0;
    int index[n];
    int j = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == a){
            count++;
            index[j] = i;
            j++;
        }
    }
    if(count>1){
    printf("%d ",a);            // try to make a structure and return that structure to main function
    for(int i = 0;i<j;i++){
        printf("%d ",index[i]);
    }
    printf("%d\n",count);
    }
}
int main(){
    int n;
    int i,j,k;
    scanf("%d",&n);
    int arr[n];
    int arr_d[n];
    int n_d = n;
    for(int i = 0 ;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i<n;i++){
        arr_d[i] = arr[i];
    }
    for( i = 0;i<n_d;i++){
        for( j = i+1;j<n_d;j++){
            if(arr_d[i] == arr_d[j]){
                for( k = j;k<n_d;k++){
                    arr_d[k] = arr_d[k+1];
                }
                n_d--;
                k--;
            }
        }
    }
    if(n_d == n){
        printf("%d",-1);
    }
    else{
     for(int i = 0;i<n;i++){
           reccurence(arr_d[i],arr,n);
        }
    }
            return 0;
    
}