#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Define the Item struct
struct Item {
  char name;
  float value;
  float weight;

  Item(char n, float v, float w) : name(n), value(v), weight(w) {}
};

int main() {
  const float MAX_CAPACITY = 20.0f;  // Maximum capacity of the backpack

  // Create a backpack stack
  std::stack<Item> backpack;
  float currentWeight = 0.0f;

  // Read the 5 items
  for (int i = 0; i < 5; i++) {
    char name;
    float value, weight;
    std::cin >> name >> value >> weight;

    // Try to fit the current item in the backpack
    if (currentWeight + weight <= MAX_CAPACITY) {
      backpack.push(Item(name, value, weight));
      currentWeight += weight;
    } else {
      // Check if worth exchanging with items in backpack
      std::stack<Item> ground;
      bool worthExchanging = false;

      while (!backpack.empty() && !worthExchanging) {
        Item topItem = backpack.top();
        backpack.pop();
        currentWeight -= topItem.weight;

        // Check if this item is worth exchanging
        if (topItem.value < value && currentWeight + weight <= MAX_CAPACITY) {
          worthExchanging = true;
          // Found an item worth exchanging, discard it
        } else {
          // Not worth exchanging, put on ground temporarily
          ground.push(topItem);
        }
      }

      // Put items from ground back into backpack
      while (!ground.empty()) {
        backpack.push(ground.top());
        currentWeight += ground.top().weight;
        ground.pop();
      }

      // Add new item if it fits and we found an item worth exchanging
      if (worthExchanging && currentWeight + weight <= MAX_CAPACITY) {
        backpack.push(Item(name, value, weight));
        currentWeight += weight;
      }
    }
  }

  // Calculate total value and prepare to display results
  float totalValue = 0.0f;
  std::vector<Item> stolenItems;

  // Transfer items to vector to display in correct order
  while (!backpack.empty()) {
    stolenItems.push_back(backpack.top());
    backpack.pop();
  }

  // Display stolen items in reverse order (bottom of stack to top)
  for (auto it = stolenItems.rbegin(); it != stolenItems.rend(); ++it) {
    std::cout << it->name << " " << it->value << " " << it->weight << std::endl;
    totalValue += it->value;
  }

  // std::cout << "weight: " << std::fixed << std::setprecision(1) <<
  // currentWeight
  //           << " kg" << std::endl;
  // std::cout << "value: " << std::fixed << std::setprecision(1) << totalValue
  //           << std::endl;
  printf("weight:%.01f\nvalue:%.01f\n", currentWeight, totalValue);

  return 0;
}