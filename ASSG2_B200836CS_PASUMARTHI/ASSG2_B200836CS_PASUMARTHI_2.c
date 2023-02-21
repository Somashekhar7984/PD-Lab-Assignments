#include<stdio.h>
#include<string.h>
int digits(int a,int neg){
    int digit[4];
    int num = a;
    int i = 0;
    int n = 0;
    while(num>0){
        digit[i] = num%10;
        i++;
        n++;
        num = num/10;
    }
    if(a>=100 && digit[3]<=digit[2] && digit[2]<=digit[1] && digit[1]<=digit[0] && neg != 1){
        printf("%d ",a);
    }
    else if(a>=100 && digit[3]<=digit[2] && digit[2]<=digit[1] && digit[1]<=digit[0] && neg == 1){
        printf("%d ",(-1)*a);
    }
    else if(a>=10 && digit[2]<=digit[1] && digit[1]<=digit[0] && neg != 1){
        printf("%d ",a);
    }
    else if(a>=10 && digit[2]<=digit[1] && digit[1]<=digit[0] && neg == 1){
        printf("%d ",(-1)*a);
    }
    else{
        return a;
    }
}
int main(){
    int n;
    int l = 0;
    scanf("%d",&n);
    int arr[n];
    int arr_b[n];
    int negative;
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i<n;i++){
        if(arr[i]<0){
            arr[i] = (-1)*arr[i];
            negative = 1;
        }
        else{
            negative = 0;
        }
       arr_b[i] = digits(arr[i],negative);
       if(arr_b[i] == arr[i]){
       l++;
       }
    }
    if(l == n){
        int c = -1;
        printf("%d",c);
    }
    return 0;
}