# Download and unpack pybind11 at configure time
message(STATUS "Getting Pybind11...")

# set(PYBIND11_PYTHON_VERSION 3.10.12)

configure_file(
  cmake/pybind11_download.cmake
  ${PROJECT_SOURCE_DIR}/externals/pybind/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . 
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/externals/pybind
  OUTPUT_QUIET)
if(result)
  message(FATAL_ERROR "Cmake Step for Pybind11 failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/externals/pybind
  OUTPUT_QUIET)
if(result)
  message(FATAL_ERROR "Build step for eigen failed: ${result}")
endif()

message(STATUS "Pybind11 downloaded!")

set(PYBIND11_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/externals/pybind/pybind11/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/externals/pybind/pybind11 EXCLUDE_FROM_ALL)