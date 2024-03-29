/*
 *  $Id: DmpElementManager.h, 2014-04-11 23:43:14 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 26/03/2014
*/

#ifndef DmpElementManager_H
#define DmpElementManager_H

#include <list>
#include <string>

template<typename DmpElement>       // DmpElement: DmpVAlgorithm, DmpVService

class DmpElementManager{
public:
  DmpElementManager(const std::string&);
  virtual ~DmpElementManager();

public:
  void Replace(DmpElement*);
  void Append(DmpElement*);
  void ListAllElements();
  bool Initialize();
  bool Finalize();
  DmpElement* Get(const std::string&);

protected:
  const std::string& Name() const {return fName;}

protected:
  std::list<DmpElement*>    fElements;
  std::string               fName;

};


// define as below
//-------------------------------------------------------------------
#include <iostream>
template<typename DmpElement>
DmpElementManager<DmpElement>::DmpElementManager(const std::string &n)
 :fName(n)
{
  std::cout<<"---> DmpCore:\tCreate "<<fName;
}

//-------------------------------------------------------------------
template<typename DmpElement>
DmpElementManager<DmpElement>::~DmpElementManager(){
        /*
  for(typename std::list<DmpElement*>::iterator it = fElements.begin();it != fElements.end();++it){
    std::cout<<"\tdelete "<<(*it)->Name()<<std::endl;;
    delete (*it);
  }
  */
  std::cout<<"\t\tDone\n"<<std::endl;
}

//-------------------------------------------------------------------
template<typename DmpElement>
void DmpElementManager<DmpElement>::Replace(DmpElement *aEle){
  std::string name = aEle->Name();
  for(typename std::list<DmpElement*>::iterator it = fElements.begin();it != fElements.end();++it){
    if((*it)->Name() == name){
      delete (*it);
      (*it) = aEle;
    }
  }
}

//-------------------------------------------------------------------
template<typename DmpElement>
void DmpElementManager<DmpElement>::Append(DmpElement *aEle){
  std::cout<<fName<<":\tappend \t"<<aEle->Name();
  fElements.push_back(aEle);
  std::cout<<"\t\tdone"<<std::endl;
}

//-------------------------------------------------------------------
template<typename DmpElement>
void DmpElementManager<DmpElement>::ListAllElements(){
  std::cout<<"There are "<<fElements.size()<<" elements in "<<fName<<std::endl;
  for(typename std::list<DmpElement*>::iterator it = fElements.begin();it != fElements.end();++it){
    std::cout<<"\t\tname : "<<(*it)->Name()<<std::endl;
  }
}

//-------------------------------------------------------------------
template<typename DmpElement>
bool DmpElementManager<DmpElement>::Initialize(){
  for(typename std::list<DmpElement*>::iterator it = fElements.begin();it != fElements.end();++it){
    if(not (*it)->Initialize()){
      std::cout<<"Error: Initialize "<<(*it)->Name()<<" failed"<<std::endl;
      return false;
    }
  }
  return true;
}

//-------------------------------------------------------------------
template<typename DmpElement>
bool DmpElementManager<DmpElement>::Finalize(){
  for(typename std::list<DmpElement*>::iterator it = fElements.begin();it != fElements.end();++it){
    if(not (*it)->Finalize()) return false;
  }
  return true;
}

//-------------------------------------------------------------------
template<typename DmpElement>
DmpElement* DmpElementManager<DmpElement>::Get(const std::string &n) {
  for(typename std::list<DmpElement*>::iterator it = fElements.begin();it != fElements.end();++it){
    if((*it)->Name() == n){
      return (*it);
    }
  }
  return 0;
}

#endif

