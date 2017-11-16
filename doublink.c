/*
Doubly Linked List
*/
#include<stdlib.h>
#include<stdio.h>
struct LinkedList{
    int data;
    struct LinkedList *next;
    struct LinkedList *prev;
};

typedef struct LinkedList list;
void InsertFront(list *head, int val);
void AddBefore(list *head, int val1, int val2);
void Delete(list *head, int val);
void Display(list *head);
int main(){
    int flag = 1, op, el, val;
    list *head = (list *) malloc(sizeof(list));
    head->next = NULL;
    head->prev = NULL;
    printf("1 - Add at Beginning\n2 - Add after a particular value\n3 - Delete a node with the given value\n4 - Display\n5 - Exit\n");
    while(flag){
        printf("Enter your choice : \n");
        scanf("%d", &op);
        switch(op){
            case 1: printf("Enter the value\n");
                    scanf("%d", &el);
                    InsertFront(head, el);
                    break;
            case 2: printf("Enter the value\n");
                    scanf("%d", &el);
                    printf("Enter the value to the left of which you want to add another node\n");
                    scanf("%d", &val);
                    AddBefore(head, val, el);
                    break;
            case 3: printf("Enter the value to delete : \n");
                    scanf("%d", &el);
                    Delete(head, el);
                    break;
            case 4: Display(head);
                    break;
            case 5: flag = 0;
                    break;
        default: printf("Choice is incorrect, Enter a correct choice\n");
                     break;
        }
    }
    return 0;
}
void InsertFront(list *head, int val){
     list *newNode = (list *) malloc(sizeof(list));
     if(head->next == NULL){
         newNode->data = val;
         newNode->prev = head;
         newNode->next = NULL;
         head->next = newNode;
         return;
     }
     newNode->data = val;
     head->next->prev = newNode;
     newNode->next = head->next;
     head->next = newNode;
     newNode->prev = head;
}
void AddBefore(list *head, int val1, int val2){
    list *node = (list *) malloc(sizeof(list));
    if(head->next == NULL){
        printf("%d is not present in the list\n", val1);
        return;
    }


    head = head->next;
    while(head != NULL){
        if(head->data == val1){
               node->data = val2;
               node->next = head;
               node->prev = head->prev;
               head->prev->next = node;
               head->prev = node;
               return;
           }
           else{
               head = head->next;
           }
       }
       printf("%d is not present in the list\n", val1);
}
void Delete(list *head, int val){
       if(head->next == NULL){
           printf("%d is not present n the list\n", val);
       }
       head = head->next;
       while(head != NULL){
           if(head->data == val){
               if(head->next == NULL){
                   head->prev->next = head->next;
                   free(head);
                   return;
               }
               head->prev->next = head->next;
               head->next->prev = head->prev;
               free(head);
               return;
           }
           else{
               head = head->next;
           }
       }
       printf("%d is not present n the list\n", val);
}
void Display(list *head){
    if(head->next == NULL){
        printf("The elements in the doubly linked list are {}\n");
        return;
    }
    printf("The elements in the doubly linked list are ");
    while(head->next != NULL){
        if(head->next->next == NULL){
            printf("%d", head->next->data);
            break;
        }
        printf("%d ", head->next->data);
        head = head->next;
     }
    printf("\n");
}
