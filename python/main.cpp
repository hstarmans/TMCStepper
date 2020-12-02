#include <pybind11/pybind11.h>
#include <TMC2130Stepper.h>

namespace py = pybind11;

PYBIND11_MODULE(steppers, m) {
    py::class_<TMC2130Stepper>(m, "TMC2130")
        .def(py::init<uint32_t>())
        .def(py::init<uint32_t, uint32_t, uint32_t, uint32_t>())
        .def("begin", &TMC2130Stepper::begin)
        .def("toff", py::overload_cast<uint8_t>(&TMC2130Stepper::toff), "Set the toff time")
        .def("stealthChop", py::overload_cast<bool>(&TMC2130Stepper::stealthChop), "Enable stealtchop with boolean")
        .def("test_connection", &TMC2130Stepper::test_connection)
        .def("microsteps", py::overload_cast<uint16_t>(&TMC2130Stepper::microsteps))
        .def("rms_current", py::overload_cast<uint16_t, float, float>(&TMC2130Stepper::rms_current), "Set the max RMS current in mili ampere",
         py::arg("mA"), py::arg("multiplier") = 0.5, py::arg("RS") = 0.11);
}