#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   struct node *next;
   struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;

void print() {
   struct node *ptr = head;
   printf("\n[head] => ");
   while(ptr != NULL) {
       if (ptr->prev != NULL) {
           printf("%d (p:%d", ptr->data, ptr->prev->data);
       } else {
           printf("%d (p:%d", ptr->data, tail->data);
       }
       if (ptr->next != NULL) {
           printf(", n:%d) => ", ptr->next->data);
       } else {
           printf(", n:%d) =>", head->data);
       }
       ptr = ptr->next;
   }
   printf(" [null]\n");
}

void insertEmpty(int data, struct node** headRef, struct node** tailRef) {
    struct node* link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    if ((*headRef) == NULL) {
        printf("head is null");
    }
    link->next = (*headRef);
    link->prev = NULL;
    if ((*headRef) != NULL) {
        (*headRef)->prev = link;
    }
    (*headRef) = link;
    (*tailRef) = (*headRef);
}

void insertFirst(int data, struct node** headRef, struct node** tailRef) {
    struct node* link = (struct node*) malloc(sizeof(struct node));
    if ((*headRef) == NULL) {
        insertEmpty(data, &head, &tail);
    } else {
        link->data = data;
        link->next = (*headRef);
        link->prev = NULL;
        if ((*headRef) != NULL) {
            (*headRef)->prev = link;
        }
        (*headRef) = link;
    }
}

int main() {
   insertFirst(1, &head, &tail);
   insertFirst(2, &head, &tail);
   insertFirst(3, &head, &tail);
   print();
}
