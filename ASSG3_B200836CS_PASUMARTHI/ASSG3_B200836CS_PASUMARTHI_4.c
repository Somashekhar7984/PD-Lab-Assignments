#include<stdio.h>
#include<string.h>
int count = 0;
int merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int arr1[n1],arr2[n2];
    for(int i = 0;i<n1;i++){
        arr1[i] = arr[l+i];
    }
    for(int i = 0;i<n2;i++){
        arr2[i] = arr[m+i+1];
    }
    i = 0;
    j = 0;
    k = l;
    for(i = 0,j = 0;i<n1 && j<n2;k++){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        count = count + 1;
    }
    for(int p = i;p<n1;p++){
        arr[k] = arr1[p];
        k++;
        count++;
    }
    for(int q = j;q<n2;q++){
        arr[k] = arr2[q];
        k++;
        count++;
    }
}
int merge_sort(int arr[],int l,int r){
    if(l<r){
        int m = (l + r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d",count);
    return 0;
}