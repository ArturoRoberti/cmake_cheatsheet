#include "example.hpp"
#include <iostream>

int main() {
    example::ExampleClass example;

    // Try normal print
    example.printVector();

    // Try getter and  overloaded print
    auto vec = example.getVector();
    example.printVector(vec);
    
    return 0;
}