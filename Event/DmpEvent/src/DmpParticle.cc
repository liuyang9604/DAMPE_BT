/*=============================================================================
#       FileName :          DmpParticle.cc
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-12-10   13:44:29
#------------------------------------------------------------------------------
#       Description  :
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-12-10   13:44:29
=============================================================================*/

#include "DmpParticle.hh"

ClassImp(DmpParticle)

//______________________________________________________________________________
DmpParticle::DmpParticle()
 :fPID(kUnknown),
  fCharge(-100),
  fEnergy(-100)
{}

//______________________________________________________________________________
DmpParticle::~DmpParticle()
{}

//______________________________________________________________________________
void DmpParticle::Reset(){
  fPID = kUnknown;
  fCharge = -100;
  fEnergy = -100;
}

