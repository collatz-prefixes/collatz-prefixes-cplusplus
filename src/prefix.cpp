/**
 * @file prefix.cpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Prefix functions are implemented here.
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#include "prefix.hpp"

uintmax_t prefix_iterate(uintmax_t n, vector<uint>& pf) {
  if (pf.empty()) return n;
  n = n / pow(2, pf[0]);
  for (int i = 1; i < int(pf.size()); i++) {
    assert((n & 1) == 1);  // n should be odd here
    n = (3 * n) + 1;
    n = n / pow(2, pf[i] - pf[i - 1]);  // treats as RECF
  }
  return n;
}

vector<uint> prefix_find(uintmax_t n, uintmax_t m) {
  if (n == m) return collatz_ECF(n);
  vector<uint> ans;
  uint twos = 0;
  bool matched = true;
  while (matched) {
    if ((n & 1) == 0 && (m & 1) == 0) {
      // both are even
      twos++;
      n = n / 2;
      m = m / 2;
    } else if ((n & 1) == 1 && (m & 1) == 1) {
      // both are odd
      ans.push_back(twos);
      n = 3 * n + 1;
      m = 3 * m + 1;
    } else {
      // they are of different parity
      matched = false;
    }
  }
  return ans;
}

uintmax_t prefix_map_to_num(const vector<uint>& pf) {
  if (pf.empty()) return 0;
  uintmax_t ans = 0;
  for (int i = 0; i < (int)pf.size(); ++i) {
    ans += 1 << pf[i];  // 2 ^ pf[i]
  }
  return ans;
}

void prefix_add(vector<uint>& pf1, const vector<uint>& pf2) {
  if (pf1.empty()) {
    pf1 = pf2;
    return;
  }
  uint pf1last = pf1.back();
  pf1.pop_back();
  uint i = pf1.size();
  pf1.insert(pf1.end(), pf2.begin(), pf2.end());
  for (; i < pf1.size(); ++i) {
    pf1[i] += pf1last;
  }
}
