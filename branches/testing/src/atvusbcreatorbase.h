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

//just a dummy for a proper logger
struct Logger {
  void error(const std::string& fcr_message){
    std::cerr << fcr_message << std::endl;
  }
};

class AtvUsbCreatorBase
{

public:
  void setDMGPath(const std::string& fcr_path);
  const std::string& getcrDMGPath() const;
  
  void setBootEfiPath(const std::string& fcr_path);
  const std::string& getcrBootEfiPath() const;
  
  void setDrive(const std::string& fcr_path);
    
  //get access to logger functionality
  Logger& logger();
  
private:
  std::string m_dmg_path;
  std::string m_bootefi_path;
  std::string m_drive;
  Logger m_logger;
};
#endif //ATVUSBCREATORBASE_H
