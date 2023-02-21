#include<stdio.h>
#include<string.h>
int count = 0;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int max_heapify(int arr[],int i,int n){
    int largest;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[left]>arr[i]){
        largest = left;
        count = count + 1;
    }
    else{
        count = count + 1;
        largest = i;
    }
    if(right < n && arr[right]>arr[largest]){
        largest = right;
        count = count + 1;
    }
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        max_heapify(arr,largest,n);
    }
}
int build_max_heap(int arr[],int n){
    for(int i = (n/2) - 1;i>=0;i--){
          max_heapify(arr,i,n);
    }
}
int heap_sort(int arr[],int n){
    build_max_heap(arr,n);
    for(int i = n-1 ;i>=0;i--){
        swap(&arr[0],&arr[i]);
        max_heapify(arr,0,i);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     heap_sort(arr,n);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n%d",count);
    return 0;
}