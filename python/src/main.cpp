#include <pybind11/pybind11.h>
#include <TMCStepper.h>

namespace py = pybind11;

PYBIND11_MODULE(steppers, m) {
    py::class_<TMC2130Stepper>(m, "TMC2130")
        //.def(py::init<uint16_t, int8_t>())                               // CS, link_index * klopt niet je moet argument zetten!
        .def(py::init<uint16_t, uint16_t, uint16_t, uint16_t, int8_t>()) // CS, MOSI, MISO, SCK, link_index *
        .def("begin", &TMC2130Stepper::begin); // check *
        
        // volgende zijn setters en getters?
        //.def("toff", py::overload_cast<uint8_t>(&TMC2130Stepper::toff), "Set the toff time") // check *
        //.def("test_connection", (py::overload_cast<uint8_t>(&TMC2130Stepper::test_connection)) // check
        //.def("microsteps", py::overload_cast<uint16_t>(&TMC2130Stepper::microsteps)) // check
        
        // snap ik niet?
        //.def("rms_current", py::overload_cast<uint16_t>(&TMC2130Stepper::rms_current), "Set the max RMS current in mili ampere",
        // py::arg("mA"), py::arg("multiplier") = 0.5, py::arg("RS") = 0.11); // check
}