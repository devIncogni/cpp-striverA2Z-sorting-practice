#include "insertion_sort.h"
#include <utility>

void insertionSort(std::vector<int> &array) {
  for (int i{1}; i < array.size(); ++i) {
    int positionOfCurrentElement{i};
    for (int j{i - 1}; j >= 0; --j) {
      if (array[positionOfCurrentElement] < array[j]) {
        std::swap(array[positionOfCurrentElement], array[j]);
        positionOfCurrentElement = j;
      }
    }
  }
}
