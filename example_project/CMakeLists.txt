cmake_minimum_required(VERSION 3.0)

project(example_project)

# Used to generate compile_commands.json - make sure to add (for VSCode Intellisense)
# '"compileCommands": "${workspaceFolder}/build/compile_commands.json",'
# to the configuration in the 'c_cpp_properties.json' file (generated via "Ctrl + Shift + P" -> "C/C++: Edit Configurations (JSON)")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add custom library
add_library(example_library src/example.cpp)
target_include_directories(example_library PUBLIC include)

# Add the executable
add_executable(example_executable src/example_executable.cpp)
target_link_libraries(example_executable example_library)

# Include external library 'Eigen3'
## - Install Eigen3 via 'sudo apt install libeigen3-dev'
## - Test Eigen3 autoinstallation via commenting out 'find_package(Eigen3 3.4.0 QUIET)'
find_package(Eigen3 3.4.0 QUIET)
if(Eigen3_FOUND)
        message(STATUS "Using system provided Eigen.")
else()
        message(STATUS "No system provided Eigen found. Auto-installing via github repo.")
        include(cmake/eigen.cmake)
endif()

## Link Eigen3 to the library - is automatically linked to the executable, as it is linked to the library
target_include_directories(example_library PUBLIC
        ${EIGEN3_INCLUDE_DIR}
)

# (Optionally) Install the library to the system to /usr/local/lib
install(TARGETS example_library DESTINATION lib)

# Testing
## - Install GTest via 'sudo apt install libgtest-dev'
option(BUILD_TESTING "Build the tests" ON)
if(BUILD_TESTING)
        find_package(GTest CONFIG REQUIRED)
        add_subdirectory(tests)
endif()

# Pybind
file(GLOB_RECURSE PYBIND_SRC src/*pybind*.cpp)
if(PYBIND_SRC)
        message(STATUS "Building Python bindings.")
        # - Install pybind via 'sudo apt install pybind11-dev'
        #   otherwise, auto-installed here
        find_package(pybind11 2.9.1 QUIET)
        if(pybind11_FOUND)
                message(STATUS "Using system provided Pybind.")
        else()
                message(STATUS "No system provided Pybind found. Auto-installing via github repo.")
                include(cmake/pybind11.cmake)
        endif()
        # Enable PIC (necessary for dynamic libraries, as without fixed memory addresses)
        set_target_properties(example_library PROPERTIES POSITION_INDEPENDENT_CODE ON)

        # Add pybind module and link to necessary libraries
        pybind11_add_module(example_py MODULE ${PYBIND_SRC})
        target_link_libraries(example_py PRIVATE example_library)
endif()