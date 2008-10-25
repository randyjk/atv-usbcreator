#include "atvusbcreatorbase.h"

void AtvUsbCreatorBase::setDMGPath(const std::string& fcr_path){
  m_dmg_path = fcr_path;
}

void AtvUsbCreatorBase::setBootEfiPath(const std::string& fcr_path){
  m_bootefi_path = fcr_path;
}

Logger& AtvUsbCreatorBase::logger(){
  return m_logger;
}
