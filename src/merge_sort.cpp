#include "merge_sort.h"
#include <cmath>
#include <vector>

void mergeSort(std::vector<int> &array) {
  if (array.size() == 1) {
    return;
  }

  int mid{static_cast<int>(std::floor(array.size() / 2))};
  std::vector<int> tempV1;
  std::vector<int> tempV2;

  tempV1.assign(array.begin(), array.begin() + mid);
  tempV2.assign(array.begin() + mid, array.end());

  mergeSort(tempV1);
  mergeSort(tempV2);

  //   5,8,9 && 1,3,4

  int posV1{0};
  int posV2{0};

  array.clear();

  while (posV1 < tempV1.size() && posV2 < tempV2.size()) {

    if (tempV1[posV1] < tempV2[posV2]) {
      array.push_back(tempV1[posV1++]);
    } else {
      array.push_back(tempV2[posV2++]);
    }
  }

  array.insert(array.end(), tempV1.begin() + posV1, tempV1.end());
  array.insert(array.end(), tempV2.begin() + posV2, tempV2.end());
}
