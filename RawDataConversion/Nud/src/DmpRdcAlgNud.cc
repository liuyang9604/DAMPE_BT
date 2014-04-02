/*
 *  $Id: DmpRdcAlgNud.cc, 2014-03-19 18:41:46 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 09/03/2014
*/

#include <iostream>

#include "TClonesArray.h"

#include "DmpRdcAlgNud.h"
#include "DmpRdcDataManager.h"
#include "DmpEventRaw.h"
#include "DmpEvtNudHit.h"
#include "DmpEvtHeader.h"
#include "DmpDetectorNud.h"

DmpRdcAlgNud::DmpRdcAlgNud(const std::string &name)
 :DmpRdcVAlgSubDet(name)
{
  fHitCollection = gDataMgr->GetRawEvent()->GetHitCollection(DmpDetector::kNud);
}

//-------------------------------------------------------------------
DmpRdcAlgNud::~DmpRdcAlgNud(){
}

//-------------------------------------------------------------------
#include "DmpRdcCnctPath.h"
bool DmpRdcAlgNud::Initialize(){
// *
// *  TODO:  check connector right?
// *
  std::string path = gCnctPathMgr->GetConnectorPath(DmpDetector::kNud);
  if(path == "default"){
    std::cout<<"\nNo set connector:\tNud"<<std::endl;
    return true;
  }else{
    fRunMe = true;
    std::cout<<"\nSetting connector:\tNud";
  }
  /*
  int FEEID, ChannelID;
  short LID, BID, SID, DID;
  int const MaxSignalNb_Side = (BT2012::kBarNb+BT2012::kRefBarNb)*BT2012::kDyNb;
  std::string note;
  char fileName[20];
  for(short l=0;l<BT2012::kPlaneNb*2;++l){
    LID = l;
    sprintf(fileName,"Layer_%d.cnct",l);
    ifstream cnctFile(path+fileName);
    if (!cnctFile.good()) {
      std::cerr<<"Error: "<<__FILE__<<"("<<__LINE__<<"), in "<<__PRETTY_FUNCTION__<<"\tRead "<<fileName<<"\tfailed..."<<std::endl;
      return false;
    }
    for(short s=0;s<BT2012::kSideNb;++s){
      getline(cnctFile,note);   // reserved 1 line for note
      cnctFile>>SID;
      getline(cnctFile,note);   // reserved 1 line for note
      cnctFile>>FEEID;
      getline(cnctFile,note);   // reserved 1 line for note
      for(short c=0;c<MaxSignalNb_Side;++c){
        cnctFile>>BID;
        cnctFile>>DID;
        cnctFile>>ChannelID;
        ConnectorNud.insert(std::make_pair(FEEID*1000+ChannelID,LID*10000+BID*100+SID*10+DID));     // FEEID*1000 + ChannelID as key, since MaxSignalNb_Side = (22+2)*3*2 = (kBarNb+kRefBarNb)*kDynb*kSideNb = 144 > 100
      }
    }
    cnctFile.close();
  }

  */
  return true;
}

//-------------------------------------------------------------------
#include "DmpRdcLog.h"
bool DmpRdcAlgNud::ProcessThisEvent(){
  if(not fRunMe) return true;
  std::cout<<"\t"<<__PRETTY_FUNCTION__;
  gRdcLog->StatusLog(0);
// *
// *  TODO: check conversion Nud
// *
//-------------------------------------------------------------------
  static short tmp=0, tmp2=0, nBytes=0;
  static std::ifstream *inFile = gDataMgr->gInFile;
  inFile->read((char*)(&tmp),1);
  if (tmp!=0xeb) {
    gRdcLog->StatusLog(-1);
    return false;
  }
  inFile->read((char*)(&tmp),1);
  if (tmp!=0x90) {
    gRdcLog->StatusLog(-2);
    return false;
  }
  inFile->read((char*)(&tmp),1);     // trigger
  sHeader->SetTrigger(DmpDetector::kNud,tmp);
  inFile->read((char*)(&tmp),1);     // run mode and FEE ID
  sHeader->SetRunMode(DmpDetector::kNud,tmp/16-DmpDetector::Nud::kFEEType);
  inFile->read((char*)(&tmp),1);     // data length, 2 Bytes
  inFile->read((char*)(&tmp2),1);
  nBytes = tmp*256+tmp2-2-2;            // 2 bytes for data length, 2 bytes for CRC
// *
// *  TODO: mode == k0Compress && data length == xxx
// *
  //if (sHeader->GetRunMode(DmpDetector::kNud) == DmpDetector::k0Compress) 
  for(short i=0;i<nBytes;i+=2){     // k0Compress
    inFile->read((char*)(&tmp),1);
    inFile->read((char*)(&tmp),1);
// *
// *  TODO: store impfore into hits
// *
    //fHitCollection->
  }
  inFile->read((char*)(&tmp),1);     // 2 bytes for CRC
  inFile->read((char*)(&tmp),1);     // 2 bytes for CRC, MUST split them
//-------------------------------------------------------------------

  gRdcLog->StatusLog(nBytes);
  return true;
}

//-------------------------------------------------------------------
void DmpRdcAlgNud::AppendThisSignal(const int &id,const float &v){

}

