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

void merge(std::vector<int> &array, int left, int mid, int right) {

  std::vector<int> Left, Right;
  Left.assign(array.begin() + left, array.begin() + mid + 1);
  Right.assign(array.begin() + mid + 1, array.begin() + right + 1);

  int l{0}, r{0}, i{left};
  while (l < Left.size() && r < Right.size()) {
    if (Left[l] < Right[r]) {
      array[i++] = Left[l++];
    } else {
      array[i++] = Right[r++];
    }
  }

  while (l < Left.size()) {
    array[i++] = Left[l++];
  }

  while (r < Right.size()) {
    array[i++] = Right[r++];
  }
}

void mergeSort(std::vector<int> &array, int left, int right) {

  if (left >= right) {
    return;
  }

  int mid{(left + right) / 2};

  mergeSort(array, left, mid);
  mergeSort(array, mid + 1, right);
  merge(array, left, mid, right);
}
