

#include "default_list.h"
#include "atvusbcreatorbase.h"

//---------------------------------------------------------------------- 
void AtvUsbCreatorBase::setDMGPath(const std::string &fcr_path) {
  m_dmg_path = fcr_path;
}

//---------------------------------------------------------------------- 
const std::string& AtvUsbCreatorBase::getcrDMGPath() const {
  return m_dmg_path;
}

//---------------------------------------------------------------------- 
void AtvUsbCreatorBase::setBootEFIPath(const std::string &fcr_path) {
  m_bootefi_path = fcr_path;
}

//---------------------------------------------------------------------- 
const std::string& AtvUsbCreatorBase::getcrBootEFIPath() const {
  return m_bootefi_path;
}

//---------------------------------------------------------------------- 
void AtvUsbCreatorBase::setDrive(const std::string &fcr_path) {
  m_drive = fcr_path;
}

//---------------------------------------------------------------------- 
void AtvUsbCreatorBase::load_installers(void) {
  int       index;
  
  for( index = 0; index < 8; index++) {
    if ( installers[index].enable ) {
      m_installers.push_back(installers[index]);
    }
  }
}

//---------------------------------------------------------------------- 
void AtvUsbCreatorBase::load_patchsticks(void) {
  int       index;
  
  for( index = 0; index < 6; index++) {
    if ( patchsticks[index].enable ) {
      m_patchsticks.push_back(patchsticks[index]);
    }
  }
}

//---------------------------------------------------------------------- 
void AtvUsbCreatorBase::load_packages(PATCHSTICK &patchstick) {
  int       index;
  
  for( index = 0; index < 21; index++) {
    if ( packages[index].enable ) {
      std::string::size_type loc = packages[index].depends.find(patchstick.depends, 0);
      if( loc != std::string::npos ) {
        m_packages.push_back(packages[index]);
      }
    }
  }
}
  
//---------------------------------------------------------------------- 
Logger& AtvUsbCreatorBase::logger() {
  return m_logger;
}
