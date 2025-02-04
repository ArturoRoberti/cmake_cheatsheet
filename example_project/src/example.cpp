#include "example.hpp"

namespace example {

/// @brief Constructor
ExampleClass::ExampleClass() {
    srand(time(NULL)); // Seed the random number generator
    vector = Eigen::VectorXd::Random(3);
}

/// @brief Print the class vector
void ExampleClass::printVector() {
    std::cout << "\nVector: (" << vector.transpose() << ")^T\n";
}

/// @brief Print a given vector
/// @param vector The vector to print
void ExampleClass::printVector(const Eigen::VectorXd& vector) {
    std::cout << "\nVector: (" << vector.transpose() << ")^T\n";
}

} // namespace example