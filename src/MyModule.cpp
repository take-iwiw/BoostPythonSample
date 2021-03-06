/*
g++ -I/usr/include/python2.7 -fPIC -shared -o MyModule.so func.cpp ClassA.cpp MyModule.cpp -lboost_python
*/

#define BOOST_PYTHON_STATIC_LIB

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>
#include "func.h"
#include "ClassA.h"

BOOST_PYTHON_MODULE( MyModule )
{
	boost::python::def( "getNumber", getNumber );
	boost::python::def( "setGetNumber", setGetNumber );
	boost::python::def( "getString", getString );
	boost::python::def( "getPoint", getPoint );
	boost::python::class_<POINT>("POINT", boost::python::init<>())
		.add_property("x", &POINT::x)
		.add_property("y", &POINT::y)
	;

	boost::python::class_<ClassA::VECTOR_2D>("ClassA::VECTOR_2D", boost::python::init<>())
		.add_property("x", &ClassA::VECTOR_2D::x)
		.add_property("y", &ClassA::VECTOR_2D::y)
	;

	boost::python::enum_<ClassA::COLOR>("ClassA_COLOR")
		.value("RED", ClassA::RED)
		.value("GREEN", ClassA::GREEN)
		.value("BLUE", ClassA::BLUE)
	;


	boost::python::class_<ClassA>("ClassA", boost::python::init<int>())
		.add_property("a", &ClassA::a)
		.def("getA", &ClassA::getA)
		.def("getVector", &ClassA::getVector)
		.def("setGetColor", &ClassA::setGetColor)
	;

}
