/**
 * @file util.cpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Utility functions are implemented here.
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#include "util.hpp"

uintmax_t PTON(vector<bool> p) {
  FLIP(p);                      // flip
  reverse(p.begin(), p.end());  // reverse
  uintmax_t n = BTON(p);        // to int
  n++;                          // increment
  return n;
}

vector<bool> NTOP(uintmax_t n) {
  n--;                          // decrement
  vector<bool> p = NTOB(n);     // to binary
  reverse(p.begin(), p.end());  // reverse
  FLIP(p);                      // flip
  return p;
}

bool ISPOW2(uintmax_t n) { return n && (((n & (n - 1)) == 0)); }

uintmax_t NEXTPOW2(uintmax_t n) {
  if (ISPOW2(n)) return n;
  uintmax_t p = 1;
  while (p < n) p <<= 1;
  return p;
}

void FLIP(vector<bool> &b) { 
  for (int i = 0; i < b.size(); ++i) {
    b[i] = !b[i];
  }
}

uintmax_t BTON(const vector<bool> &b) {
  uintmax_t ans = 0;
  for (int i = 0; i < b.size(); ++i) {
    ans <<= 1;
    if (b[i]) ans++;
  }
  return ans;
}

vector<bool> NTOB(uintmax_t n) {
  vector<bool> ans;
  while (n != 0) {
    ans.insert(ans.begin(), n & 1);
    n >>= 1;
  }
  return ans;
}

/*
vector<vector<uint> > GEN_PREFIX(uint len) {
  if (len != 1) {
    vector<vector<uint> > a = GEN_PREFIX(len - 1);
    vector<vector<uint> > b(a);
    for (auto v = a.begin(); v != a.end(); ++v) {
      (*v).push_back(len - 1);
      b.push_back(*v);
    }
    b.push_back({len - 1});
    return b;
  } else {
    return {{0}};
  }
}

vector<vector<bool> > GEN_PATH(uint len) {
  if (len != 1) {
    vector<vector<bool> > a = GEN_PATH(len - 1);
    const uint a_size = a.size();
    for (uint i = 0; i < a_size; ++i) {
      if (a[i].size() == len - 1) {
        // get two copies of latest path
        vector<bool> x0(a[i]);
        vector<bool> x1(a[i]);
        x0.push_back(0);
        x1.push_back(1);
        a.push_back(x0);
        a.push_back(x1);
      }
    }
    return a;
  } else {
    return {{0}, {1}};
  }
}
*/
