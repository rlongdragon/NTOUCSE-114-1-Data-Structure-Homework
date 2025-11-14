
#include <iostream>

typedef struct Node Node;
typedef struct Node* NodePtr;
struct Node {
  int value;
  NodePtr next;
};

void printLL(NodePtr ptr) {
  while (ptr) {
    printf(" %d ", ptr->value);
    ptr = ptr->next;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (; n > 0; n--) {
    NodePtr front = nullptr;
    NodePtr back = nullptr;

    while (true) {
      int offset;
      char mode;
      int value;

      scanf("\n%c", &mode);
      if (mode == 'q') {
        break;
      }
      if (mode == 'i') {
        scanf("%d %d", &value, &offset);
        // printf("%c %d %d\n", mode, value, offset);

      } else {
        scanf("%d", &value);
        // printf("%c %d\n", mode, value);
      }

      if (!front) {
        front = (NodePtr)malloc(sizeof(Node));
        back = front;
        front->value = value;
        front->next = nullptr;
      } else {
        switch (mode) {
          case 'f': {
            NodePtr temp = (NodePtr)malloc(sizeof(Node));
            temp->value = value;
            temp->next = front;
            front = temp;
            break;
          }
          case 'i': {
            // printf("%d %d\n", offset, value);
            NodePtr ptr = front;
            for (int i = 0; i < offset-1; i++) {
              ptr = ptr->next;
            }

            NodePtr temp = (NodePtr)malloc(sizeof(Node));
            temp->value = value;
            temp->next = ptr->next;
            ptr->next = temp;

            break;
          }
          case 'a': {
            NodePtr temp = (NodePtr)malloc(sizeof(Node));
            temp->value = value;
            temp->next = nullptr;
            back->next = temp;
            back = temp;
            break;
          }
          default:
            break;
        }
      }

      printf("Created Linked list is: ");
      printLL(front);
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}