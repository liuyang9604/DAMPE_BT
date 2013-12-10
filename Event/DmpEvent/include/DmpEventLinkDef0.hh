/*=============================================================================
#       FileName :          DmpEvtLinkDef.hh
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-13   00:39:02
#------------------------------------------------------------------------------
#       Description  :
#           for load libEvent.so in root
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-13   00:39:02
=============================================================================*/

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ enum DmpERunMode;
#pragma link C++ enum DmpEParticleID;

#pragma link C++ class DmpParticle+;
#pragma link C++ class DmpEvtAbsSubDet+;
#pragma link C++ class DmpEvtHeader+;


