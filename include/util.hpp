/**
 * @file util.hpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Header file for util.cpp and util.tpp
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#pragma once

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Used for command line arguments
#ifndef MATCH_INPUT
#define MATCH_INPUT(s) (!strcmp(argv[ac], (s)))
#endif

/**
 * @brief Find the number at the given path in RIPTree.
 *
 * @param p path
 */
uintmax_t PTON(vector<bool> p);

/**
 * @brief Find the shortest path to the given number in RIPTree.
 *
 * @param n number
 */
vector<bool> NTOP(uintmax_t n);

/**
 * @brief Get the smallest power of 2 greater than a given number.
 *
 * @param n number
 */
uintmax_t NEXTPOW2(uintmax_t n);

/**
 * @brief Flip the bools in a vector.
 *
 * @param b vector of bools
 */
void FLIP(vector<bool>& b);

/**
 * @brief Treat a boolean vector as a binary and return the corresponding number.
 *
 * @param n
 */
uintmax_t BTON(const vector<bool>& b);

/**
 * @brief Convert a number to it's binary representation as vector of bools.
 *
 * @param n
 */
vector<bool> NTOB(uintmax_t n);

/**
 * @brief Returns true if the number is a power of 2.
 *
 * @param n
 */
bool ISPOW2(uintmax_t n);

/**
 * @brief Generate all possible prefixes up to a given length.
 *
 * Example:
 * n=1, [0]
 * n=2, [0], [1], [0, 1]
 * n=3, [0], [1], [0, 1], [2], [0, 2], [1, 2], [0, 1, 2]
 *
 * @note can be refactored and optimized perhaps
 *
 * @param len length
 * @return A vector of prefixes
 */
// vector<vector<uint> > GEN_PREFIX(uint len);

/**
 * @brief Generate all possible paths with the given length.
 *
 * @note can be refactored and optimized perhaps
 *
 * @param len
 * @return A vector of paths
 */
// vector<vector<bool> > GEN_PATH(uint len);

template <typename T>
void print_vector(const vector<T>& v, const char* title = "");

template <typename TL, typename TR>
void print_vector_pair(const vector<pair<TL, TR> >& v, const char* title = "");

template <typename T>
void print_vector_vector(const vector<vector<T> >& v, const char* title = "");

template <typename T>
T random_number(T max, T min);

#include "util.tpp"
