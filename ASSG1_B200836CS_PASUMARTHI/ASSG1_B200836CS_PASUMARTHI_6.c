#include<stdio.h>
#include<string.h>
int gcd(int a,int x,int y){
    if(x%a == 0 && y%a == 0){
        printf("%d",a);
    }
    else {
        a--;
        gcd(a,x,y);
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if (a<0){
        a = (-1)*a;
    }
    if(b<0){
        b = (-1)*b;
    }
    if(a>b && a%b == 0){
        printf("%d",b);
    }
    else if(b>a && b%a == 0){
        printf("%d",a);
    }
    else if (a>b) {
      gcd(b,a,b);
    }
    else if(a<b){
        gcd(a,a,b);
    }
    
    return 0;
}