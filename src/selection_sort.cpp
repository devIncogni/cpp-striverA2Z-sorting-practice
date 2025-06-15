#include "./selection_sort.h"

void selectionSort(std::vector<int> &array) {

  for (int i{}; i < array.size(); ++i) {
    int currentElement{array.at(i)};
    for (int j{i}; j < array.size(); ++j) {
      int compareElement{array.at(j)};

      if (compareElement <= currentElement) {
        int temp{array[i]};
        array[i] = array[j];
        array[j] = temp;
        currentElement = array.at(i);
      }
    }
  }
}
