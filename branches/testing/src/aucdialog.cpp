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
  connectGui();
}

AucDialog::~AucDialog(){
  delete mp_ui;  
  delete mp_creator;
}

void AucDialog::connectGui(){
  connect(mp_ui->browseButton, SIGNAL(clicked()), this, SLOT(selectfile()));
  connect(mp_ui->startButton,  SIGNAL(clicked()), this, SLOT(build_installer));
  connect(mp_ui->installerMenu,  SIGNAL(currentIndexChanged(int)), this, SLOT(set_installer_pict));
  connect(mp_ui->installerMenu,  SIGNAL(currentIndexChanged(int)), this, SLOT(set_installer_options));
  connect(mp_ui->installMenu_2,  SIGNAL(currentIndexChanged(int)), this, SLOT(update_options2));
  connect(mp_ui->installMenu_3,  SIGNAL(currentIndexChanged(int)), this, SLOT(update_options3));
  connect(mp_ui->installCheckbox,  SIGNAL(stateChanged(int)), this, SLOT(update_options3_fromcheckbox));
  connect(mp_ui->deviceRefreshButton, SIGNAL(clicked()), this, SLOT(populate_devices));
  /*
  connect(mp_ui->live_thread,  SIGNAL(status(PyQt_PyObject)), this, SLOT(status));
  connect(mp_ui->live_thread,  SIGNAL(finished()), lambda: this, SLOT(enable_widgets(True)));
  connect(mp_ui->live_thread,  SIGNAL(terminated()), lambda: this, SLOT(enable_widgets(True)));
  connect(mp_ui->live_thread,  SIGNAL(progress(int)), this, SLOT(progress));
  connect(mp_ui->live_thread,  SIGNAL(maxprogress(int)), this, SLOT(maxprogress));
  connect(mp_ui->progress_thread, SIGNAL(progress(int)), this, SLOT(progress));
  connect(mp_ui->progress_thread, SIGNAL(maxprogress(int)), this, SLOT(maxprogress));
  connect(mp_ui->download_progress, SIGNAL(progress(int)), this, SLOT(progress));
  connect(mp_ui->download_progress, SIGNAL(maxprogress(int)), this, SLOT(maxprogress));
  */
}