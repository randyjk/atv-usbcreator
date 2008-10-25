#include "aucdialog.h"

#include <stdexcept>

#include <QtGui/QFileDialog>

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
  createPlatformSpecificCreator();
  connectGui();
}

AucDialog::~AucDialog(){
  delete mp_ui;  
  delete mp_creator;
}

void AucDialog::selectFile(){
  QString dmgfile = QFileDialog::getOpenFileName(this,"Select AppleTV Update DMG", ".", "DMG (*.dmg)" );
  if( dmgfile.size() ){
    try {
      //TODO port me
      //self.live.dmg = self._to_unicode(dmgfile)
    } catch (std::exception& e){ 
      //TODO no loggin yet
      //self.live.log.error(str(e))
      status("Sorry, I'm having trouble encoding the filename "
            "of your livecd.  You may have better luck if "
            "you move your DMG to the root of your drive "
             "(ie: C:\)");
    }
    status(dmgfile + " selected");
  }
}

void AucDialog::connectGui(){
  connect(mp_ui->browseButton, SIGNAL(clicked()), this, SLOT(selectFile()));
  connect(mp_ui->startButton,  SIGNAL(clicked()), this, SLOT(build_installer()));
  connect(mp_ui->installerMenu,  SIGNAL(currentIndexChanged(int)), this, SLOT(set_installer_pict()));
  connect(mp_ui->installerMenu,  SIGNAL(currentIndexChanged(int)), this, SLOT(set_installer_options()));
  connect(mp_ui->installMenu_2,  SIGNAL(currentIndexChanged(int)), this, SLOT(update_options2()));
  connect(mp_ui->installMenu_3,  SIGNAL(currentIndexChanged(int)), this, SLOT(update_options3()));
  connect(mp_ui->installCheckbox,  SIGNAL(stateChanged(int)), this, SLOT(update_options3_fromcheckbox()));
  connect(mp_ui->deviceRefreshButton, SIGNAL(clicked()), this, SLOT(populate_devices()));
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

void AucDialog::createPlatformSpecificCreator(){
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

void AucDialog::status(QString f_message){
  mp_ui->statusInfoEdit->append(f_message);
}
