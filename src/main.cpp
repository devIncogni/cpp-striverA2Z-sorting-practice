#include "./selection_sort.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> array{{3, 6, 2, 9, 7, 1,2, 0}};
  selectionSort(array);
  for (auto it : array) {
    std::cout << it << " ";
  }
  std::cout << '\n';
}
