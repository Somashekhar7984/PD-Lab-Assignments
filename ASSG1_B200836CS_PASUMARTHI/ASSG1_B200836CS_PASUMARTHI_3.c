#include<stdio.h>
#include<string.h>

int main(){
    char st[1000];
    gets(st);
    int len;
    len = strlen(st);
    for(int i = 0;i<len;i++){
        if(st[i]>='a' && st[i]<='z'){
            st[i] = st[i] - 32;
        }
        else if(st[i]>='A' && st[i]<='Z'){
            st[i] = st[i] + 32;
        }
    }
    puts(st);
    return 0;
}