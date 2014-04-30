/*
 *  $Id: DmpEventKernelLinkDef.h, 2014-03-22 02:28:01 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 13/12/2013
*/

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all namespaces;

#pragma link C++ class DmpRdcHeaderSubDet+;
#pragma link C++ class DmpEvtRdcHeader+;
#pragma link C++ class DmpEvtRdcMSD+;
// *
// *  TODO: choose one, EvtHeader and EvtRdcHeader
// *
#pragma link C++ class DmpEvtHeader+;
#pragma link C++ class DmpEvtSimPrimaryParticle+;

#endif
