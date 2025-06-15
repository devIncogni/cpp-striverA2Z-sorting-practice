#include "./selection_sort.h"
#include <utility>

void selectionSort(std::vector<int> &array) {

  for (int i{}; i < array.size(); ++i) {
    int currentElement{array.at(i)};
    for (int j{i}; j < array.size(); ++j) {
      int compareElement{array.at(j)};

      if (compareElement <= currentElement) {
        std::swap(array[i], array[j]);
        currentElement = array.at(i);
      }
    }
  }
}
