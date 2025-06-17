#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> array{{3, 6, 2, 9, 7, 1, 2, 0}};
  quickSort2(array, 0, array.size() - 1);
  for (auto it : array) {
    std::cout << it << " ";
  }
  std::cout << '\n';
}
