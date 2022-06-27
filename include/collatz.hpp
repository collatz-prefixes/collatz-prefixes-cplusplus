/**
 * @file collatz.hpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Header file for collatz.cpp
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

#pragma once

#include <cinttypes>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Return the number of numbers in the Collatz sequence of n.
 *
 * @param n uint64_t
 * @return int
 */
uint collatz_length(uintmax_t n);

/**
 * @brief Return a vector with the integers in the Collatz sequence of n.
 *
 * @param n uint64_t
 * @return vector<uint64_t>
 */
vector<uintmax_t> collatz_sequence(uintmax_t n);

/**
 * @brief Return a vector with the integers in the Collatz reduced sequence of n.
 * A reduced sequence is a sequence but even numbers (except the starting number if it is) omitted.
 *
 * @param n uint64_t
 * @return vector<uint64_t>
 */
vector<uintmax_t> collatz_reduced_sequence(uintmax_t n);

/**
 * @brief Return the exponential canonical form of a number.
 *
 * @param n uint64_t
 * @return vector<int>
 */
vector<uint> collatz_ECF(uintmax_t n);

/**
 * @brief Return the reduced exponential canonical form of a number.
 *
 * @param n uint64_t
 * @return vector<int>
 */
vector<uint> collatz_RECF(uintmax_t n);

/**
 * @brief Return the inverse canonical form of a number.
 *
 * @param n uint64_t
 * @return vector<pair<int, int> >
 */
vector<pair<uint, uint> > collatz_ICF(uintmax_t n);

/**
 * @brief Return the RECF of ECF.
 *
 * @param ecf vector<int>
 * @return uint64_t
 */
vector<uint> collatz_ECF_to_RECF(const vector<uint> &ecf);

/**
 * @brief Return a number from it's exponential canonical form.
 *
 * @param ecf vector<int>
 * @return uint64_t
 */
uintmax_t collatz_ECF_to_n(const vector<uint> &ecf);

/**
 * @brief Return a number from it's reduced exponential canonical form.
 *
 * @param recf vector<int>
 * @return uint64_t
 */
uintmax_t collatz_RECF_to_n(const vector<uint> &recf);

/**
 * @brief Return a number from it's inverse canonical form.
 *
 * @param icf vector<pair<int, int> >
 * @return uint64_t
 */
uintmax_t collatz_ICF_to_n(const vector<pair<uint, uint> > &icf);
