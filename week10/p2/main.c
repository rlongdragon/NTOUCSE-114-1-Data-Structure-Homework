#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int val;
  struct _Node* nxt;
} Node;

void push_back(Node** head, int n) {
  while (*head) head = &(*head)->nxt;

  *head = malloc(sizeof(Node));
  (*head)->val = n;
}

void print(Node* head) {
  while (head) {
    printf("%d ", head->val);
    head = head->nxt;
  }
}
void reverse(Node** head) {
  Node* ptr = *(head);
  Node* lastPtr = NULL;
  while (ptr) {
    Node* nextPtr = ptr->nxt;
    ptr->nxt = lastPtr;
    lastPtr = ptr;
    ptr = nextPtr;
  }
  *(head) = lastPtr;
}

int main(void) {
  int buf;
  Node* head = NULL;
  while (~scanf(" %d", &buf)) push_back(&head, buf);

  reverse(&head);
  print(head);

  return 0;
}