#include <pybind11/pybind11.h>

namespace py = pybind11;

// Temporary stub until uConfig provides a proper C++ API header.
static const char *version_stub()
{
    return "0.0.0-dev";
}

PYBIND11_MODULE(_pyuconfig, m)
{
    m.doc() = "Python bindings for uConfig (stub)";

    // Expose version() placeholder
    m.def("version", &version_stub, "Return uConfig version (stub)");
}
