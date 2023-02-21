#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int n;
    int sum = 0; // i is no of digits
    scanf("%d",&n);
    int arr[100];
    int i = 0;
    while(n>0){
        arr[i] = n%10 ;
        n = n/10;
        i++;
    }
    for(int j = i - 1;j>=0;j--){
        sum = sum + arr[j]*pow(8,i-1);
        i--;
    }
    printf("%d",sum);
    return 0;
}