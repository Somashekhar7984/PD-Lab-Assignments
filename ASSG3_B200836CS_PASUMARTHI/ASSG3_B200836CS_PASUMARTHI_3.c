#include<stdio.h>
#include<string.h>
int remove_duplicates(int arr[],int n){
      int i,j,k;
    for(i = 0;i<n;i++){
        for(j = i + 1;j<n;j++){
             if(arr[i] == arr[j]){
                 for(k = j; k<n;k++){
                  arr[k] = arr[k+1];
                  }
                  k--;
                  n--;
            }
        }
    }
    return n;
}
int binary_search(int key,int arr[],int beg,int end){
    if(beg>end){
        return 0;
    }
    int mid;
    mid = (beg + end)/2;
    if(key == arr[mid]){
        return 1;
    }
    else if(key>arr[mid]){
        binary_search(key,arr,beg,mid-1);
    }
    else if(key<arr[mid]){
        binary_search(key,arr,mid+1,end);
    }
}
int main(){
    int m,n,f;
    int j = 0;
    scanf("%d %d",&m,&n);
    int arrA[m],arrB[n];
    for(int i = 0;i<m;i++){
        scanf("%d",&arrA[i]);
    }
    fflush(stdin);
    for(int i = 0;i<n;i++){
        scanf("%d",&arrB[i]);
    }
    int new_m,new_n;
    new_m = remove_duplicates(arrA,m);
    new_n = remove_duplicates(arrB,n);
    int beg = 0;
    int end = new_n - 1;
    for(int i = 0;i<new_m;i++){
       f = binary_search(arrA[i],arrB,beg,end);
       if(f == 1){
           printf("%d ",arrA[i]);
           j++;
       }
       else{
           continue;
       }
    }
    if(j == 0){
        printf("-1");
    }
    
    return 0;
}