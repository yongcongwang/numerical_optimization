/// @file This is the file to minimize the function
#pragma once

#include <Eigen/Eigen>

#include "lbfgs.hpp"

/// @class Define the class to minimize the cost
class Minimization {
 public:
  /// @brief Default constructor
  Minimization() = default;
  /// @brief Destructor
  ~Minimization() = default;
  /// @brief Avoid copy and move
  Minimization(const Minimization&) = delete;
  Minimization& operator=(const Minimization&) = delete;
  Minimization(Minimization&&) = delete;
  Minimization& operator=(Minimization&&) = delete;

 public:
  bool Run(const int n);
};
