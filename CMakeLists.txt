cmake_minimum_required(VERSION 3.18)
project(pyuconfig LANGUAGES CXX)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include pybind11
find_package(pybind11 CONFIG REQUIRED)

# Commented out until upstream provides CMakeLists or a dedicated library target
# add_subdirectory(uConfig)

# Create the binding module named `pyuconfig`
# Build native extension and place it inside the Python package directory
pybind11_add_module(_pyuconfig bindings/module.cpp)
set_target_properties(_pyuconfig PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/pyuconfig")

# TODO: link against uConfig once a CMake target is available
# target_link_libraries(pyuconfig PRIVATE uconfig)

# Optional: add include dirs if uConfig exposes headers
# target_include_directories(pyuconfig PRIVATE uConfig/include)
