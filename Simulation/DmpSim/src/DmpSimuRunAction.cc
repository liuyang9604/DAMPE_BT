// Description: This class hinerits from G4UserRunAction. It is used to
// evoke the save() method of the ntuple manager at the end of the run 
//
// Author(s):
//  - creation by X.Wu, 09/07/2013

#include "DmpSimuRunAction.hh"
#include "DmpRootEventDataManager.hh"
#include "DmpSimuPrimaryGeneratorAction.hh"


#include <stdlib.h>
#include "G4Run.hh"
#include "G4UImanager.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"

DmpSimuRunAction::DmpSimuRunAction(DmpRootEventDataManager* rootEvtMgr, DmpSimuPrimaryGeneratorAction* rootPrimMgr)
  :rootEventDataManager(rootEvtMgr), dmpSimuPrimaryGeneratorAction(rootPrimMgr)
{
}

DmpSimuRunAction::~DmpSimuRunAction()
{
}

void DmpSimuRunAction::BeginOfRunAction(const G4Run* aRun)
{  
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  rootEventDataManager->book(aRun);
  rootEventDataManager->beginRun(aRun);
  //can also set random seed for multiple jobs of the same simulation
  /***
  if ( fReadRndm ) {
    G4cout << "\n---> rndm status restored from file: " << fRndmFileName << G4endl;
    CLHEP::HepRandom::restoreEngineStatus(fRndmFileName);
    CLHEP::HepRandom::showEngineStatus();
  }   
  ***/
}


void DmpSimuRunAction::EndOfRunAction(const G4Run* aRun)
{


  rootEventDataManager->FillRun(aRun, dmpSimuPrimaryGeneratorAction);
  G4cout << "End of Run, saving the ntuple " << G4endl;
  rootEventDataManager->save();

  //can also save random seed for multiple jobs of the same simulation
  /***
  if ( fSaveRndm ) { 
    G4int runNumber = run->GetRunID();
    std::ostringstream fileName;
    fileName << "run" << runNumber << "end.rndm";
    CLHEP::HepRandom::saveEngineStatus(fileName.str().c_str()); 
    CLHEP::HepRandom::showEngineStatus();
  }     
  ***/
}









