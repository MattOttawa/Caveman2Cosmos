#include "CvGameCoreDLL.h"

//
// Python interface for CvProperties class
// simple enough to be exposed directly - no wrapper
//

void CyPropertiesPythonInterface()
{
	python::class_<CvProperties>("CvProperties")

		.def("getProperty", &CvProperties::_getProperty, "int (int)")
		.def("getValue", &CvProperties::getValue, "int (int)")
		.def("setValue", &CvProperties::setValue, "void (int, int)")
		.def("changeValue", &CvProperties::changeValue, "void (int, int)")
		.def("getNumProperties", &CvProperties::getNumProperties, "int ()")
		.def("getValueByProperty", &CvProperties::_getValueByProperty, "int (int)")
		.def("setValueByProperty", &CvProperties::_setValueByProperty, "void (int, int)")
		.def("changeValueByProperty", &CvProperties::_changeValueByProperty, "void (int, int)")
		.def("getChangeByProperty", &CvProperties::_getChangeByProperty, "int (int)")
		.def("getPropertyDisplay", &CvProperties::getPropertyDisplay, "wstring (int)")
		;
}