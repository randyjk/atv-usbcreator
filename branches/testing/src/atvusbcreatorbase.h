//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Stephan Diederich
//
//   Project name:      atvusb-creator
//
//   Date:              10/2008
//
//   Class:             AtvUsbCreatorBase
//
//   Base class:        
//
//   Derived class(es): AtvUsbCreator{Win32,OSX,Linux} 
//
//   Exceptions:        
//
//   Description:       Base class for usb-creator functionality, specialized for the platform when needed
//
//   ---------------------------------------------------------------------- 



#ifndef ATVUSBCREATORBASE_H
#define ATVUSBCREATORBASE_H

#include <string>
#include <iostream>
#include <vector>

#include "Lists.h"


//just a dummy for a proper logger
struct Logger {
  void error(const std::string& fcr_message){
    std::cerr << fcr_message << std::endl;
  }
};

//---------------------------------------------------------------------- 
class AtvUsbCreatorBase {

public:
  void setDMGPath(const std::string &fcr_path);
  const std::string& getcrDMGPath() const;
  
  void setBootEFIPath(const std::string &fcr_path);
  const std::string& getcrBootEFIPath() const;
  
  void setDrive(const std::string &fcr_path);
    
    
  void load_installers(void);
  void load_patchsticks(void);
  void load_packages(PATCHSTICK &patchstick);
  
  //get access to logger functionality
  Logger& logger();
  
private:
  std::vector<INSTALLER>  m_installers;
  std::vector<PATCHSTICK> m_patchsticks;
  std::vector<PACKAGE>    m_packages;
  std::string             m_dmg_path;
  std::string             m_bootefi_path;
  std::string             m_drive;
  Logger                  m_logger;
};
#endif //ATVUSBCREATORBASE_H



