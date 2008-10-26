#include "aucdialog.h"

#include <stdexcept>

#include <QtGui/QFileDialog>

#include "aucreleasedownloader.h"

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

AucDialog::AucDialog(): QDialog(), mp_ui(new Ui::AucDialog), 
  mp_creator(createPlatformSpecificCreator()), 
  m_progress_thread(), 
  m_thread(mp_creator, &m_progress_thread, this)
{
  mp_ui->setupUi(this);
  
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
      //TODO what's the _to_unicode_thing? how can it go wrong?
      //self.live.dmg = self._to_unicode(dmgfile)
      mp_creator->setDMGPath(dmgfile.toStdString());
    } catch (std::exception& e){ 
      //TODO no loggin yet
      mp_creator->logger().error(e.what());
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
  connect(mp_ui->startButton,  SIGNAL(clicked()), this, SLOT(buildInstaller()));
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

AtvUsbCreatorBase* AucDialog::createPlatformSpecificCreator(){
//probably move this include hassle into an atvusbcreatorfactory.h
#ifdef WIN32
  return new AtvUsbCreatorWin32;
#else
#ifdef __APPLE__
  return new AtvUsbCreatorOSX;
#else
  return new AtvUsbCreatorLinux;
#endif
#endif  
}

void AucDialog::status(QString f_message){
  mp_ui->statusInfoEdit->append(f_message);
}

void AucDialog::enableWidgets(bool f_enable){
  mp_ui->startButton->setEnabled(f_enable);
  mp_ui->browseButton->setEnabled(f_enable);
  mp_ui->installerMenu->setEnabled(f_enable);
  mp_ui->installMenu_1->setEnabled(f_enable);
  mp_ui->installMenu_2->setEnabled(f_enable);
  mp_ui->installMenu_3->setEnabled(f_enable);
  mp_ui->installCheckbox->setEnabled(f_enable);
  mp_ui->deviceCombo->setEnabled(f_enable);
  mp_ui->deviceRefreshButton->setEnabled(f_enable);
}

void AucDialog::buildInstaller(){
  enableWidgets(false);
  mp_creator->setDrive(getSelectedDrive().toStdString());
  if (QFile::exists(QString::fromStdString(mp_creator->getcrBootEfiPath()))){
    //if boot.efi exits just use it
    m_thread.start();
  } else {
    if (! mp_creator->getcrDMGPath().empty()){
      //If the user has selected an DMG, use it.
      m_thread.start();
    } else {
      assert(0); //TODO
      //If no selected DMG, download one.
      //TODO proxies
      mp_release_downloader = new AucReleaseDownloader(mp_creator, getAtvDmgUrl(), &m_download_progress);
    /*
          self.downloader = ReleaseDownloader(
                                              self.live,
                                              self.atv_dmg_url,
                                              progress=self.download_progress,
                                              proxies=self.live.get_proxies())
          self.connect(self.downloader,
                       QtCore.SIGNAL("dlcomplete(PyQt_PyObject)"),
                       self.download_complete)
          self.connect(self.downloader,
                       QtCore.SIGNAL("status(PyQt_PyObject)"),
                       self.status)
          self.downloader.start()
          */
    }
  }
}

QString AucDialog::getSelectedDrive(){
  //TODO: fix this when we know what needs to be done here
  return mp_ui->deviceCombo->currentText();
  //.split()[0];
}

QString AucDialog::getAtvDmgUrl(){

  assert(0);
  /*
   #import urllib
   #from xml.dom import minidom
   #
   #xml_doc = minidom.parse(urllib.urlopen('http://mesu.apple.com/version.xml'))
   #self.atv_dmg_url = xml_doc.getElementsByTagName('dict')[1].getElementsByTagName('string')[1].firstChild.data
   #self.atv_dmg_url = 'http://mesu.apple.com/data/OS/061-4632.2080414.gt5rW/2Z694-5428-3.dmg'
   self.atv_dmg_url = atv_dmg_info[0]['url']
   
  */
}