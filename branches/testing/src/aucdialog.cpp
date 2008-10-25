#include "aucdialog.h"

//include our generated ui_h
#include "ui_atvusb.h"

//probably move this include hassle into an atvusbcreatorfactory.h
#ifdef WIN32
  #error "nothing here yet..implement me!"
  #include "win32/atvusbcreatorwin32.h"
#else
#ifdef __APPLE__
  #include "osx/atvusbcreatorosx.h"
#else
 //linux
 #error "nothing here yet..implement me!"
 #include "osx/atvusbcreatorlinux.h"
#endif
#endif

AucDialog::AucDialog(): QDialog(), mp_ui(new Ui::AucDialog), mp_creator(0){
  mp_ui->setupUi(this);
  //probably move this include hassle into an atvusbcreatorfactory.h
#ifdef WIN32
  mp_creator = new AtvUsbCreatorWin32;
#else
#ifdef __APPLE__
  mp_creator = new AtvUsbCreatorOSX;
#else
  mp_creator = new AtvUsbCreatorLinux;
#endif
#endif  
}

AucDialog::~AucDialog(){
  delete mp_ui;  
  delete mp_creator;
}
