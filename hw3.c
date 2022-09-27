#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct num_list
{
    int counts;
    int *p_list;
}tNumList;

void bubble_sort(tNumList *list);
void merge(tNumList *list1, tNumList *list2);
int swap(int *a,int *b);

int main(){
    tNumList *listnum1=(tNumList*)malloc(sizeof(tNumList));
    printf("please enter how many number in list :");
    scanf("%d",&(listnum1->counts));
    // printf("check : numsber: %d \n",listnum1->counts);
    listnum1->p_list=(int*)malloc(sizeof(int)*listnum1->counts);
    printf("please input %d numbers : ",listnum1->counts);
    for(int i=0;i<listnum1->counts;i++){
        scanf("%d",&(listnum1->p_list[i]));
        if(getchar()=='\n') break;
    }
    // for(int i=0;i<listnum1->counts;i++){
    //     printf(" %d ",(listnum1->p_list[i]));
    // }

    printf("\n");

    tNumList *listnum2=(tNumList*)malloc(sizeof(tNumList));
    printf("please enter how many number in list :");
    scanf("%d",&(listnum2->counts));
    // printf("check : numsber: %d \n",listnum2->counts);
    listnum2->p_list=(int*)malloc(sizeof(int)*listnum2->counts);
    printf("please input %d numbers : ",listnum2->counts);
    for(int i=0;i<listnum2->counts;i++){
        scanf("%d",&(listnum2->p_list[i]));
        if(getchar()=='\n') break;
    }
    // for(int i=0;i<listnum2->counts;i++){
    //     printf(" %d ",(listnum2->p_list[i]));
    // }


    bubble_sort(listnum1);
    printf("\nsort list1 : ");
    for(int i=0;i<listnum1->counts;i++){
        printf(" %d ",(listnum1->p_list[i]));
    }
    bubble_sort(listnum2);
    printf("\nsort list2 : ");
    for(int i=0;i<listnum2->counts;i++){
        printf(" %d ",(listnum2->p_list[i]));
    }
    printf("\nmerged list : ");
    merge(listnum1,listnum2);
    return 0;
}

int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(tNumList *list){
    for(int i=1;i<=list->counts;i++){
        for(int j=0;j<list->counts-i;j++){
            if(list->p_list[j]>list->p_list[j+1]){
                swap(&(list->p_list[j]),&(list->p_list[j+1]));
            }
        }
    }
}

void merge(tNumList *list1, tNumList *list2){
    int index1=0;
    int index2=0;
    while(list1->counts > index1 && list2->counts > index2){
        if(list1->p_list[index1]<list2->p_list[index2]){
            printf(" %d ",list1->p_list[index1++]);
        }else{
            printf(" %d ",list2->p_list[index2++]);
        }
    }
    while(list1->counts != index1){
        printf(" %d ",list1->p_list[index1++]);
    }
    while(list2->counts != index2){
        printf(" %d ",list2->p_list[index2++]);
    }
}
