/**
 * @file collatz.cpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Primitive functions such as sequences and forms for Collatz.
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#include "collatz.hpp"

uint collatz_length(uintmax_t n) {
  uint ans = 0;
  while (n > 1) {
    ans++;
    if ((n & 1) == 0) {
      n = n >> 1;
    } else {
      n = 3 * n + 1;
    }
  }
  return ans;
}

vector<uintmax_t> collatz_sequence(uintmax_t n) {
  vector<uintmax_t> ans;
  while (n > 1) {
    ans.push_back(n);
    if ((n & 1) == 0) {
      n = n >> 1;
    } else {
      n = 3 * n + 1;
    }
  }
  ans.push_back(1);
  return ans;
}

vector<uintmax_t> collatz_reduced_sequence(uintmax_t n) {
  vector<uintmax_t> ans;
  while (n > 1) {
    if ((n & 1) == 0) {
      n = n >> 1;
    } else {
      ans.push_back(n);
      n = 3 * n + 1;
    }
  }
  ans.push_back(1);
  return ans;
}

vector<uint> collatz_ECF(uintmax_t n) {
  vector<uint> ans;
  uint twos = 0;
  while (n > 1) {
    if ((n & 1) == 0) {
      twos++;
      n = n >> 1;
    } else {
      ans.push_back(twos);
      n = 3 * n + 1;
    }
  }
  ans.push_back(twos);
  return ans;
}

vector<uint> collatz_RECF(uintmax_t n) {
  vector<uint> ans;
  uint twos = 0;
  while (n > 1) {
    if ((n & 1) == 0) {
      twos++;
      n = n >> 1;
    } else {
      ans.push_back(twos);
      twos = 0;
      n = 3 * n + 1;
    }
  }
  ans.push_back(twos);
  return ans;
}

vector<pair<uint, uint> > collatz_ICF(uintmax_t n) {
  vector<pair<uint, uint> > ans;
  vector<uint> ecf = collatz_ECF(n);
  auto e2 = ecf.rbegin();
  int e3 = ecf.size() - 1;
  ans.push_back(make_pair(*e2, e3));
  ++e2;
  for (; e2 != ecf.rend(); ++e2) {
    ans.push_back(make_pair(*e2, e3--));
  }
  return ans;
}

vector<uint> collatz_ECF_to_RECF(const vector<uint> &ecf) {
  vector<uint> recf(ecf);  // copy ecf to recf
  recf[0] = ecf[0];
  for (uint i = 1; i < ecf.size(); ++i) {
    recf[i] = ecf[i] - ecf[i - 1];
  }
  return recf;
}

uintmax_t collatz_ECF_to_n(const vector<uint> &ecf) { return collatz_RECF_to_n(collatz_ECF_to_RECF(ecf)); }

uintmax_t collatz_RECF_to_n(const vector<uint> &recf) {
  auto r = recf.rbegin();
  double ans = pow(2, *r);
  ++r;
  for (; r != recf.rend(); ++r) {
    ans = (ans - 1) / 3;
    ans *= pow(2, *r);
  }
  return ans;
}

uintmax_t collatz_ICF_to_n(const vector<pair<uint, uint> > &icf) {
  auto i = icf.begin();
  double ans = pow(2, (*i).first) / pow(3, (*i).second);
  ++i;
  for (; i != icf.end(); ++i) {
    ans -= pow(2, (*i).first) / pow(3, (*i).second);
  }
  return ans;
}