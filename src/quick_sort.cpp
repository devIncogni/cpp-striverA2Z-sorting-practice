#include "quick_sort.h"
#include <utility>

void quickSort(std::vector<int> &array, int leftLarge, int rightSmall) {

  int leftLargeCopy{leftLarge};
  int rightSmallCopy{rightSmall};

  if (leftLarge >= rightSmall) {
    return;
  }

  int pivot{leftLarge};

  while (leftLarge < rightSmall) {

    while (array[leftLarge] <= array[pivot] && leftLarge < rightSmallCopy) {
      leftLarge++;
    }
    while (array[rightSmall] > array[pivot] && rightSmall > leftLargeCopy) {
      rightSmall--;
    }

    if (leftLarge < rightSmall) {
      std::swap(array[leftLarge], array[rightSmall]);
    }
  }

  std::swap(array[rightSmall], array[pivot]);
  int sortedIndex{rightSmall};

  quickSort(array, leftLargeCopy, sortedIndex - 1);
  quickSort(array, sortedIndex + 1, rightSmallCopy);
}

void quickSort2(std::vector<int> &array, int leftLarge, int rightSmall) {

  if (leftLarge >= rightSmall) {
    return;
  }

  int i{leftLarge};
  int j{rightSmall};

  int pivotIndex{(i + j) / 2};
  int pivot{array[pivotIndex]};
  std::swap(array[rightSmall], array[pivotIndex]);

  while (i < j) {
    while (array[i] < pivot && i < rightSmall) {
      ++i;
    }
    while (array[j] >= pivot && j > leftLarge) {
      --j;
    }

    if (i < j) {
      std::swap(array[i], array[j]);
    }
  }
  std::swap(array[i], array[rightSmall]);
  pivotIndex = i;

  quickSort2(array, leftLarge, pivotIndex - 1);
  quickSort2(array, pivotIndex + 1, rightSmall);
}
