#include<stdio.h>
#include<string.h>

int main()
{
    char str[20];
    fgets (str, 20, stdin);
    int len=strlen(str)-1;
    // int stack[100]={0};
    printf("len : %d\n",len);
    int res=0;
    for(int i=0,index=1;i<len-1;index++){
        if(str[i] > str[index+i])   {
            res++;
            printf("%d %d\n",i,index+i);
        }
        if(i+index==len-1){
            i++;
            index=0;
        }
    }
    printf("res : %d",res);
    return 0;
}