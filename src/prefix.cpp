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
  n /= 1 << pf[0];
  for (int i = 1; i < int(pf.size()); i++) {
    n = (3 * n) + 1;
    n /= 1 << (pf[i] - pf[i - 1]);
  }
  return n;
}

vector<uint> prefix_find(uintmax_t n, uintmax_t m) {
  vector<uint> ans;
  uint twos = 0;
  while (true) {
    if ((n & 1) == 0 && (m & 1) == 0) {
      // both are even
      twos++;
      n >>= 1;
      m >>= 1;
    } else if ((n & 1) == 1 && (m & 1) == 1) {
      // both are odd
      ans.push_back(twos);
      n = 3 * n + 1;
      m = 3 * m + 1;
    } else {
      // they are of different parity
      break;
    }
  }
  return ans;
}

uintmax_t prefix_map_to_num(const vector<uint>& pf) {
  uintmax_t ans = 0;
  for (int i = 0; i < (int)pf.size(); ++i) {
    ans += 1 << pf[i];  // 2 ^ pf[i]
  }
  return ans;
}

// todo: add prefix from num

void prefix_add(vector<uint>& pf1, const vector<uint>& pf2) {
  if (pf1.empty()) {
    pf1 = pf2;
    return;
  }
  uint pf1last = pf1.back();
  pf1.pop_back();
  uint i = pf1.size();  // old size
  pf1.insert(pf1.end(), pf2.begin(), pf2.end());
  for (; i < pf1.size(); ++i) {
    pf1[i] += pf1last;
  }
}
