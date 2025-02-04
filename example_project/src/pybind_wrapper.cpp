// pybind11
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
// #include <pybind11/stl.h>

// Own classes
#include "example.hpp"

// General
#include <sstream>

namespace py = pybind11;
using namespace example;

PYBIND11_MODULE(example_py, m) {
    py::class_<ExampleClass>(m, "ExampleClassPy")
        // Constructor(s)
        .def(py::init<>())
        // Singular methods
        .def("getSize", &ExampleClass::getSize)
        .def("getVector", &ExampleClass::getVector)
        // Overloaded method  - No input (different name - alternatively, use py::overload_cast)
        .def("printClassVector", static_cast<void (ExampleClass::*)()>(&ExampleClass::printVector))
        // Overloaded method - Vector input
        .def("printVector", static_cast<void (ExampleClass::*)(const Eigen::VectorXd&)>(&ExampleClass::printVector))
        // Representation
        .def("__repr__", [](const ExampleClass& a) {
            std::ostringstream oss;
            oss << "ExampleClass(vector=[" << a.getVector().transpose() << "])";
            return oss.str();
        });

    // Further classes and functions...
}