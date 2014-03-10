/*
 *  $Id: DmpBindingRdc.cc, 2014-03-09 23:44:57 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 07/03/2014
*/

#include <boost/python.hpp>
#include "DmpEntranceRdc.h"

BOOST_PYTHON_MODULE(libDmpRdc){
  using namespace boost::python;
  using namespace DmpCore;

  def("SetConnectorPSd",SetConnectorPsd);
  def("SetConnectorStk",SetConnectorStk);
  def("SetConnectorBgo",SetConnectorBgo);
  def("SetConnectorNud",SetConnectorNud);

  def("SetInDataPath",RdcSetInDataPath);
  def("SetOutDataPath",RdcSetOutDataPath);
  def("GetOutDataPath",RdcGetOutDataPath);
  def("SetOutDataName",RdcSetOutDataName);
  def("Initialize",RdcInitialize);
  def("Execute",RdcExecute);
  def("Clear",RdcClear);
}


