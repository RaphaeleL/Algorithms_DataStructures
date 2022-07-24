#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void print() {
   struct node *ptr = head;
   printf("\n[head] (n:%d) =>", ptr->data);
   while(ptr != NULL) {
       if (ptr->next != NULL) {
           printf(" %d (n:%d) => ", ptr->data, ptr->next->data);
       } else {
           printf(" %d (n:[null]) => ", ptr->data);
       }
       ptr = ptr->next;
   }
   printf(" [null]\n");
}

void insertFirst(int data, struct node** headRef) {
    struct node* link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = (*headRef);
    (*headRef) = link;
}

int main() {
   insertFirst(1, &head);
   insertFirst(2, &head);
   insertFirst(3, &head);

   print();
}
