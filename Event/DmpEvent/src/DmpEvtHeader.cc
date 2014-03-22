/*
 *  $Id: DmpEvtHeader.cc, 2014-03-20 20:00:00 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 13/12/2013
*/ 

#include <iostream>

#include "DmpEvtHeader.h"

ClassImp(DmpEvtHeader)

//-------------------------------------------------------------------
DmpEvtHeader::DmpEvtHeader()
 :fSec(0),
  fMillisec(0),
  fEventID(-1),
  fPdgCode(0),
  fTrgStatus(0),
  fModePsd(DmpDetector::kCompress),
  fModeStk(DmpDetector::kCompress),
  fModeBgo(DmpDetector::kCompress),
  fModeNud(DmpDetector::kCompress)
{
}

//-------------------------------------------------------------------
DmpEvtHeader::~DmpEvtHeader(){
}

//-------------------------------------------------------------------
void DmpEvtHeader::SetTime(const short &n,const short &v){
  fTime[n]=v;
  if(n < 6){
    if(n == 0){
      fSec = 0; fMillisec = 0;
    }
    fSec = fSec*256 + v;
  }else{
    fMillisec = fMillisec*256 + v;
  }
}

//-------------------------------------------------------------------
void DmpEvtHeader::PrintTime()const{
  std::cout<<"Time: ";
  for(short i=0;i<8;++i){
    std::cout<<" "<<std::hex<<fTime[i];
  }
  std::cout<<std::dec<<std::endl;
}

//-------------------------------------------------------------------
void DmpEvtHeader::GenerateTriggerStatus(){
    /*
     * all match
     *      1
     * one subDet not match the others
     *      0-(subDetID*1000 + |trigger_right - trigger_wrong|)
     * many subDet are not match, recored their ID only
     *      0-(sbuDetID_1*100 + subDetID_2*10 + subDetID_3)
     *
     */
  fTrgStatus = 0;
  static short wrongID = 0;
  for(short i=DmpDetector::gSubDetNo;i>-1;--i){
    if(fTriggers[DmpDetector::kBgo] != fTriggers[i]){
      wrongID = i;
      fTriggers[i] = fTriggers[DmpDetector::kBgo]-fTriggers[i];
      fTrgStatus = fTrgStatus*10-i;
    }
  }
  if(fTrgStatus != 0 && fTrgStatus > -10){  // only one wrong
    fTrgStatus = (fTriggers[wrongID]>0) ? (wrongID*1000+fTriggers[wrongID]):(wrongID*1000-fTriggers[wrongID]);
  }
  std::cout<<"\tWarning: event triggers not match... "<<fTrgStatus<<"\t"; PrintTime();
  for(wrongID=0;wrongID<DmpDetector::gSubDetNo;++wrongID){
    fTriggers[wrongID] = 0;
  }
}

//-------------------------------------------------------------------
void DmpEvtHeader::SetRunMode(const DmpDetector::DmpEDetectorID &id,const short &m){
  if(id == DmpDetector::kPsd){
    fModePsd = (DmpDetector::DmpERunMode)(m-1);
  }else if(id == DmpDetector::kStk){
    fModeStk = (DmpDetector::DmpERunMode)m;
  }else if(id == DmpDetector::kBgo){
    fModeBgo = (DmpDetector::DmpERunMode)m;
  }else if(id == DmpDetector::kNud){
    fModeNud = (DmpDetector::DmpERunMode)(m-2);
  }
}

//-------------------------------------------------------------------
DmpDetector::DmpERunMode DmpEvtHeader::GetRunMode(const DmpDetector::DmpEDetectorID &id) const{
  if(id == DmpDetector::kPsd)   return fModePsd;
  if(id == DmpDetector::kStk)   return fModeStk;
  if(id == DmpDetector::kBgo)   return fModeBgo;
  if(id == DmpDetector::kNud)   return fModeNud;
}

