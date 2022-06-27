/**
 * @file iterative.cpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Iterative methods to find ECF of a number.
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#include "iterative.hpp"

vector<uint> iterative_prefix(uintmax_t n, vector<uint> (*prefix_finder)(uintmax_t), bool verbose) {
  vector<uint> ans;
  vector<uint> pf;
  while (true) {
    pf = prefix_finder(n);
    if (verbose) print_vector<uint>(pf);

    prefix_add(ans, pf);
    n = prefix_iterate(n, pf);
    if (n == 1) {
      return ans;
    } else {
      n = 3 * n + 1;
      if (!ans.empty()) ans.push_back(ans.back());
    }
  }
}

vector<uint> iterative_path_extension(uintmax_t n, vector<uint> (*prefix_finder)(const vector<bool>&), bool verbose) {
  vector<bool> p = NTOP(n);
  vector<uint> pf = prefix_finder(p);
  uintmax_t x = prefix_iterate(n, pf);
  while (x != 1) {
    p.push_back(1);
    pf = prefix_finder(p);
    if (verbose) print_vector<uint>(pf);
    x = prefix_iterate(n, pf);
  }
  return pf;
}
