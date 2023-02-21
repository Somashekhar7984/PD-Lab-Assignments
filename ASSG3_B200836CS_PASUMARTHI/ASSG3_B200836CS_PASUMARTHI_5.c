#include<stdio.h>
#include<string.h>
int count = 0;
int merge(int arr[],int temp[],int beg,int mid,int end){
    int i,j,k;
    int count_inverse = 0;
    i = beg;
    j = mid;
    k = beg;
    while((i<=mid-1) && (j<=end)){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
            count_inverse = count_inverse + (mid - i);
        }
        count++;
    }
    while(i<=mid-1){
        temp[k] = arr[i];
        k++;
        i++;
        count++;
    }
    while(j<=end){
        temp[k] = arr[j];
        k++;
        j++;
        count++;
    }
    for(int i = beg;i<=end;i++){
        arr[i] = temp[i];
    }
    return count_inverse;
}
int merge_sort(int arr[],int temp[],int beg,int end){
    int count_inverse = 0;
    if(beg<end){
       int mid = (beg + end)/2;
       count_inverse = count_inverse + merge_sort(arr,temp,beg,mid);
       count_inverse = count_inverse + merge_sort(arr,temp,mid+1,end);
       count_inverse = count_inverse + merge(arr,temp,beg,mid+1,end);
    }
    return count_inverse;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n],temp[n];
    int count_inv = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    count_inv = merge_sort(arr,temp,0,n-1);
    printf("%d\n",count_inv);
    printf("%d",count);
    return 0;
}