#include <iostream>
using namespace std;

template <class K>
class SmallHeap {
 public:
  int rear, con, curidx, min;
  K *hp, temp;
  SmallHeap(int con) : rear(0), con(con) { hp = new K[con]; }

  ~SmallHeap() { delete hp; }

  K deleteTop() {
    if (rear == 0) {
      return (K)NULL;
    }
    rear--;
    K top = hp[0];
    hp[0] = hp[rear];
    curidx = 0;
    while (true) {
      if (2 * curidx + 1 >= rear) {
        break;
      }
      if (2 * curidx + 2 >= rear) {
        min = 2 * curidx + 1;
      } else {
        min = hp[2 * curidx + 1] > hp[2 * curidx + 2] ? (2 * curidx + 2)
                                                      : (2 * curidx + 1);
      }
      if (hp[curidx] > hp[min]) {
        temp = hp[curidx];
        hp[curidx] = hp[min];
        hp[min] = temp;
        curidx = min;
      } else {
        break;
      }
    }
    return top;
  }

  void insertHeap(K val) {
    curidx = rear;
    hp[rear++] = val;
    while (curidx > 0) {
      if (hp[curidx] < hp[(curidx - 1) / 2]) {
        temp = hp[curidx];
        hp[curidx] = hp[(curidx - 1) / 2];
        hp[(curidx - 1) / 2] = temp;
        curidx = (curidx - 1) / 2;
      } else {
        break;
      }
    }
  }
};

template <class K>
class BigHeap {
 public:
  int rear, con, curidx, max;
  K *hp, temp;
  BigHeap(int con) : rear(0), con(con) { hp = new K[con]; }

  ~BigHeap() { delete hp; }

  K deleteTop() {
    if (rear == 0) {
      return (K)NULL;
    }
    rear--;
    K top = hp[0];
    hp[0] = hp[rear];
    curidx = 0;
    while (true) {
      if (2 * curidx + 1 >= rear) {
        break;
      }
      if (2 * curidx + 2 >= rear) {
        max = 2 * curidx + 1;
      } else {
        max = hp[2 * curidx + 1] < hp[2 * curidx + 2] ? (2 * curidx + 2)
                                                      : (2 * curidx + 1);
      }
      if (hp[curidx] < hp[max]) {
        temp = hp[curidx];
        hp[curidx] = hp[max];
        hp[max] = temp;
        curidx = max;
      } else {
        break;
      }
    }
    return top;
  }

  void insertHeap(K val) {
    curidx = rear;
    hp[rear++] = val;
    while (curidx > 0) {
      if (hp[curidx] > hp[(curidx - 1) / 2]) {
        temp = hp[curidx];
        hp[curidx] = hp[(curidx - 1) / 2];
        hp[(curidx - 1) / 2] = temp;
        curidx = (curidx - 1) / 2;
      } else {
        break;
      }
    }
  }
};
