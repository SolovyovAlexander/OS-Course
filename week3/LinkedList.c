#include "LinkedList.h"


struct LinkedList *list = NULL;


struct LinkedList{
    int size;
    struct List_Node *head;

};

struct List_Node{
    int data;
    struct List_Node *next;
};


void insert_node(int data){
    if(list==NULL){
        list=malloc(sizeof(struct list*));
        list->size=1;
        struct List_Node *node=malloc(sizeof(struct List_Node*));
        node->data=data;
        node->next=NULL;
        list->head=node;
    }
    else{
        struct List_Node* pointer;
        pointer=list->head;
        while(pointer->next!=NULL){
            pointer=pointer->next;
        }
        struct List_Node* new=malloc(sizeof(struct List_Node*));
        new->data=data;
        new->next=NULL;
        pointer->next=new;
        list->size=list->size+1;
    }
}

void delete(int number_of_element){
    if (number_of_element==0){
        if(list->head->next!=NULL){
            list->head=list->head->next;
        }
        else{
            list->head=NULL;
        }
    }
    else if(list!=NULL && number_of_element+1<=list->size && number_of_element>=0){
        struct List_Node* pointer=list->head;
        for (int i = 0; i <number_of_element; ++i) {
            pointer=pointer->next;
        }
        if(pointer->next==NULL){
            struct List_Node* previous=list->head;
            for (int i = 0; i <number_of_element-1 ; ++i) {
                previous=previous->next;
            }
            previous->next=NULL;
            pointer=NULL;
        }
        else{
            struct List_Node* previous=list->head;
            for (int i = 0; i <number_of_element-1 ; ++i) {
                previous=previous->next;
            }
            previous->next=pointer->next;
            pointer=NULL;
        }
    }
}

void print_list(){
    struct List_Node* pointer=list->head;
    while(pointer!=NULL){
        printf("%d ",pointer->data);
        pointer=pointer->next;
    }
}