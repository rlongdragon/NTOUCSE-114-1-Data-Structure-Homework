#include <iostream>

int queue_size = 0;
int count = 0;
typedef struct {
  int key;
  /* other fields */
} element;

// void printList(element* list, int length) {
//   for (int i = 0; i < length; i++) {
//     printf("%d", list[i].key);

//     if (i == length - 1)
//       printf("\n");
//     else
//       printf(" ");
//   }
// }

element circularQueue[100];
int rear = 0;
int front = 0;

void addq(element item) {
  // if (front == rear) {
  if (count == queue_size) {
    printf("FULL\n");
    return;
  }

  rear = (rear + 1) % queue_size;
  circularQueue[rear] = item;
  count++;
}

void popq() {
  // if (front == rear) {
  if (count == 0) {
    printf("EMPTY\n");
    return;
  };

  front = (front + 1) % queue_size;
  printf("%d\n", circularQueue[front].key);
  count--;
}

int main() {
  scanf("%d", &queue_size);
  queue_size--;

  int code;
  while (1) {
    if (scanf("%d", &code) != 1) {
      break;  // Exit on scan failure
    }

    if (code == -1) {
      break;  // Exit when code is -1
    }

    // printf("\033[104m DEBUG \033[0m \033[94m%d - %d %d : => ", code, front,
    //        rear);
    // printList(queue, queue_size);
    // printf("\033[0m");

    switch (code) {
      case 1:
        element value;
        scanf("%d", &value.key);
        addq(value);
        break;

      case 0:
        popq();
        break;
    }
  }
  return 0;
}