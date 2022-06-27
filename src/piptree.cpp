/**
 * @file piptree.cpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief PIPTree (Path-Indexed Prefix Tree) is implemented here.
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#include "piptree.hpp"

bool piptree_find_nature(const vector<bool>& p, vector<uint> pf, uint rpf) {
  pf.push_back(rpf + 1);  // [p1, p2, ..., pk, pr + 1]
  const uintmax_t x = prefix_iterate(PTON(p), pf);
  if ((x & 1) == 0) {
    return true;  // even means this has to be GOOD natured
  } else {
    return false;  // odd means this has to be BAD natured
  }
}

vector<bool> piptree_get_root_directions(const vector<bool>& p) {
  vector<bool> ans;
  uintmax_t i = BTON(p);
  // start from target path and go to root
  while (i > 1) {
    if ((i & 1) == 0) {
      i = i >> 1;
      ans.push_back(false);  // left
    } else {
      i = (i - 1) >> 1;
      ans.push_back(true);  // right
    }
  }
  // root reached, now reverse the path
  reverse(ans.begin(), ans.end());
  return ans;
}

vector<uint> piptree_prefix_find(uintmax_t n) { return piptree_prefix_find(NTOP(n)); }

vector<uint> piptree_prefix_find(const vector<bool>& p) {
  // if power of two, it is the root and we know the prefix
  // also this is the only case when path is all zeros
  uintmax_t n = PTON(p);
  if (ISPOW2(n)) {
    uint ans = 0;
    while (n > 1) {
      n >>= 1;
      ans++;
    }
    return {ans};
  }

  // find directions from root to p
  vector<bool> dirs = piptree_get_root_directions(p);
  // calculate the root number
  const uintmax_t r = pow(2, (p.size() - 1));
  // calculate the root prefix
  const uint rpf = p.size() - 1;
  // calculate the root path [0, 0, ..., 0, 1]
  vector<bool> rp(p);
  for (int i = 0; i < rp.size(); i++) rp[i] = 0;
  rp[rp.size() - 1] = true;

  // start from the root and work your way to the target
  uintmax_t cur_n = r;
  vector<bool> cur_p(rp);
  vector<uint> cur_pf = {rpf};
  for (int i = 0; i < dirs.size(); i++) {
    // find nature of current node
    bool nat = piptree_find_nature(cur_p, cur_pf, rpf);
    // minus 1 everything in the prefix
    for (int pf_i = 0; pf_i < cur_pf.size(); ++pf_i) cur_pf[pf_i]--;
    if (dirs[i] == false) {
      // if GOOD and LEFT, append root prefix
      if (nat == true) cur_pf.push_back(rpf);
      // div 2 and plus root
      cur_n = (cur_n >> 1) + r;
      // go to the left child
      cur_p.push_back(0);
      cur_p.erase(cur_p.begin());
    } else {
      // if BAD and RIGHT, append root prefix
      if (nat == false) cur_pf.push_back(rpf);
      // div 2
      cur_n = (cur_n >> 1);
      // go to the right child
      cur_p.push_back(1);
      cur_p.erase(cur_p.begin());
    }
  }

  assert(n == cur_n);
  return cur_pf;
}

