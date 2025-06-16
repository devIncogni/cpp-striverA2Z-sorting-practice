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
