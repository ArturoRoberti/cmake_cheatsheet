#include <Eigen/Eigen>
#include <iostream>

namespace example {

class ExampleClass {
public:
    // Constructor and destructor
    ExampleClass();
    ~ExampleClass() = default;

    // Printers
    void printVector();
    void printVector(const Eigen::VectorXd& vector);

    // Getters
    inline int getSize() const { return vector.size(); }
    inline Eigen::VectorXd getVector() const { return vector; }

private:
    Eigen::VectorXd vector;
};

} // namespace example