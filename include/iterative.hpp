/**
 * @file iterative.hpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Header file for iterative.cpp
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#pragma once

#include <cinttypes>
#include <vector>

#include "piptree.hpp"
#include "prefix.hpp"
#include "riptree.hpp"

/**
 * @brief Find the ECF of a number by consuming the prefix iteratively. Prefixes are found via RIPTree.
 *
 * @param n number
 * @param prefix_finder function pointer to prefix finding function
 * @param verbose show extra detail
 * @return prefix
 */
vector<uint> iterative_prefix(uintmax_t n, vector<uint> (*prefix_finder)(uintmax_t), bool verbose = false);

/**
 * @brief Find the ECF of a number by extending it's path in the PIPTree. Appending 1's to the path does not change the
 * value. However, the path grows quite large and may overflow.
 *
 * @param n number
 * @param prefix_finder function pointer to prefix finding function
 * @param verbose show extra detail
 * @return prefix
 */
vector<uint> iterative_path_extension(uintmax_t n, vector<uint> (*prefix_finder)(const vector<bool>&),
                                      bool verbose = false);
