/**
 * @file piptree.hpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Header file for piptree.cpp
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#pragma once

#include <algorithm>
#include <cinttypes>
#include <cmath>
#include <vector>

#include "prefix.hpp"
#include "riptree.hpp"

/**
 * @brief Find the nature of a PIPTree node indexed by a RIPTree path p.
 *
 * @param p path
 * @param pf prefix
 * @param rpf root's prefix
 * @return nature (good = true, bad = false)
 */
bool piptree_find_nature(const vector<bool>& p, vector<uint> pf, uint rpf);

/**
 * @brief Find the path from root to the node indexed by path p.
 *
 * @param p path
 * @return A vector of Directions.
 */
vector<bool> piptree_get_root_directions(const vector<bool>& p);

/**
 * @brief Find the prefix of a number in PIPTree. This is done by finding the shortest path to n in PIPTree.
 *
 * @param n number
 * @return prefix
 */
vector<uint> piptree_prefix_find(uintmax_t n);

/**
 * @brief Find the prefix of a number in PIPTree, indexed by a path p.
 *
 * @param p path
 * @return prefix
 */
vector<uint> piptree_prefix_find(const vector<bool>& p);
