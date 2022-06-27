/**
 * @file prefix.hpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Header file for prefix.cpp
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#pragma once

#include <assert.h>

#include <cinttypes>
#include <cmath>
#include <iostream>
#include <vector>

#include "collatz.hpp"

using namespace std;

/**
 * @brief Iterate a number through it's prefix
 *
 * @param n number
 * @param pf prefix
 * @return resulting number
 */
uintmax_t prefix_iterate(uintmax_t n, vector<uint>& pf);

/**
 * @brief Find the prefix of two numbers.We apply Collatz function iteratively until we can't.
 *
 * The prefix can be extended by looping through 1 repeatedly too. An example
 * of this is 1 and 33. Normal prefix among ECF's are [0], but extended is [0, 2, 4].
 *
 * @param n number 1
 * @param m number 2
 * @return prefix
 */
vector<uint> prefix_find(uintmax_t n, uintmax_t m);

/**
 * @brief Return the ID of a prefix.
 *
 * Every prefix is unique with respect to their ID.
 * The numbers in the prefix actually tell you which bits to to write 1
 * in the binary representation.
 *
 * Example: [0, 2, 3] --> [1, 1, 0, 1] = 13.
 *
 * @param pf prefix
 * @return prefix ID
 */
uintmax_t prefix_map_to_num(const vector<uint>& pf);

/**
 * @brief Adds prefix p2 to p1.
 *
 * The addition is like stitching, p1[-1] is added to all values in p2, and p1[-1] becomes p2[0]. The final length
 * of the prefix is |p1|+|p2|-1
 *
 * Example:
 *   [0 1 2] + [2 4 5]
 * = [0 1 2 2 2]
 * +     [2 4 5]
 * = [0 1 4 6 7]
 *
 * @param p1
 * @param p2
 */
void prefix_add(vector<uint>& p1, const vector<uint>& p2);
