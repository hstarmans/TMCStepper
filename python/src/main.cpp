#include <pybind11/pybind11.h>
#include <TMCStepper.h>

namespace py = pybind11;

PYBIND11_MODULE(steppers, m) {
    py::class_<TMC2130Stepper>(m, "TMC2130")
        .def(py::init<uint16_t, float, int8_t>(), py::arg("pinCS"), py::arg("RS")=0.11, py::arg("link_index"))
        .def(py::init<uint16_t, uint16_t, uint16_t, uint16_t, int8_t>(), py::arg("pinCS"), py::arg("pinMOSI"), py::arg("pinMISO"), py::arg("pinSCK"), py::arg("link_index"))
        .def("begin", &TMC2130Stepper::begin)
        .def("test_connection", &TMC2130Stepper::test_connection)
        .def("toff", py::overload_cast<uint8_t>(&TMC2130Stepper::toff), "Set the toff time")
        .def("microsteps", py::overload_cast<uint16_t>(&TMC2130Stepper::microsteps));
        //.def("rms_current", &TMC2130Stepper::rms_current, "Set the max RMS current in mili ampere", py::arg("mA"), py::arg("mult"));
}