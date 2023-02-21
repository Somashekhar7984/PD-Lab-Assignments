#include<stdio.h>
#include<string.h>

int main(){
    int n;
    int max_sum = 0;
    int max_elements = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int j = 0;j<n;j++){
       if(arr[j]>=0){
           max_sum = max_sum + arr[j];
           max_elements++;
       }
    }
    printf("%d %d",max_sum,max_elements);
    return 0;
}