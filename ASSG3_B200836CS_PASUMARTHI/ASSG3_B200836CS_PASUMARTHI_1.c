#include<stdio.h>
#include<string.h>
int binary_search(int arr[],int beg,int end,int val,int f,int *c){
    int mid;
    mid = (beg + end)/2;
    if(beg>end){
       return -1;
    }
    if(arr[mid] == val){
        f = 1;
        printf("%d\n",mid);
        printf("%d",*c);
        return f;
    }
    else if(val<arr[mid]){
       *c = *c + 1;
       binary_search(arr,beg,mid-1,val,f,c);
    }
    else if(val>arr[mid]){
        *c = *c + 1;
        binary_search(arr,mid+1,end,val,f,c);
    }
}
int main(){
    int n,value;
    int found = 0;
    int count = 1; 
    int k ;
    scanf("%d",&n);
    int arr[n];
    int beg,end;
    beg = 0;
    end = n-1;
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&value);
    k = binary_search(arr,beg,end,value,found,&count);
    if(k == -1){
        printf("-1\n");
        printf("%d",count);
    }
    return 0;
}