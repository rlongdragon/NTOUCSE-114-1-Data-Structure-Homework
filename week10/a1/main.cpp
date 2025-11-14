#include <cstring>  // For strcmp
#include <iostream>

#define MAX_WEIGHT 20

using namespace std;

typedef struct Node Node;
typedef struct Node* NodePtr;
struct Node {
  char name[11];
  float weight;
  int value;
  NodePtr next;
};

int main() {
  float totalWeight = 0;

  NodePtr front = nullptr;
  NodePtr end = nullptr;

  while (true) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    cin >> newNode->name >> newNode->value >> newNode->weight;
    newNode->next = nullptr;

    if (strcmp(newNode->name, "-1") == 0) {
      free(newNode);
      break;
    }

    float newCp = (float)newNode->value / newNode->weight;
    totalWeight += newNode->weight;

    while (front != nullptr && totalWeight > MAX_WEIGHT) {
      float frontCp = (float)front->value / front->weight;
      if (frontCp > newCp) {
        totalWeight -= newNode->weight;
        free(newNode);
        newNode = nullptr;
        break;
      }

      NodePtr temp = front;
      totalWeight -= front->weight;
      front = front->next;
      free(temp);
      if (front == nullptr) {
        end = nullptr;
      }
    }

    if (newNode == nullptr) {
      continue;
    }

    
    if (front == nullptr || newCp < ((float)front->value / front->weight) ||
        (newCp == ((float)front->value / front->weight) &&
         newNode->weight > front->weight)) {
      newNode->next = front;
      front = newNode;
      if (end == nullptr) {
        end = newNode;
      }
    } else {
      NodePtr current = front;
      while (current->next != nullptr &&
             (newCp > ((float)current->next->value / current->next->weight) ||
              (newCp == ((float)current->next->value / current->next->weight) &&
               newNode->weight <= current->next->weight))) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
      if (newNode->next == nullptr) {
        end = newNode;
      }
    }

    // NodePtr ptr = front;
    // while (ptr) {
    //   printf("(%s %d %f) ", ptr->name, ptr->value, ptr->weight);
    //   ptr = ptr->next;
    // }
    // printf("\n");
  }

  int totalValue = 0;
  NodePtr ptr = front;
  while (ptr) {
    if (ptr->next) printf("%s ", ptr->name);
    else printf("%s", ptr->name);
    totalValue += ptr->value;
    ptr = ptr->next;
  }
  printf("\n");
  printf("total weight:%.2f\n", totalWeight);
  printf("total value:%d\n", totalValue);

  while (front != nullptr) {
    NodePtr temp = front;
    front = front->next;
    free(temp);
  }

  return 0;
}
