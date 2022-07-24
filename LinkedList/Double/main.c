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
struct node *prev = NULL;
struct node *current = NULL;

void print() {
   struct node *ptr = head;
   printf("\n[head] (n:%d) => ", ptr->data);
   while(ptr != NULL) {
       if (ptr->prev != NULL) {
           printf("%d (p:%d", ptr->data, ptr->prev->data);
       } else {
           printf("%d (p:[head]", ptr->data);
       }
       if (ptr->next != NULL) {
           printf(", n:%d) => ", ptr->next->data);
       } else {
           printf(", n:[null]) =>");
       }
       ptr = ptr->next;
   }
   printf(" [null]\n");
}

void insertFirst(int data, struct node** headRef) {
    struct node* link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = (*headRef);
    link->prev = NULL;
    if ((*headRef) != NULL) {
        (*headRef)->prev = link;
    }
    (*headRef) = link;
}

int main() {
   insertFirst(1, &head);
   insertFirst(2, &head);
   insertFirst(3, &head);

   print();
}
