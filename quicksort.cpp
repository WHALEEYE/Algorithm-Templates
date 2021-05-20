#include <iostream>
using namespace std;
long long pivot;
int idx, i, j;

//注意：此方法只可用来排序普通数组！因为数组是默认引用传递，而其他容器如vector是直接复制一份传参的，这就会导致被排序的动态数组和外界的动态数组不是同一个。
void quickSort(long long seq[], int index[], int l, int r) {
  if (l < r) {
    i = l;
    j = r;
    pivot = seq[l];
    idx = index[l];
    while (i < j) {
      while (i < j && seq[j] >= pivot) {
        j--;
      }
      if (i < j) {
        seq[i] = seq[j];
        index[i] = index[j];
        i++;
      }
      while (i < j && seq[i] < pivot) {
        i++;
      }
      if (i < j) {
        seq[j] = seq[i];
        index[j] = index[i];
        j--;
      }
    }
    index[i] = idx;
    seq[i] = pivot;
    quickSort(seq, index, l, i - 1);
    quickSort(seq, index, i + 1, r);
  }
}