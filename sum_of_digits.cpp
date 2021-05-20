#include <iostream>
using namespace std;

//给定一个正整数，将其各位相加，再将得到的结果各位相加...直到结果只剩一位
int toOneDigit(int x) { return x - ((x - 1) / 9 * 9); }

//给定一个正整数，将其各位相加
int simpleAddDigits(int x) {
  int rst = 0;
  while (x != 0) {
    rst += (x % 10);
    x = x / 10;
  }
  return rst;
}

int main() {
  int s;
  while (1) {
    cin >> s;
    cout << "toOneDigit: " << toOneDigit(s) << '\n';
    cout << "simpleAddDigits: " << simpleAddDigits(s) << '\n';
  }
  return 0;
}