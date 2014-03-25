/*
 *  $Id: DmpServiceManager.cc, 2014-03-15 10:00:34 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 15/03/2014
*/

#include <iostream>
#include "DmpServiceManager.h"
#include "DmpVService.h"

//-------------------------------------------------------------------
DmpServiceManager::~DmpServiceManager(){
  for(std::map<std::string,DmpVService*>::iterator it=fServiceMap.begin();it != fServiceMap.end();++it){
    std::cout<<"delete service: "<<it->first<<std::endl;;
    delete it->second;
  }
  std::cout<<"Delete DmpServiceManager"<<std::endl;
}

//-------------------------------------------------------------------
DmpVService* DmpServiceManager::GetService(const std::string &name, bool create){
// *
// *  TODO: ???  protect me ?
// *
  return fServiceMap[name];
}

//-------------------------------------------------------------------
void DmpServiceManager::AppendThisService(const std::string &name,DmpVService *aSvc){
  if(fServiceMap.find(name) != fServiceMap.end()){  // exist
    DmpVService *tmp = fServiceMap[name];
    delete tmp;
    fServiceMap[name] = aSvc;
  }else{    // no exist
    fServiceMap.insert(std::pair<std::string,DmpVService*>(name,aSvc));
  }
}

//-------------------------------------------------------------------
void DmpServiceManager::ListAllService(){
  for(std::map<std::string,DmpVService*>::iterator it=fServiceMap.begin();it!=fServiceMap.end();++it){
    std::cout<<"service : "<<it->first<<std::endl;
  }
}

//-------------------------------------------------------------------
DmpServiceManager::DmpServiceManager(){
  std::cout<<"\n*********************************************************"<<std::endl;
  std::cout<<"\t\tDAMPE software version 1.0"<<std::endl;
  std::cout<<"*********************************************************"<<std::endl;
  std::cout<<"Initalize core:"<<std::endl;
  std::cout<<"\tSetup DmpServiceManager...    Done"<<std::endl;
  ListAllService();
}

//-------------------------------------------------------------------
DmpServiceManager *gServiceMgr = DmpServiceManager::GetInstance();
