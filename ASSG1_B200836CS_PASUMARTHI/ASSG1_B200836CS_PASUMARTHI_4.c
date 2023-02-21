#include<stdio.h>
#include<string.h>
void circular_left_shift(int arr[16],int k){
    int arrL[16];
    for(int i = k,j = 0;i<16;i++,j++){
        arrL[j] = arr[i] ;
    }
    for(int i = 0 ; i<k;i++){
        arrL[15-i] = arr[k-1-i]; 
    }
    for(int i = 0;i<16;i++){
         printf("%d",arrL[i]);
     }
}
void circular_right_shift(int arr[16],int k){
    int arrR[16];
    for(int j = k,i = 0;i<16-k;i++,j++){
        arrR[j] = arr[i] ;
    }
    for(int i = 0 ; i<k;i++){
        arrR[i] = arr[15-i]; 
    }
    for(int i = 0;i<16;i++){
         printf("%d",arrR[i]);
     }
}
int convert(int n,int k){
     int arr[16];
     for(int i = 0;i<16;i++){
         arr[15-i] = n%2;
         n = n/2;
     }
     for(int i = 0;i<16;i++){
         printf("%d",arr[i]);
     }
     printf("\n");
     circular_left_shift(arr,k);
     printf("\n");
     circular_right_shift(arr,k);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    convert(n,k);
    return 0;
}