#include <pybind11/pybind11.h>
#include "lensdriver.h"
#include "pylensdriver.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pylensdriver, m) {
  m.doc() = "Python bindings for lens driver";

  py::class_<PyLensDriver>(m, "PyLensDriver")
    .def(py::init<std::string>())
    .def("set_current_4096",
         [](PyLensDriver &d, int i) { d.command_i(cmd_set_current_4096, i); },
         "Set current");
};
