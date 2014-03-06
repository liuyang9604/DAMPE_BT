/*
 *  $Id: DmpEventRaw.h, 2014-03-06 16:46:54 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 25/02/2014
*/

#include "TObject.h"

class TClonesArray;
class DmpEvtHeader;

class DmpEventRaw : public TObject{
/*
 *  DmpEventRaw
 *
 *  use this to book branch of RawDataConversion(output is Raw.root), only save all ADC information
 *  at the begining of Reconstruction will use the Raw.root and update the Hits information then save the opend root file
 *  (the sturctures of input and output root files of are the same)
 *
 *  Simulation will also use this class to book the branch, and the output of Simulation has the information of Hits
 *
 */
public:
  DmpEventRaw();
  ~DmpEventRaw();
  DmpEvtHeader* GetEventHeader() const {return fEvtHeader;};
  //TClonesArray* GetHitCollectionPsd() const {return fPsdHits;};
  //TClonesArray* GetHitCollectionStk() const {return fStkHits;};
  TClonesArray* GetHitCollectionBgo() const {return fBgoHits;};
  //TClonesArray* GetHitCollectionNud() const {return fNudHits;};

private:
  DmpEvtHeader      *fEvtHeader;
// *
// *  TODO: add hits collection of Psd, Stk and Nud
// *
  //TClonesArray      *fPsdHits;  //->
  //TClonesArray      *fStkHits;  //->
  TClonesArray      *fBgoHits;  //->
  //TClonesArray      *fNudHits;  //->

  ClassDef(DmpEventRaw,1)
};
