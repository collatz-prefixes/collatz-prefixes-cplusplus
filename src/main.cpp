#include <iostream>

#include "collatz.hpp"
#include "iterative.hpp"
#include "piptree.hpp"
#include "prefix.hpp"
#include "riptree.hpp"
#include "util.hpp"

#ifndef COLLATZ_TESTING
int main(int argc, char *argv[]) {
  uintmax_t n = 1, m = 1;
  bool verbose = false, itermethod[4] = {false};
  for (int ac = 1; ac < argc; ++ac) {
    if (MATCH_INPUT("-n")) {
      ac++;
      if (ac < argc)
        n = atoi(argv[ac]);
      else
        exit(-1);
    } else if (MATCH_INPUT("-m")) {
      ac++;
      if (ac < argc)
        m = atoi(argv[ac]);
      else
        exit(-1);
    } else if (MATCH_INPUT("-v"))
      verbose = true;
    else if (MATCH_INPUT("-irip"))
      itermethod[0] = true;
    else if (MATCH_INPUT("-ipip"))
      itermethod[1] = true;
    else if (MATCH_INPUT("-irpath"))
      itermethod[2] = true;
    else if (MATCH_INPUT("-ippath"))
      itermethod[3] = true;
    else {
      printf(
          "Usage: %s\n"
          "  -n <num> Primary number.\n"
          "  -m <num> Secondary number.\n"
          "  -v       Verbose mode.\n"
          "  -irip    Iterative method RIPTree.\n"
          "  -ipip    Iterative method PIPTree.\n"
          "  -irpath  Iterative RIPTree Path Extension.\n"
          "  -ippath  Iterative PIPTree Path Extension.\n",
          argv[0]);
      return 0;
    }
  }
  if (verbose) {
    cout << "Using " << sizeof(uintmax_t) * 8 << " bit integers." << endl;
    cout << "N: " << n << "\tM: " << m << endl;
  }

  // ECF
  vector<uint> ecf = collatz_ECF(n);

  // Iterative Methods
  if (itermethod[0]) {
    vector<uint> ecf_irip = iterative_prefix(n, &riptree_prefix_find, verbose);
    print_vector<uint>(ecf_irip, "ECF found via Iterative RIPTree Prefix: ");
    assert(ecf == ecf_irip);
  };
  if (itermethod[1]) {
    vector<uint> ecf_ipip = iterative_prefix(n, &piptree_prefix_find, verbose);
    print_vector<uint>(ecf_ipip, "ECF found via Iterative PIPTree Prefix: ");
    assert(ecf == ecf_ipip);
  }
  if (itermethod[2]) {
    vector<uint> ecf_path = iterative_path_extension(n, &riptree_prefix_find, verbose);
    print_vector<uint>(ecf_path, "ECF found via RIPTree Path Extensions: ");
    assert(ecf == ecf_path);
  }
  if (itermethod[3]) {
    vector<uint> ecf_path = iterative_path_extension(n, &piptree_prefix_find, verbose);
    print_vector<uint>(ecf_path, "ECF found via PIPTree Path Extensions: ");
    assert(ecf == ecf_path);
  }
  return 0;
}
#endif