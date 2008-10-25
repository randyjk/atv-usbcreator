#include "atvusbcreatorbase.h"

void AtvUsbCreatorBase::setDMGPath(const std::string& fcr_path){
  m_dmg_path = fcr_path;
}

const std::string& AtvUsbCreatorBase::getcrDMGPath() const{
  return m_dmg_path;
}

void AtvUsbCreatorBase::setBootEfiPath(const std::string& fcr_path){
  m_bootefi_path = fcr_path;
}

const std::string& AtvUsbCreatorBase::getcrBootEfiPath() const{
  return m_bootefi_path;
}

void AtvUsbCreatorBase::setDrive(const std::string& fcr_path){
  m_drive = fcr_path;
}
Logger& AtvUsbCreatorBase::logger(){
  return m_logger;
}
