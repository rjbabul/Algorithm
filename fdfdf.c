#include<stdio.h>
int num[1000000];
int main()
{

    int n,max=0,x,i,j, min=100000000;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        num[x]++;
        if(min>x) min=x;
        if(max<x) max=x;
    }
    for(i=max;i>=min;i--){
        if(num[i]>0)for(j=1;j<=num[i];j++){
            printf("%d ", i);
        }
    }

    return 0;
}
