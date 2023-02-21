#include<stdio.h>
#include<string.h>

int Index(char S[],char sub[],int n,int l,int s)
{
    int k=0,b;
    for(int i=s;i<n-l+1;i++)
    {
        k=0;int index=i;b=0;
        if(S[i]==sub[k])
        {
            for(int j=0;j<l;j++)
            {
                if(S[index+j]!=sub[j])
                {
                    b=1;
                }
            }
            if(b==1)
            {
                continue;
            }
            else
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    char S[100],F[100],R[100];int c=0;
    scanf("%[^\n]s",S);
    getchar();
    char sub[100];
    scanf("%[^\n]s",sub);
    int n=strlen(S);
    int l=strlen(sub);
    //printf("%d\n",Index(S, sub, n, l, 0));
    for(int i=0;i<n;i++)
    {
        R[i]=S[i];
    }
    for(int i=0;i<n-l+1;i++)
    {
        int index=Index(S, sub, n, l, i);
        if(index==-1)
        {
            break;
        }
        for(int j=0;j<l;j++)
        {
            R[index+j]='1';
        }
    }
    R[n]='\0';
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(R[i]!='1')
        {
            F[j]=R[i];
            j++;
        }
    }
    F[j]='\0' ;
    puts(F);
}
