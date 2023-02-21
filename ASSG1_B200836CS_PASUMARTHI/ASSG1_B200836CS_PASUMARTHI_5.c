#include<stdio.h>
#include<string.h>
int reccurence(int a,int arr[],int size){
         int count = 0;
         for(int i = 0;i<size;i++){
             if(arr[i] == a){
                   count++;
             }
         }
         return count;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int k = m+n;
    int l = 0;
    int x,y,z;
    int n_d = k;
    int arr1[m],arr2[n],t_arr[k],temp[k],single[k];
    int count = 0;
    for(int i = 0;i<m;i++){
        scanf("%d",&arr1[i]);
        t_arr[i] = arr1[i];
    }
    for(int i = 0;i<n;i++){
        scanf("%d",&arr2[i]);
        t_arr[i+m] = arr2[i];
    }
    for(int i = 0;i<k;i++){
        temp[i] = t_arr[i];
    }
    for( x = 0;x<n_d;x++){
        for( y = x+1;y<n_d;y++){
            if(temp[x] == temp[y]){
                for( z = y;z<n_d;z++){
                    temp[z] = temp[z+1];
                }
                n_d--;
                z--;
            }
        }
    }
    for(int i = 0,j = 0;i<z;i++){
        int re_occur;
       re_occur = reccurence(temp[i],t_arr,k);
       if(re_occur>1){
           for(int j = 0;j<re_occur;j++){
               printf("%d ",temp[i]);
           }
       }
       else{
               single[j] = temp[i];
               l++;
               j++;
           }
       }
    for(int j = 0 ;j<l;j++){
        printf("%d ",single[j]);
    }
    
    return 0;
}