/**
 * @file riptree.cpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief RIPTree (Recursive Index-Parity Tree) is implemented here.
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#include "riptree.hpp"

uintmax_t riptree_next_in_path(uintmax_t n, const vector<bool>& p) {
  return n + pow(2, p.size());  // m = n + 2^|p|
}

vector<uint> riptree_prefix_find(uintmax_t n) { return riptree_prefix_find(NTOP(n)); }

vector<uint> riptree_prefix_find(const vector<bool>& p) {
  // if the number is a power of 2, we know the ECF (which is also prefix)
  uintmax_t n = PTON(p);
  if (ISPOW2(n)) {
    uint ans = 0;
    while (n > 1) {
      n >>= 1;
      ans++;
    }
    return {ans};
  } else {
    return prefix_find(n, riptree_next_in_path(n, p));  // prefix find with the next in path
  }
}
