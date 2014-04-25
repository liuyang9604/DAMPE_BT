/*
 *  $Id: DmpRdcAlgBgo.h, 2014-04-17 00:18:49 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 09/03/2014
*/

#ifndef DmpRdcAlgBgo_H
#define DmpRdcAlgBgo_H

#include "DmpRdcVAlgSubDet.h"

class DmpRdcAlgBgo : public DmpRdcVAlgSubDet{
/*
 *  DmpRdcAlgBgo
 *
 *      This is the default Rdc Alg of Bgo
 *
 *      User could write a new one, and
 *      append it into DmpAlgMgr in JobOpt file. Then,
 *      could run the new Alg.
 *
 */
public:
  DmpRdcAlgBgo();
  ~DmpRdcAlgBgo();
  bool ProcessThisEvent();      // convert one event

private:
  bool InitializeSubDet();      // setup connector, etc.
  void AppendThisSignal(const int&,const float&);

};

#endif

