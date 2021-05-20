#include <math.h>

#include <algorithm>
#include <complex>
#include <iostream>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);

complex<double> *omega = new complex<double>[400020];
complex<double> *conj_inv = new complex<double>[400020];

void FFT(complex<double> *fft_coe, int len, bool inv) {
  int j = len / 2, temp_int;
  complex<double> temp;

  for (int i = 1; i < len - 1; i++) {
    if (i < j) {
      temp = fft_coe[i];
      fft_coe[i] = fft_coe[j];
      fft_coe[j] = temp;
    }
    temp_int = len / 2;
    while (j >= temp_int) {
      j -= temp_int;
      temp_int /= 2;
    }
    if (j < temp_int) {
      j += temp_int;
    }
  }

  int wid = 2, mid;
  while (wid <= len) {
    mid = wid / 2;
    for (int i = 0; i < len; i += wid) {
      for (int k = 0; k < mid; k++) {
        if (inv) {
          temp = conj_inv[len / wid * k] * fft_coe[i + k + mid];
        } else {
          temp = omega[len / wid * k] * fft_coe[i + k + mid];
        }
        fft_coe[i + k + mid] = fft_coe[i + k] - temp;
        fft_coe[i + k] = fft_coe[i + k] + temp;
      }
    }
    wid *= 2;
  }
  if (inv) {
    for (int i = 0; i < len; i++) {
      fft_coe[i].real(fft_coe[i].real() / len);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int *l = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  sort(l, l + n);
  int len = 1, max_len = 2 * l[n - 1],
      max_l = l[n - 1] + 1;  // max_l is the max l + 1, the length of num_of_l
  ll *num_of_l = new ll[max_len + 1]();
  num_of_l[0] = 0;
  for (int i = 0; i < n; i++) {
    num_of_l[l[i]]++;
  }
  while (len < 2 * max_l) {
    len *= 2;
  }
  ll *num_of_sum = new ll[max_len + 1];

  num_of_sum[0] = 0;

  complex<double> *fft_coe = new complex<double>[len];

  for (int i = 0; i < len; i++) {
    omega[i] = complex<double>(cos(2 * PI * i / len), sin(2 * PI * i / len));
    conj_inv[i] = conj(omega[i]);
  }

  for (int i = 0; i < len; i++) {
    if (i < max_l) {
      fft_coe[i] = complex<double>(num_of_l[i], 0);
    } else {
      fft_coe[i] = complex<double>(0, 0);
    }
  }
  FFT(fft_coe, len, false);
  for (int i = 0; i < len; i++) {
    fft_coe[i] = fft_coe[i] * fft_coe[i];
  }
  FFT(fft_coe, len, true);
  for (int i = 1; i <= max_len; i++) {
    num_of_sum[i] = (ll)(fft_coe[i].real() + 0.5);
  }
}