#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage
{
    int number;
    struct num_storage *next;
} tNumStorage;

typedef struct num_stor_head
{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
} tNumStorHead;


void sort_list(tNumStorHead *list, int input);
void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);


int main (void)
{
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void initial_list(tNumStorHead *list)
{
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list)
{
    tNumStorage *node_ptr = list->head;

    printf("  list->counts: %d\n", list->counts);
    printf("  The sorted list: ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n\n");
}
void get_input(tNumStorHead *list){
    int num;
    printf(" input a number : ");
    scanf("%d",&num);
    if(num==-1) return;
    list->counts++;
    sort_list(list,num);
    print_list(list);
    get_input(list);
}
void sort_list(tNumStorHead *list, int input){
    tNumStorage *node=(tNumStorage*)malloc(sizeof(tNumStorage));
    node->number=input;
    node->next=NULL;
    if(list->head==NULL && list->tail==NULL){
        list->head=node;
        list->tail=node;
        return ;
    }
    tNumStorage *curr=list->head;
    // insert to head
    if(node->number < curr->number){
        node->next=curr;
        list->head=node;
        return ;
    }
    if(list->tail->number < node->number){
        tNumStorage *temp=list->tail;
        temp->next=node;
        list->tail=node;
        return ;
    }
    while(curr!=list->tail){
        if(node->number < curr->next->number && node->number > curr->number ){
            node->next=curr->next;
            curr->next=node;
        }
        curr=curr->next;
    }
    return ;
}