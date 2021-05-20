#include <iostream>
using namespace std;
int mid, s, k, p;

void combine(long long seq[], long long tseq[], int idx[], int tidx[], int l,
             int mid, int r) {
  s = l, k = mid + 1, p = l;
  while (true) {
    if (s <= mid && k <= r) {
      if (seq[s] > seq[k]) {
        tseq[p] = seq[k];
        tidx[p] = idx[k];
        k++;
      } else {
        tseq[p] = seq[s];
        tidx[p] = idx[s];
        s++;
      }
    } else if (s == mid + 1) {
      tseq[p] = seq[k];
      tidx[p] = idx[k];
      k++;
    } else if (k == r + 1) {
      tseq[p] = seq[s];
      tidx[p] = idx[s];
      s++;
    }
    if (s == mid + 1 && k == r + 1) {
      for (int i = l; i <= r; i++) {
        seq[i] = tseq[i];
        idx[i] = tidx[i];
      }
      break;
    }
    p++;
  }
}

void mergeSort(long long seq[], long long tseq[], int idx[], int tidx[], int l,
               int r) {
  if (l < r) {
    mid = (l + r) / 2;
    mergeSort(seq, tseq, idx, tidx, l, mid);
    mid = (l + r) / 2;
    mergeSort(seq, tseq, idx, tidx, mid + 1, r);
    mid = (l + r) / 2;
    combine(seq, tseq, idx, tidx, l, mid, r);
  }
}
