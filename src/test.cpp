/**
 * @file tests.cpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Tests are are implemented here.
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#include <cinttypes>
#include <cmath>
#include <vector>

#include "collatz.hpp"
#include "iterative.hpp"
#include "piptree.hpp"
#include "prefix.hpp"
#include "riptree.hpp"

// Tests for collatz functions. You may comment out ICF parts, as they are expensive and prone to overflowing.
void test_collatz(uintmax_t n, bool verbose) {
  cout << "\nCollatz tests started." << endl;
  if (verbose) {
    print_vector<uintmax_t>(collatz_sequence(n), "Sequence: ");
    print_vector<uintmax_t>(collatz_reduced_sequence(n), "Reduced Sequence: ");
  }
  assert(collatz_sequence(n).size() == 1 + collatz_length(n));

  vector<uint> ecf = collatz_ECF(n);

  if (verbose) {
    print_vector<uint>(ecf, "ECF: ");
    // print_vector_pair<uint, uint>(icf, "ICF: ");
  }

  assert(1 == prefix_iterate(n, ecf));
  assert(n == collatz_ECF_to_n(ecf));
  // assert(n == collatz_ICF_to_n(icf));

  cout << "Collatz tests done." << endl;
}

// Tests about prefixes.
void test_prefix(uintmax_t n, uintmax_t m, bool verbose) {
  cout << "\nPrefix tests started." << endl;
  vector<uint> pf = prefix_find(n, m);

  if (verbose) {
    print_vector<uint>(collatz_ECF(n), "ECF n: ");
    print_vector<uint>(collatz_ECF(m), "ECF m: ");
    print_vector<uint>(pf, "Prefix: ");
    cout << "Prefix ID: " << prefix_map_to_num(pf) << endl;
  }

  assert(pf == prefix_find(m, n));                          // reverse shoud be same
  if (!pf.empty()) assert(prefix_iterate(n, pf) % 2 == 1);  // prefix result should always be odd

  cout << "Prefix tests done." << endl;
}

// Test about RIPTree methods.
void test_riptree(uintmax_t n, bool verbose) {
  cout << "\nRIPTree tests started." << endl;
  vector<uint> upf = riptree_prefix_find(n);
  vector<bool> p = NTOP(n);
  if (verbose) {
    const uintmax_t m = riptree_next_in_path(n, p);
    print_vector<bool>(p, "Number to Path: ");
    cout << "Next in path: " << m << endl;
    print_vector<uint>(collatz_ECF(n), "ECF n: ");
    print_vector<uint>(collatz_ECF(m), "ECF m: ");
    print_vector<uint>(upf, "RIPTree Prefix: ");
    cout << "Iter n -> PF: " << prefix_iterate(n, upf) << endl;
  }
  assert(PTON(p) == n);
  assert(prefix_iterate(n, upf) % 2 == 1);  // prefix result should always be odd
  cout << "RIPTree tests done." << endl;
}

// Tests about PIPTree methods.
void test_piptree(uintmax_t n, bool verbose) {
  cout << "\nPIPTree tests started." << endl;
  vector<uint> upf = piptree_prefix_find(n);
  if (verbose) {
    print_vector<uint>(collatz_ECF(n), "ECF n: ");
    print_vector<uint>(upf, "PIPTree Prefix: ");
    cout << "Iter n -> PF: " << prefix_iterate(n, upf) << endl;
  }
  assert(prefix_iterate(n, upf) % 2 == 1);  // prefix result should always be odd
  assert(upf == riptree_prefix_find(n));
  cout << "PIPTree tests done." << endl;
}

// Tests about iterative methods.
void test_iterative(uintmax_t n, bool verbose) {
  cout << "\nIterative tests started." << endl;
  vector<uint> ecf = collatz_ECF(n);
  vector<uint> ecfrip = iterative_prefix(n, &riptree_prefix_find, verbose);
  vector<uint> ecfpip = iterative_prefix(n, &piptree_prefix_find, verbose);
  if (verbose) {
    print_vector<uint>(ecf, "ECF n: ");
    print_vector<uint>(ecfrip, "ECFRIP n: ");
    print_vector<uint>(ecfpip, "ECFPIP n: ");
  }
  assert(ecf == ecfrip);
  assert(ecf == ecfpip);
  cout << "Iterative tests done." << endl;
}

#ifdef COLLATZ_TESTING
int main() {
  int n = 5;
  int m = 16;
  bool verbose = false;
  // TODO: create large random values here

  // Tests
  test_collatz(n, verbose);
  test_prefix(n, m, verbose);
  test_riptree(n, verbose);
  test_piptree(n, verbose);
  test_iterative(n, verbose);
  return 0;
}
#endif