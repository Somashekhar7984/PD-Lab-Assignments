#include<stdio.h>
#include<string.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    int new_arr[n];
    int max_sum = 0;
    int min_sum = 0;
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[j]>arr[i]){
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i = 0;i<n;i++){
        new_arr[i] = arr[i];
    }
    for(int i = 0;i<m;i++){
        max_sum = max_sum + arr[n-1-i];
    }
    for(int i = 0;i<m;i++){
        min_sum = min_sum + arr[i];
    }
    printf("%d",max_sum - min_sum);
    return 0;
}