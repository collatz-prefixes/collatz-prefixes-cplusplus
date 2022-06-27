/**
 * @file util.tpp
 * @author Erhan Tezcan (erhany96@gmail.com)
 * @brief Template function definitions for util.hpp
 * @version 0.1
 * @date 2021-08-02
 *
 * @copyright Erhan Tezcan (c) 2021
 *
 */

/**
 * @brief Print the contents of a vector.
 *
 * @tparam T type of the vector
 * @param v vector
 * @param title optional title for printing
 */
template <typename T>
void print_vector(const vector<T>& v, const char* title) {
  cout << title << "[";
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << "]" << endl;
}

/**
 * @brief Print the contents of a vector of pairs.
 *
 * @tparam TL type of pair.first
 * @tparam TR type of pair.second
 * @param v vector of pairs
 * @param title optional title for printing
 */
template <typename TL, typename TR>
void print_vector_pair(const vector<pair<TL, TR> >& v, const char* title) {
  cout << title << "[";
  for (int i = 0; i < v.size(); ++i) {
    cout << "(" << v[i].first << ", " << v[i].second << ") ";
  }
  cout << "]" << endl;
}

/**
 * @brief Print the contents of a vector of vectors.
 *
 * @tparam T type of vector
 * @param v vector of vectors
 * @param title optional title for printing
 */
template <typename T>
void print_vector_vector(const vector<vector<T> >& v, const char* title) {
  cout << title << "[";
  for (int i = 0; i < v.size(); ++i) {
    cout << "[";
    for (int j = 0; j < v[i].size(); ++j) {
      cout << v[i][j] << ' ';
    }
    cout << "] ";
  }
  cout << "]" << endl;
}

/**
 * @brief Generates a random number in the given [min, max] range.
 *
 * @tparam T type of the number
 * @param max maximum value
 * @param min minimum value
 * @return a random number of type T
 */
template <typename T>
double random_number(T max, T min) {
  return (T)((((double)rand() / RAND_MAX) * (double)(max - min)) + (double)(min));
}
