#include<stdio.h>
#include<string.h>
int binary_search(int beg,int end,int val,int count){
     int mid;
     mid = (beg + end)/2;
     count++;
    if(mid == val){
       printf("%d\n",val);
       printf("%d",count);
    }
    if(val<mid){
        binary_search(beg,mid-1,val,count);
    }
    if(val>mid){
        binary_search(mid+1,end,val,count);
    }
}
int main(){
    int n,value,c;
    int count = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&value);
    for(int i = 0;i<n;i++){
        if(arr[i] == value){
            c = i;
            break;
        }
    }
    int beg = 0;
    int end = n-1;
    binary_search(beg,end,c,count);
    return 0;
}