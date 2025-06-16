#include "insertion_sort.h"

void insertionSort(std::vector<int> &array) {
  for (int i{1}; i < array.size(); ++i) {
    int currentElement{array[i]};
    // for (int j{i - 1}; j >= 0; --j) {
    //   if (array[positionOfCurrentElement] < array[j]) {
    //     std::swap(array[positionOfCurrentElement], array[j]);
    //     positionOfCurrentElement = j;
    //   }
    // }
    int j{i - 1};
    while (j >= 0 && array[j] > currentElement) {
      // Keep shifting one position fwd
      array[j + 1] = array[j];
      --j;
    } // After every shift, j and j+1 will have duplicates since j was shifted
      // to j+1. Hence now put current element at j.
    array[j + 1] = currentElement;
  }
}

void insertionSortRecursive(std::vector<int> &array, int posOfCurrElement) {
  int currentElement{array[posOfCurrElement]};

  int j{posOfCurrElement - 1};

  while (j >= 0 && array[j] > currentElement) {
    array[j + 1] = array[j];
    --j;
  }

  array[j + 1] = currentElement;
  insertionSortRecursive(array, posOfCurrElement + 1);
}
