#include<stdio.h>
#include<string.h>
int InsertionSortAs(int arr[],int n){
    int temp;
     for(int i = 0;i<n;i++){
         int j = i;
         while(j>0 && arr[j]<arr[j-1]){
             temp = arr[j];
             arr[j] = arr[j-1];
             arr[j-1] = temp;
             j--;
         }
     }
}
int InsertionSortDs(int arr[],int n){
    int temp;
     for(int i = 0;i<n;i++){
         int j = i;
         while(j>0 && arr[j]>arr[j-1]){
             temp = arr[j];
             arr[j] = arr[j-1];
             arr[j-1] = temp;
             j--;
         }
     }
}
void PRINT(int arr[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int l = n/2;
    int j = 0;
    int k = 0;
    int B[n]; // even
    int C[n];   // odd
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
        if(i%2 == 0){
             B[j] = arr[i];
             j++;
        }
        else{
            C[k] = arr[i];
            k++;
        }
    }
    InsertionSortAs(B,j);
    PRINT(B,j);
    printf("\n");
    InsertionSortDs(C,k);
    PRINT(C,k);
    return 0;
}