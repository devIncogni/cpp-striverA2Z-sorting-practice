#include "bubble_sort.h"
#include <utility>
void bubbleSort(std::vector<int> &array) {

  for (int i{}; i < array.size(); ++i) {
    for (int j{}; j + 1 < array.size() - 1; ++j) {
      if (array[j + 1] < array[j]) {
        std::swap(array[j + 1], array[j]);
      }
    }
  }
}

void bubbleSortRecursive(std::vector<int> &array, int end) {

  if (end <= 1) {
    return;
  }

  for (int j{}; j + 1 < end; ++j) {
    if (array[j] > array[j + 1]) {
      std::swap(array[j], array[j + 1]);
    }
  }
  bubbleSortRecursive(array, end - 1);
}
