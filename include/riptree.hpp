/**
 * @file riptree.hpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Header file for riptree.cpp
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#pragma once

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

#include "prefix.hpp"
#include "util.hpp"

/**
 * @brief Find the next number in the path of n in RIPTree.
 *
 * For path p of n, the next number is at n + 2^|p|.
 *
 * @param n
 * @return uintmax_t
 */
uintmax_t riptree_next_in_path(uintmax_t n, const vector<bool>& p);

/**
 * @brief Find the prefix of a number via the next number in it's RIPTree path.
 *
 * @param n number
 * @return vector<uint>
 */
vector<uint> riptree_prefix_find(uintmax_t n);

/**
 * @brief Find the prefix of the first number at the given path in RIPTree.
 *
 * @param p path
 * @return vector<uint>
 */
vector<uint> riptree_prefix_find(const vector<bool>&);
