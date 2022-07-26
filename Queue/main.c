#include <stdio.h>

#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
  if (rear == SIZE - 1) {
    printf("Can not enqueue, Queue is Full\n");
  } else {
    if (front == -1) {
      front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted => %d\n", value);
  }
}

void dequeue() {
  if (front == -1) {
    printf("Can not dequeue, Queue is Empty\n");
  } else {
    printf("Deleted => %d\n", queue[front]);
    front++;
    if (front > rear) {
      front = rear = -1;
    }
  }
}

void print() {
  if (rear == -1) {
    printf("Can not print, Queue is Empty\n");
  } else {
    int i;
    printf("Queue: [");
    for (i = front; i <= rear; i++) {
      if (i == rear) {
        printf("%d", queue[i]);
      } else {
        printf("%d, ", queue[i]);
      }
    }
    printf("]\n");
  }
}

int main() {
  dequeue();

  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);

  enqueue(6);

  print();

  dequeue();
  dequeue();

  print();

  return 0;
}
